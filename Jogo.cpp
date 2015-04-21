#include "Jogo.h"

Jogo::Jogo()
{

}

Jogo::~Jogo()
{

}

void Jogo::inicializar()
{
	uniInicializar(1360, 768, false, "Biathlon Game");
	flechaCont = 0; //Resetar o contador de flechas
	particulasCont = 0;
	force = 0; //Resetar a for�a do lan�amento
	for (int i = 0; i < 14; i++) //Rodar um loop para inicializar todas as flechas
	{
		flecha[i].Inicializar("Flecha", "data/Sprites/ArrowTest.png", 1, 1);
	}

	for (int i = 0; i < 16; i++) //Rodar um loop para inicializar todas as part�culas
	{
		particulaMira[i].Inicializar("Particula", "data/Sprites/AimingBall.png", 1, 1);
	}
	ground.Iniciar("Chao", "data/Sprites/GroundTest.png");
	ground.setRot(0);
	ground.setX(ground.getSprite()->getLargura()/2.0);
	ground.setY(janela.getAlturaTela() - 100);
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

	for (int i = 0; i < 16; i++) //Rodar um loop para finalizar todas as part�culas
	{
		particulaMira[i].Finalizar();
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

			if (particulasCont < 15) //Rodar um loop atirando todas as part�culas
			{
				particulasCont++;
				particulaMira[particulasCont].Atirar(janela.getLarguraTela() / 20, janela.getAlturaTela() / 2, force);
			}
			else
			{
				particulasCont = 0;
				particulaMira[particulasCont].Atirar(janela.getLarguraTela() / 20, janela.getAlturaTela() / 2, force);
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

			for (int i = 0; i < 16; i++) //Fazer um loop por todas as part�culas de mira e desabilita elas, para que n�o saiam voando junto com a flecha
			{
				particulaMira[i].setAtiva(false);
			}
			force = 0;
		}

		for (int i = 0; i < 14; i++) //Fazer um loop por todas as flechas checando se est�o ativas e atualizando e desenhando elas
		{
			if (uniColisao(flecha[i].getSprite(), flecha[i].getX(), flecha[i].getY(), flecha[i].getRot(), ground.getSprite(), ground.getX(), ground.getY(), ground.getRot()))
			{
				flecha[i].setNoAr(false);
			}

			if (flecha[i].getAtiva())
			{
				flecha[i].Atualizar();
				flecha[i].Desenhar();
			}
		}

		for (int i = 0; i < 16; i++) //Fazer um loop por todas as part�culas checando se est�o ativas e atualizando e desenhando elas
		{
			if (particulaMira[i].getAtiva())
			{
				particulaMira[i].Atualizar();
				particulaMira[i].Desenhar();
			}
		}
		ground.Desenhar();

		uniTerminarFrame();
	}
}