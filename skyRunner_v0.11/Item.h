#pragma once
#include <ctime>
#include "libUnicornio.h"

enum TipoItem { noneItem, disc, lifePill, specialPill, multiPill, goldPill, speedBoots, shadowCloak, magnetRing, opticalShield };
enum TipoInimigo { noneInimigo, robotBomb };
enum TipoParteRobo { noneRobo, helmetRobo, armorRobo, legRobo, handRobo };

class Item
{
public:
	Item();
	~Item();

	void inicializar();
	void atualizar();
	void desenhar();
	void resetar();
	void testarColisao(bool colisao);
	float getX() { return x; }
	float getY() { return y; }
	bool getMagnetized() { return magnetized; }
	TipoItem getTipoItem() { return item; }
	TipoInimigo getTipoInimigo() { return inimigo; }
	TipoParteRobo getTipoRobo() { return parteRobo; }
	Sprite getSprite() { return sprite; }

	void setMagnetized(bool magnetized);
	void setPositionFinal(float x, float y);

protected:
	Sprite sprite;
	float x, y, speed, moveTime, moveDuration;
	int corAlpha, probability;
	bool magnetized;
	TipoItem item;
	TipoInimigo inimigo;
	TipoParteRobo parteRobo;
	Som som;
	Vetor2D position, positionStart, positionFinal;


};
