#include "Librarie.hpp"
#include <string>
#include <iostream>



Librarie::Librarie(char *denumire){
    int len = strlen(denumire) + 1;
    this->denumire = (char *)malloc(len);
    strcpy(this->denumire, denumire);
}

bool Librarie::sterge_produs(char *nume){
    for(std::vector<Produs>::iterator it = lista_produse.begin(); it != lista_produse.end(); it++){
        if(strcmp(nume, it->denumire) == 0){
            lista_produse.erase(it);
            return true;
        }
    }
    return false;
}
float Librarie::cumpara(char *nume, int cantitate){
    for(std::vector<Produs>::iterator it = lista_produse.begin(); it != lista_produse.end(); it++){
        if(strcmp(nume, it->denumire) == 0){
            float pret = it->pret;
            if(it->scade_stoc(cantitate))
                return pret*cantitate;
            else
                return -1;
        }
    }
    return 0;
}


Librarie::Librarie(const Librarie &p){
    //std::cout<<"copiem libraria "<< p.denumire << std::endl;
    int len = strlen(p.denumire) + 1;
    this->denumire = (char *)malloc(len);
    strcpy(this->denumire, p.denumire);
    
    for(Produs i : p.lista_produse){
        Produs i1=i;
        lista_produse.push_back(i1);
    }


}

Librarie *Librarie::operator=(const Librarie &p){
    //std::cout<<"assignment libraria "<<p.denumire<<std::endl;
    int len = strlen(p.denumire) + 1;
    this->denumire = (char *)malloc(len);
    strcpy(this->denumire, p.denumire);

    for(Produs i : p.lista_produse){
        Produs i1 = i;
        lista_produse.push_back(i1);
    }

    return this;
}

Librarie::~Librarie(){
    //std::cout << "Destructor librarie" << std::endl;
    lista_produse.clear();
}
void Librarie::afiseaza(){
    for(Produs p:lista_produse)
        p.afiseaza();
}