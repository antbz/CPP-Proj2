#include "Menus.h"


void mainMenu(Agency &agency){
	line(35);
	cout << right << setfill(' ') << setw(22) << "MAIN MENU" << endl;
	line(35);
	cout << setw(4) << left << '|' << "1. Make Purchase" << endl;
	cout << setw(4) << left << '|' << "2. Business Insights" << endl;
	cout << setw(4) << left << '|' << "3. Client Management" << endl;
	cout << setw(4) << left << '|' << "4. Packet Management" << endl;
	cout << setw(4) << left << '|' << "5. Agency Management" << endl;
	cout << endl << setw(4) << left << '|' << "0. CLOSE" << endl;
	line(35);

	mainMenuSelect(agency);
}

void mainMenuSelect(Agency &agency) {
	string str;
	int opt;
	bool valid;

	do {
		getOption(opt);
		valid = true;
		switch (opt) {
		    case 0: // Close
                cout << "Save changes (Y/n): ";
                getline(cin, str);
                if (str == "N" || str == "n") {
                    cout << "Closed without saving" << endl;
                } else {
                    agency.saveAgency();
                    cout << "Changes saved!" << endl;
                }
                break;
			case 1: { // Make purchase
				int client_pos, packet_pos;
				while (true) {
					cout << "Client NIF (* - cancel): ";
					getline(cin, str);
					if (str == "*") {
						break;
					}
					else if (isNumeric(str) && str.length() == 9) {
						client_pos = findClient(agency.getClients(), stoi(str));
						if (client_pos == -1) {
							str = "*";
							cinERR("Client does not exist!");
						}
						break;
					}
					cinERR("ERROR: Invalid NIF, try again!");
				}
				if (str == "*") {
					cout << endl << "ENTER to go to the MAIN MENU";
					getline(cin, str);
					mainMenu(agency);
					break;
				}
				while (true) {
					cout << "Packet ID (* - cancel): ";
					getline(cin, str);
					if (str == "*") {
						break;
					}
					else if (isNumeric(str)) {
						packet_pos = findPacket(stoi(str), agency.getPackets());
						if (packet_pos == -1) {
							str = "*";
							cinERR("Packet does not exist!");
						}
						break;
					}
				}
				if (str == "*") {
					cout << endl << "ENTER to go to the MAIN MENU";
					getline(cin, str);
					mainMenu(agency);
					break;
				}
				if (buyPack(agency, client_pos, packet_pos)) {
					cout << "Successfull purchase!";
				}
				cout << endl << "ENTER to go to the MAIN MENU";
				getline(cin, str);
				mainMenu(agency);
				break;
			}
			case 2: {
				insightsMenu(agency);
				break;
			}
		    case 4: // Packet management
		        packetsMenu(agency);
		        break;
		    case 5: // Agency management
		        agencyMenu(agency);
                break;
            default:
                valid = false;
                cinERR("ERROR: Option does not exist, try again");
                break;
		}
	} while (!valid);
}

void insightsMenu(Agency &agency) {
	line(35);
	cout << right << setfill(' ') << setw(22) << "INSIGHTS" << endl;
	line(35);
	cout << setw(4) << left << '|' << "1. Sales Report" << endl;
	cout << setw(4) << left << '|' << "2. See N Most Visited Sites" << endl;
	cout << setw(4) << left << '|' << "3. Client Suggestions Based On N Most Visited Sites" << endl;
	cout << endl << setw(4) << left << '|' << "0. GO BACK" << endl;
	line(35);

	insightsMenuSelect(agency);
}

void insightsMenuSelect(Agency &agency) {
	string str;
	string n;
	int opt;
	bool valid;

	do {
		getOption(opt);
		valid = true;
		switch (opt) {
		case 0:
			mainMenu(agency);
			break;
		case 1:
			salesReport(agency);
			cout << endl << "ENTER to go back";
			getline(cin, str);
			insightsMenu(agency);
			break;
		case 2:
			cout << endl << "How many sites? - ";
			getline(cin, n);
			nSites(agency, stoi(n));
			cout << endl << "ENTER to go back";
			getline(cin, str);
			insightsMenu(agency);
			break;
		case 3:
			cout << endl << "How many sites? - ";
			getline(cin, n);
			suggestedPackets(agency, stoi(n));
			cout << endl << "ENTER to go back";
			getline(cin, str);
			insightsMenu(agency);
			break;
		default:
			valid = false;
			cinERR("ERROR: Option does not exist, try again");
			break;
		}
	} while (!valid);
}


void packetsMenu(Agency &agency) {
    line(35);
    cout << right << setfill(' ') << setw(22) << "PACKETS" << endl;
    line(35);
    cout << setw(4) << left << '|' << "1. Display packets" << endl;
    cout << setw(4) << left << '|' << "2. Search & Edit packet" << endl;
    cout << setw(4) << left << '|' << "3. Create new packet" << endl;
    cout << setw(4) << left << '|' << "4. Remove packet" << endl;
    cout << endl << setw(4) << left << '|' << "0. GO BACK" << endl;
    line(35);

    packetsMenuSelect(agency);
}

void packetsMenuSelect(Agency &agency) {
    string str;
    int opt;
    bool valid;

    do {
        getOption(opt);
        valid = true;
        switch (opt) {
            case 0:
                mainMenu(agency);
                break;
            case 1: {
                viewPacketsMenu(agency);
                break;
            }
            case 2: {
                editPacket(agency);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                packetsMenu(agency);
                break;
            }
            case 3: {
                newPacket(agency);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                packetsMenu(agency);
                break;
            }
            case 4: {
                removePacket(agency);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                packetsMenu(agency);
                break;
            }
            default:
                valid = false;
                cinERR("ERROR: Option does not exist, try again");
                break;
        }
    } while (!valid);
}

void viewPacketsMenu(Agency &agency) {
    line(35);
    cout << right << setfill(' ') << setw(22) << "DISPLAY PACKS" << endl;
    line(35);
    cout << setw(4) << left << '|' << "1. All" << endl;
    cout << setw(4) << left << '|' << "2. By site" << endl;
    cout << setw(4) << left << '|' << "3. By date" << endl;
    cout << setw(4) << left << '|' << "4. By site and date" << endl;
    cout << setw(4) << left << '|' << "5. By ID" << endl;
    cout << endl << setw(4) << left << '|' << "0. GO BACK" << endl;
    line(35);

    viewPacketsMenuSelect(agency);
}

void viewPacketsMenuSelect(Agency &agency) {
    string str;
    int opt;
    bool valid;

    do {
        getOption(opt);
        valid = true;
        switch (opt) {
            case 0:
                packetsMenu(agency);
                break;
            case 1: { // View all packets
                viewPackets(agency);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                viewPacketsMenu(agency);
                break;
            }
            case 2: { // Select based on site
                cout << "Site (* - cancel): ";
                getline(cin, str);
                if (str == "*") {
                    viewPacketsMenu(agency);
                    return;
                }
                viewPackets(agency, str);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                viewPacketsMenu(agency);
                break;
            }
            case 3: { // Select based on date
                string beginDate_str, endDate_str;
                Date beginDate, endDate;
                do {
                    cout << "Begin date (* - cancel): ";
                    getline(cin, beginDate_str);
                    if (validDate(beginDate_str)) {
                        beginDate = Date(beginDate_str);
                        break;
                    } else if (beginDate_str == "*") {
                        viewPacketsMenu(agency);
                        return;
                    }
                    cinERR("ERROR: Invalid date, use format YYYY/MM/DD");
                } while (!validDate(beginDate_str));

                do {
                    cout << "End date: ";
                    getline(cin, endDate_str);
                    if (validDate(endDate_str)) {
                        endDate = Date(endDate_str);
                        break;
                    } else if (endDate_str == "*") {
                        viewPacketsMenu(agency);
                        return;
                    }
                    cinERR("ERROR: Invalid date, use format YYYY/MM/DD");
                } while (!validDate(endDate_str));

                viewPackets(agency, beginDate, endDate);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                viewPacketsMenu(agency);
                break;
            }
            case 4: { // Select based on date and site
                cout << "Site (* - cancel): ";
                getline(cin, str);
                if (str == "*") {
                    viewPacketsMenu(agency);
                    return;
                }

                string beginDate_str, endDate_str;
                Date beginDate, endDate;
                do {
                    cout << "Begin date: ";
                    getline(cin, beginDate_str);
                    if (validDate(beginDate_str)) {
                        beginDate = Date(beginDate_str);
                        break;
                    } else if (beginDate_str == "*") {
                        viewPacketsMenu(agency);
                        return;
                    }
                    cinERR("ERROR: Invalid date, use format YYYY/MM/DD");
                } while (!validDate(beginDate_str));

                do {
                    cout << "End date: ";
                    getline(cin, endDate_str);
                    if (validDate(endDate_str)) {
                        endDate = Date(endDate_str);
                        break;
                    } else if (endDate_str == "*") {
                        viewPacketsMenu(agency);
                        return;
                    }
                    cinERR("ERROR: Invalid date, use format YYYY/MM/DD");
                } while (!validDate(endDate_str));

                viewPackets(agency, beginDate, endDate, str);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                viewPacketsMenu(agency);
                break;
            }
            case 5: { // Select based on ID
                int id;
                while (true) {
                    try {
                        cout << "ID (* - cancel): ";
                        getline(cin, str);
                        if (str == "*") {
                            viewPacketsMenu(agency);
                            return;
                        }
                        id = stoi(str);
                        break;
                    } catch (invalid_argument) {
                        cinERR("ERROR: Invalid entry, try again!");
                    }
                }

                viewPackets(agency, id);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                viewPacketsMenu(agency);
                break;
            }
            default:
                valid = false;
                cinERR("ERROR: Option does not exist, try again");
                break;
        }
    } while (!valid);
}

void agencyMenu(Agency &agency) {
    line(35);
    cout << right << setfill(' ') << setw(22) << "AGENCY" << endl;
    line(35);
    cout << setw(4) << left << '|' << "1. Display info" << endl;
    cout << setw(4) << left << '|' << "2. Edit info" << endl;
    cout << endl << setw(4) << left << '|' << "0. GO BACK" << endl;
    line(35);

    agencyMenuSelect(agency);
}

void agencyMenuSelect(Agency &agency) {
    string str;
    int opt;
    bool valid;

    do {
        getOption(opt);
        valid =  true;
        switch (opt) {
            case 0:
                mainMenu(agency);
                break;
            case 1:
                cout << agency;
                cout << endl << "ENTER to go back";
                getline(cin, str);
                agencyMenu(agency);
                break;
            case 2:
                editAgency(agency);
                cout << endl << "ENTER to go back";
                getline(cin, str);
                agencyMenu(agency);
                break;
            default:
                valid = false;
                cinERR("ERROR: Option does not exist, try again");
                break;
        }
    } while (!valid);
}