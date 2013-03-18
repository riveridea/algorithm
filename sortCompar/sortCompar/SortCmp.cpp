//============================================================================
// Name        : SortCmp.cpp
// Author      : Jingzhi Yu
// Version     :
// Copyright   : NEU
// Description : Performance of sorting algorithm
//============================================================================

#include <iostream>
#include <vector>
#include "rstream.h"
#include "merge.h"
#include "quick.h"
#include "counting.h"
#include "selection.h"
#include "insert.h"
#include "bubble.h"
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

const double PII = 3.141592654;
const double DoubleSize = sizeof(double);
const unsigned long int FACTOR = 663608941;
const double max_value = 4294967295.0; // (2**(32))-1

// initial our array
void populateVector( vector< int > &a,  int M)
{
	static Rstream pRndS( 10 );
	for( unsigned int i = 0; i < a.size(); i++ )
	{
		a[i] = (int)pRndS.uniform_discrete( 0, M-1 );
	}
}


/***********************************************************************
** function:    Rstream, constructor;
** parameters:  unsigned long int, a seed s;
** description: Create a stream with a seed s.
***********************************************************************/
    Rstream::Rstream( unsigned long int s ) {

      xi = ( s % 2 ) ? s :( s + 1 ); // Make sure the seed is an odd number
    } // End constructor


    /***********************************************************************
    ** function:    uniform01;
    ** parameters:  none;
    ** description: Generate a random number between 0 and 1 based on the
    **              relation X(i+1)  =  (X(i) * 663608941) mod (2**32).
    ***********************************************************************/
double Rstream::uniform01()
{
    xi *= FACTOR;
    // This includes the '% 2**32', since the g++ arithmetic is % 2**32
    double mid = ( (double)xi / max_value );
    return mid;
} // End uniform01


    /***********************************************************************
    ** function:    uniform;
    ** parameters:  double, lower and upper;
    ** description: Generate a random number between lower and upper.
    ***********************************************************************/
double Rstream::uniform( double lower, double upper )
{
    return ( uniform01() * (upper - lower) + lower );
} // End uniform

    /***********************************************************************
    ** function:    uniform_discrete
    ** parameters:  int, lower, upper
    ** description: Generate a discrete random number between lower and
    **              upper (lower and upper included).
    ***********************************************************************/
unsigned long int Rstream::uniform_discrete( unsigned long int lower, unsigned long int upper )
{
	return ((unsigned long int )floor(uniform(lower, upper)));
} // End uniform_discrete


bool isSorted(const vector<int> &arr)
{
	 int length = arr.size();
	 for (int i = 0; i < length-2; i++)
	 {
	     if (arr[i]>arr[i+1])
	     {
	     	cout << "\nSort Failed!!! \n";
	      	return false;
	     }
	     //cout << arr[i] << "\n";
	 }
	 cout << "\nSort Success!!! \n";
	 return true;
}

int main() {
    int aSize, sw;
    bool verbose = 0;
	int maxElem = 0;
    float elapTicks, elapMilli, elapSeconds, elapMinutes;
    clock_t Begin, End;

    cout << "Please input the vector size: \n";
    cin >> aSize;
    cout << "which sort will you test: \n";
    cout << "1: counting 2: selection 3: insert 4: bubble 5: merge 6: quick Other: quit \n";
    cin >> sw;
    cout << "display elements? 0: No, 1: Yes \n";
    cin >>verbose;


	int count = 0;
	unsigned int i;
	vector<int> aa(aSize);

	switch (sw){

	case 1:
		//test counting sort
		//We cannot allocate too much memory here!
		populateVector(aa, 50000000);
		for (i=0;i<aa.size();i++)
		{
			if (aa[i]>=maxElem)
				maxElem=aa[i];
		}

	    Begin = clock();//start the timer
	    count = countingSort(aa, 1, maxElem);
	    End = clock();// * CLK_TCK;        //stop the timer

		cout << "Counting Sort Counts: "<< count << "\n";
		for(i=0;i<aa.size();i++)
		{
			if (verbose)
				cout<<aa[i]<<" ";
		}
		isSorted(aa);
		count = 0;
		break;

	case 2:
		//test  selection sort
		populateVector(aa, max_value);

	    Begin = clock();//start the timer
		count = selectionSort(aa);
		End = clock();

		cout << "Selection Sort Counts: "<< count << "\n";
		for(i=0;i<aa.size();i++)
		{
			if (verbose)
				cout<<aa[i]<<" ";
		}
		isSorted(aa);
		count = 0;
		break;

	case 3:
		//test insert sort
		populateVector(aa, max_value);

		Begin = clock();
		count = insertSort(aa);
		End = clock();

		cout << "Insert Sort Counts: "<< count << "\n";
		for(i=0;i<aa.size();i++)
		{
			if (verbose)
				cout<<aa[i]<<" ";
		}
		isSorted(aa);
		count = 0;
		break;

	case 4:
		//test bubble sort
		populateVector(aa, max_value);

		Begin = clock();
		count = bubbleSort(aa);
		End = clock();

		cout << "Bubble Sort Counts: "<< count << "\n";
		for(i=0;i<aa.size();i++)
		{
			if (verbose)
				cout<<aa[i]<<" ";
		}
		isSorted(aa);
		count = 0;
		break;

	case 5:
		//test merge sort
		populateVector(aa, max_value);

		Begin = clock();
		count = mergesort(aa);
		End = clock();

		cout << "Merge Sort Counts: "<< count << "\n";
		for(i=0;i<aa.size();i++)
		{
			if (verbose)
				cout<<aa[i]<<" ";
		}
		isSorted(aa);
		break;

	case 6:
		//test quick sort
		populateVector(aa, max_value);

		Begin = clock();
		count = quickSort_2(aa, 0,aa.size()-1);
		End = clock();

		cout << "Quick Sort Counts: "<< count << "\n";
		for(i=0;i<aa.size();i++)
		{
			if (verbose)
				cout<<aa[i]<<" ";
		}
		isSorted(aa);
		break;

	default:
		cout << "Invalid input \n";
		Begin = End = 0;
		break;
	}

    elapTicks = End - Begin;        //the number of ticks from Begin to End

    elapMilli = elapTicks*1000/CLOCKS_PER_SEC;     //milliseconds from Begin to End
    elapSeconds = elapMilli/1000;   //seconds from Begin to End
    elapMinutes = elapSeconds/60;   //minutes from Begin to End

    cout << "\nTicks elapsed: "<< elapTicks;;
    //To correctly identify elapsed time
    if(elapSeconds < 1)
          cout<<"\n\nIt took "<<elapMilli<<" milliseconds."<<endl;
    else if(elapSeconds == 1)
          cout<<"\n\nIt took  1 second.";
    else if(elapSeconds > 1 && elapSeconds < 60)
          cout<<"\n\nIt took  "<<elapSeconds<<" seconds."<<endl;
    else if(elapSeconds >= 60)
          cout<<"\n\nIt took  "<<elapMinutes<<" minutes."<<endl;

	return 0;
}
