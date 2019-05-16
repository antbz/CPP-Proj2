#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "Date.h"

using namespace std;

class Packet {
private:
	int id; // packet unique identifier
	vector<string> sites; // touristic sites to visit
	Date begin;  // begin date
	Date end;  // end date
	double pricePerPerson; // price per person
	unsigned totalPersons;
	unsigned soldPersons;
	unsigned maxPersons; // number of persons still available in the packet (updated whenever the packet is sold to a new client)
public:
	Packet();
	Packet(int id, vector<string> sites, Date begin, Date end, double pricePerPerson, unsigned totalPersons, unsigned soldPersons, unsigned maxPersons);

	// GET methods
	int getId() const;
	vector<string> getSites() const;
	Date getBeginDate() const;
	Date getEndDate() const;
	double getPricePerPerson() const;
	unsigned getTotalPersons() const;
	unsigned getSoldPersons() const;
	unsigned getMaxPersons() const;

	// SET methods
	void setId(int id);  // to set negatve if "deprecated"
	void setSites(vector<string> sites);
	void setBeginDate(Date begin);
	void setEndDate(Date end);
	void setPricePerPerson(double pricePerPerson);
	void setTotalPersons(unsigned maxPersons);
	void setSoldPersons(unsigned soldPersons);
	void setMaxPersons(unsigned maxPersons);

	// other methods

	friend ostream& operator<<(ostream& out, const Packet & packet);
};

vector<Packet> findPackets(const vector<int> &IDs, const vector<Packet> &packets);

vector<Packet> findPackets(const string &site, const vector<Packet> &packets);

vector<Packet> findPackets(const Date &beginDate, const Date &endDate, const vector<Packet> &packets);

vector<Packet> findPackets(const Date &beginDate, const Date &endDate, const string &site, const vector<Packet> &packets);

int findPacket(const int &ID, const vector<Packet> &packets);

