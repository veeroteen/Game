#include "Engine.h"
using namespace sf;

void Engine::input() 
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}
	
	
	if (Keyboard::isKeyPressed(Keyboard::W) && WallCheck(2))//Foward
	{
		actor.MoveFoward();
	}
	else
	{
		actor.StopFoward();
	}
	
	if (Keyboard::isKeyPressed(Keyboard::S) && WallCheck(4))//Back
	{
		actor.MoveBack();
	}
	else
	{
		actor.StopBack();
	}

	if (Keyboard::isKeyPressed(Keyboard::A) && WallCheck(3))//Left
	{
		
		actor.MoveLeft();


	}
	else
	{
		actor.StopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::D) && WallCheck(1))//Right
	{
		
		actor.MoveRight();

		

	}
	else
	{
		actor.StopRight();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num1)) {
	
	
	}

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		level.dimension.tile_map[int(MouseTile().y)][int(MouseTile().x)] = 1;


	}
}

sf::Vector2f Engine::MouseTile() {
	MTile = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	MTile.x = int(MTile.x / 32);
	MTile.y = int(MTile.y / 32);
	return (MTile);
}