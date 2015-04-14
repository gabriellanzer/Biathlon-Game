#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1920, 1080, true, "Biathlon Game");
	flechaCont = 0;
	for (int i = 0; i < 7; i++)
	{
		flecha[i].Inicializar("Flecha1", "data/Sprites/ArrowTest.png", 1, 1);
	}

	//	O resto da inicializa��o vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finaliza��o vem aqui (provavelmente, em ordem inversa a inicializa��o)!
	//	...
	for (int i = 0; i < 7; i++)
	{
		flecha[i].Finalizar();
	}
	uniFinalizar();
}

void Jogo::executar()
{
	while(!teclado.soltou[TECLA_ESC] && !aplicacao.sair)
	{
		uniIniciarFrame();

		if (teclado.pressionou[TECLA_ESPACO])
		{
			if (flechaCont < 6)
			{
				flechaCont++;
				flecha[flechaCont].Atirar(janela.getLarguraTela() / 20, janela.getAlturaTela() / 20);
			}
			else
			{
				flechaCont = 0;
				flecha[flechaCont].Atirar(janela.getLarguraTela() / 20, janela.getAlturaTela() / 20);
			}
		}

		for (int i = 0; i < 7; i++)
		{
			if (flecha[i].getAtiva())
			{
				flecha[i].Atualizar();
				flecha[i].Desenhar();
			}
		}

		uniTerminarFrame();
	}
}