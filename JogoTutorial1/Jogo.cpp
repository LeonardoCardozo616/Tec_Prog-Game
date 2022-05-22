#include "Jogo.h"

Jogo::Jogo():
	window(sf::VideoMode(400, 400), "Jogo!")
{
    player1 = new Jogador();
    fase1 = new Fase(player1, &window);
    player1->setWindow(&window);
    LES = fase1->getListaEntidades();
    
	executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player1->move();
        window.clear();
        
        for (int i = 0; i < LES->LEs.getLen(); i++) {
            Entidade* temp = LES->LEs.getItem(i);
            temp->draw();
        }

        window.display();
    }
}
