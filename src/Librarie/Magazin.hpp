#ifndef _MAGAZIN
#define _MAGAZIN
#include "Produs/Produs.hpp"
#include "Carte/Carte.hpp"
#include "Rechizita/Rechizita.hpp"
#include <vector>

namespace Librarie{
    
    template <typename T>
    class Magazin{
        public:
            char *denumire;
            std::vector<T> id_locatii;
        private:
            std::vector <Produs*> lista_produse;
        public:
            Magazin(){}
            Magazin(char *denumire);
            Magazin(const Magazin &p);
            Magazin(Magazin &&p);
            Magazin *operator=(const Magazin &p);
            ~Magazin();

            bool sterge_produs(char* nume);
            void adauga_produs(Produs *p){
                lista_produse.push_back(p);
            }
            float cumpara(char *nume, int cantitate);
            float cumpara_black_friday(char *nume, int cantitate);
            void afiseaza();
            void adauga_locatie(T loc){
                id_locatii.push_back(loc);
            }        
    };
    template <typename T>
    Magazin<T>::Magazin(char *denumire){
        int len = strlen(denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, denumire);
    }

    template <typename T>
    bool Magazin<T>::sterge_produs(char *nume){
        for(std::vector<Produs*>::iterator it = lista_produse.begin(); it != lista_produse.end(); it++){
            if(strcmp(nume, (*it)->denumire) == 0){
                lista_produse.erase(it);
                return true;
            }
        }
        return false;
    }
    template <typename T>
    float Magazin<T>::cumpara(char *nume, int cantitate){
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

    template <typename T>
    float Magazin<T>::cumpara_black_friday(char *nume, int cantitate){
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


    template <typename T>
    Magazin<T>::Magazin(const Magazin &p){
        //std::cout<<"copiem libraria "<< p.denumire << std::endl;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        
        for(Produs* i : p.lista_produse){
            Produs *i1 = new Produs(*i);
            lista_produse.push_back(i1);
        }
        for(T i : p.id_locatii){
            id_locatii.push_back(i1);
        }
    }

    template <typename T>
    Magazin<T>::Magazin(Magazin &&p){
        //std::cout<<"mutam libraria "<< p.denumire << std::endl;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);
        
        for(Produs* i : p.lista_produse){
            Produs *i1 = new Produs(*i);
            this->lista_produse.push_back(i1);
        }
        
        for(T i : p.id_locatii){
            this->id_locatii.push_back(i1);
        }

        p.denumire = nullptr;
        p.lista_produse.clear();
        p.id_locatii.clear();
    }

    template <typename T>
    Magazin<T> *Magazin<T>::operator=(const Magazin &p){
        //std::cout<<"assignment libraria "<<p.denumire<<std::endl;
        int len = strlen(p.denumire) + 1;
        this->denumire = (char *)malloc(len);
        strcpy(this->denumire, p.denumire);

        for(Produs* i : p.lista_produse){
            Produs *i1 = new Produs(*i);
            this->lista_produse.push_back(i1);
        }
        
        for(T i : p.id_locatii){
            this->id_locatii.push_back(i1);
        }

        return this;
    }

    template <typename T>
    Magazin<T>::~Magazin(){
        std::cout << "Destructor librarie " << denumire << std::endl;
        if(denumire != nullptr)
            free(denumire);
        lista_produse.clear();
        id_locatii.clear();
    }
    template <typename T>
    void Magazin<T>::afiseaza(){
        std::cout << "magazinul " << denumire << ". Id locatii: ";
        for(T i: id_locatii)
            std::cout << i << ", ";
        std::cout<<"\n";
        for(Produs *p:lista_produse){
            p->afiseaza();
        }
    }
}

#endif