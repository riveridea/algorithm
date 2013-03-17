/*
 * knapsack.cpp
 *
 *  Created on: Mar 15, 2013
 *      Author: alexzh
 */
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

int get_max_value(int n, int W, int* weights, int* values){
	int* f = (int*)std::malloc((n+1)*(W+1)*sizeof(int));
	std::memset(f, 0, (n+1)*(W+1)); //reset the the first row and first column to zero

	int i, j;
	// start the loop from 1
	for(i=1; i<=n; i++){
		for(j=1; j<=W; j++){
        	std::cout << f[(i-1)*(W+1) + j] << "  " << f[(i-1)*(W+1) + j] << " ";
	        if (j >= weights[i]){
	        	f[i*(W+1)+j] = std::max(f[(i-1)*(W+1) + j], values[i] + f[(i-1)*(W+1) + j - weights[i]]);
	        }
	        else{
	        	f[i*(W+1)+j] = f[(i-1)*(W+1) + j];
	        }
        	std::cout << f[i*(W+1)+j] << std::endl;
		}
	}

	std::free(f);
	int rt = f[(n+1)*(W+1) - 1];
	return rt; //pay attention to the index
}



