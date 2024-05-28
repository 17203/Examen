#ifndef partida_h
#define partida_h

class Partida{
private: 
int rondas;
bool juegoSigue;
int prob;
public:

Partida(int r,bool JS);
void jugar(RenderWindow &window);
};


#endif
