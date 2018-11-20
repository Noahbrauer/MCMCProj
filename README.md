# MCMCProj
C++/Python Implementation of a MCMC that takes input of our Bayes net and approximates the Probability for P(B|D+T,G+T) given a bayesian net and probability tables for said net. 

\\ You can run this code with your method of choice. When running in shell you simply use make and then run the file with 
\\ the unix command ./MCMC. When run it should first output the five different binary values for the run. Then it will output 
\\ a table that holds data on the runs and there 1000 piece slices.

--BayeSource--
This is my main file which implements 5 different initialized Bayesian nets. I then conduct a Markov Chain Monte Carlo decision
process, in accordence to the random bias of the Markov Blanket, to approximate the ratio for runs where B=T. For each run I add 
the outcome, 1 for B=T and 0 for B=F, to the total for that set of 1000 instances. I also add it to the total for that whole run.
Finally after doing this 5 times, 1 for each run, I'm able to output my results into a readable table. At the end I display my 
final ratio for each full run.

--BayesNet.h--
This is the class file for my net. In its private data is held the tables of probabilities. The map takes a binary number 
converted to an int and it mapes that index to the probability. The binary numbers are found by shifting bools and concatonating
them with Ors. Also held in the private data is our initializing value for the random device used. I used random device because
when using other pseudo-random number generator the values would all end up similar.
In the public data is the initializing function and MCMC function for the net, but these are implemented in the source file.

--BayesNet.cpp--
This is the implementation file for the member functions held in the header file. The first function uses the generator
initialized in the header and a Mersenne Twister pseudo-random generator. From those were able calculate a bernoulli distribution 
and find single binary digits to assign to our initial boolean variables. The next funuciton is the implementation of the mcmc and 
uses shift operators on boolean values to simplify concatonating them together. I again use the bernoulli distribution method but
in this case instead of 0.5 the probability found in the map is used. 

--Learning Outcome--
For this project we were able to take a Bayesian Net with a few conditional probability tables and transform those tables into 
Markov Blanket probability tables. From these we could then iterate 10000 instances, updating the values during each instance, 
while keeping track of ratio of occasions where B is true after the instances. From this we can see that for each run the ratios
converge on a similar decimal value. 
-One thing that was found is that there are two different ways to update your boolean values. You can do it sequentially or all at 
once. In the case of updating the values all at once its found that the ratios converged close to 0.563 but when updated 
sequentially the ratios are slightly higher and converge closer to 0.585. I submitted the case of updating sequentially because 
Dr. Goldsmith said it should be more accurate.
---From these calculations we see a pattern that each run converges towards 0.585.
