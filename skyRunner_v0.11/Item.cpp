#include "Item.h"
#include <ctime>


Item::Item()
{
}

Item::~Item()
{
}



void Item::inicializar()
{
	//carregamento de imagens

	//items

	if (!gRecursos.carregouSpriteSheet("disc_score"))
	{
		gRecursos.carregarSpriteSheet("disc_score", "assets/image/obj/00_disc_score.png");
	}
	if (!gRecursos.carregouSpriteSheet("life_pill"))
	{
		gRecursos.carregarSpriteSheet("life_pill", "assets/image/obj/01_life_pill.png");
	}
	if (!gRecursos.carregouSpriteSheet("special_pill"))
	{
		gRecursos.carregarSpriteSheet("special_pill", "assets/image/obj/02_special_pill.png");
	}
	if (!gRecursos.carregouSpriteSheet("multi_pill"))
	{
		gRecursos.carregarSpriteSheet("multi_pill", "assets/image/obj/03_multi_pill.png");
	}
	if (!gRecursos.carregouSpriteSheet("gold_pill"))
	{
		gRecursos.carregarSpriteSheet("gold_pill", "assets/image/obj/04_gold_pill.png");
	}
	if (!gRecursos.carregouSpriteSheet("speed_boots"))
	{
		gRecursos.carregarSpriteSheet("speed_boots", "assets/image/obj/05_speed_boots.png");
	}
	if (!gRecursos.carregouSpriteSheet("shadow_cloak"))
	{
		gRecursos.carregarSpriteSheet("shadow_cloak", "assets/image/obj/06_shadow_cloak.png");
	}
	if (!gRecursos.carregouSpriteSheet("magnet_ring"))
	{
		gRecursos.carregarSpriteSheet("magnet_ring", "assets/image/obj/07_magnet_ring.png");
	}
	if (!gRecursos.carregouSpriteSheet("optical_shield"))
	{
		gRecursos.carregarSpriteSheet("optical_shield", "assets/image/obj/08_optical_shield.png");
	}

	// partes do robo

	if (!gRecursos.carregouSpriteSheet("robot_armor"))
	{
		gRecursos.carregarSpriteSheet("robot_armor", "assets/image/obj/robot_armor.png");
	}
	if (!gRecursos.carregouSpriteSheet("robot_hand"))
	{
		gRecursos.carregarSpriteSheet("robot_hand", "assets/image/obj/robot_hand.png");
	}
	if (!gRecursos.carregouSpriteSheet("robot_leg"))
	{
		gRecursos.carregarSpriteSheet("robot_leg", "assets/image/obj/robot_leg.png");
	}
	if (!gRecursos.carregouSpriteSheet("robot_helmet"))
	{
		gRecursos.carregarSpriteSheet("robot_helmet", "assets/image/obj/robot_helmet.png");
	}


	//inimigos

	if (!gRecursos.carregouSpriteSheet("RobotBomb"))
	{
		gRecursos.carregarSpriteSheet("RobotBomb", "assets/image/obj/enemy_bomb.png");
	}



	if (!gRecursos.carregouAudio("pill_SE"))
	{
		gRecursos.carregarAudio("pill_SE", "assets/sounds/SE/pill_SE.ogg");
	}
	if (!gRecursos.carregouAudio("disc_SE"))
	{
		gRecursos.carregarAudio("disc_SE", "assets/sounds/SE/disc_SE.ogg");
	}
	if (!gRecursos.carregouAudio("bufferItem_SE"))
	{
		gRecursos.carregarAudio("bufferItem_SE", "assets/sounds/SE/bufferItem_SE.ogg");
	}
	if (!gRecursos.carregouAudio("robotParts_SE"))
	{
		gRecursos.carregarAudio("robotParts_SE", "assets/sounds/SE/robotParts_SE.ogg");
	}
	if (!gRecursos.carregouAudio("robotBomb_SE"))
	{
		gRecursos.carregarAudio("robotBomb_SE", "assets/sounds/SE/robotBomb_SE.mp3");
	}

	srand(time(0));

	resetar();

	som.setVolume(30.0f);

}

void Item::resetar()
{
	// Calculo de probabilidade de aparição

	//PROBABILIDADES: 

	// Comum 50%     --------------------------disc
	// Melhorado - Azul 20% -------------------life,special
	// Raro - 11% -----------------------------multi,speed
	// Épico - Verde 8% ----------------------- magnet,shadow
	// Lendário 3% ----------------------------gold, optical

	probability = (rand() % 100 + 1);

	if (probability >= 50 && probability <= 100) // comum
	{
		probability = rand() % 3 + 1;
		if (probability == 1)
		{
			item = disc;
			inimigo = noneInimigo;
		}
		else
		{
			item = noneItem;
			inimigo = robotBomb;
		}

		probability = 0;
	}
	if (probability >= 30 && probability < 50) // melhorado
	{
		probability = rand() % 3 + 1;
		if (probability == 1)
		{
			item = specialPill;
			inimigo = noneInimigo;
		}
		else
		{
			item = lifePill;
			inimigo = noneInimigo;
		}
		probability = 0;
	}
	if (probability >= 19 && probability < 30) // raro
	{
		probability = rand() % 3 + 1;
		if (probability == 1)
		{
			item = speedBoots;
			inimigo = noneInimigo;
		}
		else
		{
			item = shadowCloak;
			inimigo = noneInimigo;
		}
		probability = 0;
	}
	if (probability > 3 && probability <= 8) // épico
	{
		probability = rand() % 2 + 1;
		if (probability == 1)
		{
			item = goldPill;
			inimigo = noneInimigo;
		}
		else
		{
			item = magnetRing;
			inimigo = noneInimigo;
		}
		probability = 0;
	}
	if (probability > 0 && probability <= 3) // lendário
	{
		item = opticalShield;
		probability = 0;
	}

	// Definindo parâmetros do item

	switch (item)
	{
	case noneItem:
		break;
	case disc:
		sprite.setSpriteSheet("disc_score");
		sprite.avancarAnimacao();
		som.setAudio("disc_SE");
		break;
	case lifePill:
		sprite.setSpriteSheet("life_pill");
		sprite.avancarAnimacao();
		som.setAudio("pill_SE");
		break;
	case specialPill:
		sprite.setSpriteSheet("special_pill");
		sprite.avancarAnimacao();
		som.setAudio("pill_SE");
		break;
	case multiPill:
		sprite.setSpriteSheet("multi_pill");
		sprite.avancarAnimacao();
		som.setAudio("pill_SE");
		break;
	case goldPill:
		sprite.setSpriteSheet("gold_pill");
		sprite.avancarAnimacao();
		som.setAudio("pill_SE");
		break;
	case speedBoots:
		sprite.setSpriteSheet("speed_boots");
		sprite.avancarAnimacao();
		som.setAudio("bufferItem_SE");
		break;
	case shadowCloak:
		sprite.setSpriteSheet("shadow_cloak");
		sprite.avancarAnimacao();
		som.setAudio("bufferItem_SE");
		break;

	case magnetRing:
		sprite.setSpriteSheet("magnet_ring");
		sprite.avancarAnimacao();
		som.setAudio("bufferItem_SE");
		break;
	case opticalShield:
		sprite.setSpriteSheet("optical_shield");
		sprite.avancarAnimacao();
		som.setAudio("bufferItem_SE");
		break;
	default:
		break;
	}

	switch (inimigo)
	{
	case noneInimigo:
		break;
	case robotBomb:
		sprite.setSpriteSheet("RobotBomb");
		sprite.setEscala(1, 1);
		sprite.avancarAnimacao();
		som.setAudio("robotBomb_SE");
		break;
	default:
		break;
	}

	switch (parteRobo)
	{
	case noneRobo:
		break;
	case helmetRobo:
		sprite.setSpriteSheet("robot_helmet");
		sprite.setEscala(1, 1);
		sprite.avancarAnimacao();
		som.setAudio("robotParts_SE");
		break;
	case armorRobo:
		sprite.setSpriteSheet("robot_armor");
		sprite.setEscala(1, 1);
		sprite.avancarAnimacao();
		som.setAudio("robotParts_SE");
		break;
	case legRobo:
		sprite.setSpriteSheet("robot_leg");
		sprite.setEscala(0.5, 0.5);
		sprite.avancarAnimacao();
		som.setAudio("robotParts_SE");
		break;
	case handRobo:
		sprite.setSpriteSheet("robot_hand");
		sprite.setEscala(0.5, 0.5);
		sprite.avancarAnimacao();
		som.setAudio("robotParts_SE");
		break;
	default:
		break;
	}

	// Definindo posição de respawn

	x = gJanela.getLargura() * 1.5 + sprite.getLargura();
	y = rand() % 500 + sprite.getAltura();

	speed = (float)(rand() % 5 + 1);

	magnetized = false;
	position.set(x, y);
	positionStart = position;
	positionFinal = position;
	moveTime = 0;
	moveDuration = speed;


}

void Item::testarColisao(bool colisao)
{
	if (colisao)
	{
		som.tocar();
		resetar();
	}
	if (!colisao)
	{
		// nada acontece
	}

}

void Item::setMagnetized(bool magnetized)
{
	this->magnetized = magnetized;
}

void Item::setPositionFinal(float x, float y)
{
	positionFinal.x = x;
	positionFinal.y = y;
}

void Item::atualizar()
{
	// movimento do item

	if (item != noneItem && magnetized)
	{
		if (position != positionFinal)
		{
			moveTime += gTempo.getDeltaTempo();
			if (moveTime >= moveDuration)
			{
				moveTime = moveDuration;
			}

			position.x = uniEaseInOutQuad(moveTime, moveDuration, positionStart.x, positionFinal.x - positionStart.x);
			position.y = uniEaseLinear(moveTime, moveDuration, positionStart.y, positionFinal.y - positionStart.y);
		}
	}

	x -= speed;

	if (x < -(gJanela.getLargura() / 2 + sprite.getLargura()))
	{
		resetar();
	}
	//sprite.avancarAnimacao();
	//sprite.setVelocidadeAnimacao(3.0f);
}

void Item::desenhar()
{
	if (!(noneItem || noneInimigo || noneRobo))
	{
		sprite.desenhar(x, y);
	}


}
