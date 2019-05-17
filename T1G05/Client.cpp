#include "Client.h"

Client::Client() {

}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address){
    this->name = name;
    this->VATnumber = VATnumber;
    this->familySize = familySize;
    this->address = address;
    this->totalPurchased = 0;
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet> &packets, string packetListStr, double totalPurchased){
    this->name = name;
    this->VATnumber = VATnumber;
    this->familySize = familySize;
    this->address = address;
    this->packets = packets;
    this->packetListStr = packetListStr;
    this->totalPurchased = totalPurchased;
}

/*
 * GET methods
 */

string Client::getName() const{
    return name;
}

unsigned Client::getVATnumber() const{
    return VATnumber;
}

unsigned short Client::getFamilySize() const{
    return familySize;
}

Address Client::getAddress() const{
    return address;
}

vector<Packet> Client::getPacketList() const{
    return packets;
}

string Client::getPacketListStr() const {
    return packetListStr;
}

double Client::getTotalPurchased() const{
    return totalPurchased;
}

  // metodos SET

void Client::setName(string name){
    this->name = name;
}

void Client::setVATnumber(unsigned VATnumber){
    this->VATnumber = VATnumber;
}

void Client::setFamilySize(unsigned short familySize){
    this->familySize = familySize;
}

void Client::setAddress(Address address){
    this->address = address;
}

void Client::setPacketList(vector<Packet> &packets){
    this->packets = packets;
}

void Client::setPacketListStr(string packetListStr) {
    this->packetListStr = packetListStr;
}

void Client::setTotalPurchased(double totalPurchased){
    this->totalPurchased = totalPurchased;
}

  // outros metodos

ostream& operator<<(ostream& out, const Client &client){
    out << "/" << endl;
    out << setw(4) << left << '|' << "Name: " << client.name << endl;
    out << setw(4) << left << '|' << "NIF: " << right << setfill('0') << setw(9) << client.VATnumber << setfill(' ') <<endl;
    out << setw(4) << left << '|' << "Family size: " << client.familySize << endl;
    out << setw(4) << left << '|' << "Address: " << client.address << endl;
    out << setw(4) << left << '|' << "Purchased packs: ";
    for (int i = 0; i < client.packets.size(); i++) {
        if (i == client.packets.size() - 1)
            out << client.packets.at(i).getId();
        else
            out << client.packets.at(i).getId() << ", ";
    }
    out << endl << setw(4) << left << '|' << "Total of purchased packs: " << client.totalPurchased << endl;
    out << "\\_" << endl;
	return out;
}

int findClient(vector<Client> clients, unsigned VATnumber) {
	int result = -1;

	for (int i = 0; i < clients.size(); i++) {
		if (clients.at(i).getVATnumber() == VATnumber) {
			result = i;
			break;
		}
	}

	return result;
}
