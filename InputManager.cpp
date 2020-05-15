#include "InputManager.hpp"

namespace gui {
	bool InputManager::isSpriteClicked(sf::Sprite obj, sf::Mouse::Button button, 
			sf::RenderWindow& window) {
		if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect tempRect(obj.getPosition().x, obj.getPosition().y, 
					obj.getGlobalBounds().width, obj.getGlobalBounds().height);
			if (tempRect.contains(sf::Mouse::getPosition(window)))
				return true;
		}
		return false;
	}

	sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window) {
		return sf::Mouse::getPosition(window);
	}
}
