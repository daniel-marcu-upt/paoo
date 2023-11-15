#ifndef _PRODUS
#define _PRODUS
#include <iostream>
#include "../BlackFriday/BlackFriday.hpp"

namespace Librarie{

    class Produs: public BlackFriday{
        public:
            char *denumire;
            float pret;

        protected:
            int stoc;
            char *furnizor;

        public:
            Produs(){}
            Produs(char *denumire, float pret, int stoc, char *furnizor);
            Produs(const Produs &p);
            Produs(Produs &&p);
            Produs *operator=(const Produs &p);
            ~Produs();
            bool scade_stoc();
            bool scade_stoc(int cantitate);
            void seteaza_stoc(int cantitate){this->stoc=cantitate;}
            virtual void afiseaza();
            virtual float pret_redus(){std::cout<<"pret produs\n";return pret;}
        private:
    };
}

#endif