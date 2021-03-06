#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#include "utilities.h"
#include "Address.h"
#include "Packet.h"
#include "Client.h"
#include "Date.h"

using namespace std;

class Agency{
 private:
  string name; // name of the  agency
  unsigned int VATnumber; // VAT number of the agency
  string URL; // URL of the agency Web site
  Address address; // address of the agency
  string clientsFileName;
  string packetsFileName;
  vector<Client> clients; // vector to store the existing clients
  vector<Packet> packets; // vector to store the existing packets
  
  bool clientsInfoHasChanged; // flag that is set to "true" if at least one client has been changed/added/deleted
  bool packetsInfoHasChanged; // flag that is set to "true" if at least one packet has been changed/added/deleted
  bool agencyInfoHasChanged; // flag that is set to "true" if at least one agency parameter has been changed/added/deleted
//  unsigned int maxClientsId; // maximum value among all clients identifiers
//  unsigned int maxPacketsId; // maximum value among all packets identifiers
  static unsigned lastID;
  string fileName;

 public:
  Agency(string fileName);
  void saveAgency();

  // methods GET
  string getName() const;
  unsigned getVATnumber() const;
  Address getAddress() const;
  string getURL() const;
  vector<Client> getClients() const;
  vector<Packet> getPackets() const;
  string getClientsFileName() const;
  string getPacketsFileName() const;
  unsigned getLastID() const;

  
  // methods SET
  void setName(string name);
  void setVATnumber(unsigned VATnumber);
  void setAddress(Address address);
  void setURL(string url);
  void setClients(vector<Client> & clients);
  void setPackets(vector<Packet> & packets);
  void setClientsFileName(string clientsFileName);
  void setPacketsFileName(string packetsFileName);
  void setLastID(unsigned lastID);

  // other methods */
  
  friend ostream& operator<<(ostream& out, const Agency & agency);

};

bool buyPack(Agency &agency, int c_pos, int p_pos);

void salesReport(Agency &agency);

void nSites(Agency &agency, int n);

Packet findPacketBySite(Agency &agency, string site);

void suggestedPackets(Agency &agency, int n);

bool editAgency(Agency &agency);

bool newClient(Agency &agency);

bool editClient(Agency &agency);

bool removeClient(Agency &agency);

bool newPacket(Agency &agency);

bool editPacket(Agency &agency);

bool removePacket(Agency &agency);

bool viewPackets(const Agency &agency);

bool viewPackets(const Agency &agency, const string &site);

bool viewPackets(const Agency &agency, const Date &beginDate, const Date &endDate);

bool viewPackets(const Agency &agency, const Date &beginDate, const Date &endDate, const string &site);

bool viewPackets(const Agency &agency, const int &id);

