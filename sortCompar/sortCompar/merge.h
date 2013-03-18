/*
 * merge.h
 *
 *  Created on: Dec 4, 2011
 *      Author: alexzhang
 */

#ifndef MERGE_H_
#define MERGE_H_
#include "rstream.h"
#include <iostream>
#include <vector>
using namespace std;

unsigned long merge(int low, int mid, int high, vector<int>& values, vector<int>& scratch);
unsigned long mergesort_b(vector<int>& values, vector<int>& scratch, int low, int high, int& cnt );
unsigned long mergesort(vector<int> &aa);

#endif /* MERGE_H_ */
