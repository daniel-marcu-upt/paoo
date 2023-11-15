#ifndef _RECHIZITA
#define _RECHIZITA
#include "../Produs/Produs.hpp"
namespace Librarie{

    class Rechizita : public Produs{
        public:
            char *categorie;
        private:

        public:
            Rechizita(){}
            Rechizita(char *denumire, float pret, int stoc, char *furnizor, char *categorie);
            Rechizita(const Rechizita &p);
            Rechizita(Rechizita &&p);
            Rechizita *operator=(const Rechizita &p);
            ~Rechizita();
            void afiseaza();
            float pret_redus(){std::cout<<"pret rechizita\n";return pret*0.85;}
    };
}
#endif