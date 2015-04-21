#include "libUnicornio.h"
#include <time.h>

using namespace std;

class Obstaculo
{
private:
	int x, y;
	bool ativo;
	float rotation;
	Sprite sprite;
	string name;

public:
	Obstaculo();
	~Obstaculo();

	int getX();
	void setX(int _x);

	int getY();
	void setY(int _y);

	float getRot();
	void setRot(float r);

	bool getAtivo();
	void setAtivo(bool b);

	void Desenhar();
	void Atualizar();

	Sprite* getSprite();

	void Iniciar(string _name, string spritesheetpath);
};