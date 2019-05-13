#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool isNumeric(const string &str);

string trim(string &str);

vector<string> strToVect(const string &str, char delim = ' ');

vector<int> strToIntVect(const string &str, char delim = ' ');
