#include "Obstaculo.h"

Obstaculo::Obstaculo()
{

}

Obstaculo::~Obstaculo()
{

}

int Obstaculo::getX()
{
	return x;
}

void Obstaculo::setX(int _x)
{
	x = _x;
}

int Obstaculo::getY()
{
	return y;
}

void Obstaculo::setY(int _y)
{
	y = _y;
}

float Obstaculo::getRot()
{
	return rotation;
}

void Obstaculo::setRot(float r)
{
	rotation = r;
}

bool Obstaculo::getAtivo()
{
	return ativo;
}

void Obstaculo::setAtivo(bool b)
{
	ativo = b;
}

void Obstaculo::Desenhar()
{
	sprite.desenhar(x, y, rotation);
}

void Obstaculo::Iniciar(string _name, string spritesheetpath)
{
	if (!recursos.carregouSpriteSheet(_name))
	{
		recursos.carregarSpriteSheet(_name, spritesheetpath);
	}
	sprite.setSpriteSheet(_name);

	ativo = true;
	x = 0;
	y = 0;
	rotation = 0;
}

Sprite* Obstaculo::getSprite()
{
	return &sprite;
}