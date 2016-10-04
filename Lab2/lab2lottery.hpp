/*
 * lab2lottery.hpp
 *
 *  Created on: Sep 29, 2016
 *      Author: Ryan
 */

#ifndef LAB2LOTTERY_HPP_
#define LAB2LOTTERY_HPP_

struct Customer {
	int custID;
	int tix; // keeps track of # of tix the customer purchased
	int **lotterynums;
};

struct Store {
	int storeID;
	int numCust; // # of customers who bought lottery tix
	int *custList;
	int numSold; // total # of tix sold
	int *numWinners;
};

struct Owner {
	int *stores;
	int numStores; // # of stores owner owns
	int totalSold; // total # of tix sold at all stores
	int *totalWinners;
};

Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners(int winners[]);
void findWinners(Owner *owner, int *ls);
int checkWin(int *nums, int *winners);


#endif /* LAB2LOTTERY_HPP_ */
