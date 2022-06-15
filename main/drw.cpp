#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"


void Engine::drwTile() {




	for (int i = 0; i < MapY; i++) {
		for (int n = 0; n < MapX; n++)
		{
			
			if (level.dimension.tile_map[(int(ACPos.y) / 32) - 9 + i][(int(ACPos.x) / 32) - 16 + n] == 0)MapSprite.setTextureRect(sf::Rect<int>(32, 0, 32, 32));
			else if (level.dimension.tile_map[(int(ACPos.y) / 32) - 9 + i][(int(ACPos.x) / 32) - 16 + n] == 1)MapSprite.setTextureRect(sf::Rect<int>(32, 0, 32, 32));
			else if (level.dimension.tile_map[(int(ACPos.y) / 32) - 9 + i][(int(ACPos.x) / 32) - 16 + n] == 2)MapSprite.setTextureRect(sf::Rect<int>(64, 0, 32, 32));
			else if (level.dimension.tile_map[(int(ACPos.y) / 32) - 9 + i][(int(ACPos.x) / 32) - 16 + n] == 3)MapSprite.setTextureRect(sf::Rect<int>(96, 0, 32, 32));
			else if (level.dimension.tile_map[(int(ACPos.y) / 32) - 9 + i][(int(ACPos.x) / 32) - 16 + n] == ' ')MapSprite.setColor(sf::Color::White);
			
				MapSprite.setPosition(((int(ACPos.x) / 32) - 16 + n) * 32, (int((ACPos.y) / 32) - 9 + i) * 32);
			window.draw(MapSprite);
		}
	}
};

void Engine::drwObject()
{

	for (int i = 0; i < MapY; i++) {
		for (int n = 0; n < MapX; n++)
		{

			
			if (level.dimension.obj_map[(int(ACPos.y) / 32) - 9 + i][(int(ACPos.x) / 32) - 16 + n] != 0)
			{
				Objspr.setPosition(((int(ACPos.x) / 32) - 16 + n) * 32, (int((ACPos.y) / 32) - 9 + i) * 32);
				window.draw(Objspr);
			}
			
			if (i== 7 && n == 0)
			{
			window.draw(actor.GetSprite());
			}

				
			
		}
	}




}




void Engine::drw()
{
    window.clear(sf::Color::White);
    
    drwTile();
	drwObject();

	

   
    window.display();


}