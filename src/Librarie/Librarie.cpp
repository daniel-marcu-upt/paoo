#include "Librarie.hpp"

bool Librarie::sterge_produs(char *nume){
    for(std::vector<Produs>::iterator it = lista_produse.begin(); it != lista_produse.end(); it++){
        if(strcmp(nume, it->denumire)){
            lista_produse.erase(it);
            return true;
        }
    }
    return false;
}
float Librarie::cumpara(char *nume, int cantitate){
    for(std::vector<Produs>::iterator it = lista_produse.begin(); it != lista_produse.end(); it++){
        if(strcmp(nume, it->denumire)){
            float pret = it->pret;
            if(it->scade_stoc(cantitate))
                return pret*cantitate;
            else
                return -1;
        }
    }
    return 0;
}