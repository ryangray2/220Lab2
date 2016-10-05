///*
// * lab2lottery.cpp
// *
// *  Created on: Sep 29, 2016
// *
// */
//
//

//Ryan Gray
//Brian Turnbull

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
	Owner *x;
	int num = rand() % 10 + 1;
	x->numStores = num;
	Store storeList[num];
	int total = 0;
	for (int i = 0; i < num; i++) {
		Store s = makeStore();
		storeList[i] = s;
		int n = s.numSold;
		total += n;
	} // for i
	x->stores = storeList;
	x->totalSold = total;
	return x;
} // makeOwner

Store makeStore() {
	Store x;
	int num = rand() % 100 + 1;
	x.storeID = num;
	int num2 = rand() % 10 + 1;
	x.numCust = num2;
	Customer custList[num2];
	int total = 0;
	for (int i = 0; i < num2; i++) {
		Customer c = makeCustomer();
		custList[i] = c;
		int n = c.tix;
		total += n;
	} // for i
	x.custList = custList;
	x.numSold = total;
	return x;
} // makeStore

Customer makeCustomer() {
	Customer x;
	int num = rand() % 1000 + 1;
	x.custID = num;
	int num2 = rand() % 20;
	x.tix = num2;
	int ** arr;

	for (int i = 0; i < num2; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				int n = rand() % 9;
				arr[i][j] = n;
			} // if j == 0
			else if (j == 1) {
				int n = rand() % 9;
				if (n == arr[i][j - 1]) {
					if (n == 9) {
						n -= 1;
					} // if n == 9
					else {
						n += 1;
					} // else
				} // n == arr[i][j-1]
				arr[i][j] = n;
			} // else if j == 1
			else {
				int n = rand() % 9;
				if (n == arr[i][j - 1]) {
					if (n == 9) {
						n -= 1;
					} // if n == 9
					else {
						n += 1;
					} // else
				} // n == arr[i][j-1]
				if (n == arr[i][j - 2]) {
					if (n == 9) {
						n -= 1;
					} // if n == 9
					else {
						n += 1;
					} // else
				} // if n == arr[i][j-2]
				arr[i][j] = n;
			} // else
		} // for j
	} // for i
	x.lotterynums = arr;
	return x;
} // makeCustomer

void getWinners(int winners[]) {
	winners[0] = rand() % 9;
	winners[1] = rand() % 9;
	winners[2] = rand() % 9;
} // getWinners

int checkWin(int *nums, int *winners) {
	int total = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (nums[i] == winners[j]) {
				total += 1;
			} // if
		} // for j
	} // for i
	return total;
} // checkWin

void findWinners(Owner *owner, int *ls) {
	cout << "Total lottery tickets sold: " << owner->totalSold << endl;
	cout << "Winning numbers: ";
	for (int h = 0; h < 3; h++) {
		cout << ls[h];
	} //for
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
			//int tickets[][] = c.lotterynums;
			cout << "/t customer: " << c.custID << endl;
			for (int k = 0; k < c.tix; k++) {
				int thisTicket[3];
				thisTicket[0] = c.lotterynums[k][0];
				thisTicket[1] = c.lotterynums[k][1];
				thisTicket[2] = c.lotterynums[k][2];
				for (int l = 0; l < 3; l++) {
					int matches = checkWin(thisTicket, ls);
					if (matches > 0) {
						totalWins += 1;
						storeWins += 1;
						cout << "/t ticket:/t";
						for (int m = 0; m < 3; m++) {
							cout << thisTicket[m];
						} // for
						cout << " matched   ";
						if (matches == 1) {
							total1Wins += 1;
							store1Wins +=1;
							cout << "1" << endl;
						} // if matches == 1
						else if (matches == 2) {
							total2Wins += 1;
							store2Wins += 1;
							cout << "2" << endl;
						} // else if matches == 2
						else {
							total3Wins += 1;
							store3Wins += 1;
							cout << "3" << endl;
						} // else if matches == 3
					} // if matches > 0
				} // for l
			} // for k
		} // for j
		cout << "/t Total count for store " << s.storeID << ": ";
		cout << store1Wins << " ";
		cout << store2Wins << " ";
		cout << store3Wins << endl;
		s.numWinners[0] = store1Wins;
		s.numWinners[1] = store2Wins;
		s.numWinners[2] = store3Wins;
	} // for i
	owner->totalWinners[0] = total1Wins;
	owner->totalWinners[1] = total2Wins;
	owner->totalWinners[2] = total3Wins;
} // findWinners

