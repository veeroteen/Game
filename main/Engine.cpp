#include "Engine.h"
Engine::Engine()
{
	MapTexture.loadFromFile("textures/static/tilemap.png");
	MapSprite.setTexture(MapTexture);
	Objtext.loadFromFile("textures/static/tree.png");
	Objspr.setTexture(Objtext);
	Objspr.setTextureRect(sf::Rect<int>(0, 0, 100, 128));
	window.create(sf::VideoMode(1920, 1080), "Gametest");
	view.reset(sf::FloatRect(0, 0, 1920, 1080));
	
	
	Objects bb;
	bb.link = "textures/static/tree.png";
	bb.Name = "Tree";
	bb.solid = 100;
	objid.push_back(bb);
	


}

void Engine::start() {

	level.LoadMap("SS.xml");


	sf::Clock clock;
	sf::Time dt;
	
	

	while (window.isOpen())
	{
		if (window.hasFocus()) {

			dt = clock.restart();
			actor.update(dt.asSeconds());
			window.setView(ForeGoing(actor.GetActorPos()));
			input();
			drw();
			std::cout << actor.Position.x << ' ' << actor.Position.y << std::endl;
		}
	}
}

bool Engine::WallCheck(int i) 
{
	// 1 Right 2 Foward 3 Left 4 Back

	bool ret;

	switch (i) {
	case 1: {


		ret = !(wmap[(actor.Position.x+26)/32][(actor.Position.y+ 26)/32].intersects({ int(actor.Position.x + 26), int(actor.Position.y+34),5,24 })) &&
			!(wmap[(actor.Position.x + 26)/32][(actor.Position.y + 60)/32].intersects({ int(actor.Position.x + 26), int(actor.Position.y + 34),5,24 }));


		return ret;
		break;


	}
	case 2: {

		ret = !(wmap[(actor.Position.x +2) / 32][(actor.Position.y + 1) / 32].intersects({ int(actor.Position.x + 4), int(actor.Position.y + 28),24,5 })) &&
			!(wmap[(actor.Position.x + 26) / 32][(actor.Position.y + 1) / 32].intersects({ int(actor.Position.x + 4), int(actor.Position.y + 28),24,5 }));

		return ret;
		break;

	}
	case  3: {

		ret = !(wmap[(actor.Position.x + 2) / 32][(actor.Position.y + 26) / 32].intersects({ int(actor.Position.x + 2), int(actor.Position.y + 34),5,24 })) &&
			!(wmap[(actor.Position.x + 2) / 32][(actor.Position.y + 60) / 32].intersects({ int(actor.Position.x + 2), int(actor.Position.y + 34),5,24 }));


		return ret;
		break;

	}
	case 4: {

		ret = !(wmap[(actor.Position.x + 2) / 32][(actor.Position.y + 60) / 32].intersects({ int(actor.Position.x + 4), int(actor.Position.y + 59),24,5 })) &&
			!(wmap[(actor.Position.x + 28) / 32][(actor.Position.y + 60) / 32].intersects({ int(actor.Position.x + 4), int(actor.Position.y + 59),24,5 }));
		return ret;
		break;

	}
	}




}