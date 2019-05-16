#include <iostream>

#include "utilities.h"
#include "Address.h"
#include "Agency.h"
#include "Client.h"
#include "Packet.h"
#include "Menus.h"

using namespace std;

int mainz() {
    Agency agency("agency.txt");

    mainMenu(agency);

}