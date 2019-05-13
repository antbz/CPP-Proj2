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

/*
 * METODOS GET
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

//
//  // metodos SET
//
//void Address::setStreet(string street){
//
//  // REQUIRES IMPLEMENTATION
//}
//
//void Address::setDoorNumber(unsigned short doorNumber){
//
//  // REQUIRES IMPLEMENTATION
//}
//
//void Address::setFloor(string floor){
//
//  // REQUIRES IMPLEMENTATION
//}
//
//void Address::setPostalCode(string postalCode){
//
//  // REQUIRES IMPLEMENTATION
//}
//
//void Address::setLocation(string  location){
//
//  // REQUIRES IMPLEMENTATION
//}
//
//
///*********************************
// * Mostrar Address
// ********************************/
//
//// discplyes an address in a nice format
//ostream& operator<<(ostream& out, const Address & address){
//
//  // REQUIRES IMPLEMENTATION
//
//}
//
