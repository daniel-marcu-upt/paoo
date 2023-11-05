#include "Magazin.hpp"
#include <string>
#include <iostream>


namespace Librarie{

    Magazin::Magazin(char *denumire){
        int len = strlen(denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, denumire);
    }

    bool Magazin::sterge_produs(char *nume){
        for(std::vector<Produs*>::iterator it = lista_produse.begin(); it != lista_produse.end(); it++){
            if(strcmp(nume, (*it)->denumire) == 0){
                lista_produse.erase(it);
                return true;
            }
        }
        return false;
    }
    float Magazin::cumpara(char *nume, int cantitate){
        for(std::vector<Produs*>::iterator it = lista_produse.begin(); it != lista_produse.end(); it++){
            if(strcmp(nume, (*it)->denumire) == 0){
                float pret = (*it)->pret;
                if((*it)->scade_stoc(cantitate))
                    return pret*cantitate;
                else
                    return -1;
            }
        }
        return 0;
    }

    float Magazin::cumpara_black_friday(char *nume, int cantitate){
        for(std::vector<Produs*>::iterator it = lista_produse.begin(); it != lista_produse.end(); it++){
            if(strcmp(nume, (*it)->denumire) == 0){
                float pret = (*it)->pret_redus();
                if((*it)->scade_stoc(cantitate))
                    return pret*cantitate;
                else
                    return -1;
            }
        }
        return 0;
    }


    Magazin::Magazin(const Magazin &p){
        //std::cout<<"copiem libraria "<< p.denumire << std::endl;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        
        for(Produs* i : p.lista_produse){
            Produs *i1 = new Produs(*i);
            lista_produse.push_back(i1);
        }
    }

    Magazin::Magazin(Magazin &&p){
        //std::cout<<"mutam libraria "<< p.denumire << std::endl;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        
        for(Produs* i : p.lista_produse){
            Produs *i1 = new Produs(*i);
            lista_produse.push_back(i1);
        }

        p.denumire = nullptr;
        p.lista_produse.clear();
    }

    Magazin *Magazin::operator=(const Magazin &p){
        //std::cout<<"assignment libraria "<<p.denumire<<std::endl;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);

        for(Produs* i : p.lista_produse){
            Produs *i1 = new Produs(*i);
            lista_produse.push_back(i1);
        }

        return this;
    }

    Magazin::~Magazin(){
        std::cout << "Destructor librarie" << std::endl;
        lista_produse.clear();
    }
    void Magazin::afiseaza(){
        for(Produs *p:lista_produse){
            p->afiseaza();
        }
    }
}