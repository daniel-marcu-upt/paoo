#ifndef _CARTE
#define _CARTE
#include "Produs.hpp"
class Carte : public Produs{
    public:
        char *autor;
    public:
        Carte(){};
        Carte(char *denumire, float pret, int stoc, char *furnizor, char *autor);
        Carte(const Carte &p);
        Carte *operator=(const Carte &p);
        ~Carte();
        void afiseaza();
};

#endif