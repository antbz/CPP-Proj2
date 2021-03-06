#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "utilities.h"

using namespace std;

class Address{
 private:
  string street; // street name
  unsigned short doorNumber; // door number
  string floor; // floor number ("-" is not applicable)
  string postalCode; // postal code
  string location; // site

 public:
  Address();
  Address(string street, unsigned short doorNumber, string floor, string postalCode, string location);
  Address(string fullAddress, char delim = '/');

  // metodos GET
  string getStreet() const;
  unsigned short getDoorNumber() const;
  string getFloor() const;
  string getPostalCode() const;
  string getLocation() const;
  
  // metodos SET
  void setStreet(string street);
  void setDoorNumber(unsigned short doorNumber);
  void setFloor(string floor);
  void setPostalCode(string postalCode);
  void setLocation(string  location);

  // outros */
  
  friend ostream& operator<<(ostream& out, const Address & address);

};

bool validAddress(string &str, char delim = '/');