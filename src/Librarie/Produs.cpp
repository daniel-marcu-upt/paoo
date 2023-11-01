#include "Produs.hpp"

bool Produs::scade_stoc(){
    return scade_stoc(1);
}
bool Produs::scade_stoc(int cantitate){
    if(this->stoc<cantitate)
        return false;
    this->stoc--;
    return true;
}