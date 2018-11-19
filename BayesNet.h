#pragma once
#include <map>
using namespace std;

/*
	--Implemented--
	The class BayesNet holds our boolean values to be changed based on a biased input.
	Our bias is the probability given multiplied by 1000 to account for a random number 
	generated from 1-1000.
	Maps are based on conditional probabilities for markov blanket found by Adrian and Asare.
	The map is made with the values after the given bar of the probability all concatenated 
	which is mapped to the probabilty for their result.
	--Needs Work--
	Possibly immplement function for MCMC sampling using the Markov Blanket 
	concept (also called block Gibbs sampling).
*/
class BayesNet {
	
	map<int, float> AgiveDBE = { {111, 0.50909},{110, 0.93333},{101, 0.80576},{100, 0.96137} };

	map<int, float> BgiveACEF = { {1111, 0.10638},{1110, 0.21739},{1101, 0.61644},{1100, 0.78947},{1011, 0.40000},{1010, 0.40000},{1001, 0.36000},{1000, 0.90000},
								  {0111, 0.32258},{0110, 0.52632},{0101, 0.74074},{0100, 0.86957},{0011, 0.14286},{0010, 0.72727},{0001, 0.50000},{0000, 0.94118} };

	map<int, float> CgiveBF = { {11, 0.38462},{10, 0.13514},{01, 0.57143},{00, 0.14286} };

	map<int, float> DgiveA = { {1, 0.80000},{0, 0.30000} };

	map<int, float> EgiveGABF = { {1111, 0.00613},{1110, 0.01597},{1101, 0.19814},{1100, 0.75000},{1011, 0.17489},{1010, 0.75000},{1001, 0.69231},{1000, 0.94737} };

	map<int, float> FgiveGBCE = { {1111, 0.20000},{1110, 0.66667},{1101, 0.05882},{1100, 0.32468},{1011, 0.42257},{1010, 0.82353},{1001, 0.50000},{1000, 0.88889} };

	map<int, float> GgiveEF = { {11, 0.10000},{10, 0.40000},{01, 0.40000},{00, 0.20000} };

	int mcmc();

private:
	bool A, B, C, D, E, F, G;
};
