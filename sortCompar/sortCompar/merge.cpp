/*
 * merge.cpp
 *
 *  Created on: Dec 2, 2011
 *      Author: jingzhi Yu
 */
#include <iostream>
#include <vector>
#include "rstream.h"
#include "merge.h"
#include <math.h>
#include <cstdlib>
#include <cstring>
using namespace std;

// Non-recursive function to merge two sorted intervals (low..mid & mid+1..high)
// of a vector, using "scratch" as temporary copying space.
unsigned long merge(int low, int mid, int high, vector<int>& values, vector<int>& scratch)
{

  // some output so we can watch how merge sort works
  int i=low, j=mid+1, k=low;
  unsigned long count = 0;

  // while there's still something left in one of the sorted subintervals...
  while (i <= mid && j <= high)
  {
	  // look at the top values, grab the smaller one, store it in the scratch vector
	  // we count the comparison
	  ++count;
	  if (values[i] < values[j])
	  {
		  scratch[k] = values[i]; ++i;
	  }
	  else
	  {
      scratch[k] = values[j]; ++j;
	  }
	  ++k;
  }

  // Copy the remainder of the interval that hasn't been exhausted
  // Note: only one of for loops will do anything (have a non-zero index range)
  for ( ; i<=mid; ++i, ++k )
  {
	  ++count;
	  scratch[k] = values[i];  // low interval
  }
  for ( ; j<=high; ++j, ++k )
  {
	  ++count;
	  scratch[k] = values[j]; // high interval
  }

  // Copy from scratch back to values
  for ( i=low; i<=high; ++i )
  {
	  ++count;
	  values[i] = scratch[i];
  }

  return count;
}

// Here's the actual merge sort function.  It splits the vector in
    // half, recursively sorts each half, and then merges the two sorted
    // halves into a single sorted interval.
unsigned long mergesort_b(vector<int>& values, vector<int>& scratch, int low, int high) {
      //cout << "mergesort:  low = " << low << ", high = " << high << endl;
      unsigned long cnt1 = 0, cnt2 = 0, cnt3 = 0;
      if (low >= high)  //  intervals of size 0 or 1 are already sorted!
        return 0;

      int  mid = (low + high) / 2;
      cnt1 = mergesort_b( values, scratch, low, mid);
      cnt2 = mergesort_b(values, scratch, mid+1, high);
      cnt3 = merge(low, mid, high, values, scratch);

      return (cnt1 + cnt2 + cnt3);
}

unsigned long mergesort(vector<int> &aa)
{
	unsigned long counter = 0;

	vector<int> scratch(aa.size());
	int high = aa.size()-1;
	counter = mergesort_b(aa, scratch, 0, high);

	return counter;
}

