///*
// * lab2main.cpp
// *
// *  Created on: Oct 4, 2016
// *
// */
//
//

//Ryan Gray
//Brian Turnbull

#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "lab2lottery.hpp"
using namespace std;

int main() {
	srand(time(NULL));
	Owner *me = makeOwner();
	int winners[3] = {0, 0, 0};
	getWinners(winners);
	for (int i = 0; i < 3; i++) {
		cout << winners[i] << "/n";
	} // for
	findWinners(me, winners);
	cout << "won with 1 number: " << me->totalWinners[0] << "/n";
	cout << "won with 2 numbers: " << me->totalWinners[1] << "/n";
	cout << "won with 3 numbers: " << me->totalWinners[2] << "/n";
	return 0;
}



