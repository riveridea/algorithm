/*
 * insert.cpp
 *
 *  Created on: Dec 4, 2011
 *      Author: Jingzhi Yu
 */
#include <iostream>
#include <vector>
#include "rstream.h"
#include "insert.h"
#include <math.h>
#include <cstdlib>
#include <cstring>
using namespace std;

// INSERTION SORT
  int insertSort(vector <int> &arr)
    {
    unsigned int i, j, index;
    int count=0;
    for(i=1; i < arr.size();i++)
    {
        index  = arr[i];
        j = i;
        while((j > 0) && (arr[j-1] > index))
           {
            count++;
            arr[j] = arr[j-1];
            j = j-1;
           }
       arr[j] = index;
    }
     cout<<endl<<"There're "<<count<< " operations on this sort\n";
     return count;
    }
