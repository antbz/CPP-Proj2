#include "Menus.h"


void mainMenu(Agency agency){
	line(35);
	cout << right << setfill(' ') << setw(22) << "IN�CIO" << endl;
	line(35);
	cout << setw(4) << left << '|' << "1. Registar compra" << endl;
	cout << setw(4) << left << '|' << "2. Relat�rio" << endl;
	cout << setw(4) << left << '|' << "3. Gerir clientes" << endl;
	cout << setw(4) << left << '|' << "4. Gerir pacotes" << endl;
	cout << setw(4) << left << '|' << "5. Gerir ag�ncia" << endl;
	cout << endl << setw(4) << left << '|' << "0. Fechar" << endl;
	line(35);
}
    
