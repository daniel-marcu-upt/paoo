#include <iostream>
#include "Librarie/Magazin.hpp"

using namespace std;
using namespace Librarie;

int main(){
    Carte c1("cartea1", 15, 5, "RAO", "Autor1");
    Rechizita r1("Creion mecanic", 10, 50, "Rotring", "Instrumente de scris");

    
    Magazin<int> l1("libraria1");
    l1.adauga_produs(&c1);
    l1.adauga_produs(&r1);
    l1.adauga_locatie(1);
    l1.adauga_locatie(2);

    l1.afiseaza();
    cout<<"----------------------------\n";
    Magazin<char*> l2("libraria2");
    Carte c2=c1;
    Rechizita r2=r1;
    l2.adauga_produs(&c2);
    l2.adauga_produs(&r2);
    l2.adauga_locatie("locatia1");
    l2.adauga_locatie("locatia2");

    l2.afiseaza();
    cout<<"----------------------------\n";


    return 0;
}