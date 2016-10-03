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
	// not finished
}
