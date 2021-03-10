#include "BarPoints.h"



BarPoints::BarPoints()
{
}


BarPoints::~BarPoints()
{
}

void BarPoints::inicializar(int idPlayer)
{
	this->idPlayer = idPlayer;

	if (!gRecursos.carregouSpriteSheet("HUD_barPoints"))
	{
		gRecursos.carregarSpriteSheet("HUD_barPoints", "assets/image/hud/hud_barPoints.png", 1, 6);
	}

	spriteBarPoints.setSpriteSheet("HUD_barPoints");
	spriteBarPoints.setEscala(1, 1.5);
}

void BarPoints::atualizar(int specialPlayer, int lifePlayer)
{
	specialPlayerPoints = specialPlayer;
	lifePlayerPoints = lifePlayer;
}

void BarPoints::desenhar()
{
	count = 0;

	spriteBarPoints.setFrame(0);
	for (int bar = 0; bar < specialPlayerPoints; bar++)
	{
		x = gJanela.getLargura() / 4 * idPlayer - 179 + count;
		y = gJanela.getAltura() - 22;
		spriteBarPoints.desenhar(x, y);
		count += 3;
	}

	for (int p = 0; p <= 4; p++)
	{
		if (idPlayer == p)
		{
			count = 0;

			spriteBarPoints.setFrame(p);
			for (int bar = 0; bar < lifePlayerPoints; bar++)
			{
				x = gJanela.getLargura() / 4 * idPlayer - 179 + count;
				y = gJanela.getAltura() - 45;
				spriteBarPoints.desenhar(x, y);
				count += 3;
			}
		}
	}
	
}