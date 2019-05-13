#include <iostream>
#include "utilities.h"
#include "Date.h"
#include "Packet.h"

using namespace std;

int mainz() {
	Packet packet1;
	packet1.setId(3);
	packet1.setSites(sitesStrToVect("Douro - a, tua, prima"));
	Date tempDate("2019/05/13");
	packet1.setBeginDate(tempDate);
	packet1.setEndDate(Date(15, 05, 2019));
	packet1.setPricePerPerson(300.56);
	packet1.setMaxPersons(35);
	cout << packet1 << endl;
	char c;
	cin >> c;
}
