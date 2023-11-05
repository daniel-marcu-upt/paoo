#ifndef _MAGAZIN
#define _MAGAZIN
#include "Produs.hpp"
#include "Carte.hpp"
#include "Rechizita.hpp"
#include <vector>

namespace Librarie{

    class Magazin{
        public:
            char *denumire;
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
        
    };
}

#endif