#include "Level.h"
void Level::LoadMap(std::string s) {

	tinyxml2::XMLDocument lmap;
	tinyxml2::XMLNode* node ;
	tinyxml2::XMLElement *element, * list;
	std::vector <int> vbuff;
	std::vector <int> obuff;
	std::vector <sf::Rect<int>> wbuff;
	int traid;
	std::string str;
	


	lmap.LoadFile(s.c_str());
	node = lmap.FirstChildElement();
	//while (node != nullptr)
	list = node->FirstChildElement();
	element = list->FirstChildElement();
	
	for (int y = 0; y < 300; y++) {
		for (int x = 0; x < 300; x++) {
			if (node == nullptr) break;
			if (element == nullptr) break;
			traid = atoi(element->GetText());				
			vbuff.push_back(traid);
			//element->QueryIntAttribute("obj_id", &traid);
			obuff.push_back(0);
			element = element->NextSiblingElement();
			wbuff.push_back({ 2372,2072,32,32 });
		}
		dimension.wall_map.push_back(wbuff);
		dimension.tile_map.push_back(vbuff);
		dimension.obj_map.push_back(obuff);
		vbuff.clear();
		obuff.clear();
		wbuff.clear();

	}
	

		element = list->NextSiblingElement();

		
		dimension.opacity = 0;


		//node = Lmap.FirstChildElement();
	
		
}