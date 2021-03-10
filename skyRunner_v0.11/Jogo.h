#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
#include "Objeto.h"
#include "Item.h"
#include "HUD.h"
#include "BarPoints.h"
#include <string>


enum StatusTela {stMenu, stSelecao, stJogo,stCreditos, stInstrucoes, stPontuacao, stSair};

//enum JoystickGenerico {BOTAO_JOYSTICK_Y, BOTAO_JOYSTICK_B, BOTAO_JOYSTICK_A, BOTAO_JOYSTICK_X, BOTAO_JOYSTICK_LB, BOTAO_JOYSTICK_RB, BOTAO_JOYSTICK_LT, BOTAO_JOYSTICK_RT, BOTAO_JOYSTICK_BACK, BOTAO_JOYSTICK_START };

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

protected:
	void telaMenu();
	void telaSelecao();
	void telaJogo();
	void telaCreditos();
	void telaInstrucoes();
	//void telaPontuacao();

	StatusTela tela;
	//BotaoSprite bJogar, bInstrucoes, bCreditos, bSair, bVoltar, bContinuar;

	Sprite background1, background2, background3, frontground1, hudMaster, hudScore;
	HUD hudSprite[4];
	BarPoints spriteBarPoints[4];
	Personagem player[4];
	Objeto objClouds[10];
	Item item[20];
	Musica stageClear;
	Texto textScore, textGoal;
	float bgSky_x1, bgSky_y1, bgSky_x2, bgSky_y2, bgCity_x1, bgCity_y1, bgCity_x2, bgCity_y2, fgMist_x1, fgMist_y1, hudMasterX, hudMasterY, hudScoreX, hudScoreY;
	bool colisao, specialFull;
	int nPlayer, scorePlayer, scoreGoal, scoreTotal, posmenu;


};