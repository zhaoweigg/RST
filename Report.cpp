// Guanhong Zhou <guzhou@ucsd.edu>, Evan Su <e2su@ucsd.edu>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>

// Globals, shared by all threads
// DO NOT change these declarations as we rely on them to grade your assignment
//
// Candidate primes
extern std::vector<int64_t> candidates;
// Identify which number(s) is (are) prime
extern std::vector<bool> primeFlags;

// Write this routine to show the output of your prime number tester
void ReportPrimes(int n){


    std::cout << "Candidate primes:" << std::endl;

    // go through candidates vector to count the number of trues
    int flags = 0;
    for (int i = 0; i < n; i++) {
        std::cout << candidates[i] << std::endl;
        if (primeFlags[i]==true) {
            flags++;
        }  
    }
    std::cout << " " << std::endl;
    
    //output the number of primes and their values
    std::cout << "A total of "<< flags << " primes were identified" << std::endl;
    for (int i = 0; i < n; i++) {
        if (primeFlags[i] == true) {
            std::cout << candidates[i] << " is a prime number" << std::endl;
        }
    }

    
}
