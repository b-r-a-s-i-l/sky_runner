#pragma once
#include "libUnicornio.h"

enum TipoObj { cloud_1, cloud_2, cloud_3, cloud_4 };

class Objeto
{
public:
	Objeto();
	~Objeto();

	void inicializar();
	void atualizar();
	void desenhar();
	void resetar();


protected:
	Sprite clouds;
	float objX, objY, objSpeed, objScale;
	TipoObj obj;
	int corAlpha;


};

