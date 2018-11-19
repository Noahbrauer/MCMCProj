#include <iostream>
#include "BayesNet.h"
int main()
{
	BayesNet net;
	int numTrue = 0;
	int record[10];
	net.initVars();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 1000; j++)
		{
			numTrue += net.mcmc();
		}
		record[i] = numTrue;
		cout << numTrue << endl;
		numTrue = 0;
	}

	system("PAUSE");
}
