#include "Flecha.h"
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

bool Flecha::getNoAr()
{
	return noAr;
}

void Flecha::setNoAr(bool b)
{
	noAr = b;
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
	acelVento = 0;
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
	float yTemp = y; //Criamos uma vari�vel tempor�ria para checarmos se o objeto est� subindo ou descendo
	if (noAr) //Checamos se a flecha continua no ar
	{
		//Aceleramos a velocidade da Gravidade
		if (compVertical > 10) //Como na vida real, todos os objetos tem uma velocidade m�xima de queda-livre (For�a resultante = 0), no nosso caso ser� 10px/frame ou 300px/s � 30FPS
		{
			compVertical = 10; //Ent�o definimos a velocidade da gravidade constante
		}
		else if (compVertical < -10)
		{
			compVertical = -10;
		}
		else
		{
			compVertical += 0.1; //Caso contr�rio, continuamos acelerando
		}

		if (compHorizontal > 30) //Definimos um limite para a componente horizontal
		{
			compHorizontal = 30; //Ent�o definimos o valor dela constante
		}
		else if (compHorizontal < -30)
		{
			compHorizontal = -30;
		}
		else
		{
			compHorizontal -= 0.1 * cos(rot * PI/180); //Definimos o atrito conforme o �ngulo da flecha
			compHorizontal -= acelVento;
		}

		if (compHorizontal > 0)
		{
			rot = atan((float)compVertical / (float)compHorizontal) * 180.0 / PI;
		}
		else
		{
			rot = (atan((float)compVertical / (float)compHorizontal) * 180.0 / PI) -180;
		}
	}
	else
	{
		compVertical = 0; //Caso a flecha n�o esteja mais no ar, devemos parar de aplicar a gravidade
		compHorizontal = 0;
	}
	y += compVertical; //Somando a velocidade da gravidade ao nosso Y, fazemos a flecha descer ou subir de forma acelerada
	x += compHorizontal;
	varVert = y - yTemp; //Calculamos se o objeto est� descendo ou subindo pela varia��o de Y ao final do frame
}

void Flecha::Finalizar()
{
	recursos.descarregarSpriteSheet(spriteName);
}

void Flecha::Atirar(int _x, int _y, float _force)
{
	//Definimos todas as vari�veis em seus estados padr�es e ativamos a flecha
	rot = atan((float)(mouse.y - _y) / (float)(mouse.x - _x)) * 180.0 / PI;
	
	compVertical = _force * sin(rot * PI/180.0) / 3.0; //Usamos SENO para projetar o impulso na vertical
	varVert = compVertical / 10.0; //Definimos uma varia��o inicial da vertical, apenas o sinal importa na realidade
	compHorizontal = _force * cos(rot * PI/180.0); //Usamos COSSENO para projetar o impulso na horizontal

	//Definimos a posi��o de Spawn da flecha
	x = _x;
	y = _y;

	//Definimos que a flecha foi lan�ada
	noAr = true;
	ativo = true;
}

Sprite* Flecha::getSprite()
{
	return &arrowSprite;
}