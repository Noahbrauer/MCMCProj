CFLAGS = -std=c++11 -Wall

PROGRAM = MCMC
OBJS  =  BayesNet.o BayeSource.o

all:$(PROGRAM)

$(PROGRAM): $(OBJS)
	g++ $(OBJS) -o $(PROGRAM)

main.o:  BayeSource.cpp
	g++ -c $(CFLAGS) BayesSource.cpp

BayesNet.o: BayesNet.cpp Bayesnet.h
	g++ -c $(CFLAGS) BayesNet.cpp

clean:
	rm -f core $(PROGRAM) $(OBJS)
