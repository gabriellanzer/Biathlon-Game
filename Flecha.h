#include "libUnicornio.h"

using namespace std;

class Flecha
{
public:
	Flecha();
	~Flecha();
	int getX();
	void setX(int _x);

	int getY();
	void setY(int _y);


	float getRot();
	void setRot(float r);

	bool getAtiva();
	void setAtiva(bool b);

	void Inicializar(string name, string path, int nAnims, int nFrames);
	void Desenhar();
	void Atualizar();
	void Finalizar();

	void Atirar(int _x, int _y);

private:
	int x, y; //Posição
	float rot, velocidadeGravidade, varVeloc /*Define a variação na velocidade no eixo Y*/;
	Sprite arrowSprite;
	string spriteName;
	bool noAr, ativo;
};