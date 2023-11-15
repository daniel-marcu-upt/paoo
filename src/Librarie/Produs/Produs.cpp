#include "Produs.hpp"
#include <string>
#include <iostream>

namespace Librarie{
    Produs::Produs(char *denumire, float pret, int stoc, char *furnizor){
        this->pret = pret;
        this->stoc = stoc;
        int len = strlen(denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, denumire);
        len = strlen(furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, furnizor);
    }
    Produs::Produs(const Produs &p){
        // std::cout<<"copiem produsul "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);
    }

    Produs::Produs(Produs &&p){
        // std::cout<<"mutam produsul "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);

        p.denumire = nullptr;
        p.furnizor = nullptr;
    }

    Produs *Produs::operator=(const Produs &p){
        //std::cout<<"assignment produsul "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);
        return this;
    }

    Produs::~Produs(){
        if(denumire != NULL){
            std::cout<<"stergem produsul " << denumire<<std::endl;
            free(denumire);
            denumire = NULL;
        }
        if(furnizor != NULL){
            free(furnizor);
            furnizor = NULL;
        }
    }

    bool Produs::scade_stoc(){
        return scade_stoc(1);
    }
    bool Produs::scade_stoc(int cantitate){
        if(this->stoc<cantitate)
            return false;
        this->stoc-=cantitate;
        return true;
    }
    void Produs::afiseaza(){
        std::cout << "Produsul " << denumire;
        std::cout << " pret=" << pret;
        std::cout << " stoc=" << stoc << " furnizor=" << furnizor << std::endl;
    }
}