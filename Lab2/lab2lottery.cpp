/*
 * lab2lottery.cpp
 *
 *  Created on: Sep 29, 2016
 *      Author: Ryan
 */


#include "lab2lottery.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <stdio.h>
#include <algorithm>
using namespace std;



Owner *makeOwner() {
	srand (time(NULL));
	Owner x = new Owner;
	int num = rand() % 10 + 1;
	x.numStores = num;
	list<Store> storeList;
	int total = 0;
	for (int i = 0; i < num; i++) {
		Store s = makeStore();
		storeList.push_front(s);
		int n = s.numSold;
		total += n;
	}
	x.stores = &storeList;
	x.totalSold = total;
	return x;
}

Store makeStore() {
	Store x = new Store;
	int num = rand() % 100 + 1;
	x.storeID = num;
	int num2 = rand() % 10 + 1;
	x.numCust = num2;
	list<Customer> custList;
	int total = 0;
	for (int i = 0; i < num2; i++) {
		Customer c = makeCustomer();
		custList.push_front(c);
		int n = c.tix;
		total += n;
	}
	x.custList = &custList;
	x.numSold = total;
	return x;
}

Customer makeCustomer() {
	Customer x = new Customer;
	int num = rand() % 1000 + 1;
	x.custID = num;
	int num2 = rand() % 20;
	x.tix = num2;
	int arr [num2] [3];
	for (int i = 0; i < num2; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				int n = rand() % 9;
				arr[i][j] = n;
			} else if (j == 1) {
				int n = rand() % 9;
				if (n == arr[i][j - 1]) {
					if (n == 9) {
						n -= 1;
					} else {
						n += 1;
					}
				}
				arr[i][j] = n;
			} else {
				int n = rand() % 9;
				if (n == arr[i][j - 1]) {
					if (n == 9) {
						n -= 1;
					} else {
						n += 1;
					}
				}
				if (n == arr[i][j - 2]) {
					if (n == 9) {
						n -= 1;
					} else {
						n += 1;
					}
				}
				arr[i][j] = n;
			}
		}
	}
	x.lotterynums = arr;
	return x;
}

void getWinners(int winners[]) {
	winners[0] = rand() % 9;
	winners[1] = rand() % 9;
	winners[2] = rand() % 9;
}

int checkWin(int *nums, int *winners) {
	int total = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (nums[i] == winners[j]) {
				total += 1;
			}
		}
	}
	return total;
}

void findWinners(Owner *owner, int *ls) {
	cout << "Total lottery tickets sold: " << owner->totalSold << endl;
	cout << "Winning numbers: ";
	for (int h = 0; h < 3; h++) {
		cout << ls[h];
	}
	cout << endl;
	int totalWins = 0;
	int total1Wins = 0;
	int total2Wins = 0;
	int total3Wins = 0;
	for (int i = 0; i < owner->numStores; i++) {
		Store s = owner->stores[i];
		int storeWins = 0;
		int store1Wins = 0;
		int store2Wins = 0;
		int store3Wins = 0;
		cout << "store: " << s.storeID;
		for (int j = 0; j < s.numCust; j++) {
			Customer c = s.custList[j];
			int tickets = c.lotterynums;
			cout << "/t customer: " << c.custID << endl;
			for (int k = 0; k < c.tix; k++) {
				int thisTicket[];
				thisTicket[0] = tickets[k][0];
				thisTicket[1] = tickets[k][1];
				thisTicket[2] = tickets[k][2];
				for (int l = 0; l < 3; l++) {
					int matches = checkWin(thisTicket, ls);
					if (matches > 0) {
						totalWins += 1;
						storeWins += 1;
						cout << "/t ticket:/t";
						for (int m = 0; m < 3; m++) {
							cout << thisTicket[m];
						}
						cout << " matched   ";
						if (matches == 1) {
							total1Wins += 1;
							store1Wins +=1;
							cout << "1" << endl;
						} else if (matches == 2) {
							total2Wins += 1;
							store2Wins += 1;
							cout << "2" << endl;
						} else if (matches == 3) {
							total3Wins += 1;
							store3Wins += 1;
							cout << "3" << endl;
						}
					}
				}
			}
		}
		cout << "/t Total count for store " << s.storeID << ": ";
		cout << store1Wins << " ";
		cout << store2Wins << " ";
		cout << store3Wins << endl;
		s.numWinners[0] = store1Wins;
		s.numWinners[1] = store2Wins;
		s.numWinners[2] = store3Wins;
	}
	cout << "won with 1 number: " << total1Wins << endl;
	cout << "won with 2 numbers: " << total2Wins << endl;
	cout << "won with 3 numbers: " << total3Wins << endl;
	owner->totalWinners[0] = total1Wins;
	owner->totalWinners[1] = total2Wins;
	owner->totalWinners[2] = total3Wins;
}

