#include "Flecha.h"
#include "ControladorDeFisica.h"
#include <math.h>

#define PI 3.14159265 //Definimos o valor de PI, poderia ser feito por uma variável também

Flecha::Flecha()
{

}

Flecha::~Flecha()
{

}

int Flecha::getX()
{
	return x;
}

void Flecha::setX(int _x)
{
	x = _x;
}

int Flecha::getY()
{
	return y;
}

void Flecha::setY(int _y)
{
	y = _y;
}

bool Flecha::getAtiva()
{
	return ativo;
}

void Flecha::setAtiva(bool b)
{
	ativo = b;
}

float Flecha::getRot()
{
	return rot;
}

void Flecha::setRot(float r)
{
	rot = r;
}

void Flecha::Inicializar(string name, string path, int nAnims, int nFrames)
{
	if (!recursos.carregouSpriteSheet(name)) //Checamos se o SpriteSheet ja está carregada, caso não, carregar
	{
		recursos.carregarSpriteSheet(name, path, nAnims, nFrames);
	}
	arrowSprite.setSpriteSheet(name); //Definimos o SpriteSheet do Sprite
	spriteName = name; //Guardamos o nome para usar depois
	
	//Definimos as variáveis de ativação como padrões
	noAr = false;
	ativo = false;
}

void Flecha::Desenhar()
{
	if (ativo)
	{
		arrowSprite.desenhar(x, y, rot); //Desenhamos a flecha na respectiva posição e rotação
	}
}

void Flecha::Atualizar()
{
	//if (true/*uniColisao()*/)
	//{
	//	noAr = false;
	//}
	float yTemp = y; //Criamos uma variável temporária para checarmos se o objeto está subindo ou descendo
	if (noAr) //Checamos se a flecha continua no ar
	{
		//Aceleramos a velocidade da Gravidade
		if (velocidadeGravidade >= 10) //Como na vida real, todos os objetos tem uma velocidade máxima de queda-livre (Força resultante = 0), no nosso caso será 10px/frame ou 300px/s à 30FPS
		{
			velocidadeGravidade = 10; //Então definimos a velocidade da gravidade constante
		}
		else
		{
			velocidadeGravidade += 0.1; //Caso contrário, continuamos acelerando
		}

		if (varVeloc > 0) //Checamos se o objeto está subindo ou descendo
		{
			rot = asin(velocidadeGravidade / 10) * 180.0 / PI; //Fazemos ele girar no sentido anti-horário se estiver subindo
		}
		else
		{
			rot = -asin(velocidadeGravidade / 10) * 180.0 / PI; //E no horário se estiver descendo
		}
		x += 10.0;
	}
	else
	{
		velocidadeGravidade = 0; //Caso a flecha não esteja mais no ar, devemos parar de aplicar a gravidade
	}
	y += velocidadeGravidade; //Somando a velocidade da gravidade ao nosso Y, fazemos a flecha descer ou subir de forma acelerada
	varVeloc = y - yTemp; //Calculamos se o objeto está descendo ou subindo pela variação de Y ao final do frame
}

void Flecha::Finalizar()
{
	recursos.descarregarSpriteSheet(spriteName);
}

void Flecha::Atirar(int _x, int _y)
{
	//Definimos todas as variáveis em seus estados padrões e ativamos a flecha
	varVeloc = 0;
	velocidadeGravidade = -2;
	rot = 0.0;
	x = _x;
	y = _y;
	noAr = true;
	ativo = true;
}