#include <iostream>
#include <iomanip> 
#include "BayesNet.h"

int main()
{
	// Creating all net objects
	BayesNet net1;
	BayesNet net2;
	BayesNet net3;
	BayesNet net4;
	BayesNet net5;
	double numTrue[5][10] = { 0 };
	double record[5] = { 0 };

	// Run 1 storing count in first slice of numTrue
	net1.initVars(1);
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 1000; k++)
		{
			numTrue[0][j] += net1.mcmc();
		}
		record[0] += numTrue[0][j];

	}

	// Run 2 storing count in second slice of numTrue
	net2.initVars(2);
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 1000; k++)
		{
			numTrue[1][j] += net1.mcmc();
		}
		record[1] += numTrue[1][j];

	}

	// Run 3 storing count in third slice of numTrue
	net3.initVars(3);
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 1000; k++)
		{
			numTrue[2][j] += net1.mcmc();
		}
		record[2] += numTrue[2][j];

	}

	// Run 4 storing count in fourth slice of numTrue
	net4.initVars(4);
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 1000; k++)
		{
			numTrue[3][j] += net1.mcmc();
		}
		record[3] += numTrue[3][j];

	}

	// Run 5 storing count in fifth slice of numTrue
	net5.initVars(5);
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 1000; k++)
		{
			numTrue[4][j] += net1.mcmc();
		}
		record[4] += numTrue[4][j];

	}

	// Printing values for each run
	cout << "Number of B=T for each 1000 chunk  " << "Run 1" << setw(8) << "Run 2" << setw(8) << "Run 3" << setw(8) << "Run 4" << setw(8) << "Run 5\n";
	for (int j = 0; j < 10; j++) {

		cout << "Proportion in" << setw(3) << j + 1 << "000 Instances: " << setw(8) << numTrue[0][j]/1000.0 << setw(8) << numTrue[1][j]/1000.0 << setw(8) << numTrue[2][j]/1000.0 << setw(8) << numTrue[3][j]/1000.0 << setw(8) << numTrue[4][j]/1000.0 << endl;
	}

	// Printing final result for each iteration inside an array
	cout << "\nPr(B|D,G) = [ ";
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
			cout << record[i] / 10000.0 << " ]\n\n";
		else cout << record[i] / 10000.0 << " , ";
	}

}
