// Guanhong Zhou <guzhou@ucsd.edu>, Evan Su <e2su@ucsd.edu>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>

// Global shared vectors 
extern std::vector<int64_t> candidates;
extern std::vector<bool> primeFlags; 

// This code currently reads only the number of candidate primes
// off the command line
// You need to add code read in the number of threads and also to read
// athe candidate primes into a vector
//
// e.g. If we run ./primes 2 5 7,
// the number of threads (NT) is 2
// and the candidates are 5 and 7
//
//
// DO NOT change the signature for this code as we rely on
// it to test your assignment
//
void getInput(int argc, char *argv[], int &n, int &NT){
    n = argc; n-=2 ; //changed so that n = argc - 2
    if (n<0) n=0; // in case of no extra arguments
    NT = 1; //default
    
    // Read in the number of threads and candidate primes
    if (argc >= 2) {
	NT = atoi(argv[1]); //convert char to int
    }
    std::cout << "Testing " << n << " candidate primes" << std::endl;
    std::cout << "Number of threads: "<< NT << std::endl;
    std::cout <<" "<< std::endl;
    for (int i = 2; i < argc; i++) {
        candidates.push_back(atoll(argv[i])); //populate candidates from command line
	primeFlags.push_back(false);  //populate primeFlags with all falses 
                                      //just to ensure the correct vector size. we will f
                                      //ill correct values using prime_th
    }

}
