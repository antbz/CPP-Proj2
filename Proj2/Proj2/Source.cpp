#include <iostream>
#include "utilities.h"
#include "Date.h"
#include "Packet.h"
#include "Client.h"

using namespace std;

int mainz() {
	string date = "1/2/1";
	cout << validDate(date) << endl;
	Date date1(date);
	cout << date1 << endl;
	char c;
	cin >> c;
	return 0;
}
