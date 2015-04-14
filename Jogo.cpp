#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false, "Biathlon Game");
	f.Inicializar("Flecha1", "data/Sprites/ArrowTest.png", 1, 1);
	

	//	O resto da inicialização vem aqui!
	//	...
}

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...
	f.Finalizar();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!teclado.soltou[TECLA_ESC] && !aplicacao.sair)
	{
		uniIniciarFrame();

		if (teclado.pressionou[TECLA_ESPACO])
		{
			f.Atirar(janela.getLarguraTela()/20, janela.getAlturaTela()/20);
		}

		if (f.getAtiva())
		{
			f.Atualizar();
			f.Desenhar();
		}

		uniTerminarFrame();
	}
}