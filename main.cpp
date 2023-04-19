// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
//test
// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;
int main()
{
	sf::View view(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));
	// Create a video mode object
	//VideoMode vm(1920, 1080);
	VideoMode vm(800, 600);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!", Style::Default);

	vector<Vector2f> vertices;

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					Vector2i pixelPos = { event.mouseButton.x, event.mouseButton.y };
					Vector2f worldPos = window.mapPixelToCoords(pixelPos, view);
					vertices.push_back(worldPos);

					//vertices.push_back(Vector2f((float)event.mouseButton.x,
					//	(float)event.mouseButton.y));
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update the scene
		****************************************
		*/
		// Measure time
		//Time dt = clock.restart();

		// Update the text
		//std::stringstream ss;
		//ss << "Score = " << score;
		//scoreText.setString(ss.str());

		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.setView(view);
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		
		RectangleShape shape{ Vector2f{4,4} };
		shape.setFillColor(Color::Cyan);
		for (size_t i = 0; i < vertices.size(); i++)
		{
			shape.setPosition(vertices.at(i));
			window.draw(shape);
		}
		//window.draw();
		// Show everything we just drew
		window.display();
	}

	return 0;
}