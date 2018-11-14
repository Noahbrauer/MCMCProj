#pragma once
#include <map>
using namespace std;


//--Implemented--
//The class BayesNet holds our boolean values to be changed based on a biased input.
//Our bias is the probability given multiplied by 1000 to account for a random number 
//generated from 1-1000.
class BayesNet {

	map<int, int> AgiveDEB = { {111, },{110, },{101, },{100, },{011, },{010, },{001, },{000, } };
	map<int, int> BgiveAEFC = { {1111, },{1110, },{1101, },{1100, },{1011, },{1010, },{1001, },{1000, }, 
								{0111, },{0110, },{0101, },{0100, },{0011, },{0010, },{0001, },{0000, } };
	map<int, int> CgiveBF = { {11, },{10, },{01, },{00, } };
	map<int, int> DgiveA = { {1, },{0, } };
	map<int, int> EgiveABGF = { {1111, },{1110, },{1101, },{1100, },{1011, },{1010, },{1001, },{1000, },
								{0111, },{0110, },{0101, },{0100, },{0011, },{0010, },{0001, },{0000, } };
	map<int, int> FgiveBCGE = { {1111, },{1110, },{1101, },{1100, },{1011, },{1010, },{1001, },{1000, },
								{0111, },{0110, },{0101, },{0100, },{0011, },{0010, },{0001, },{0000, } };
	map<int, int> GgiveEF = { {11, },{10, },{01, },{00, } };




private:
	bool A, B, C, D, E, F, G;
};