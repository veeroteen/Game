#pragma once
#include <SFML/Graphics.hpp>

class actor 
{
private:

	
	sf::Image Aimage;
	sf::Sprite Asprite;
	sf::Texture Atexture;
	int Hud[10] = {0,1,2,3,4,5,6,7,8,9};
	int CyrrenSlot;
public:
	sf::Vector2f Position;
	actor();

	bool Aleft, Aright, Afoward, Aback;

	float Speed;

	void MoveFoward();
	void MoveBack();
	void MoveLeft();
	void MoveRight();
	
	void StopFoward();
	void StopBack();
	void StopLeft();
	void StopRight();
	
	void update(float dt);

	//void SetSprite();
	sf::Sprite GetSprite();

	void SetSpriteRect(sf::Rect<int> set);

	sf::Vector2f GetActorPos();

	sf::Vector3f GetActorRX();
	sf::Vector3f GetActorLX();
	sf::Vector3f GetActorFY();
	sf::Vector3f GetActorBY();


};