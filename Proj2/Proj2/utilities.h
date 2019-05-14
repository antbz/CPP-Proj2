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

void cinERR(const string &message);

void getOption(int &dest, const string &message = "Option: ");

bool validNIF(string const &nif);

//bool buyPack(Agency agency, int c_pos, int p_pos);
