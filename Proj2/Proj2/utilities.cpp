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