#include "utilities.h"

bool isNumeric(const string &str) {
    // Checks if a string is made up exclusively by numbers
    if (str.empty())
        return false;
    for (int i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

string trim(string &str) {
    // Removes whitespace from both ends of a string
    auto str_init = str.find_first_not_of(" \t");
    if (str_init == string::npos)
        return ""; // String is all whitespace
    auto str_end = str.find_last_not_of(" \t");
    auto str_range = str_end - str_init + 1;

    return str.substr(str_init, str_range);
}

string sitesVectToStr(vector<string> sites) {
	string result = sites.at(0);
	if (sites.size() > 1) {
		result += " - ";
		for (int i = 1; i < sites.size(); i++) {
			if (i == sites.size() - 1) {
				result += sites.at(i);
			}
			else {
				result += sites.at(i) + ", ";
			}
		}
		
	}
	return result;
};

vector<string> strToVect(const string &str, char delim) {
    // Splits a string into a vector of strings
    vector<string> result;
    string tmp;
    // Create stream from string
	istringstream ss(str);
    // Grab the elements from the stream, separated by delim
    while (getline(ss, tmp, delim)) {
        result.push_back(trim(tmp));
        // Skip whitespace
        ss >> ws;
    }
    return result;
}

vector<string> sitesStrToVect(string sites) {
	vector<string> result = strToVect(sites, '-');
	if (result.size() > 1) {
		vector<string> subsites = strToVect(result.at(1), ',');
		result.pop_back();
		result.insert(result.end(), subsites.begin(), subsites.end());
	}
	return result;
}

vector<int> strToIntVect(const string &str, char delim) {
    // Splits a string into a vector of UNSIGNED integers
    vector<int> result;
    string tmp;
    // Create stream from string
    istringstream ss(str);
    // Grab the elements from the stream, separated by delim
    // If string is empty return an empty vector
    while (getline(ss, tmp, delim)) {
        tmp = trim(tmp);
        if (isNumeric(tmp))
            result.push_back(stoi(tmp));
        else
            throw 100;
        // Skip whitespace
        ss >> ws;
    }
    return result;
}

void line(int size, char ch) {
    // Prints a line of specified size with specified character
    cout << setfill(ch) << setw(size) << "" << endl << setfill(' ');
}

void cinERR(const string &message) {
	// Outputs an error message and clears cin flags
	cerr << message;
	cout << endl;
	cin.clear();
}


void getOption(int &dest, const string &message) {
	// Tries to get a valid int option from cin to use in a switch-case
	string str;

	while (true) {
		try {
			cout << endl << message;
			getline(cin, str);
			cout << endl;
			dest = stoi(str);
			break;
		}
		catch (invalid_argument) {
			str = "";
			cinERR("ERROR: Invalid entry, try again");
		}
	}
}

bool validNIF(string const &nif) {
	if (nif.length() != 9 || !isNumeric(nif))
		return false;
	return true;
}