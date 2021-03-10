#include "Objeto.h"

Objeto::Objeto()
{
}


Objeto::~Objeto()
{
}

void Objeto::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("Clouds_1"))
	{
		gRecursos.carregarSpriteSheet("Clouds_1", "assets/image/obj/clouds_1.png");
	}
	if (!gRecursos.carregouSpriteSheet("Clouds_2"))
	{
		gRecursos.carregarSpriteSheet("Clouds_2", "assets/image/obj/clouds_2.png");
	}
	if (!gRecursos.carregouSpriteSheet("Clouds_3"))
	{
		gRecursos.carregarSpriteSheet("Clouds_3", "assets/image/obj/clouds_3.png");
	}
	if (!gRecursos.carregouSpriteSheet("Clouds_4"))
	{
		gRecursos.carregarSpriteSheet("Clouds_4", "assets/image/obj/clouds_4.png");
	}

	resetar();

}

void Objeto::resetar()
{
	obj = (TipoObj)(rand() % 4);
	corAlpha = rand() % 50 + 25;
	objScale = (rand() % 4) / 2.0f;

	switch (obj)
	{
	case cloud_1:
		clouds.setSpriteSheet("Clouds_1");
		clouds.setCorAlpha(corAlpha);
		clouds.setEscala(objScale, objScale);
		break;
	case cloud_2:
		clouds.setSpriteSheet("Clouds_2");
		clouds.setCorAlpha(corAlpha);
		clouds.setEscala(objScale, objScale);
		break;
	case cloud_3:
		clouds.setSpriteSheet("Clouds_3");
		clouds.setCorAlpha(corAlpha);
		clouds.setEscala(objScale, objScale);
		break;
	case cloud_4:
		clouds.setSpriteSheet("Clouds_4");
		clouds.setCorAlpha(corAlpha);
		clouds.setEscala(objScale, objScale);
		break;
	default:
		break;
	}
	objX = gJanela.getLargura() * 1.5 + clouds.getLargura();
	objY = rand() % 500 + clouds.getAltura();
	objSpeed = (float)(rand() % 3 + 1);
}

void Objeto::atualizar()
{
	objX -= objSpeed;
	if (objX < -(gJanela.getLargura() / 2 + clouds.getLargura()))
	{
		resetar();
	}
	clouds.avancarAnimacao();
}

void Objeto::desenhar()
{

	clouds.desenhar(objX, objY);

}


