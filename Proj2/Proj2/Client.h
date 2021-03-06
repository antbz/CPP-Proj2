#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "Address.h"
#include "Packet.h"

using namespace std;

class Client{
 private:
  string name, packetListStr; // name of the client
  unsigned VATnumber; // VAT number of client
  unsigned short familySize;  // number of family members
  Address address; // client's address
  vector<Packet> packets; // vector to store client's packets bought
  double  totalPurchased; // total value spent by the client

 public:
  Client();
  Client(string name, unsigned VATnumber, unsigned short familySize, Address address);  // for a new client
  Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet> &packets, string packetListStr, double totalPurchased);  // client read from file

  // GET methods
  
  string getName() const;
  unsigned getVATnumber() const;
  unsigned short getFamilySize() const;
  Address getAddress() const;
  vector<Packet> getPacketList() const;
  string getPacketListStr() const;
  double getTotalPurchased() const;
  
  // SET methods
  
  void setName(string name);
  void setVATnumber(unsigned VATnumber);
  void setFamilySize(unsigned short familySize);
  void setAddress(Address address);
  void setPacketList(vector<Packet> & packets);
  void setPacketListStr(string packetListStr);
  void setTotalPurchased(double totalPurchased);
  
  // other methods

  friend ostream& operator<<(ostream& out, const Client & client);
};

int findClient(vector<Client> clients, unsigned VATnumber);
