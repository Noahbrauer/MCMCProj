import random

#1'S SIGNIFY TRUE
#0'S SIGNIFY FALSE 

#uses the probablities to assign a biased random value
def evaluation(probability):
    true_false = 0
    value = random.uniform(0,1)
    if (value < probability):
        true_false = 1

    return true_false

#Actual values still need to be inserted, but this will be the general gist of how it will work
def true_prob_E(value_A, value_B, value_F):
    #TTT
    if (value_A == 1 and value_B == 1 and value_F == 1):
        value_E = 1
    #TTF
    elif (value_A == 1 and value_B == 1 and value_F == 0):
        value_E = 1
    #TFT
    elif (value_A == 1 and value_B == 0 and value_F == 1):
        value_E = 1
    #FTT
    elif (value_A == 0 and value_B == 1 and value_F == 1):
        value_E = 1
    #TFF
    elif (value_A == 1 and value_B == 0 and value_F == 0):
        value_E = 1
    #FFT
    elif (value_A == 0 and value_B == 0 and value_F == 1):
        value_E = 1
    #FTF
    elif (value_A == 0 and value_B == 1 and value_F == 0):
        value_E = 1
    #FFF
    elif (value_A == 0 and value_B == 0 and value_F == 0):
        value_E = 1

#uses the markov blanket in order to assign values to each of the variables
def main():

    #VALUE A
    prob_A = .7
    prob_not_A = 1 - prob_A
    value_A = evaluation(prob_A)

    #VALUE B
    prob_B = .5
    prob_not_B = 1 - prob_B
    #Set value
    value_B = 1
#    value_B = evaluation(prob_B)

    #VALUE C
    prob_C = .7
    prob_not_C = 1 - prob_C
    value_C = evaluation(prob_C)


    #VALUE D
    if (value_A == 1):
        prob_D = .8
        prob_not_D = 1 - prob_D
        value_D = evaluation(prob_D)
    else:
        prob_D = .3
        prob_not_D = 1 - prob_D
        #Set value
        value_D = 1
#       value_D = evaluation(prob_D)


    #VALUE E
    if (value_A == 1 and value_B == 1):
        prob_E = .1
        prob_not_E = .9
        value_E = evaluation(prob_E)

    elif (value_A == 1 and value_B == 0):
        prob_E = .6
        prob_not_E = 1 - prob_E
        value_E = evaluation(prob_E)

    elif (value_A == 0 and value_B == 1):
        prob_E = .6
        prob_not_E = 1 - prob_E
        value_E = evaluation(prob_E)

    elif (value_A == 0 and value_B == 0):
        prob_E = .9
        prob_not_E = 1 - prob_E
        value_E = evaluation(prob_E)


    #VALUE F
    if (value_B == 1 and value_C == 1):
        prob_F = .5
        prob_not_F = 1 - prob_F
        value_F = evaluation(prob_F)

    elif (value_B == 1 and value_C == 0):
        prob_F = .2
        prob_not_F = 1 - prob_F
        value_F = evaluation(prob_F)

    elif (value_B == 0 and value_C == 1):
        prob_F = .7
        prob_not_F = 1 - prob_F
        value_F = evaluation(prob_F)

    elif (value_B == 0 and value_C == 0):
        prob_F = .8
        prob_not_F = 1 - prob_F
        value_F = evaluation(prob_F)


    #VALUE G
    if (value_E == 1 and value_F == 1):
        prob_G = .1
        prob_not_G = 1 - prob_G
        value_G = evaluation(prob_G)

    elif (value_E == 1 and value_F == 0):
        prob_G = .4
        prob_not_G = 1 - prob_G
        value_G = evaluation(prob_G)

    elif (value_E == 0 and value_F == 1):
        prob_G = .4
        prob_not_G = 1 - prob_G
        value_G = evaluation(prob_G)

    elif (value_E == 0 and value_F == 0):
        prob_G = .2
        prob_not_G = 1 - prob_G
        value_G = evaluation(prob_G)


    true_prob_E(value_A, value_B, value_F)

    print("A = " + str(value_A))
    print("B = " + str(value_B))
    print("C = " + str(value_C))
    print("D = " + str(value_D))
    print("E = " + str(value_E))
    print("F = " + str(value_F))
    print("G = " + str(value_G))

main()
