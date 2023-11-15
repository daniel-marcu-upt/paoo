#ifndef _CARTE
#define _CARTE
#include "../Produs/Produs.hpp"
namespace Librarie{
    
    class Carte : public Produs{
        public:
            char *autor;
        public:
            Carte(){};
            Carte(char *denumire, float pret, int stoc, char *furnizor, char *autor);
            Carte(const Carte &p);
            Carte(Carte &&p);
            Carte *operator=(const Carte &p);
            ~Carte();
            void afiseaza();
            float pret_redus(){std::cout<<"pret carte\n";return (float)(pret*0.75);}
    };
}
#endif