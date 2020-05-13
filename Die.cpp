#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Die.hpp"

Die::Die(int maxNumberIn) {
	max_number = maxNumberIn;
}

int Die::getCurrentNumber() {
	return current_number;
}

void Die::decrement() {
	current_number--;
}

void Die::roll() {
	srand(time(NULL));
	current_number = rand() % max_number + 1;
}