#include <iostream>
#include "utilities.h"
#include "Address.h"
#include "Client.h"
#include "Packet.h"

using namespace std;

int main() {
    string addr = "Marisa Santa, 23, 4ESQ, 4900-879, Viseu", packs = "1 2 55";

    Packet packet1;
    packet1.setId(3);
    packet1.setSites(sitesStrToVect("Douro - a, tua, prima"));
    Date tempDate("2019/05/13");
    packet1.setBeginDate(tempDate);
    packet1.setEndDate(Date(15, 05, 2019));
    packet1.setPricePerPerson(300.56);
    packet1.setMaxPersons(35);

    vector<Packet> packVector = {packet1};


    Client client1("Antonio", 111222333, 2, Address(addr, ','), packVector, 3);


    cout << client1;




    char c;
    cin >> c;
}