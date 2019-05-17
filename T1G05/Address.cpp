#include "Address.h"


Address::Address(){
}

Address::Address(string street, unsigned short doorNumber, string floor, string postalCode, string location){
    this->street = street;
    this->doorNumber = doorNumber;
    this->floor = floor;
    this->postalCode = postalCode;
    this->location = location;
}

Address::Address(string fullAddress, char delim) {
    vector<string> temp;
    temp = strToVect(fullAddress, delim);
    street = temp.at(0);
    doorNumber = stoi(temp.at(1));
    floor = temp.at(2);
    postalCode = temp.at(3);
    location = temp.at(4);
}

/*
 * GET methods
 */


string Address::getStreet() const{
    return street;
}

unsigned short Address::getDoorNumber() const{
    return doorNumber;
}

string Address::getFloor() const{
    return floor;
}

string Address::getPostalCode() const{
    return postalCode;
}

string Address::getLocation() const{
    return location;
}

/*
 * SET methods
 */

void Address::setStreet(string street){
    this->street = street;
}

void Address::setDoorNumber(unsigned short doorNumber){
    this->doorNumber = doorNumber;
}

void Address::setFloor(string floor){
    this->floor = floor;
}

void Address::setPostalCode(string postalCode){
    this->postalCode = postalCode;
}

void Address::setLocation(string location){
    this->location = location;
}


/*
 * SHOW Address
 */

// Displays an address in a nice format
ostream& operator<<(ostream& out, const Address & address){
    out << address.street + " / " + to_string(address.doorNumber) + " / " + address.floor + " / " + address.postalCode + " / " + address.location;
    return out;
}

bool validAddress(string &str, char delim) {
    // Returns whether the address format is valid and
    // extracts it to the dest vector
    vector<string> temp;
    temp = strToVect(str, delim);
    if (temp.size() != 5 || !isNumeric(temp.at(1)))
        return false;
    return true;
}
