#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Generally useful functions

bool isNumeric(const string &str);

string trim(string &str);

// Vector/String conversion functions

string sitesVectToStr(vector<string> sites);

vector<string> strToVect(const string &str, char delim = ' ');

vector<string> sitesStrToVect(string sites);

vector<int> strToIntVect(const string &str, char delim = ' ');

// Display functions

void line(int size, char ch = '-');
