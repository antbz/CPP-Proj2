#include <iostream>
#include "utilities.h"
#include "Address.h"

using namespace std;

int main() {
    Address addr1("Maria Feliciana", 12, "cegei", "cafadn", "difhd");
    cout << addr1.getStreet() << endl;
    cout << addr1.getDoorNumber() << endl;
    addr1.setDoorNumber(520);
    cout << addr1.getDoorNumber() << endl;
    cout << addr1.getFloor() << endl;
    cout << addr1.getPostalCode() << endl;
    cout << addr1.getLocation() << endl;

    char c;
    cin >> c;
}