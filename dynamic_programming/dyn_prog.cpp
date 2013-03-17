//============================================================================
// Name        : dyn_prog.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include "dyn_prog.hpp"
#include "changemaking.hpp"
#include "knapsack.hpp"
#include <iostream>

int main(){
	//fibonaci
	int i;
	for(i=0; i< 10; i++){
		//std::cout << fibonacci(i) << std::endl;
	}

	//change making problem
	int deno[3] = {1, 3, 4};
	std::cout << changemaking(deno, 6, 3) << std::endl;

	//knapsack problem
    int W = 5, n = 4;
    int weights[5] = {0, 2, 1, 3, 2};
    int values[5] = {0, 12, 10, 20, 15};
    std::cout << get_max_value(n, W, weights, values) << std::endl;

	return 0;
}

