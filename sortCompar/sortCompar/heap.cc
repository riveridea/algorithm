#include <iostream>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sort_print(const vector<int> &array, int num)
{
    for(auto i = 0; i < num; i++)
    {
	cout << array[i] << " ";
    }
    cout << endl;
}

int verify_sort_l2h(const vector<int> &array, int num)
{
    for(auto i = 0; i < num -1; i++)    
    {
	if(array[i] > array[i + 1]) return false;
    }
    return true;
}

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

int parent(int index)
{
    return (index+1)/2 - 1;
}

int left(int index)
{
    return (index + 1)*2 - 1;
}

int right(int index)
{
    return (index + 1)*2;
}

//recursive method to heapify
void heapify_rec_imp(vector<int> &array, int index, int num)
{
    int l_index = left(index);
    int r_index = right(index);

    int largest = index;
    if(l_index < num && array[l_index] > array[largest])
	largest = l_index;
    if(r_index < num && array[r_index] > array[largest])
	largest = r_index;

    if(largest != index)
    {
	swap(&array[largest], &array[index]);
	heapify_rec_imp(array, largest, num);
    }
}

//interatvie method to heapify
void heapify_iter_imp(vector<int> &array, int index, int num)
{
    int largest = index;
    int curr_index = index;
    int l, r;
    
    while(true){
	l = left(curr_index);
	r = right(curr_index);
	if(l < num && array[l] > array[largest]) largest = l;	
	if(r < num && array[r] > array[largest]) largest = r;
	if(largest != curr_index)
	{
	    swap(&array[largest], &array[curr_index]);
	    curr_index = largest;
	}
	else
	    break;
    }
}

//build heap from the given vector
void build_heap(vector<int> &array, int num)
{
    //heapify all the non-leaf nodes
    for(auto i = num/2 + 1; i >= 0; i--){
	heapify_rec_imp(array, i, num);
    }
}

//heap sort based on heapify and build_heap
void heap_sort(vector<int> &array, int num)
{
    build_heap(array, num);
    for(auto i = num - 1; i > 0; i--)
    {
	swap(&array[i], &array[0]);
	//heapify_rec_imp(array, 0, i);
	heapify_iter_imp(array, 0, i);
    }
}


int main()
{
    int num = 20000;
    vector<int> array;

    //generate the random integer between 1 and 100
    srand(time(NULL));
    for(auto i = 0 ; i < num; i++)
    {
	array.push_back(rand()%500000 + 1);
    }
    //sort_print(array, num);

    //build_heap(array, num);
    heap_sort(array, num);
    cout << (verify_sort_l2h(array, num)? "Sort Successfully!":"FAILED Sort") << endl;
    //sort_print(array, num);
    //heap_sort(parray, num);

    return 0;
}
