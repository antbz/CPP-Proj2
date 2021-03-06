#include "Date.h"

Date::Date() {
}

Date::Date(string date) {
	vector<string> vdata = strToVect(date, '/');
	this->day = stoi(vdata.at(2));
	this->month = stoi(vdata.at(1));
	this->year = stoi(vdata.at(0));
}


Date::Date(unsigned short day, unsigned short month, unsigned year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

/*********************************
 * GET Methods
 ********************************/
unsigned short Date::getDay() const {
	return day;
}


unsigned short Date::getMonth() const {
	return month;
}

unsigned Date::getYear() const {
	return year;
}

/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day) {
	this->day = day;
}
void Date::setMonth(unsigned short month) {
	this->month = month;
}

void Date::setYear(unsigned year) {
	this->year = year;
}


/*********************************
 * Show Date
 ********************************/

 // display a Date in a nice format
ostream& operator<<(ostream &out, const Date &date) {
	out << setfill('0') << right << setw(4) << to_string(date.year);
	out << "/" << setfill('0') << setw(2) << to_string(date.month);
	out << "/" << setfill('0') << setw(2) << to_string(date.day);
	return out;
}

bool validDate(string date) {
	if (date.empty())
		return false;

	vector<string> vsdate = strToVect(date, '/');

	if (vsdate.size() != 3)
		return false;

	vector<int> vdate(3);

	for (int i = 0; i < 3; i++) {
		try {
			vdate.at(i) = stoul(vsdate.at(i));
		} catch (invalid_argument) {
			return false;
		}
	}

	if (vdate.at(0) < 1) {
		return false;
	}
	else if (vdate.at(1) < 1 || vdate.at(1) > 12) {
		return false;
	}
	else if (vdate.at(2) < 1) {
		return false;
	}
	else {
		switch (vdate.at(1)) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (vdate.at(2) > 31) {
				return false;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (vdate.at(2) > 30) {
				return false;
			}
			break;
		case 2:
			if (vdate.at(2) > 29) {
				return false;
			}
			break;
		default:
			break;
		}
	}
	return true;
}

bool cmpDate(const Date &date_1, const Date &date_2) {
	// Checks if date_1 is later than or the same as date_2
	if (date_1.getYear() < date_2.getYear())
		return false;
	else if (date_1.getMonth() < date_2.getMonth() && date_1.getYear() == date_2.getYear())
		return false;
	else if (date_1.getDay() < date_2.getDay() && date_1.getMonth() == date_2.getMonth() && date_1.getYear() == date_2.getYear())
		return false;
	return true;
}