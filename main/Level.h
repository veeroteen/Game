#pragma once
#include <string>
#include <vector>
#include "tinyxml2.h"
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>


struct Layer
{
	std::vector < std::vector <int>> tile_map;
	std::vector < std::vector <int>> obj_map;
	std::vector < std::vector <sf::Rect<int>>> wall_map;
	int opacity;
};

class Level
{
public:
	//std::vector<Layer> dimension;
	//Level();
	Layer dimension;
	void LoadMap(std::string s);


};

