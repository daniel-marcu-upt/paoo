#include <iostream>
#include "Librarie/Magazin.hpp"

using namespace std;
using namespace Librarie;

int main(){
    Carte c1("cartea1", 15, 5, "RAO", "Autor1");
    Rechizita r1("Creion mecanic", 10, 50, "Rotring", "Instrumente de scris");

    unique_ptr<Magazin<int> > l1 = make_unique<Magazin<int> >((char *) "libraria 1");
    // // Magazin<int> l1("libraria1");
    l1->adauga_produs(&c1);
    l1->adauga_produs(&r1);
    l1->adauga_locatie(1);
    l1->adauga_locatie(2);

    unique_ptr<Magazin<int> > tmp1 = move(l1);
    tmp1->afiseaza();
    // l1->afiseaza(); // eroare

    cout<<"----------------------------\n";
    cout<<"----------------------------\n";
    cout<<"----------------------------\n";
    shared_ptr<Magazin<char *> > l2 = make_shared<Magazin<char *> >((char *) "libraria 1");
    // Magazin<char*> l2("libraria2");
    Carte c2=c1;
    Rechizita r2=r1;
    c2.pret = 20;
    l2->adauga_produs(&c2);
    l2->adauga_produs(&r2);
    l2->adauga_locatie("locatia1");

    shared_ptr<Magazin<char *> > tmp2 = l2;
    tmp2->adauga_locatie("locatia2");

    l2->afiseaza();
    cout<<"----------------------------\n";
    tmp2->afiseaza();
    cout<<"----------------------------\n";


    return 0;
}