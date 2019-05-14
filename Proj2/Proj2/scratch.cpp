#include <iostream>

#include "utilities.h"
#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Packet.h"

using namespace std;

int mainz() {
    char c;
    Agency NiceHols("agency.txt");

    cout << NiceHols.getPackets().at(0);

    cin >> c;
    vector <Packet> tmp = NiceHols.getPackets();
    Date datta("2019/1/2");
    tmp.at(0).setBeginDate(datta);
    NiceHols.setPackets(tmp);
    cout << endl << NiceHols.getPackets().at(0);

    cin >> c;

    NiceHols.saveAgency();

    cin >> c;
}