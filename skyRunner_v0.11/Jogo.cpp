#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
	exit(0);
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, true, "Sky Runners");

	// INICIALIZA플O - MENUS

	posmenu = 0;

	if (!gRecursos.carregouSpriteSheet("gameTitle_bg"))
	{
		gRecursos.carregarSpriteSheet("gameTitle_bg", "assets/image/title/gameTitle_bg.png");
	}
	if (!gRecursos.carregouSpriteSheet("gameTitle"))
	{
		gRecursos.carregarSpriteSheet("gameTitle", "assets/image/title/gameTitle.png");
	}
	if (!gRecursos.carregouSpriteSheet("gameController"))
	{
		gRecursos.carregarSpriteSheet("gameController", "assets/image/title/gameController.png");
	}
	if (!gRecursos.carregouSpriteSheet("gameCredits"))
	{
		gRecursos.carregarSpriteSheet("gameCredits", "assets/image/title/gameCredits.png");
	}

	if (!gRecursos.carregouSpriteSheet("menu_jogar"))
	{
		gRecursos.carregarSpriteSheet("menu_jogar", "assets/image/title/gameTitle_menu'jogar'.png");
	}
	if (!gRecursos.carregouSpriteSheet("menu_control"))
	{
		gRecursos.carregarSpriteSheet("menu_control", "assets/image/title/gameTitle_menu'ctrl'.png");
	}
	if (!gRecursos.carregouSpriteSheet("menu_credit"))
	{
		gRecursos.carregarSpriteSheet("menu_credit", "assets/image/title/gameTitle_menu'credit'.png");
	}
	if (!gRecursos.carregouSpriteSheet("menu_exit"))
	{
		gRecursos.carregarSpriteSheet("menu_exit", "assets/image/title/gameTitle_menu'exit'.png");
	}
	
	tela = stMenu;

	// INICIALIZA플O - BACKGROUND

	if (!gRecursos.carregouSpriteSheet("Background_1"))
	{
		gRecursos.carregarSpriteSheet("Background_1", "assets/image/bg/sky_1024x728.jpg");
	}
	if (!gRecursos.carregouSpriteSheet("Background_2"))
	{
		gRecursos.carregarSpriteSheet("Background_2", "assets/image/bg/city_1024x728.png");
	}
	if (!gRecursos.carregouSpriteSheet("Background_3"))
	{
		gRecursos.carregarSpriteSheet("Background_3", "assets/image/bg/back_city_1024x728.png");
	}

	if (!gRecursos.carregouSpriteSheet("Frontground_1"))
	{
		gRecursos.carregarSpriteSheet("Frontground_1", "assets/image/bg/mist_1024x728.png");
	}

	background1.setSpriteSheet("Background_1");
	background2.setSpriteSheet("Background_2");
	background3.setSpriteSheet("Background_3");
	frontground1.setSpriteSheet("Frontground_1");

	bgSky_x1 = 0;
	bgSky_y1 = gJanela.getAltura() / 2;
	bgSky_x2 = gJanela.getLargura();
	bgSky_y2 = gJanela.getAltura() / 2;

	bgCity_x1 = 0;
	bgCity_y1 = gJanela.getAltura() / 2;
	bgCity_x2 = gJanela.getLargura();
	bgCity_y2 = gJanela.getAltura() / 2;


	fgMist_x1 = -gJanela.getLargura();
	fgMist_y1 = gJanela.getAltura() / 2;


	// INICIALIZA플O - OBJETOS / ITENS


	for (int i = 0; i < 10; i++)
	{
		objClouds[i].inicializar();
	}

	for (int i = 0; i < 20; i++)
	{
		item[i].inicializar();
	}

	// INICIALIZA플O - PERSONAGENS 
	nPlayer = 1;

	for (int p = 0; p < nPlayer; p++)
	{
		player[p].inicializar(p + 1);
	}

	// INICIALIZA플O - MUSIC  & SFX 

	if (!gRecursos.carregouMusica("Stage_1"))
	{
		gRecursos.carregarMusica("Stage_1", "assets/sounds/BGM/Stage_1.mp3", 30.0f);
	}

	if (!gRecursos.carregouMusica("stage_Clear"))
	{
		gRecursos.carregarMusica("stage_Clear", "assets/sounds/BGM/stageClear.mp3", 30.0f);
	}

	// INICIALIZA플O - HUD & FONTS

	if (!gRecursos.carregouSpriteSheet("HUD_master"))
	{
		gRecursos.carregarSpriteSheet("HUD_master", "assets/image/hud/hud_master.png");
	}
	if (!gRecursos.carregouSpriteSheet("HUD_score"))
	{
		gRecursos.carregarSpriteSheet("HUD_score", "assets/image/hud/hud_barScore.png");
	}
	if (!gRecursos.carregouSpriteSheet("font_BMP"))
	{
		string caracteres =
			"0123456"
			"789ABCD"
			"EFGHIJK"
			"LMNOPQR"
			"STUVWXY"
			"Z�!'(),"
			"-./묾끽"
			"?:'$㎚ ";

		gRecursos.carregarFonte("font_BMP", "assets/image/hud/font_game.png", caracteres, 7, 8, QUALIDADE_ESCALA_ALTA);
	}

	hudMaster.setSpriteSheet("HUD_master");
	hudMasterX = hudMaster.getLargura() / 2;
	hudMasterY = gJanela.getAltura() - hudMaster.getAltura() / 2;

	for (int p = 0; p < nPlayer; p++)
	{
		hudSprite[p].inicializar(p + 1);
	}

	hudScore.setSpriteSheet("HUD_score");
	hudScore.setEscala(2, 2);
	hudScoreX = gJanela.getLargura() / 2;
	hudScoreY = hudScore.getAltura() / 2;
	
	textScore.setFonte("font_BMP");
	textScore.setAlinhamento(TEXTO_CENTRALIZADO);
	Fonte* fonte = gRecursos.getFonte("font_BMP");
	for (int i = 0; i < fonte->getNumGlifos(); ++i)
		fonte->getGlifoPeloIndice(i)->avanco = 12;

	scorePlayer = 0;
	scoreTotal = 0;
	scoreGoal = 1000;

	textGoal.setFonte("font_BMP");
	textGoal.setAlinhamento(TEXTO_CENTRALIZADO);
	textGoal.setEscala(5, 5);
	
	for (int p = 0; p < nPlayer; p++)
	{
		spriteBarPoints[p].inicializar(p+1);
	}	
}

void Jogo::finalizar()
{
	gRecursos.descarregarTodosSpriteSheets();
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{

	while (tela != stSair && !gEventos.sair)
	{
		uniIniciarFrame();
		//EXECU플O - MENUS

		switch (tela)
		{
		case stMenu: telaMenu();
			break;
		case stSelecao: telaSelecao();
			break;
		case stJogo: telaJogo();
			break;
		case stCreditos: telaCreditos();
			break;
		case stInstrucoes: telaInstrucoes();
			break;
		/*case stPontuacao: telaPontuacao();
			break;*/
		}

		
		uniTerminarFrame();
	}

}


// TELAS


void Jogo::telaMenu()
{
	/*if(!gMusica.estaTocando() || gMusica.getNomeMusica() != "musicaMenu")
	gMusica.tocar("musicaMenu", true);*/

	if (gMusica.estaTocando())
	{
		gMusica.parar();
	}

	background1.setSpriteSheet("gameTitle_bg");
	background2.setSpriteSheet("gameTitle");

	switch (posmenu)
	{
	case 0:
		background3.setSpriteSheet("menu_jogar");
		break;
	case 1:
		background3.setSpriteSheet("menu_control");
		break;
	case 2:
		background3.setSpriteSheet("menu_credit");
		break;
	case 3:
		background3.setSpriteSheet("menu_exit");
		break;
	}

	if (posmenu < 0)
	{
		posmenu = 0;
	}

	if (posmenu > 3)
	{
		posmenu = 3;
	}

	if (gTeclado.pressionou[TECLA_BAIXO] || gJoysticks.player1.y > 0 && posmenu < 4)
	{
		posmenu++;
	}

	if (gTeclado.pressionou[TECLA_CIMA] || gJoysticks.player1.y < 0 && posmenu > -1)
	{
		posmenu--;
	}


	if (posmenu == 0 && gTeclado.pressionou[TECLA_ENTER] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_A])
	{
		tela = stSelecao;

	}

	if (posmenu == 1 && gTeclado.pressionou[TECLA_ENTER] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_A])
	{
		tela = stInstrucoes;
	}

	if (posmenu == 2 && gTeclado.pressionou[TECLA_ENTER] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_A])
	{
		tela = stCreditos;
	}


	if (posmenu == 3 && gTeclado.pressionou[TECLA_ENTER] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_A])
	{
		tela = stSair;
	}

	background1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	background2.desenhar(gJanela.getLargura() / 2, 100);
	background3.desenhar(gJanela.getLargura() / 2, 600);

}

void Jogo::telaSelecao()
{
	background1.setSpriteSheet("Background_1");
	background2.setSpriteSheet("Background_2");
	background3.setSpriteSheet("Background_3");
	frontground1.setSpriteSheet("Frontground_1");

	bgSky_x1 = 0;
	bgSky_y1 = gJanela.getAltura() / 2;
	bgSky_x2 = gJanela.getLargura();
	bgSky_y2 = gJanela.getAltura() / 2;

	bgCity_x1 = 0;
	bgCity_y1 = gJanela.getAltura() / 2;
	bgCity_x2 = gJanela.getLargura();
	bgCity_y2 = gJanela.getAltura() / 2;


	fgMist_x1 = -gJanela.getLargura();
	fgMist_y1 = gJanela.getAltura() / 2;
	tela = stJogo;
}

void Jogo::telaJogo()
{
	if (gTeclado.pressionou[TECLA_ESC] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_START] || gJoysticks.player2.pressionou[BOTAO_JOYSTICK_START] || gJoysticks.player3.pressionou[BOTAO_JOYSTICK_START] || gJoysticks.player4.pressionou[BOTAO_JOYSTICK_START])
	{
		tela = stMenu;
	}

	// EXECU플O - BACKGROUND

	background1.desenhar(bgSky_x1, bgSky_y1);
	background1.desenhar(bgSky_x2, bgSky_y2);

	if (bgSky_x2 < background1.getLargura() + background1.getLargura() * 0.5)
	{
		bgSky_x2 += 0.2;
	}
	else
	{
		bgSky_x2 = -background1.getLargura() * 0.5;
	}

	if (bgSky_x1 < background1.getLargura() + background1.getLargura() * 0.5)
	{
		bgSky_x1 += 0.2;
	}
	else
	{
		bgSky_x1 = -background1.getLargura() * 0.5;
	}

	background3.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	background2.desenhar(bgCity_x1, bgCity_y1);
	background2.desenhar(bgCity_x2, bgCity_y2);

	if (bgCity_x2 > -background2.getLargura() * 0.5)
	{
		bgCity_x2 -= 0.5;
	}
	else
	{
		bgCity_x2 = background2.getLargura()  * 1.5;
	}

	if (bgCity_x1 > -background2.getLargura() * 0.5)
	{
		bgCity_x1 -= 0.5;
	}
	else
	{
		bgCity_x1 = background2.getLargura()  * 1.5;
	}


	// EXECU플O - ITEMS & OBJETOS

	for (int i = 0; i < 5; i++)
	{
		objClouds[i].atualizar();
		objClouds[i].desenhar();
	}

	for (int i = 0; i < 10; i++)
	{
		item[i].atualizar();
		item[i].desenhar();

		for (int p = 0; p < nPlayer; p++)
		{
			item[i].testarColisao(player[p].testColision(item[i]));
		}

	}

	// EXECU플O - PLAYERS 

	for (int p = 0; p < nPlayer; p++)
	{
			player[p].atualizar();
			player[p].desenhar();	
	}

	// EXECU플O - OBJETOS (FRONTGROUND)

	for (int i = 6; i < 10; i++)
	{
		objClouds[i].atualizar();
		objClouds[i].desenhar();
	}

	// EXECU플O - FRONTGROUND

	if (fgMist_x1 < frontground1.getLargura() * 2)
	{
		fgMist_x1 += 1;
	}
	else
	{
		fgMist_x1 = -frontground1.getLargura() * 4;
	}

	frontground1.desenhar(fgMist_x1, fgMist_y1);

	// EXECU플O - HUD

	hudMaster.desenhar(hudMasterX, hudMasterY);

	for (int p = 0; p < nPlayer; p++)
	{
		if (player[p].getSpecial() == 30)
		{
			specialFull = 1;
		}
		if (player[p].getSpecial() < 30)
		{
			specialFull = 0;
		}
		hudSprite[p].atualizar(specialFull, p+1);
		hudSprite[p].desenhar();
	}

	hudScore.desenhar(hudScoreX, hudScoreY);

	scorePlayer = 0;
	for (int p = 0; p < nPlayer; p++)
		scorePlayer += player[p].getScore();

	if (scorePlayer > scoreTotal)
	{
		scoreTotal = scorePlayer;
	}

	textScore.setString(to_string(scoreTotal) + "-" + to_string(scoreGoal) + " ");
	textScore.desenhar(gJanela.getLargura() / 2, hudScoreY);

	// EXECU플O - BGM
	if (!gMusica.estaTocando())
	{
		gMusica.tocar("Stage_1", false);
	}

	if (scoreTotal == scoreGoal)
	{

		textGoal.setString("STAGE CLEAR!");
		textGoal.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		gRecursos.descarregarMusica("Stage_1");
		if (!gMusica.estaTocando())
		{
			gMusica.tocar("Stage_1", false);
		}
	}

	for (int p = 0; p < nPlayer; p++)
	{
		spriteBarPoints[p].atualizar(player[p].getSpecial(), player[p].getLife());
		spriteBarPoints[p].desenhar();
	}

	// Debug

	gDebug.depurar("speed: ", player[0].getSpeed());
	gDebug.depurar("timeAction: ", player[0].getTimeAciton());
	gDebug.depurar("time: ", player[0].getTime());
	gDebug.depurar("raio: ", player[0].getRaio());
}

void Jogo::telaCreditos()
{
	background1.setSpriteSheet("gameTitle_bg");
	background2.setSpriteSheet("gameCredits");
	background3.setSpriteSheet("");

	if (gTeclado.pressionou[TECLA_ENTER] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_A])
	{
		tela = stMenu;
	}

	background1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	background2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	
}

void Jogo::telaInstrucoes()
{
	background1.setSpriteSheet("gameTitle_bg");
	background2.setSpriteSheet("gameController");
	background3.setSpriteSheet("");

	if (gTeclado.pressionou[TECLA_ENTER] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_A])
	{
		tela = stMenu;
	}

	background1.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	background2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

//void Jogo::telaPontuacao()
//{
//	/*bVoltar.atualizar();
//	bVoltar.desenhar();
//	if (bVoltar.estaClicado())
//	{
//		tela = stMenu;
//	}*/
//}
