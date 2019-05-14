#include "Agency.h"

unsigned Agency::lastID;

Agency::Agency(string fileName) {
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
        packets.back().setMaxPersons(stoi(str));

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
    this->name = name;
}

void Agency::setVATnumber(unsigned VATnumber){
    this->VATnumber = VATnumber;
}

void Agency::setAddress(Address address){
    this->address = address;
}
  void Agency::setURL(string url){
    this->URL = url;

}
  void Agency::setClients(vector<Client> &clients){
    this->clients = clients;

  }
  void Agency::setPackets(vector<Packet> &packets){
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
