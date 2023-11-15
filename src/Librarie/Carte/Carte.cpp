#include "Carte.hpp"
#include <string>
#include <iostream>

namespace Librarie{

    Carte::Carte(char *denumire, float pret, int stoc, char *furnizor, char *autor){
        this->pret = pret;
        this->stoc = stoc;
        int len = (int)strlen(denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, denumire);
        len = (int)strlen(furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, furnizor);
        len = (int)strlen(autor) + 1;
        this->autor = (char *)malloc(len);
        strcpy(this->autor, autor);
    }
    Carte::Carte(const Carte &p){
        // std::cout<<"copiem cartea "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = (int)strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = (int)strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);
        len = (int)strlen(p.autor) + 1;
        this->autor = (char *)malloc(len);
        strcpy(this->autor, p.autor);
    }
    Carte::Carte(Carte &&p){
        // std::cout<<"mutam cartea "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = (int)strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = (int)strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);
        len = (int)strlen(p.autor) + 1;
        this->autor = (char *)malloc(len);
        strcpy(this->autor, p.autor);
        
        p.autor = nullptr;
        p.denumire = nullptr;
        p.furnizor = nullptr;
    }

    Carte *Carte::operator=(const Carte &p){
        //std::cout<<"assignment cartea "<<p.denumire<<std::endl;
        this->pret = p.pret;
        this->stoc = p.stoc;
        int len = (int)strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        len = (int)strlen(p.furnizor) + 1;
        this->furnizor = (char *)malloc(len);
        strcpy(this->furnizor, p.furnizor);
        len = (int)strlen(p.autor) + 1;
        this->autor = (char *)malloc(len);
        strcpy(this->autor, p.autor);
        return this;
    }

    Carte::~Carte(){
        if(autor != NULL){
            free(autor);
            autor = NULL;
        }
        if(denumire != NULL){
            // std::cout<<"stergem cartea " << denumire<<std::endl;
            free(denumire);
            denumire = NULL;
        }
        if(furnizor != NULL){
            free(furnizor);
            furnizor = NULL;
        }
    }

    void Carte::afiseaza(){
        std::cout << "Cartea " << denumire << " de " << autor;
        std::cout << ": pret=" << pret;
        std::cout << " stoc=" << stoc << " furnizor=" << furnizor << std::endl;
    }
}