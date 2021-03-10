#pragma once
#include "Item.h"
#include <time.h>

enum MovimentChar {mUp, mRight, mDown, mLeft, mIdle};
enum Character {atraente = 1, vital, espectro, temporal};

enum JoystickGenerico { BOTAO_JOYSTICK_Y, BOTAO_JOYSTICK_B, BOTAO_JOYSTICK_A, BOTAO_JOYSTICK_X, BOTAO_JOYSTICK_LB, BOTAO_JOYSTICK_RB, BOTAO_JOYSTICK_LT, BOTAO_JOYSTICK_RT, BOTAO_JOYSTICK_BACK, BOTAO_JOYSTICK_START };


class Personagem
{
public:
	Personagem();
	~Personagem();

	void inicializar(int idPlayer);
	
	// métodos de movimento
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void stayIdle();
	
	// métodos de testes
	bool testColision(Item item);
	bool testMagneticArea();
	bool testActionTimeOfItem();
	

	// métodos sets
	void setPosition(int playerX, int playerY);
	void setPlayerSpeed(int playerSpeed);
	void setSpriteSheet(Character personagem, string spritesheet);
	void setActionTimeOfItem(int timeAction);

	// métodos gets
	int getScore() { return scorePlayer; }
	int getSpecial() { return specialPointsPlayer; }
	int getLife() { return lifePointsPlayer; }
	int getSpeed() { return playerSpeed; }
	int getTimeAciton() { return timeActionItem; }
	int getTime() { return time; }

	float getRaio();

	string getCharacter(int idPlayer);
	Sprite getPlayerSprite() { return playerSprite; }
	Sprite getSpriteFx() { return *playerFxSprite; }
	MovimentChar getMovimentChar() { return movimentPlayer; }

	// metódos de saída e animação
	void atualizar();
	void desenhar();
	void animate();
	

protected:
	Sprite playerSprite, *playerFxSprite;
	int playerX, playerY, playerSpeed;
	int idPlayer, scorePlayer, lifePointsPlayer, specialPointsPlayer, timeActionItem, time;
	float raio = 0;
	bool vivo, move, colisao, hit, dash, usingItem, invisible, magnetic;
	
	MovimentChar movimentPlayer;
	Character character;
	TipoItem itemInAciton;
	Uint64 timerStart;
	
};

