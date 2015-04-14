#include "Flecha.h"
#include "ControladorDeFisica.h"
#include <math.h>

#define PI 3.14159265 //Definimos o valor de PI, poderia ser feito por uma vari�vel tamb�m

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
	if (!recursos.carregouSpriteSheet(name)) //Checamos se o SpriteSheet ja est� carregada, caso n�o, carregar
	{
		recursos.carregarSpriteSheet(name, path, nAnims, nFrames);
	}
	arrowSprite.setSpriteSheet(name); //Definimos o SpriteSheet do Sprite
	spriteName = name; //Guardamos o nome para usar depois
	
	//Definimos as vari�veis de ativa��o como padr�es
	noAr = false;
	ativo = false;
}

void Flecha::Desenhar()
{
	if (ativo)
	{
		arrowSprite.desenhar(x, y, rot); //Desenhamos a flecha na respectiva posi��o e rota��o
	}
}

void Flecha::Atualizar()
{
	//if (true/*uniColisao()*/)
	//{
	//	noAr = false;
	//}
	float yTemp = y; //Criamos uma vari�vel tempor�ria para checarmos se o objeto est� subindo ou descendo
	if (noAr) //Checamos se a flecha continua no ar
	{
		//Aceleramos a velocidade da Gravidade
		if (velocidadeGravidade >= 10) //Como na vida real, todos os objetos tem uma velocidade m�xima de queda-livre (For�a resultante = 0), no nosso caso ser� 10px/frame ou 300px/s � 30FPS
		{
			velocidadeGravidade = 10; //Ent�o definimos a velocidade da gravidade constante
		}
		else
		{
			velocidadeGravidade += 0.1; //Caso contr�rio, continuamos acelerando
		}

		if (varVeloc > 0) //Checamos se o objeto est� subindo ou descendo
		{
			rot = asin(velocidadeGravidade / 10) * 180.0 / PI; //Fazemos ele girar no sentido anti-hor�rio se estiver subindo
		}
		else
		{
			rot = -asin(velocidadeGravidade / 10) * 180.0 / PI; //E no hor�rio se estiver descendo
		}
		x += 10.0;
	}
	else
	{
		velocidadeGravidade = 0; //Caso a flecha n�o esteja mais no ar, devemos parar de aplicar a gravidade
	}
	y += velocidadeGravidade; //Somando a velocidade da gravidade ao nosso Y, fazemos a flecha descer ou subir de forma acelerada
	varVeloc = y - yTemp; //Calculamos se o objeto est� descendo ou subindo pela varia��o de Y ao final do frame
}

void Flecha::Finalizar()
{
	recursos.descarregarSpriteSheet(spriteName);
}

void Flecha::Atirar(int _x, int _y)
{
	//Definimos todas as vari�veis em seus estados padr�es e ativamos a flecha
	varVeloc = 0;
	velocidadeGravidade = -2;
	rot = 0.0;
	x = _x;
	y = _y;
	noAr = true;
	ativo = true;
}