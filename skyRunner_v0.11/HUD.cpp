#include "HUD.h"



HUD::HUD()
{
}


HUD::~HUD()
{
}


void HUD::inicializar(int idPlayer)
{
	this->idPlayer = idPlayer;

	if (!gRecursos.carregouSpriteSheet("HUD_atraente"))
	{
		gRecursos.carregarSpriteSheet("HUD_atraente", "assets/image/hud/hud_atraente.png");
	}
	if (!gRecursos.carregouSpriteSheet("HUD_atraente_sp"))
	{
		gRecursos.carregarSpriteSheet("HUD_atraente_sp", "assets/image/hud/hud_atraente_sp.png");
	}
	if (!gRecursos.carregouSpriteSheet("HUD_vital"))
	{
		gRecursos.carregarSpriteSheet("HUD_vital", "assets/image/hud/hud_vital.png");
	}
	if (!gRecursos.carregouSpriteSheet("HUD_vital_sp"))
	{
		gRecursos.carregarSpriteSheet("HUD_vital_sp", "assets/image/hud/hud_vital_sp.png");
	}
	if (!gRecursos.carregouSpriteSheet("HUD_espectro"))
	{
		gRecursos.carregarSpriteSheet("HUD_espectro", "assets/image/hud/hud_espectro.png");
	}
	if (!gRecursos.carregouSpriteSheet("HUD_espectro_sp"))
	{
		gRecursos.carregarSpriteSheet("HUD_espectro_sp", "assets/image/hud/hud_espectro_sp.png");
	}
	if (!gRecursos.carregouSpriteSheet("HUD_temporal"))
	{
		gRecursos.carregarSpriteSheet("HUD_temporal", "assets/image/hud/hud_temporal.png");
	}
	if (!gRecursos.carregouSpriteSheet("HUD_temporal_sp"))
	{
		gRecursos.carregarSpriteSheet("HUD_temporal_sp", "assets/image/hud/hud_temporal_sp.png");
	}

	if (idPlayer == 1)
	{
		hudSprite.setSpriteSheet("HUD_atraente");
		hudSprite.setEscala(1.5, 1.5);
		hudPlayerX = gJanela.getLargura() / 4 - hudSprite.getLargura();
		hudPlayerY = gJanela.getAltura() - hudSprite.getAltura() / 2;
	}
	if (idPlayer == 2)
	{
		hudSprite.setSpriteSheet("HUD_vital");
		hudSprite.setEscala(1.5, 1.5);
		hudPlayerX = gJanela.getLargura() / 4 * 2 - hudSprite.getLargura();
		hudPlayerY = gJanela.getAltura() - hudSprite.getAltura() / 2;
	}
	if (idPlayer == 3)
	{
		hudSprite.setSpriteSheet("HUD_espectro");
		hudSprite.setEscala(1.5, 1.5);
		hudPlayerX = gJanela.getLargura() / 4 * 3 - hudSprite.getLargura();
		hudPlayerY = gJanela.getAltura() - hudSprite.getAltura() / 2;
	}
	if (idPlayer == 4)
	{
		hudSprite.setSpriteSheet("HUD_temporal");
		hudSprite.setEscala(1.5, 1.5);
		hudPlayerX = gJanela.getLargura() / 4 * 4 - hudSprite.getLargura();
		hudPlayerY = gJanela.getAltura() - hudSprite.getAltura() / 2;
	}

	specialFull = 0;
}

void HUD::atualizar(bool specialFull, int idPlayer)
{
	this->idPlayer = idPlayer;

	// CASO SPECIAL BAR MAX

	if (idPlayer == 1)
	{
		if (specialFull)
		{
			hudSprite.setSpriteSheet("HUD_atraente_sp");
		}
		if (!specialFull)
		{
			hudSprite.setSpriteSheet("HUD_atraente");
		}
		hudSprite.setEscala(1.5, 1.5);
		hudPlayerX = gJanela.getLargura() / 4 - hudSprite.getLargura();
		hudPlayerY = gJanela.getAltura() - hudSprite.getAltura() / 2;
	}
	if (idPlayer == 2)
	{
		if (specialFull)
		{
			hudSprite.setSpriteSheet("HUD_vital_sp");
		}
		if (!specialFull)
		{
			hudSprite.setSpriteSheet("HUD_vital");
		}
		hudSprite.setEscala(1.5, 1.5);
		hudPlayerX = gJanela.getLargura() / 4 * 2 - hudSprite.getLargura();
		hudPlayerY = gJanela.getAltura() - hudSprite.getAltura() / 2;
	}
	if (idPlayer == 3)
	{
		if (specialFull)
		{
			hudSprite.setSpriteSheet("HUD_espectro_sp");
		}
		if (!specialFull)
		{
			hudSprite.setSpriteSheet("HUD_espectro");
		}
		hudSprite.setEscala(1.5, 1.5);
		hudPlayerX = gJanela.getLargura() / 4 * 3 - hudSprite.getLargura();
		hudPlayerY = gJanela.getAltura() - hudSprite.getAltura() / 2;
	}
	if (idPlayer == 4)
	{
		if (specialFull)
		{
			hudSprite.setSpriteSheet("HUD_temporal_sp");
		}
		if (!specialFull)
		{
			hudSprite.setSpriteSheet("HUD_temporal");
		}
		hudSprite.setEscala(1.5, 1.5);
		hudPlayerX = gJanela.getLargura() / 4 * 4 - hudSprite.getLargura();
		hudPlayerY = gJanela.getAltura() - hudSprite.getAltura() / 2;
	}
}

void HUD::desenhar()
{
	hudSprite.desenhar(hudPlayerX, hudPlayerY);
}
