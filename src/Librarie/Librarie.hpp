#ifndef _LIBRARIE
#define _LIBRARIE
#include "Produs.hpp"
#include "Carte.hpp"
#include "Rechizita.hpp"
#include <vector>

class Librarie{
    private:
        vector <Produs> lista_produse;
    public:
        Librarie(){}
        bool sterge_produs(char* nume);
        void adauga_produs(Produs p){
            lista_produse.push_back(p);
        }
        float cumpara(char *nume, int cantitate);
    
};

#endif