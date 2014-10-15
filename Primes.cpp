// Guanhong Zhou <guzhou@ucsd.edu>, Evan Su <e2su@ucsd.edu>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <thread>

// Tests list of numbers for primality
// Usage: a.out n1 [n2...]
// Where the n_i are numbers to be tested for primality
// Scott B. Baden, UCSD, 17 April 2013
//
// Use this web page to test for primarility and generate
// lists of prime numbers in the vicitinty of a given number
// http://markknowsnothing.com/cgi-bin/primes.php
//

// Globals, shared by all threads
//
// DO NOT change these declarations as we rely on them to grade your assignment
//
// Candidate primes
std::vector<int64_t> candidates;
// Identify which number(s) is (are) prime
std::vector<bool> primeFlags;

//
// DO NOT change the signatures of these 4 functions as we will rely on
// them to test your assignment

// Write this routine to show the output of your prime number tester
void ReportPrimes(int n);

void getInput(int argc, char *argv[], int &n, int &NT);

// The thread function
void prime_th(int TID, int NT, int n);

// A timer
double getTime();

//
// End declaration of 4 functions
//

//
// --- Main module
//
int main(int argc, char *argv[]) {
    int n, NT;

    // Sets the number of candidate primes to test
    // and the number of threads
    // Follow further instructions in getInput()
    getInput(argc,argv,n,NT);

    // Start the timer
    double t0 = getTime();

    // Read in each number, report on primality
    // write a thread function to read in
    // values from the vector setup by getInput
    // such that each thread samples its own section of the vector.
    // The first argument specifies the thread ID, the second
    // the number of threads, the third, the number of primes.
    // The thread function will divide the n primes into
    // disjoint subsets, giving each thread exactly one subset
    
    //create threads
    std::thread *thrds = new std::thread[NT];

    //assign tasks for each thread
    for (int t = 0; t < NT; t++) {
        thrds[t] = std::thread(prime_th, t, NT, n);
    }
    
    //join all the threads
    for (int t = 0; t < NT; t++) {
        thrds[t].join();
    }
    


    // Stop the Timer
    double t1 = getTime();

    ReportPrimes(n);  

    // Report the timings
    std::cout << "Testing the candidate primes " << " took ";
    std::cout << "  " << t1-t0 << " seconds";
    std::cout << "  on " << NT << " threads" << std::endl;

    
    std::cout << std::endl;

    // delete all data that thrds pointer is pointing to to avoid memory leak
    delete [] thrds;
    return 0;
}
