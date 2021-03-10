#include "Personagem.h"



Personagem::Personagem()
{
	// === CONFIGURAÇÕES PERSONAGEM == //

	playerSprite.setEscala(1.2, 1.2);
	lifePointsPlayer = 30;
	specialPointsPlayer = 30;
	scorePlayer = 0;
	playerSpeed = 1;
	timeActionItem = 0;
	time = 0;

	movimentPlayer = mIdle;
	itemInAciton = noneItem;

	dash = false;
	hit = false;
	usingItem = false;
	invisible = false;
	magnetic = false;
}


Personagem::~Personagem()
{
}

void Personagem::inicializar(int idPlayer)
{
	this->idPlayer = idPlayer;

	// ===== RECURSOS === //

	// ATRAENTE

	if (!gRecursos.carregouSpriteSheet("atraente_move"))
	{
		gRecursos.carregarSpriteSheet("atraente_move", "assets/image/char/Atraente_move.png", 4, 1);
	}
	if (!gRecursos.carregouSpriteSheet("atraente_idle"))
	{
		gRecursos.carregarSpriteSheet("atraente_idle", "assets/image/char/Atraente_idle.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("atraente_hit"))
	{
		gRecursos.carregarSpriteSheet("atraente_hit", "assets/image/char/Atraente_hit.png", 1, 3);
	}
	if (!gRecursos.carregouSpriteSheet("atraente_dead"))
	{
		gRecursos.carregarSpriteSheet("atraente_dead", "assets/image/char/Atraente_dead.png", 1, 7);
	}
	if (!gRecursos.carregouSpriteSheet("atraente_dash"))
	{
		gRecursos.carregarSpriteSheet("atraente_dash", "assets/image/char/Atraente_dash.png", 4, 1);
	}

	// VITAL

	if (!gRecursos.carregouSpriteSheet("vital_move"))
	{
		gRecursos.carregarSpriteSheet("vital_move", "assets/image/char/Vital_move.png", 4, 1);
	}
	if (!gRecursos.carregouSpriteSheet("vital_idle"))
	{
		gRecursos.carregarSpriteSheet("vital_idle", "assets/image/char/Vital_idle.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("vital_hit"))
	{
		gRecursos.carregarSpriteSheet("vital_hit", "assets/image/char/Vital_hit.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("vital_dead"))
	{
		gRecursos.carregarSpriteSheet("vital_dead", "assets/image/char/Vital_dead.png", 1, 7);
	}
	if (!gRecursos.carregouSpriteSheet("vital_dash"))
	{
		gRecursos.carregarSpriteSheet("vital_dash", "assets/image/char/Vital_dash.png", 4, 1);
	}

	//ESPECTRO

	if (!gRecursos.carregouSpriteSheet("espectro_move"))
	{
		gRecursos.carregarSpriteSheet("espectro_move", "assets/image/char/Espectro_move.png", 4, 1);
	}
	if (!gRecursos.carregouSpriteSheet("espectro_idle"))
	{
		gRecursos.carregarSpriteSheet("espectro_idle", "assets/image/char/Espectro_idle.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("espectro_hit"))
	{
		gRecursos.carregarSpriteSheet("espectro_hit", "assets/image/char/Espectro_hit.png", 1, 3);
	}
	if (!gRecursos.carregouSpriteSheet("espectro_dead"))
	{
		gRecursos.carregarSpriteSheet("espectro_dead", "assets/image/char/Espectro_dead.png", 1, 7);
	}
	if (!gRecursos.carregouSpriteSheet("espectro_dash"))
	{
		gRecursos.carregarSpriteSheet("espectro_dash", "assets/image/char/Espectro_dash.png", 4, 1);
	}

	// TEMPORAL

	if (!gRecursos.carregouSpriteSheet("temporal_move"))
	{
		gRecursos.carregarSpriteSheet("temporal_move", "assets/image/char/Temporal_move.png", 4, 1);
	}
	if (!gRecursos.carregouSpriteSheet("temporal_idle"))
	{
		gRecursos.carregarSpriteSheet("temporal_idle", "assets/image/char/Temporal_idle.png", 1, 4);
	}
	if (!gRecursos.carregouSpriteSheet("temporal_hit"))
	{
		gRecursos.carregarSpriteSheet("temporal_hit", "assets/image/char/Temporal_hit.png", 1, 3);
	}
	if (!gRecursos.carregouSpriteSheet("temporal_dead"))
	{
		gRecursos.carregarSpriteSheet("temporal_dead", "assets/image/char/Temporal_dead.png", 1, 7);
	}
	if (!gRecursos.carregouSpriteSheet("temporal_dash"))
	{
		gRecursos.carregarSpriteSheet("temporal_dash", "assets/image/char/Temporal_dash.png", 4, 1);
	}

	// FX
	if (!gRecursos.carregouSpriteSheet("magnetic_ring"))
	{
		gRecursos.carregarSpriteSheet("magnetic_ring", "assets/image/fx/magneticRingBubble.png");
	}

	setSpriteSheet(character,getCharacter(idPlayer)+"_idle");
	setPosition(100, 415);
}

void Personagem::moveRight()
{
	if (playerX < gJanela.getLargura() - playerSprite.getLargura() / 2)
	{
		playerX += playerSpeed + 1;
	}

	movimentPlayer = mRight;
}

void Personagem::moveLeft()
{
	if (playerX < gJanela.getLargura() - playerSprite.getLargura() / 2)
	{
		playerX -= playerSpeed;
	}

	movimentPlayer = mLeft;
}

void Personagem::moveUp()
{
	if (playerY > 0)
	{
		playerY -= playerSpeed + 1;
	}

	movimentPlayer = mUp;
}

void Personagem::moveDown()
{
	if (playerY < gJanela.getAltura() - 150)
	{
		playerY += playerSpeed;
	}

	movimentPlayer = mDown;
}

void Personagem::stayIdle()
{
	animate();
	movimentPlayer = mIdle;
}

float Personagem::getRaio()
{
	if (itemInAciton == magnetRing)
	{
		raio = playerFxSprite->getAltura();
	}

	return raio;
}

string Personagem::getCharacter(int idPlayer)
{
	character = (Character)idPlayer;

	switch (character)
	{
	case atraente:
		return "atraente";
		break;
	case vital:
		return "vital";
		break;
	case espectro:
		return "espectro";
		break;
	case temporal:
		return "temporal";
		break;
	default:
		break;
	}
}

void Personagem::atualizar()
{
	// === CONTROLES === //

	if (move && vivo && !hit)
	{
		stayIdle();

		// Player 1

		if ((gTeclado.segurando[TECLA_DIR] || gJoysticks.player1.x > 0) && idPlayer == 1)
		{
			moveRight();
		}
		if ((gTeclado.segurando[TECLA_ESQ] || gJoysticks.player1.x < 0) && idPlayer == 1)
		{
			moveLeft();
		}
		if ((gTeclado.segurando[TECLA_CIMA] || gJoysticks.player1.y < 0) && idPlayer == 1)
		{
			moveUp();
		}
		if ((gTeclado.segurando[TECLA_BAIXO] || gJoysticks.player1.y > 0) && idPlayer == 1)
		{
			moveDown();
		}

		/*

		// Player 2

		if ((gTeclado.segurando[TECLA_D] || gJoysticks.player2.x > 0) && idPlayer == 2)
		{
			if (playerX < gJanela.getLargura() - playerSprite.getLargura() / 2)
			{
				playerX += playerSpeed + 1;
			}

			movimentPlayer = mRight;
		}
		if ((gTeclado.segurando[TECLA_A] || gJoysticks.player2.x < 0) && idPlayer == 2)
		{
			if (playerX > playerSprite.getLargura() / 2)
			{
				playerX -= playerSpeed;
			}

			movimentPlayer = mLeft;
		}
		if ((gTeclado.segurando[TECLA_W] || gJoysticks.player2.y < 0) && idPlayer == 2)
		{
			if (playerY > 0)
			{
				playerY -= playerSpeed + 1;
			}

			movimentPlayer = mUp;
		}
		if ((gTeclado.segurando[TECLA_S] || gJoysticks.player2.y > 0) && idPlayer == 2)
		{
			if (playerY < gJanela.getAltura() - 150)
			{
				playerY += playerSpeed;
			}

			movimentPlayer = mDown;
		}

		// Player 3

		if ((gTeclado.segurando[TECLA_L] || gJoysticks.player3.x > 0) && idPlayer == 3)
		{
			if (playerX < gJanela.getLargura() - playerSprite.getLargura() / 2)
			{
				playerX += playerSpeed + 1;
			}

			movimentPlayer = mRight;
		}
		if ((gTeclado.segurando[TECLA_J] || gJoysticks.player3.x < 0) && idPlayer == 3)
		{
			if (playerX > playerSprite.getLargura() / 2)
			{
				playerX -= playerSpeed;
			}

			movimentPlayer = mLeft;
		}
		if ((gTeclado.segurando[TECLA_I] || gJoysticks.player3.y < 0) && idPlayer == 3)
		{
			if (playerY > 0)
			{
				playerY -= playerSpeed + 1;
			}

			movimentPlayer = mUp;
		}
		if ((gTeclado.segurando[TECLA_K] || gJoysticks.player3.y > 0) && idPlayer == 3)
		{
			if (playerY < gJanela.getAltura() - 150)
			{
				playerY += playerSpeed;
			}

			movimentPlayer = mDown;
		}

		// Player 4

		if ((gTeclado.segurando[TECLA_H] || gJoysticks.player4.x > 0) && idPlayer == 4)
		{
			if (playerX < gJanela.getLargura() - playerSprite.getLargura() / 2)
			{
				playerX += playerSpeed + 1;
			}

			movimentPlayer = mRight;
		}
		if ((gTeclado.segurando[TECLA_F] || gJoysticks.player4.x < 0) && idPlayer == 4)
		{
			if (playerX > playerSprite.getLargura() / 2)
			{
				playerX -= playerSpeed;
			}

			movimentPlayer = mLeft;
		}
		if ((gTeclado.segurando[TECLA_T] || gJoysticks.player4.y < 0) && idPlayer == 4)
		{
			if (playerY > 0)
			{
				playerY -= playerSpeed + 1;
			}

			movimentPlayer = mUp;
		}
		if ((gTeclado.segurando[TECLA_G] || gJoysticks.player4.y > 0) && idPlayer == 4)
		{
			if (playerY < gJanela.getAltura() - 150)
			{
				playerY += playerSpeed;
			}

			movimentPlayer = mDown;
		}
		*/

		if (getMovimentChar() != mIdle) //define sprite de movimento
		{
			setSpriteSheet(character, getCharacter(idPlayer) + "_move");

			if (dash) //define sprite de dash
			{
				setSpriteSheet(character, getCharacter(idPlayer) + "_dash");
			}
			playerSprite.setAnimacao(movimentPlayer);
			animate();
		}
		if (getMovimentChar() == mIdle)
		{
			setSpriteSheet(character, getCharacter(idPlayer) + "_idle");
			animate();
			playerSprite.setVelocidadeAnimacao(2);
		}
	}

	// Se morrer
	if (lifePointsPlayer <= 0 && idPlayer == character) //define sprite de dead
	{
		move = false;
		hit = false;

		setSpriteSheet(character, getCharacter(idPlayer) + "_dead");
		
		playerSprite.setVelocidadeAnimacao(5);
		animate();

		if (playerSprite.terminouAnimacao())
		{
			playerSprite.terminouAnimacao();
			vivo = false;
		}
	}

	// Se hitado

	if (hit && vivo) //define sprite de hit
	{
		setSpriteSheet(character, getCharacter(idPlayer) + "_hit");

		playerSprite.setVelocidadeAnimacao(5);
		animate();

		moveLeft(); // recuo dado pela batida

		if (playerSprite.terminouAnimacao())
		{
			hit = false;
			move = true;
		}
	}

	// Se usando habilidade DASH

	if (specialPointsPlayer > 0 && character)
	{
		switch (character)
		{
		case atraente:
			if (specialPointsPlayer > 0 && (gTeclado.segurando[TECLA_SHIFT_DIR] || gJoysticks.player1.segurando[BOTAO_JOYSTICK_RB]))
			{
				dash = true;
				if (dash && (gTeclado.pressionou[TECLA_SHIFT_DIR] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_RB]))
				{
					playerSpeed += 4;
					specialPointsPlayer--;
				}
			}
			if (specialPointsPlayer <= 0 || (gTeclado.soltou[TECLA_SHIFT_DIR] || gJoysticks.player1.soltou[BOTAO_JOYSTICK_RB]))
			{
				dash = false;
				playerSpeed -= 4;
			}
			break;



		case vital:
			if (specialPointsPlayer > 0 && (gTeclado.segurando[TECLA_SHIFT_ESQ] || gJoysticks.player2.segurando[BOTAO_JOYSTICK_RB]))
			{
				dash = true;
				if (dash && (gTeclado.pressionou[TECLA_SHIFT_ESQ] || gJoysticks.player2.pressionou[BOTAO_JOYSTICK_RB]))
				{
					playerSpeed += 4;
					specialPointsPlayer--;
				}
			}
			if (specialPointsPlayer <= 0 || (gTeclado.soltou[TECLA_SHIFT_ESQ] || gJoysticks.player2.soltou[BOTAO_JOYSTICK_RB]))
			{
				dash = false;
				playerSpeed -= 4;
			}
			break;



		case espectro:
			if (specialPointsPlayer > 0 && (gTeclado.segurando[TECLA_ESPACO] || gJoysticks.player3.segurando[BOTAO_JOYSTICK_RB]))
			{
				dash = true;
				if (dash && (gTeclado.pressionou[TECLA_ESPACO] || gJoysticks.player3.pressionou[BOTAO_JOYSTICK_RB]))
				{
					playerSpeed += 4;
					specialPointsPlayer--;
				}
			}
			if (specialPointsPlayer <= 0 || (gTeclado.soltou[TECLA_ESPACO] || gJoysticks.player3.soltou[BOTAO_JOYSTICK_RB]))
			{
				dash = false;
				playerSpeed -= 4;
			}
			break;



		case temporal:
			if (specialPointsPlayer > 0 && (gTeclado.segurando[TECLA_M] || gJoysticks.player4.segurando[BOTAO_JOYSTICK_RB]))
			{
				dash = true;
				if (dash && (gTeclado.pressionou[TECLA_M] || gJoysticks.player4.pressionou[BOTAO_JOYSTICK_RB]))
				{
					playerSpeed += 4;
					specialPointsPlayer--;
				}
			}
			if (specialPointsPlayer <= 0 || (gTeclado.soltou[TECLA_M] || gJoysticks.player4.soltou[BOTAO_JOYSTICK_RB]))
			{
				dash = false;
				playerSpeed -= 4;
			}
			break;
		}

	}


	// Se usando habilidade individual 

	if (specialPointsPlayer == 30 && (gTeclado.pressionou[TECLA_CTRL_DIR] || gJoysticks.player1.pressionou[BOTAO_JOYSTICK_B]))
	{
		specialPointsPlayer -= 30;
	}



	// Definindo special e life points para 0 quando < 0

	if (specialPointsPlayer < 0)
	{
		specialPointsPlayer = 0;
	}
	if (lifePointsPlayer < 0)
	{
		lifePointsPlayer = 0;
	}

	// Se usando item
	if (usingItem == true)
	{
		testActionTimeOfItem();
	}

}


bool Personagem::testColision(Item item)
{
	if (vivo);
	{
		if (invisible)
		{
			colisao = false;
		}

		if (!invisible)
		{
			if (itemInAciton == magnetRing)
			{
				magnetic = uniTestarColisao(*playerFxSprite, playerX + 300, playerY + 300, 0, item.getSprite(), item.getX(), item.getY(), 0);

				if(magnetic == true)
				{
					item.setMagnetized(true);
					item.setPositionFinal(playerX, playerY);
				}
				if (magnetic == false)
				{
					item.setMagnetized(false);
				}
			}
			
			colisao = uniTestarColisao(playerSprite, playerX, playerY, 0, item.getSprite(), item.getX(), item.getY(), 0);
		}

		if (colisao)
		{
			//item
			switch (item.getTipoItem())
			{
			case disc:
				scorePlayer += 10;
				break;
			case lifePill:
				lifePointsPlayer += 1;
				if (lifePointsPlayer >= 30)
				{
					lifePointsPlayer = 30;
				}
				break;
			case specialPill:
				specialPointsPlayer += 1;
				if (specialPointsPlayer >= 30)
				{
					specialPointsPlayer = 30;
				}
				break;
			case multiPill:
				lifePointsPlayer += rand() % 10 + 1;
				specialPointsPlayer += rand() % 5 + 1;
				if (lifePointsPlayer >= 30)
				{
					lifePointsPlayer = 30;
				}
				if (specialPointsPlayer >= 30)
				{
					specialPointsPlayer = 30;
				}
				break;
			case goldPill:
				lifePointsPlayer += (rand() % 30 + 1) + 20;
				specialPointsPlayer += (rand() % 30 + 1) + 10;
				if (lifePointsPlayer >= 30)
				{
					lifePointsPlayer = 30;
				}
				if (specialPointsPlayer >= 30)
				{
					specialPointsPlayer = 30;
				}
				break;
			case speedBoots:
				if (usingItem == false)
				{
					playerSpeed += 2;
					itemInAciton = speedBoots;
					setActionTimeOfItem(10);
				}
				break;
			case shadowCloak:
				if (usingItem == false)
				{
					invisible = true;
					itemInAciton = shadowCloak;
					setActionTimeOfItem(5);
					playerSprite.setCorAlpha(150);
				}
				break;
			case magnetRing:
				if (usingItem == false)
				{
					playerFxSprite = new Sprite;
					playerFxSprite->setSpriteSheet("magnetic_ring");
					playerFxSprite->setEscala(0.7, 0.7);
					itemInAciton = magnetRing;
					setActionTimeOfItem(7);
				}
				break;
			}

			//inimigos
			switch (item.getTipoInimigo())
			{
			case robotBomb:
				lifePointsPlayer -= 5;
				hit = true;
				move = false;
			default:
				break;
			}

			//robo
			switch (item.getTipoRobo())
			{
			case noneRobo:
				// bool considerando true
				break;
			case helmetRobo:
				// bool considerando true
				break;
			case armorRobo:
				// bool considerando true
				break;
			case legRobo:
				// bool considerando true
				break;
			case handRobo:
				// bool considerando true
				break;
			default:
				break;
			}
		}
	}
	if (!vivo)
	{
		colisao = false;
	}

	return colisao;
}

bool Personagem::testMagneticArea()
{
	

	return false;
}

void Personagem::setPosition(int playerX, int playerY)
{
	this->playerX = playerX;
	this->playerY = playerY;
}

void Personagem::setPlayerSpeed(int playerSpeed)
{
	this->playerSpeed = playerSpeed;
}

void Personagem::setSpriteSheet(Character personagem, string spritesheet)
{
	playerSprite.setSpriteSheet(spritesheet);
}

void Personagem::setActionTimeOfItem(int timeActionItem)
{
	this->timeActionItem = timeActionItem;
	timerStart = gTempo.getTicks();
	usingItem = true;
}

bool Personagem::testActionTimeOfItem()
{
	if (usingItem == true)
	{
		time = gTempo.getTempoAteTickAtual(timerStart);
	}
	if (time >= timeActionItem && usingItem == true)
	{
		switch (itemInAciton)
		{
		case noneItem:
			break;
		case disc:
			break;
		case lifePill:
			break;
		case specialPill:
			break;
		case multiPill:
			break;
		case goldPill:
			break;
		case speedBoots:
			playerSpeed -= 2;
			break;
		case shadowCloak:
			invisible = false;
			playerSprite.setCorAlpha(255);
			break;
		case magnetRing:
			delete playerFxSprite;
			break;
		case opticalShield:
			break;
		default:
			break;
		}

		itemInAciton = noneItem;
		timeActionItem = 0;
		time = 0;
		return usingItem = false;
	}
}

void Personagem::animate()
{
	playerSprite.avancarAnimacao();
}

void Personagem::desenhar()
{
	if (vivo)
	{
		if (itemInAciton == magnetRing)
		{
			playerFxSprite->desenhar(playerX, playerY);
		}

		playerSprite.desenhar(playerX, playerY);

	}
}
