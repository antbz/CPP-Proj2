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
    cout << endl << "Massive destroyy";
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
