#include "Rrectangle.hpp"
#include "Rondas.hpp"
Rectangle::Rectangle(Vector2f size, RenderWindow &window){
    this->shape = RectangleShape(size);
    this->shape.setPosition({rand()%1200,940});
    this->shape.setFillColor(Color::Red);
    this->speed=Vector2f(4.f,4.f);
    this->acc=Vector2f(0.f, 0.f);
    this->shape.setOutlineThickness(3);
    this->shape.setOutlineColor(Color::Cyan);
    this->rebotesx=0;
    this->rebotesy=0;
    this->vivo=true;
}

void Rectangle::update(){
    
    this->speed-= this->acc;
    this->shape.move(this->speed);
    if(shape.getPosition().x+shape.getSize().x>=1200|| shape.getPosition().x<0){
            
            speed.x*= -1;
            this->shape.setOutlineColor(Color::White);
            this->rebotesx++;
    }
    if(this->vivo == true){// Aplica solo si el pato esta muerto(color verde del cuadro)
    if(shape.getPosition().y+shape.getSize().y>=1000|| shape.getPosition().y<0){
            
            this->speed.y*= -1;
            this->shape.setOutlineColor(Color::Green);
            this->rebotesy++;
        }
    }else if(shape.getPosition().y+shape.getSize().y>=1000){
        speed.y=0;//no desaparece de pantalla estatico abajo
    }
    if(this->rebotesy>5){
       if(this->shape.getPosition().y<=0){
            this->shape.setPosition(-1000,-1000);
       }
    }
    if(this->vivo == true){
    if(this->rebotesy>1){
       if(this->shape.getPosition().y+this->shape.getSize().y>=600){
        this->rebotesy++;
        this->speed.y*= -1;}
    }
}
}
void Rectangle::drawTo(RenderWindow &window){
    window.draw(this->shape);
}

void Rectangle::changeColorIfClicked(Vector2i position){
    float x =this->shape.getPosition().x;
    float y = this->shape.getPosition().y;
    float w = this-> shape.getSize().x;
    float h = this->shape.getSize().y;
    int mouseX = position.x;
    int mouseY = position.y;
    if(mouseX>=x && mouseX <=x+w && mouseY>=y && mouseY<=y+h){
        this->shape.setFillColor(Color::Green);
        this->vivo=false;
        this->speed.y=4;
        this->speed.x=0;
        }
    }