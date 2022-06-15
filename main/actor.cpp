#include "actor.h"

actor::actor() 
{
	Position.x = 2000;
	Position.y = 2000;

	Atexture.loadFromFile("textures/creatures/test.png");

	Asprite.setTexture(Atexture);

	Asprite.setTextureRect(sf::Rect<int>(0, 0, 32, 64));


	Speed = 200;


}

void actor::MoveFoward()
{
	Afoward = true;
}
void actor::MoveBack()
{
	Aback = true;
}
void actor::MoveLeft()
{
	Aleft = true;
}
void actor::MoveRight()
{
	Aright = true;
}

void actor::StopFoward()
{
	Afoward = false;
}
void actor::StopBack()
{
	Aback = false;
}
void actor::StopLeft()
{
	Aleft = false;
}
void actor::StopRight()
{
	Aright = false;
}
sf::Sprite actor::GetSprite()
{
return Asprite;
}

void actor::update(float dt) 
{
	if (Afoward && !Aback)
	{
		Position.y -= Speed*dt;
	}


	if (Aback && !Afoward)
	{
		Position.y += Speed * dt;
	}

	if (Aleft && !Aright)
	{
		Position.x -= Speed * dt;
	}


	if (Aright && !Aleft)
	{
		Position.x += Speed * dt;
	}

	Asprite.setPosition(Position);
}

sf::Vector2f actor::GetActorPos() 
{
	return (Position);
}

void actor::SetSpriteRect(sf::Rect<int> set)
{
	Asprite.setTextureRect(set);
}

sf::Vector3f actor::GetActorRX() 
{
	sf::Vector3f ret;
	ret.x = Position.y + 38;
	ret.y = Position.y + 58;
	ret.z = Position.x + 32;
	return ret;
}


sf::Vector3f actor::GetActorLX()
{
	sf::Vector3f ret;
	ret.x = Position.y + 38;
	ret.y = Position.y + 58;
	ret.z = Position.x;
	return ret;
}
sf::Vector3f actor::GetActorFY()
{
	sf::Vector3f ret;
	ret.x = Position.x + 6;
	ret.y = Position.x + 25;
	ret.z = Position.y + 30;
	return ret;
}
sf::Vector3f actor::GetActorBY()
{
	sf::Vector3f ret;
	ret.x = Position.x + 6;
	ret.y = Position.x + 25;
	ret.z = Position.y + 65;
	return ret;
}