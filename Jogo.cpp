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
	force = 0; //Resetar a força do lançamento
	for (int i = 0; i < 14; i++) //Rodar um loop para inicializar todas as flechas
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

		if (mouse.segurando[BOTAO_ESQ]) //Carregar a força quando o botão é apertador
		{
			force += 0.3;
			if (force >= 30)
			{
				force = 30;
			}
		}
		if (mouse.soltou[BOTAO_ESQ]) //Lançar a flecha quando o botão for solto
		{
			if (flechaCont < 13) //Rodar um loop passando pelas flechas não lançadas ou re-utilizando as primeiras
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

		for (int i = 0; i < 14; i++) //Fazer um loop por todas as flechas checando se estão ativas e atualizando e desenhando elas
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