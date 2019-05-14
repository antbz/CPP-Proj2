#include "Packet.h"

Packet::Packet() {

}

Packet::Packet(unsigned id, vector<string> sites, Date begin, Date end, double pricePerPerson, unsigned maxPersons) {
	this->id = id;
	this->sites = sites;
	this->begin = begin;
	this->end = end;
	this->pricePerPerson = pricePerPerson;
	this->maxPersons = maxPersons;
}

// metodos GET

unsigned Packet::getId() const {
	return id;
}

vector<string> Packet::getSites() const {
	return sites;
}

Date Packet::getBeginDate() const {
	return begin;
}

Date Packet::getEndDate() const {
	return end;
}

double Packet::getPricePerPerson() const {
	return pricePerPerson;
}

unsigned Packet::getTotalPersons() const {
	return totalPersons;
}

unsigned Packet::getMaxPersons() const {
	return maxPersons;
}

// metodos SET

void Packet::setId(unsigned id) {
	this->id = id;
}

void Packet::setSites(vector<string> sites) {
	this->sites = sites;
}

void Packet::setBeginDate(Date begin) {
	this->begin = begin;
}

void Packet::setEndDate(Date end) {
	this->end = end;
}

void Packet::setPricePerPerson(double pricePerPerson) {
	this->pricePerPerson = pricePerPerson;
}

void Packet::setTotalPersons(unsigned totalPersons){
	this->totalPersons = totalPersons;
}

void Packet::setMaxPersons(unsigned maxPersons) {
	this->maxPersons = maxPersons;
}



/*********************************
 * Show Packet information
 ********************************/

 // shows a packet content 
ostream& operator<<(ostream& out, const Packet & packet) {
	out << "Packet ID       : " << packet.id << endl;
	out << "Destination(s)  : " << sitesVectToStr(packet.sites) << endl;
	out << "Begins          : " << packet.begin << endl;
	out << "Ends            : " << packet.end << endl;
	out << "Price Per Person: " << packet.pricePerPerson << endl;
	out << "Available Stock : " << packet.maxPersons;
	return out;
}


// OUTROS

vector<Packet> findPackets(const vector<int> &IDs, const vector<Packet> &packets) {
    vector<Packet> result;
	for (int i = 0; i < IDs.size(); i++) {
    	for (int j = 0; j < packets.size(); j++) {
			if (packets.at(j).getId() == IDs.at(i) || packets.at(j).getId() == -IDs.at(i))
				result.push_back(packets.at(j));
    	}
    }
    return result;
}