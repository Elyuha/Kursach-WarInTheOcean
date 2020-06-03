#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Need_More_Control.h"

using namespace std;
using namespace sf;



RenderWindow window(VideoMode(1280, 720), "SFMLworks");


bool res = true;

int main()
{
	
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::TextEntered && event.text.unicode != 8) {
				if (put_in.size() < 6) {
					put_in += event.text.unicode;
				}
			}
			if (event.type == Event::KeyPressed) 
				if (event.key.code == Keyboard::Backspace)
					if (!put_in.empty())
						put_in.resize(put_in.size() - 1);
			if (event.key.code == Keyboard::Enter) {
				if (put_in == "reset") {
					NMC.reset();
				}
				if (put_in == "exit")
					window.close();
				if (put_in[0] > 40 && put_in[1] < 107) {

					if (NMC.get_pos() == 'd') {
						res = NMC.attack_enemy(put_in[1], put_in[0]);
					}
					if (NMC.get_pos() == 'c') {
						res = NMC.set_ship(put_in[1], put_in[0]);
					}
					if (NMC.get_pos() == 'b') {
						res = NMC.choise_ships(put_in[0]);
					}
				}
				put_in = "";
			}
			
		}


		
		window.display();
	}
	return 0;
}