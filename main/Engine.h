#pragma once
#include <SFML/Graphics.hpp>
#include "actor.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include "tinyxml2.h"
#include "Level.h"
#include "Material.h"

class Engine
{
private:

	actor actor;
	const int MapY = 18;
	const int MapX = 32;
	sf::RenderWindow window;
	sf::Texture MapTexture;
	sf::Sprite MapSprite;
	sf::View view;
	sf::Vector2f MTile;
	sf::Vector2f& ACPos = actor.Position;
	sf::Texture Objtext;
	sf::Sprite Objspr;

public:
	bool WallCheck(int i);
	Level level;
	Engine();
	float count = 0.0;
	void input();
	void drw();
	void drwTile();
	void drwObject();
	void start();
	bool crossing();
	std::vector <std::vector <sf::Rect<int>>>& wmap = level.dimension.wall_map;
	sf::View ForeGoing(sf::Vector2f Apos) {
		view.setCenter(Apos.x+38 , Apos.y+38);
		return (view);
	}

	std::vector <Objects> objid;

	sf::Vector2f MouseTile();


	
};