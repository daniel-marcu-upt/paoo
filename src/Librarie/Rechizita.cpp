#include "Rechizita.hpp"
#include <string>
#include <iostream>

namespace Librarie{

    Rechizita::Rechizita(char *denumire, float pret, int stoc, char *furnizor, char *categorie){
        this->pret = pret;
        this->stoc = stoc;
        int len = strlen(denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, denumire);
        len = strlen(furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, furnizor);
        len = strlen(categorie) + 1;
        this->categorie = (char *)malloc(len);
        strcpy(this->categorie, categorie);
    }
    Rechizita::Rechizita(const Rechizita &p){
        //std::cout<<"copiem rechizita "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);
        len = strlen(p.categorie) + 1;
        this->categorie = (char *)malloc(len);
        strcpy(this->categorie, p.categorie);
    }

    Rechizita::Rechizita(Rechizita &&p){
        //std::cout<<"mutam rechizita "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);
        len = strlen(p.categorie) + 1;
        this->categorie = (char *)malloc(len);
        strcpy(this->categorie, p.categorie);

        p.categorie = NULL;
        p.denumire = NULL;
        p.furnizor = NULL;
    }

    Rechizita *Rechizita::operator=(const Rechizita &p){
        //std::cout<<"assignment rechizita "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);
        len = strlen(p.categorie) + 1;
        this->categorie = (char *)malloc(len);
        strcpy(this->categorie, p.categorie);
        return this;
    }

    Rechizita::~Rechizita(){
        if(categorie != NULL){
            free(categorie);
            categorie = NULL;
        } 
        if(denumire != NULL){
            std::cout<<"stergem rechizita " << denumire<<std::endl;
            free(denumire);
            denumire = NULL;
        }
        if(furnizor != NULL){
            free(furnizor);
            furnizor = NULL;
        }
    }

    void Rechizita::afiseaza(){
        std::cout << "Rechizita " << denumire << ": pret=" << pret;
        std::cout << " categorie=" << categorie;
        std::cout << " stoc=" << stoc << " furnizor=" << furnizor << std::endl;
    }
}