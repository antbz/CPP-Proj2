#include "Packet.h"

Packet::Packet() {

}

Packet::Packet(int id, vector<string> sites, Date begin, Date end, double pricePerPerson, unsigned totalPersons, unsigned soldPersons, unsigned maxPersons) {
	this->id = id;
	this->sites = sites;
	this->begin = begin;
	this->end = end;
	this->pricePerPerson = pricePerPerson;
	this->totalPersons = totalPersons;
	this->soldPersons = soldPersons;
	this->maxPersons = maxPersons;
}

// metodos GET

int Packet::getId() const {
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

unsigned Packet::getSoldPersons() const {
	return soldPersons;
}

unsigned Packet::getMaxPersons() const {
	return maxPersons;
}

// metodos SET

void Packet::setId(int id) {
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

void Packet::setSoldPersons(unsigned soldPersons){
	this->soldPersons = soldPersons;
}

void Packet::setMaxPersons(unsigned maxPersons) {
	this->maxPersons = maxPersons;
}



/*********************************
 * Show Packet information
 ********************************/

 // shows a packet content 
ostream& operator<<(ostream& out, const Packet & packet) {
	out << "| Packet ID       : " << packet.id << endl;
	out << "| Destination(s)  : " << sitesVectToStr(packet.sites) << endl;
	out << "| Begins          : " << packet.begin << endl;
	out << "| Ends            : " << packet.end << endl;
	out << "| Price Per Person: " << packet.pricePerPerson << endl;
	out << "| Available Stock : " << packet.maxPersons;
	return out;
}


// OUTROS

vector<Packet> findPackets(const vector<int> &IDs, const vector<Packet> &packets) {
    vector<Packet> result;
	for (int i = 0; i < IDs.size(); i++) {
	    bool found = false;
    	for (int j = 0; j < packets.size(); j++) {
			if (packets.at(j).getId() == IDs.at(i) || packets.at(j).getId() == -IDs.at(i)) {
                result.push_back(packets.at(j));
                found = true;
            }
    	}
    	if (!found)
    	    throw 100;
    }
    return result;
}

vector<Packet> findPackets(const string &site, const vector<Packet> &packets) {
    vector<Packet> result;
    for (int i = 0; i < packets.size(); i++) {
        vector<string> sites = packets.at(i).getSites();
        bool isThere = find(sites.begin(), sites.end(), site) != sites.end();
        if (isThere) {
            result.push_back(packets.at(i));
        }
    }

    return result;
}

vector<Packet> findPackets(const Date &beginDate, const Date &endDate, const vector<Packet> &packets) {
    vector<Packet> result;
    for (int i = 0; i < packets.size(); i++) {
        if (cmpDate(packets.at(i).getBeginDate(), beginDate) && cmpDate(endDate, packets.at(i).getEndDate()))
            result.push_back(packets.at(i));
    }

    return result;
}

vector<Packet> findPackets(const Date &beginDate, const Date &endDate, const string &site, const vector<Packet> &packets) {
    vector<Packet> result;
    for (int i = 0; i < packets.size(); i++) {
        vector<string> sites = packets.at(i).getSites();
        bool condition = (find(sites.begin(), sites.end(), site) != sites.end()) &&
            (cmpDate(packets.at(i).getBeginDate(), beginDate) && cmpDate(endDate, packets.at(i).getEndDate()));
        if (condition) {
            result.push_back(packets.at(i));
        }
    }

    return result;
}

int findPacket(const int &ID, const vector<Packet> &packets) {
	int result = -1;

	for (int i = 0; i < packets.size(); i++) {
		if (ID == packets.at(i).getId()) {
			result = i;
			break;
		}
	}

	return result;
}

vector<int> getIDs(const vector<Packet> &packets) {
    vector<int> result;

    for (int i = 0; i < packets.size(); i++)
        result.push_back(packets.at(i).getId());

    return result;
}