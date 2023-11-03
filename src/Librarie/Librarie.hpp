#ifndef _LIBRARIE
#define _LIBRARIE
#include "Produs.hpp"
#include "Carte.hpp"
#include "Rechizita.hpp"
#include <vector>

class Librarie{
    public:
        char *denumire;
    private:
        std::vector <Produs*> lista_produse;
    public:
        Librarie(){}
        Librarie(char *denumire);
        Librarie(const Librarie &p);
        Librarie(Librarie &&p);
        Librarie *operator=(const Librarie &p);
        ~Librarie();

        bool sterge_produs(char* nume);
        void adauga_produs(Produs *p){
            lista_produse.push_back(p);
        }
        float cumpara(char *nume, int cantitate);
        float cumpara_black_friday(char *nume, int cantitate);
        void afiseaza();
    
};

#endif