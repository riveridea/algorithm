/*
 * changemaking.cpp
 *
 *  Created on: Mar 10, 2013
 *      Author: alexzh
 */
#include "changemaking.hpp"
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

int changemaking(int* d, int n, int m){
	int* f = (int*)std::malloc((n+1)*sizeof(int));

	std::memset(f, 0, n+1);
	int rt;
	if (n == 0) rt = 0;

	int temp;
	int i;
	for(i=1 ; i<=n; i++){
		temp = 65535;
		int j;
		for(j=0; j<m; j++){
			if(i >= d[j]){
				//std::cerr << "temp:" << temp << "f[" << i << "- d["<< j << "]]:" << f[i-d[j]] << std::endl;
				temp = std::min(temp, f[i-d[j]]);
			}
		}
		f[i] = temp + 1;
	}

	rt = f[n];
	std::free(f);
	return rt;
}



