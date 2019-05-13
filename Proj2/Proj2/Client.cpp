#include "Client.h"

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address){
    this->name = name;
    this->VATnumber = VATnumber;
    this->familySize = familySize;
    this->address = address;
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet> &packets, unsigned totalPurchased){
    this->name = name;
    this->VATnumber = VATnumber;
    this->familySize = familySize;
    this->address = address;
    this->packets = packets;
    this->totalPurchased = totalPurchased;
}

  // GET methods

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

unsigned Client::getTotalPurchased() const{
    return totalPurchased;
}

  // metodos SET

void Client::setName(string nome){
    this->name = name;
    this->VATnumber = VATnumber;
    this->familySize = familySize;
    this->address = address;
    this->packets = packets;
    this->totalPurchased = totalPurchased;
}

void Client::setVATnumber(unsigned VATnumber){

}

void Client::setFamilySize(unsigned short familySize){

}
void Client::setAddress(Address address){

}
void Client::setPacketList(vector<Packet> & packets){

}
unsigned Client::setTotalPurchased(unsigned totalPurchased){

}

  // outros metodos

ostream& operator<<(ostream& out, const Client & client){


}
