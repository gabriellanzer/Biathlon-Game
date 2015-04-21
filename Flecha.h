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

	bool getNoAr();
	void setNoAr(bool b);

	void Inicializar(string name, string path, int nAnims, int nFrames);
	void Desenhar();
	void Atualizar();
	void Finalizar();

	void Atirar(int _x, int _y, float _force);

	Sprite* getSprite();

private:
	int x, y; //Posi��o
	float rot, compVertical, compHorizontal, varVert /*Define a varia��o na velocidade no eixo Y*/, impulso /*Define a for�a inicial de lan�amento*/;
	Sprite arrowSprite;
	string spriteName;
	bool noAr, ativo;
};