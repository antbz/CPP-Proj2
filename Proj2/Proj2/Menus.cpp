#include "Menus.h"


void mainMenu(Agency &agency){
	line(35);
	cout << right << setfill(' ') << setw(22) << "MAIN MENU" << endl;
	line(35);
	cout << setw(4) << left << '|' << "1. Make Purchase" << endl;
	cout << setw(4) << left << '|' << "2. Report" << endl;
	cout << setw(4) << left << '|' << "3. Client Management" << endl;
	cout << setw(4) << left << '|' << "4. Packet Management" << endl;
	cout << setw(4) << left << '|' << "5. Agency Management" << endl;
	cout << endl << setw(4) << left << '|' << "0. CLOSE" << endl;
	line(35);
}

void mainMenuSelect(Agency &agency) {
	string str;
	int opt;
	bool valid;

	do {
		getOption(opt);
		valid = true;
		switch (opt) {
		case 1:
			int client_pos, packet_pos;
			while (true) {
				cout << "Client NIF (0 - cancel): ";
				getline(cin, str);
				if (str == "0") {
					break;
				}
				else if (isNumeric(str) && str.length() == 9) {
					client_pos = findClient(agency.getClients(), stoi(str));
					if (client_pos == -1) {
						str = "0";
						cinERR("Client does not exist!");
					}
					break;
				}
				cinERR("ERROR: Invalid NIF, try again!");
			}
			if (str == "0") {
				cout << endl << "ENTER to go to the MAIN MENU";
				getline(cin, str);
				mainMenu(agency);
				break;
			}
			while (true) {
				cout << "Packet ID (0 - cancel): ";
				getline(cin, str);
				if (str == "0") {
					break;
				}
				else if (isNumeric(str)) {
					packet_pos = findPacket(stoi(str), agency.getPackets());
					if (packet_pos == -1) {
						str = "0";
						cinERR("Packet does not exist!");
					}
					break;
				}
			}
			if (str == "0") {
				cout << endl << "ENTER to go to the MAIN MENU";
				getline(cin, str);
				mainMenu(agency);
				break;
			}
			/*if (buyPack(agency, client_pos, packet_pos)) {
				cout << "Successfull purchase!";
			}*/
			cout << endl << "ENTER to go to the MAIN MENU";
			getline(cin, str);
			mainMenu(agency);
			break;
		}
	} while (!valid);
}