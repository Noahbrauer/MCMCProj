#include "BayesNet.h"


void BayesNet::initVars(int run)
{
	mt19937 gen(rd());
	bernoulli_distribution dist(0.5);

	A = dist(gen);
	B = dist(gen);
	C = dist(gen);
	D = 1;
	E = dist(gen);
	F = dist(gen);
	G = 1;
	cout << "Initial values of ABCDEFG respectively run #";
	cout << run <<  " :" << A << B << C << D << E << F << G << endl;
}

int BayesNet::mcmc()
{

	srand(time(NULL));

	// Shift operations are conducted to create binary values from the 
	// boolean variables given.
	
	// Generate new A value based on bias
	int DBE = (D<<2) | (B<<1) | E;
	mt19937 generatorA(rd());
	bernoulli_distribution distA(AgiveDBE[DBE]);
	A = distA(generatorA);

	int ACEF = (A<<3) | (C<<2) | (E<<1) | F;
	// Generate new B value based on bias
	mt19937 generatorB(rd());
	bernoulli_distribution distB(BgiveACEF[ACEF]);
	B = distB(generatorB);

	int BF = (B<<1) | F;
	// Generate new C value based on bias
	mt19937 generatorC(rd());
	bernoulli_distribution distC(CgiveBF[BF]);
	C = distC(generatorC);

	int GABF = (G<<3) | (A<<2) | (B<<1) | F;
	// Generate new E value based on bias
	mt19937 generatorE(rd());
	bernoulli_distribution distE(EgiveGABF[GABF]);
	E = distE(generatorE);

	int GBCE = (G<<3) | (B<<2) | (C<<1) | E;
	// Generate new F value based on bias
	mt19937 generatorF(rd());
	bernoulli_distribution distF(FgiveGBCE[GBCE]);
	F = distF(generatorF);

	// Return case
	if (B == true) {
		return 1;
	}
	else return 0;
}
