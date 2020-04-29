#include "Game.hpp"

Game::Game() {
	//colors begin at index 0
	deck.emplace(deck.begin(), Card("white", 'c'));
	deck.emplace_back(Card("blue", 'c'));
	deck.emplace_back(Card("red", 'c'));
	deck.emplace_back(Card("brown", 'c'));
	deck.emplace_back(Card("green", 'c'));
	deck.emplace_back(Card("purple", 'c'));

	//weapons begin at index 6
	deck.emplace_back(Card("candlestick", 'w'));
	deck.emplace_back(Card("revolver", 'w'));
	deck.emplace_back(Card("rope", 'w'));
	deck.emplace_back(Card("wrench", 'w'));
	deck.emplace_back(Card("lead pipe", 'w'));
	deck.emplace_back(Card("knife", 'w'));

	//rooms begin at index 12
	deck.emplace_back(Card("study", 'r'));
	deck.emplace_back(Card("library", 'r'));
	deck.emplace_back(Card("conservatory", 'r'));
	deck.emplace_back(Card("hall", 'r'));
	deck.emplace_back(Card("kitchen", 'r'));
	deck.emplace_back(Card("ballroom", 'r'));
	deck.emplace_back(Card("lounge", 'r'));
	deck.emplace_back(Card("billiard room", 'r'));
}

void Game::givePlayerCard(vector<Card> &v) {
	int idx = rand() % deck.size();
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);
}

void Game::giveBoardCards(vector<Card> &v) {
	int idx = (rand() % ((deck.size() - 1) - 12 + 1) + 12);
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);

	idx = (rand() % (11 - 6 + 1) + 6);
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);

	idx = rand() % 6;
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);
}
