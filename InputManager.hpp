#pragma once

#include <SFML/Graphics.hpp>

namespace gui {
	class InputManager {
		public:
			InputManager() {}
			~InputManager() {}

			bool isSpriteClicked(sf::Sprite obj, sf::Mouse::Button button, 
					sf::RenderWindow& window);
			sf::Vector2i getMousePosition(sf::RenderWindow& window);
	};
}
