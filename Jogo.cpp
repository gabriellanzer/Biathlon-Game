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
	force = 0;
	for (int i = 0; i < 14; i++)
	{
		flecha[i].Inicializar("Flecha", "data/Sprites/ArrowTest.png", 1, 1);
	}

	//	O resto da inicialização vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...
	for (int i = 0; i < 14; i++)
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


		uniDepurar("test ", atan((float) (mouse.y - janela.getAlturaTela()/2)/(float) (mouse.x - janela.getLarguraTela()/20))* 180.0/PI);
		uniDepurar("force ", force);

		if (teclado.segurando[TECLA_ESPACO])
		{
			force += 0.2;
			if (force >= 30)
			{
				force = 30;
			}
		}
		if (teclado.soltou[TECLA_ESPACO])
		{
			if (flechaCont < 13)
			{
				flechaCont++;
				flecha[flechaCont].Atirar(janela.getLarguraTela() / 20, janela.getAlturaTela() / 2, force);
			}
			else
			{
				flechaCont = 0;
				flecha[flechaCont].Atirar(janela.getLarguraTela() / 20, janela.getAlturaTela() / 2, force);
			}
			force = 0;
		}

		for (int i = 0; i < 14; i++)
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