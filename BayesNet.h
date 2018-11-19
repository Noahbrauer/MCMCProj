#pragma once
#include <iostream>
#include <map>
#include <time.h>

using namespace std;

/*
	The class BayesNet holds in its private section our boolean values to be changed based on 
	a biased input and the map variables computed using the Markov Blanket. In the public 
	portion we declared a member function for randomly changing the boolean values held in the 
	private data.
*/
class BayesNet {
public:
	void initVars();
	int mcmc();

private:
	bool A, B, C, D, E, F, G;
	map<int, float> AgiveDBE = { {111, 0.50909},{110, 0.93333},{101, 0.80576},{100, 0.96137} };
	map<int, float> BgiveACEF = { {1111, 0.10638},{1110, 0.21739},{1101, 0.61644},{1100, 0.78947},{1011, 0.40000},{1010, 0.40000},{1001, 0.36000},{1000, 0.90000},
								  {0111, 0.32258},{0110, 0.52632},{0101, 0.74074},{0100, 0.86957},{0011, 0.14286},{0010, 0.72727},{0001, 0.50000},{0000, 0.94118} };
	map<int, float> CgiveBF = { {11, 0.38462},{10, 0.13514},{01, 0.57143},{00, 0.14286} };
	map<int, float> EgiveGABF = { {1111, 0.00613},{1110, 0.01597},{1101, 0.19814},{1100, 0.75000},{1011, 0.17489},{1010, 0.75000},{1001, 0.69231},{1000, 0.94737} };
	map<int, float> FgiveGBCE = { {1111, 0.20000},{1110, 0.66667},{1101, 0.05882},{1100, 0.32468},{1011, 0.42257},{1010, 0.82353},{1001, 0.50000},{1000, 0.88889} };
};
