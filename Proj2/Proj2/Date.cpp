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
	out << to_string(date.year) + "/" + to_string(date.month) + "/" + to_string(date.day);
	return out;
}