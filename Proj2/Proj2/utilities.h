#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
<<<<<<< HEAD
#include <map>
=======

>>>>>>> 3b4b30db5850363809ceea03a6f5b9eaef18d31f

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

void cinERR(const string &message);

void getOption(int &dest, const string &message = "Option: ");

bool validNIF(string const &nif);
