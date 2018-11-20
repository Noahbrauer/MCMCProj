#pragma once
#include <iostream>
#include <map>
#include <time.h>
#include <random>
using namespace std;

/*
	The class BayesNet holds in its private section our boolean values to be changed based on 
	a biased input and the map variables computed using the Markov Blanket. We also declared a 
	member function for randomly changing the boolean values held in the private data.
*/
class BayesNet {
public:
	// initVars() is the function to initialize the variable contained in the class.
	void initVars(int run);
	// mcmc() is the function that uses our probabilities to bias if a value is set to
	// true or false. It uses probabilities of the given Bayesian Net that were computed 
	// for each according to its Markov Blanket.
	int mcmc();

private:
	// These variables are used to store the boolean values of the nodes in the net.
	bool A, B, C, D, E, F, G;
	random_device rd;
	// Our map variables contain a map from given portion of the probability to the probability
	// that the given case equates to true. The index is a binary value where each place holds 
	// a vaule for the given boolean.
	map<int, double> AgiveDBE = { {7, 0.50909},{6, 0.93333},{5, 0.80576},{4, 0.96137} };
	map<int, double> BgiveACEF = { {15, 0.10638},{14, 0.21739},{13, 0.61644},{12, 0.78947},{11, 0.40000},{10, 0.40000},{9, 0.36000},{8, 0.90000},
								  {7, 0.32258},{6, 0.52632},{5, 0.74074},{4, 0.86957},{3, 0.14286},{2, 0.72727},{1, 0.50000},{0, 0.94118} };
	map<int, double> CgiveBF = { {3, 0.38462},{2, 0.13514},{1, 0.57143},{0, 0.14286} };
	map<int, double> EgiveGABF = { {15, 0.00613},{14, 0.1597},{13, 0.19814},{12, 0.75000},{11, 0.17489},{10, 0.75000},{9, 0.69231},{8, 0.94737} };
	map<int, double> FgiveGBCE = { {15, 0.20000},{14, 0.66667},{13, 0.5882},{12, 0.32468},{11, 0.42257},{10, 0.82353},{9, 0.50000},{8, 0.88889} };
};
