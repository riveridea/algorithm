/*
 * quick.cpp
 *
 *  Created on: Dec 4, 2011
 *      Author: alexzhang
 */
#include <iostream>
#include <vector>
#include "rstream.h"
#include "quick.h"
#include <math.h>
#include <cstdlib>
#include <cstring>
using namespace std;

//we count the operations of swap and comparison

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//this partition is consistent with "introduction to algorithm"
int partition(vector <int> &arr, int low, int high, unsigned long& cnt)
{
	int pivot = arr[low];

	int i=low;
	int j=high;

	while(1)
	{
		for(;i<high;i++)
		{
			cnt++;
			if(arr[i] >= pivot) break;
		}
		for(;j>low;j--)
		{
			cnt++;
			if(arr[j] <= pivot) break;
		}
		if(i<j)
		{
			cnt++;
			swap(&arr[i], &arr[j]);
		}
		else
			return j;
	}
}

int quickSort_2(vector <int> &arr, int start, int end)
{
	int p;
	unsigned long count = 0;
	unsigned long cnt1, cnt2;
	cnt1 = cnt2 = 0;

	if (start < end)
	{
		p = partition(arr, start, end, count);
		if(start <= p && end >= p)
		{
			cnt1 = quickSort_2(arr, start, p);
			cnt2 = quickSort_2(arr, p+1, end);
		}
		else
		{
			return 0;
		}
	}

	return (cnt1 + cnt2 + count);
}



//Quick Sort
int quicksort(vector <int> &arr, int start, int end)
{
      int pivot, starth, endh; // store pivot # keep start & end in memory for split
      int counter = 0;
      starth = start;
      endh = end;
      pivot = arr[start];
      while(start < end)
      {
       while((arr[end] >= pivot) && (start < end))
       end--;
       counter++;
         if (start != end)
         {
           arr[start] = arr[end];
           start++;
         }
       while ((arr[start] <= pivot) && (start < end))
           start++;
           counter++;
         if (start != end)
         {
           arr[end] = arr[start];
           end--;
           }
     }
     arr[start] = pivot;
     pivot = start;
     start = starth;
     end = endh;   if(start < pivot)
     quicksort(arr, start, pivot-1);
     if(end > pivot)
     quicksort(arr, pivot+1, end);
     return counter;
}

