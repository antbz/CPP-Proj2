#include "Agency.h"

unsigned Agency::lastID;

Agency::Agency(string fileName) {
    clientsInfoHasChanged = false;
    packetsInfoHasChanged = false;
    agencyInfoHasChanged = false;
    this->fileName = fileName;

    string str;
    ifstream agency_file(fileName);
    
    getline(agency_file, name);
    getline(agency_file, str);
    VATnumber = stoi(str);
    getline(agency_file, URL);
    getline(agency_file, str);
    address = Address(str);
    
    getline(agency_file, clientsFileName);
    getline(agency_file, packetsFileName);
    
    agency_file.close();

    ifstream packets_file(packetsFileName);


    // Grabs lastID
    getline(packets_file, str);
    lastID = stoi(str);

    while (getline(packets_file, str)) {
        // Adds new pack to vector
        packets.emplace_back();

        // Gets pack id
        packets.back().setId(abs(stoi(str)));

        // Gets destinations
        getline(packets_file, str);
        packets.back().setSites(sitesStrToVect(str));


        // Gets start date
        getline(packets_file, str);
        packets.back().setBeginDate(Date(str));
        // Gets end date
        getline(packets_file, str);
        packets.back().setEndDate(Date(str));

        // Get price
        getline(packets_file, str);
        packets.back().setPricePerPerson(stod(str));

        // Get seats
        getline(packets_file, str);
        packets.back().setTotalPersons(stoi(str));
        getline(packets_file, str);
        packets.back().setSoldPersons(stoi(str));
        packets.back().setMaxPersons(packets.back().getTotalPersons() - packets.back().getSoldPersons());

        // Discard delimiter
        getline(packets_file, str);
    }

    packets_file.close();
    
    
    ifstream clients_file(clientsFileName);

    while (getline(clients_file, str)) {
      // Adds new client to vector
      clients.emplace_back();
  
      // Grabs the client info from the file
      clients.back().setName(str);
      getline(clients_file, str);
      clients.back().setVATnumber(stoi(str));
      getline(clients_file, str);
      clients.back().setFamilySize(stoi(str));
      getline(clients_file, str);
      clients.back().setAddress(Address(str));
      getline(clients_file, str);
      vector<Packet> pacc = findPackets(strToIntVect(str, ';'), packets);
      clients.back().setPacketList(pacc);
      getline(clients_file, str);
      clients.back().setTotalPurchased(stoi(str));
  
      // Discards delimiter line
      getline(clients_file, str);
    }
  
    clients_file.close();
  
}

void Agency::saveAgency() {
    if (agencyInfoHasChanged) {
        ofstream agency_file(fileName);
        agency_file << name << endl;
        agency_file << VATnumber << endl;
        agency_file << URL << endl;
        agency_file << address << endl;
        agency_file << clientsFileName << endl;
        agency_file << packetsFileName;
        agency_file.close();
    }

    if (packetsInfoHasChanged) {
        ofstream packets_file(packetsFileName);
        packets_file << lastID << endl;

        for (int i = 0; i < packets.size(); i++) {
            packets_file << packets.at(i).getId() << endl;

            for (int j = 0; j < packets.at(i).getSites().size(); j++) {
                if (j == 0)
                    packets_file << packets.at(i).getSites().at(j);
                else if (j == 1)
                    packets_file << " - " << packets.at(i).getSites().at(j);
                else
                    packets_file << ", " << packets.at(i).getSites().at(j);
            }

            packets_file << endl << packets.at(i).getBeginDate() << endl;
            packets_file << packets.at(i).getEndDate() << endl;

            packets_file << packets.at(i).getPricePerPerson() << endl;
            packets_file << packets.at(i).getTotalPersons() << endl;
            packets_file << packets.at(i).getSoldPersons();

            if (i != packets.size() - 1)
                packets_file << endl << "::::::::::" << endl;
        }

        packets_file.close();
    }

    if (clientsInfoHasChanged) {
        ofstream clients_file(clientsFileName);

        for (int i = 0; i < clients.size(); i++) {
            clients_file << clients.at(i).getName() << endl;
            clients_file << clients.at(i).getVATnumber() << endl;
            clients_file << clients.at(i).getFamilySize() << endl;
            clients_file << clients.at(i).getAddress() << endl;

            for (int j = 0; j < clients.at(i).getPacketList().size(); j++) {
                if (j == 0)
                    clients_file << clients.at(i).getPacketList().at(j).getId();
                else
                    clients_file << "; " << clients.at(i).getPacketList().at(j).getId();
            }

            clients_file << endl << clients.at(i).getTotalPurchased();

            if (i != clients.size() - 1)
                clients_file << endl << "::::::::::" << endl;
        }

        clients_file.close();
    }
}

  // GET METHODS

string Agency::getName() const{
    return name;
}

unsigned Agency::getVATnumber() const{
    return VATnumber;
}

Address Agency::getAddress() const{
    return address;
}

string Agency::getURL() const{
    return URL;
}

vector<Client> Agency::getClients() const{
    return clients;
}

vector<Packet> Agency::getPackets() const{
    return packets;
}

string Agency::getClientsFileName() const{
    return clientsFileName;
}

string Agency::getPacketsFileName() const {
    return packetsFileName;
}

unsigned Agency::getLastID() const {
    return lastID;
}

  // SET Methods

void Agency::setName(string name){
    agencyInfoHasChanged = true;
    this->name = name;
}

void Agency::setVATnumber(unsigned VATnumber){
    agencyInfoHasChanged = true;
    this->VATnumber = VATnumber;
}

void Agency::setAddress(Address address){
    agencyInfoHasChanged = true;
    this->address = address;
}

void Agency::setURL(string url){
    agencyInfoHasChanged = true;
    this->URL = url;
}

void Agency::setClients(vector<Client> &clients){
    clientsInfoHasChanged = true;
    this->clients = clients;
}

void Agency::setPackets(vector<Packet> &packets){
    packetsInfoHasChanged = true;
    this->packets = packets;
}

void Agency::setClientsFileName(string clientsFileName) {
    agencyInfoHasChanged = true;
    this->clientsFileName = clientsFileName;
}

void Agency::setPacketsFileName(string packetsFileName) {
    agencyInfoHasChanged = true;
    this->packetsFileName = packetsFileName;
}

void Agency::setLastID(unsigned lastID) {
    packetsInfoHasChanged = true;
    this->lastID = lastID;
}


// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency &agency){
    out << setw(2) << ' ' << agency.name << endl;
    out << "/" << endl;
    out << setw(4) << left << '|' << "NIF: " << agency.VATnumber << endl;
    out << setw(4) << left << '|' << "Website: " << agency.URL << endl;
    out << setw(4) << left << '|' << "Address: " << agency.address << endl;
    out << setw(4) << left << '|' << "Clients file: " << agency.clientsFileName << endl;
    out << setw(4) << left << '|' << "Packets file: " << agency.packetsFileName << endl;
    out << "\\_" << endl;
    return out;
}

bool buyPack(Agency &agency, int c_pos, int p_pos) {
    vector<Client> c_tmp = agency.getClients();
    vector<Packet> p_tmp = agency.getPackets();


    if (p_tmp.at(p_pos).getMaxPersons() == 0) {
        cout << "Packet Sold Out!";
        return false;
    }

    vector<Packet> lpacket = c_tmp.at(c_pos).getPacketList();
    lpacket.push_back(p_tmp.at(p_pos));
    c_tmp.at(c_pos).setPacketList(lpacket);

    p_tmp.at(p_pos).setSoldPersons(p_tmp.at(p_pos).getSoldPersons() + 1);
    p_tmp.at(p_pos).setMaxPersons(p_tmp.at(p_pos).getMaxPersons() - 1);

    agency.setClients(c_tmp);
    agency.setPackets(p_tmp);
    return true;
}

void salesReport(Agency &agency) {
    line(35);
    cout << right << "Report " << agency.getName() << endl;
    line(35);
    cout << setw(4) << left << '-' << agency.getClients().size() << " clients" << endl;
    cout << setw(4) << left << '-' << agency.getPackets().size() << " packets" << endl;

    long n_sales = 0, np_sales = 0;
    double v_sales = 0, vp_sales = 0;
    for (int i = 0; i < agency.getPackets().size(); i++) {
        n_sales += agency.getPackets().at(i).getSoldPersons();
        v_sales += agency.getPackets().at(i).getSoldPersons() * agency.getPackets().at(i).getPricePerPerson();
        np_sales += agency.getPackets().at(i).getMaxPersons();
        vp_sales += agency.getPackets().at(i).getMaxPersons() * agency.getPackets().at(i).getPricePerPerson();
    }

    cout << setw(4) << left << '-' << "Sold packets: " << n_sales << endl;
    cout << setw(4) << left << '-' << "Value of sold packets: " << v_sales << endl;
    cout << setw(4) << left << '-' << "Packets still available: " << np_sales << endl;
    cout << setw(4) << left << '-' << "Value of packets still available: " << vp_sales << endl;
}

void nSites(Agency &agency, int n) {
	vector<Packet> packets = agency.getPackets();
	map<string, int> sites;
	vector<pair<string, int>> orderedSites;
	orderedSites.reserve(sites.size());

	for (int i = 0; i < packets.size(); i++) {
		vector<string> tmp = packets.at(i).getSites();
		for (int j = 0; j < tmp.size(); j++) {
			if (sites.find(tmp.at(j)) == sites.end()) {
				sites[tmp.at(j)] = packets.at(i).getSoldPersons();
			}
			else {
				sites.at(tmp.at(j)) += packets.at(i).getSoldPersons();
			}
		}
	}

	for (auto itr = sites.begin(); itr != sites.end(); itr++) {
		orderedSites.push_back(*itr);
	}

	sort(orderedSites.begin(), orderedSites.end(), [](pair<string, int>& a, pair<string, int>& b)
	{
		return a.second > b.second;
	}
	);

	for (int k = 0; k < n; k++) {
		cout << k + 1 << " -- " << orderedSites.at(k).first << " || Visits: " << orderedSites.at(k).second << endl;
	}
}

Packet findPacketBySite(Agency &agency, string site) {
	vector<Packet> packets = agency.getPackets();
	vector<pair<Packet, int>> s_packets;

	for (int i = 0; i < packets.size(); i++) {
		vector<string> sites = packets.at(i).getSites();

		for (int j = 0; j < sites.size(); j++) {
			if (find(sites.begin(), sites.end(), site) != sites.end()) {
				s_packets.push_back(make_pair(packets.at(i), packets.at(i).getPricePerPerson()));
			}
		}
	}

	sort(s_packets.begin(), s_packets.end(), [](pair<Packet, int>& a, pair<Packet, int>& b)
	{
		return a.second > b.second;
	}
	);

	return s_packets.at(0).first;
}

void suggestedPackets(Agency &agency, int n) {
	vector<Packet> packets = agency.getPackets();
	vector<Client> clients = agency.getClients();
	map<string, int> sites;
	vector<pair<string, int>> orderedSites;
	orderedSites.reserve(sites.size());

	for (int i = 0; i < packets.size(); i++) {
		vector<string> tmp = packets.at(i).getSites();
		for (int j = 0; j < tmp.size(); j++) {
			if (sites.find(tmp.at(j)) == sites.end()) {
				sites[tmp.at(j)] = packets.at(i).getSoldPersons();
			}
			else {
				sites.at(tmp.at(j)) += packets.at(i).getSoldPersons();
			}
		}
	}

	for (auto itr = sites.begin(); itr != sites.end(); itr++) {
		orderedSites.push_back(*itr);
	}

	sort(orderedSites.begin(), orderedSites.end(), [](pair<string, int>& a, pair<string, int>& b)
	{
		return a.second > b.second;
	}
	);

	for (int k = 0; k < clients.size(); k++) {
		vector<Packet> p_tmp = clients.at(k).getPacketList();
		vector<string> s_tmp;

		for (int l = 0; l < p_tmp.size(); l++) {
			vector<string> sites_tmp = p_tmp.at(l).getSites();
			for (int o = 0; o < sites_tmp.size(); o++) {
				if (find(s_tmp.begin(), s_tmp.end(), sites_tmp.at(o)) == s_tmp.end()) {
					s_tmp.push_back(sites_tmp.at(o));
				}
			}
		}

		for (int m = 0; m < n; m++) {
			if (find(s_tmp.begin(), s_tmp.end(), orderedSites.at(m).first) == s_tmp.end()) {
				cout << clients.at(k).getName() << " should buy packet " << findPacketBySite(agency, orderedSites.at(m).first).getId() << endl;
				break;
			}
		}
	}
}

bool editAgency(Agency &agency) {
    string name, VATnumber, URL, address_str, clientsFileName, packetsFileName;
    Address address;

    cout << setw(2) << ' ' << "EDITING AGENCY (* - cancel)" << endl;
    cout << "/" << endl;

    cout << setw(4) << left << '|' << "Name (" << agency.getName() << "): ";
    getline(cin, name);
    if (name.empty()) {
        name = agency.getName();
    } else if (name == "*") {
        return false;
    }

    do {
        cout << setw(4) << left << '|' << "NIF (" << agency.getVATnumber() << "): ";
        getline(cin, VATnumber);
        if (VATnumber.empty()) {
            VATnumber = to_string(agency.getVATnumber());
            break;
        } else if (VATnumber == "*") {
            return false;
        } else if (validNIF(VATnumber)) {
            break;
        }
        cinERR("ERROR: Invalid NIF, try again!");
    } while (!validNIF(VATnumber));

    cout << setw(4) << left << '|' << "Website (" << agency.getURL() << "): ";
    getline(cin, URL);
    if (URL.empty()) {
        URL = agency.getURL();
    } else if (URL == "*") {
        return false;
    }

    do {
        cout << setw(4) << left << '|' << "Address (" << agency.getAddress() << "): ";
        getline(cin, address_str);
        if (address_str.empty()) {
            address = agency.getAddress();
            break;
        } else if (address_str == "*") {
            return false;
        } else {
            if (validAddress(address_str, ',')) {
                address = Address(address_str, ',');
                break;
            }
        }
        cinERR("ERROR: Invalid address, separate items with ,");
    } while(!validAddress(address_str, ','));

    cout << setw(4) << left << '|' << "Clients file (" << agency.getClientsFileName() << "): ";
    getline(cin, clientsFileName);
    if (clientsFileName.empty()) {
        clientsFileName = agency.getClientsFileName();
    } else if (clientsFileName == "*") {
        return false;
    }

    cout << setw(4) << left << '|' << "Packets (" << agency.getPacketsFileName() << "): ";
    getline(cin, packetsFileName);
    if (packetsFileName.empty()) {
        packetsFileName = agency.getPacketsFileName();
    } else if (packetsFileName == "*") {
        return false;
    }

    agency.setName(name);
    agency.setVATnumber(stoi(VATnumber));
    agency.setURL(URL);
    agency.setAddress(address);
    agency.setClientsFileName(clientsFileName);
    agency.setPacketsFileName(packetsFileName);
    return true;
}

bool newPacket(Agency &agency) {
    vector<Packet> temp_packets = agency.getPackets();
    string sites_str, beginDate_str, endDate_str, str;
    vector<string> sites;
    Date beginDate, endDate;
    double pricePerPerson;
    unsigned totalPersons, soldPersons, maxPersons;
    int id;

    id = agency.getLastID() + 1;
    cout << "NEW PACK ID: " << id << " (* - cancel)" << endl;

    bool pass = true;
    do {
        cout << "Sites (main_site - subsite, subsite, ...): ";
        getline(cin, sites_str);
        if (sites_str.empty()) {
            pass = false;
            cinERR("ERROR: Invalid entry, try again");
            continue;
        } else if (sites_str == "*") {
            return false;
        } else {
            sites = sitesStrToVect(sites_str);
            break;
        }
    } while (!pass);

    do {
        cout << "Begin date: ";
        getline(cin, beginDate_str);
        if (validDate(beginDate_str)) {
            beginDate = Date(beginDate_str);
            break;
        } else if (beginDate_str == "*") {
            return false;
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
            return false;
        }
        cinERR("ERROR: Invalid date, use format YYYY/MM/DD");
    } while (!validDate(endDate_str));


    while (true) {
        try {
            cout << "Price per person: ";
            getline(cin, str);
            if (str == "*")
                return false;
            pricePerPerson = stod(str);
            break;
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid price, try again");
        }
    }

    while (true) {
        try {
            cout << "Total seats: ";
            getline(cin, str);
            if (str == "*")
                return false;
            totalPersons = stoul(str);
            break;
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid entry, try again");
        }
    }

    while (true) {
        try {
            cout << "Sold seats: ";
            getline(cin, str);
            if (str == "*")
                return false;
            soldPersons = stoul(str);
            break;
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid entry, try again");
        }
    }

    maxPersons = totalPersons - soldPersons;

    agency.setLastID(id);
    temp_packets.emplace_back(id, sites, beginDate, endDate, pricePerPerson, totalPersons, soldPersons, maxPersons);
    agency.setPackets(temp_packets);
}

bool editPacket(Agency &agency) {
    vector<Packet> temp_packets = agency.getPackets();
    string str;
    int packet_pos = -1;

    do {
        cout << "ID of packet to edit (* - cancel): ";
        getline(cin, str);
        if (str == "*")
            return false;
        try {
            packet_pos = findPacket(stoi(str), temp_packets);
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid entry, try again!");
            continue;
        }
        if (packet_pos != -1)
            break;
        cinERR("ERROR: Packet does not exist, try again!");
    } while (packet_pos == -1);

    string sites_str, beginDate_str, endDate_str;
    vector<string> sites;
    Date beginDate, endDate;
    double pricePerPerson;
    unsigned totalPersons, soldPersons, maxPersons;
    int id;

    cout << "EDITING PACK " << temp_packets.at(packet_pos).getId() << "(* - cancel)" << endl;

    // ID
    while (true) {
        try {
            cout << "| ID (" << temp_packets.at(packet_pos).getId() << "): ";
            getline(cin, str);
            if (str == "*") {
                return false;
            } else if (str.empty()) {
                id = temp_packets.at(packet_pos).getId();
                break;
            }
            id = stoi(str);
            break;
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid entry, try again");
        }
    }

    // Sites
    cout << "| Sites (" << sitesVectToStr(temp_packets.at(packet_pos).getSites()) << "): ";
    getline(cin, sites_str);
    if (sites_str.empty()) {
        sites = temp_packets.at(packet_pos).getSites();
    } else if (sites_str == "*") {
        return false;
    } else {
        sites = sitesStrToVect(sites_str);
    }

    // Begin date
    do {
        cout << "| Begin date (" << temp_packets.at(packet_pos).getBeginDate() << "): ";
        getline(cin, beginDate_str);
        if (beginDate_str.empty()) {
            beginDate = temp_packets.at(packet_pos).getBeginDate();
            break;
        } else if (validDate(beginDate_str)) {
            beginDate = Date(beginDate_str);
            break;
        } else if (beginDate_str == "*") {
            return false;
        }
        cinERR("ERROR: Invalid date, use format YYYY/MM/DD");
    } while (!validDate(beginDate_str));

    // End date
    do {
        cout << "| End date (" << temp_packets.at(packet_pos).getEndDate() << "): ";
        getline(cin, endDate_str);
        if (endDate_str.empty()) {
            endDate = temp_packets.at(packet_pos).getEndDate();
            break;
        } else if (validDate(endDate_str)) {
            endDate = Date(endDate_str);
            break;
        } else if (endDate_str == "*") {
            return false;
        }
        cinERR("ERROR: Invalid date, use format YYYY/MM/DD");
    } while (!validDate(endDate_str));

    // Price per person
    while (true) {
        try {
            cout << "| Price per person (" << temp_packets.at(packet_pos).getPricePerPerson() << "): ";
            getline(cin, str);
            if (str.empty()) {
                pricePerPerson = temp_packets.at(packet_pos).getPricePerPerson();
                break;
            } else if (str == "*") {
                return false;
            }
            pricePerPerson = stod(str);
            break;
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid price, try again");
        }
    }

    // Total seats
    while (true) {
        try {
            cout << "| Total seats (" << temp_packets.at(packet_pos).getTotalPersons() << "): ";
            getline(cin, str);
            if (str.empty()) {
                totalPersons = temp_packets.at(packet_pos).getTotalPersons();
                break;
            } else if (str == "*")
                return false;
            totalPersons = stoul(str);
            break;
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid entry, try again");
        }
    }

    // Sold seats
    while (true) {
        try {
            cout << "| Sold seats (" << temp_packets.at(packet_pos).getSoldPersons() << "): ";
            getline(cin, str);
            if (str.empty()) {
                soldPersons = temp_packets.at(packet_pos).getSoldPersons();
                break;
            } else if (str == "*")
                return false;
            soldPersons = stoul(str);
            break;
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid entry, try again");
        }
    }

    maxPersons = totalPersons - soldPersons;

    if (id > agency.getLastID())
        agency.setLastID(id);
    temp_packets.at(packet_pos) = Packet(id, sites, beginDate, endDate, pricePerPerson, totalPersons, soldPersons, maxPersons);
    agency.setPackets(temp_packets);
}

bool removePacket(Agency &agency) {
    vector<Packet> temp_packets = agency.getPackets();
    string str;
    int packet_pos = -1;

    do {
        cout << "ID of packet to remove (* - cancel): ";
        getline(cin, str);
        if (str == "*")
            return false;
        try {
            packet_pos = findPacket(stoi(str), temp_packets);
        } catch (invalid_argument) {
            cinERR("ERROR: Invalid entry, try again!");
            continue;
        }
        if (packet_pos != -1)
            break;
        cinERR("ERROR: Packet does not exist, try again!");
    } while (packet_pos == -1);


    temp_packets.at(packet_pos).setId(-temp_packets.at(packet_pos).getId());
    agency.setPackets(temp_packets);
    cout << "Pack removed!";
}

bool viewPackets(const Agency &agency) {
    for (int i = 0; i < agency.getPackets().size(); i++) {
        cout << "/" << endl;
        cout << agency.getPackets().at(i);
        cout << endl << "\\" << endl;
    }
	return true;
}

bool viewPackets(const Agency &agency, const string &site) {
    vector<Packet> selected;
    selected = findPackets(site, agency.getPackets());
    for (int i = 0; i < selected.size(); i++) {
        cout << "/" << endl;
        cout << selected.at(i);
        cout << endl << "\\" << endl;
    }
    if (selected.empty()) {
        cinERR("No packets to specified destination");
        return false;
    }
    return true;
}

bool viewPackets(const Agency &agency, const Date &beginDate, const Date &endDate) {
    vector<Packet> selected;
    selected = findPackets(beginDate, endDate, agency.getPackets());
    for (int i = 0; i < selected.size(); i++) {
        cout << "/" << endl;
        cout << selected.at(i);
        cout << endl << "\\" << endl;
    }
    if (selected.empty()) {
        cinERR("No packets between specified dates");
        return false;
    }
    return true;
}

bool viewPackets(const Agency &agency, const Date &beginDate, const Date &endDate, const string &site) {
    vector<Packet> selected;
    selected = findPackets(beginDate, endDate, site, agency.getPackets());
    for (int i = 0; i < selected.size(); i++) {
        cout << "/" << endl;
        cout << selected.at(i);
        cout << endl << "\\" << endl;
    }
    if (selected.empty()) {
        cinERR("No packets between/to specified dates/destination");
        return false;
    }
    return true;
}

bool viewPackets(const Agency &agency, const int &id) {
    int pos = findPacket(id, agency.getPackets());

    if (pos == -1) {
        cinERR("No packet with specified id");
        return false;
    }

    Packet selected = agency.getPackets().at(pos);

    cout << "/" << endl;
    cout << selected;
    cout << endl << "\\" << endl;
}