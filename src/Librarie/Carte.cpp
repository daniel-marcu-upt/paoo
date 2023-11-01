#include "Carte.hpp"
#include <string>
#include <iostream>


Carte::Carte(char *denumire, float pret, int stoc, char *furnizor, char *autor){
    this->pret = pret;
    this->stoc = stoc;
    int len = strlen(denumire) + 1;
    this->denumire = (char *)malloc(len);
    strcpy(this->denumire, denumire);
    len = strlen(furnizor) + 1;
    this->furnizor = (char *)malloc(len);
    strcpy(this->furnizor, furnizor);
    len = strlen(autor) + 1;
    this->autor = (char *)malloc(len);
    strcpy(this->autor, autor);
}
Carte::Carte(const Carte &p){
    std::cout<<"copiem cartea "<<p.denumire<<std::endl;
    this->pret = p.pret;
    this->stoc = p.stoc;
    int len = strlen(p.denumire) + 1;
    this->denumire = (char *)malloc(len);
    strcpy(this->denumire, p.denumire);
    len = strlen(p.furnizor) + 1;
    this->furnizor = (char *)malloc(len);
    strcpy(this->furnizor, p.furnizor);
    len = strlen(p.autor) + 1;
    this->autor = (char *)malloc(len);
    strcpy(this->autor, p.autor);
}

Carte *Carte::operator=(const Carte &p){
    std::cout<<"assignment cartea "<<p.denumire<<std::endl;
    this->pret = p.pret;
    this->stoc = p.stoc;
    int len = strlen(p.denumire) + 1;
    this->denumire = (char *)malloc(len);
    strcpy(this->denumire, p.denumire);
    len = strlen(p.furnizor) + 1;
    this->furnizor = (char *)malloc(len);
    strcpy(this->furnizor, p.furnizor);
    len = strlen(p.autor) + 1;
    this->autor = (char *)malloc(len);
    strcpy(this->autor, p.autor);
    return this;
}

Carte::~Carte(){
    std::cout<<"stergem cartea " << denumire<<std::endl;
    if(autor != NULL)
        free(autor);
}

void Carte::afiseaza(){
    std::cout << "Rechizita " << denumire << " de " << autor;
    std::cout << ": pret=" << pret;
    std::cout << " stoc=" << stoc << " furnizor=" << furnizor << std::endl;
}