#include <iostream>
#include "Librarie/Magazin.hpp"

using namespace std;
using namespace Librarie;

int main(){
    Magazin l1("libraria1");
    Carte c1("cartea1", 15, 5, "RAO", "Autor1");
    Carte c2("cartea2", 25, 15, "RAO", "Autor2");
    Rechizita r1("Creion mecanic", 10, 50, "Rotring", "Instrumente de scris");

    //pt copy constructor
    Carte c3=c1;
    //move constructor
    Carte c4(std::move(c3));

    l1.adauga_produs(&c1);
    l1.adauga_produs(&c2);
    
    l1.adauga_produs(&r1);
    l1.afiseaza();
    cout<<"----------------------------\n";


    float pret = l1.cumpara("cartea2", 5);
    cout<<"cumpara normal\n";
    if(pret < 0){
        cout<<"stoc insuficient!\n";
    }else if(pret == 0){
        cout<<"produsul nu a fost gasit!\n";
    }else{
        cout<<"pret: " << pret << "\n";
    }

    cout<<"----------------------------\n";

    float pret1 = l1.cumpara_black_friday("cartea2", 5);
    cout<<"cumpara black friday\n";
    if(pret1 < 0){
        cout<<"stoc insuficient!\n";
    }else if(pret1 == 0){
        cout<<"produsul nu a fost gasit!\n";
    }else{
        cout<<"pret: " << pret1 << "\n";
    }

    cout<<"----------------------------\n";
    l1.afiseaza();
    cout<<"----------------------------\n";


    return 0;
}