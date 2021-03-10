#pragma once
#include "libUnicornio.h"
class HUD
{
public:
	HUD();
	~HUD();

	void inicializar(int idPLayer);
	void atualizar(bool specialFull, int idPlayer);
	void desenhar();

protected:
	Sprite hudSprite;
	float hudPlayerX, hudPlayerY;
	int idPlayer;
	bool specialFull;

};

