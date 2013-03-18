/*
 * counting.cpp
 *
 *  Created on: Dec 4, 2011
 *      Author: alexzhang
 */
#include <iostream>
#include <vector>
#include "rstream.h"
#include "counting.h"
#include <math.h>
#include <cstdlib>
#include <cstring>
using namespace std;

// COUTING SORT
int countingSort(vector<int> &v, int min, int max)
{
    int range = max - min + 1;
    int cnt;
	int* counts = new int[range];
	int offset = -min;
	vector<int>::size_type size = v.size();

	memset(counts, 0, range * sizeof(int));

	for(int i = 0; i < size; ++i)
	{
		++counts[v[i] + offset];
		cnt++;
    }
	int index = 0;
	for(int i = 0; i < range; ++i)
	{
		cnt++;
		while(counts[i]--)
		{
			v[index++] = i - offset;
        }
	}

	delete [] counts;

	return cnt;
}

