#include <iostream>
#include "Librarie/Librarie.hpp"

using namespace std;

int main(){
    Librarie l1("libraria1");
    Carte c1("cartea1", 15, 5, "RAO", "Autor1");
    Carte c2("cartea2", 25, 15, "RAO", "Autor2");
    Rechizita r1("Creion mecanic", 10, 50, "Rotring", "Instrumente de scris");

    l1.adauga_produs(c1);
    l1.adauga_produs(c2);
    
    l1.adauga_produs(r1);
    l1.afiseaza();
    cout<<"----------------------------\n";

    Librarie l2 = l1;

    float pret = l1.cumpara("cartea2", 15);
    if(pret < 0){
        cout<<"stoc insuficient!\n";
    }else if(pret == 0){
        cout<<"produsul nu a fost gasit!\n";
    }else{
        cout<<"pret: " << pret << "\n";
    }


    cout<<"----------------------------\n";
    l1.afiseaza();
    cout<<"----------------------------\n";
    l2.afiseaza();

    return 0;
}