#include <iostream>

#include "utilities.h"
#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Packet.h"
#include "Menus.h"

using namespace std;

int main() {
    Agency agency("agency.txt");

    mainMenu(agency);
//    clientsMenu(agency);
//    editClient(agency);

//    cout << agency.getClients().at(0);

}