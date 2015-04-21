#pragma once
#include "libUnicornio.h"
#include "Flecha.h"
#include "Personagem.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Mira.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	Flecha flecha[14];
	Mira particulaMira[16];
	Obstaculo ground;
	float force;
	int flechaCont, particulasCont;
};

