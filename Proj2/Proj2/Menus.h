#pragma once

#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "utilities.h"
#include "Agency.h"


using namespace std;

void mainMenuSelect(Agency &agency);

void mainMenu(Agency &agency);

void insightsMenu(Agency &agency);

void insightsMenuSelect(Agency &agency);

void packetsMenu(Agency &agency);

void packetsMenuSelect(Agency &agency);

void viewPacketsMenu(Agency &agency);

void viewPacketsMenuSelect(Agency &agency);

void agencyMenu(Agency &agency);

void agencyMenuSelect(Agency &agency);
