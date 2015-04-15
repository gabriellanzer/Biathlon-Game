#pragma once
#include "libUnicornio.h"
#include "Flecha.h"
#include "Personagem.h"
#include "Obstaculo.h"
#include "Inimigo.h"

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
	float force;
	int flechaCont;
};

