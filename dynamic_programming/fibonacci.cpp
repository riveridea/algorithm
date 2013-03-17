/*
 * fibonacci.cpp
 *
 *  Created on: Mar 9, 2013
 *      Author: alexzh
 */
#include <iostream>
#include "fibonacci.hpp"

int f[2];

int fibonacci(int n){
	int i = 2, tmp = 0;
	f[1] = 1;
	f[0] = 0;
	for( ;i < n+1;i++){
		tmp = f[1] + f[0];
		f[0] = f[1];
		f[1] = tmp;
	}
	return tmp;
}




