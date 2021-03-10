#pragma once
#include "libUnicornio.h"
#include "Personagem.h"

class BarPoints
{
public:
	BarPoints();
	~BarPoints();

	void inicializar(int idPlayer);
	void atualizar(int specialPlayer, int lifePlayer);
	void desenhar();

protected:
	Sprite spriteBarPoints;
	float x, y;
	int idPlayer, specialPlayerPoints, lifePlayerPoints, count = 0;
};

