#include <iostream>

#include "utilities.h"
#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Packet.h"

using namespace std;

int mainz() {

    Agency NiceHols("agency.txt");

    cout << NiceHols;

    char c;
    cin >> c;
}