#ifndef _PRODUS
#define _PRODUS

class Produs{
    public:
        char *denumire;
        float pret;
        char *descriere;

    private:
        int stoc;
        char *furnizor;

    public:
        Produs();
        ~Produs();
        bool scade_stoc();
        bool scade_stoc(int cantitate);
        void seteaza_stoc(int cantitate){this->stoc=cantitate;}

    private:
};


#endif