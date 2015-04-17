#include "libUnicornio.h"

using namespace std;

class Mira
{
public:
	Mira();
	~Mira();
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

	void Atirar(int _x, int _y, float _force);

	Sprite* getSprite();

private:
	int x, y; //Posição
	float rot, compVertical, compHorizontal, varVert /*Define a variação na velocidade no eixo Y*/, impulso /*Define a força inicial de lançamento*/;
	Sprite aimSprite;
	string spriteName;
	bool noAr, ativo;
};