#include "Fase.h"

Fase::Fase(Jogador* j1, sf::RenderWindow* w)
{
	this->window = w;
	this->jogador1 = j1;
	listaEntidades = new ListaEntidades();
	i1 = new Inimigo();
	i1->setWindow(window);
	inicializaElementos();
}

Fase::~Fase()
{
}

void Fase::inicializaElementos()
{
	listaEntidades->LEs.push(jogador1);
	listaEntidades->LEs.push(i1);
}

void Fase::gerenciar_colisoes()
{
}
