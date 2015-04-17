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
	flechaCont = 0; //Resetar o contador de flechas
	force = 0; //Resetar a for�a do lan�amento
	for (int i = 0; i < 14; i++) //Rodar um loop para inicializar todas as flechas
	{
		flecha[i].Inicializar("Flecha", "data/Sprites/ArrowTest.png", 1, 1);
	}

	//	O resto da inicializa��o vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finaliza��o vem aqui (provavelmente, em ordem inversa a inicializa��o)!
	//	...

	for (int i = 0; i < 14; i++) //Rodar um loop para finalizar todas as flechas
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

		//----------------DEBUGING-----------------//
		uniDepurar("test ", atan((float) (mouse.y - janela.getAlturaTela()/2)/(float) (mouse.x - janela.getLarguraTela()/20))* 180.0/PI);
		uniDepurar("force ", force);
		//----------------DEBUGING-----------------//

		if (mouse.segurando[BOTAO_ESQ]) //Carregar a for�a quando o bot�o � apertador
		{
			force += 0.3;
			if (force >= 30)
			{
				force = 30;
			}
		}
		if (mouse.soltou[BOTAO_ESQ]) //Lan�ar a flecha quando o bot�o for solto
		{
			if (flechaCont < 13) //Rodar um loop passando pelas flechas n�o lan�adas ou re-utilizando as primeiras
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

		for (int i = 0; i < 14; i++) //Fazer um loop por todas as flechas checando se est�o ativas e atualizando e desenhando elas
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