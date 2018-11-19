#include "BayesNet.h"


void BayesNet::initVars()
{
	srand(time(NULL));
	A = rand() % 2;
	B = rand() % 2;
	C = rand() % 2;
	D = 1;
	E = rand() % 2;
	F = rand()% 2;
	G = 1;
	cout << A << B << C << D << E << F << G << endl;
}

int BayesNet::mcmc()
{

	srand(time(NULL));

	// Shift operations to create base 2 values from the boolean values.
	int DBE = (D<<2) | (B<<1) | E;
	int ACEF = (A<<3) | (C<<2) | (E<<1) | F;
	int BF = (B<<1) | F;
	int GABF = (G<<3) | (A<<2) | (B<<1) | F;
	int GBCE = (G<<3) | (B<<2) | (C<<1) | E;
	
	// Generate new A value based on bias
	float randNum = (rand() * rand()) % 100000 / 100000.0;
	if (AgiveDBE[DBE] > randNum) {
		A = false;
	}
	else {
		A = true;
	}

	// Generate new B value based on bias
	randNum = (rand() * rand()) % 100000 / 100000.0;
	if (BgiveACEF[ACEF] > randNum) {
		B = false;
	}
	else {
		B = true;
	}

	// Generate new C value based on bias
	randNum = (rand() * rand()) % 100000 / 100000.0;
	if (CgiveBF[BF] > randNum) {
		C = false;
	}
	else {
		C = true;
	}

	// Generate new E value based on bias
	randNum = (rand() * rand()) % 100000 / 100000.0;
	if (EgiveGABF[GABF] > randNum) {
		E = false;
	}
	else {
		E = true;
	}

	// Generate new F value based on bias
	randNum = (rand() * rand()) % 100000 / 100000.0;
	if (FgiveGBCE[GBCE] > randNum) {
		F = false;
	}
	else {
		F = true;
	}

	if (B == true) {
		return 1;
	}
	else return 0;
}
