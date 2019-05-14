#include <iostream>
#include "utilities.h"
#include "Date.h"
#include "Packet.h"
#include "Client.h"
#include "Agency.h"
#include "Menus.h"

using namespace std;

int mainz() {
	Agency agency("agency.txt");
	mainMenu(agency);
	char c;
	cin >> c;
	return 0;
}
