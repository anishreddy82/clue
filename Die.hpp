#pragma once


class Die {
private:
	int max_number;
	int current_number;
public:
	Die() {};
	Die(int maxCount);
	int getCurrentNumber();
	void roll();
	void decrement();
};