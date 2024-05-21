#include "Rondas.hpp"

Ronda::Ronda(){
    this->balas=3;
    this->puntuacion=0;
    this->enemigos=0;
}

void Ronda::update(){
    
}
void Ronda::drawTo(RenderWindow &window){
}

void Ronda::disparaBala(){
    if(balas>0){
    balas--;}
    else{

    }
}
