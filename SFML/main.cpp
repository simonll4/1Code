#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    bool gameOver = false;
    RenderWindow *ventana;

    ventana = new RenderWindow(VideoMode(800,600),"hola pibes" );

    while(!gameOver){
        ventana->clear(Color::Blue);
        ventana->display();
    }

 return 0;
}
