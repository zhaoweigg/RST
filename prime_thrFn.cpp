// Guanhong Zhou <guzhou@ucsd.edu>, Evan Su <e2su@ucsd.edu>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <thread>
#include <vector>



bool isPrime(int64_t x);

// Shared globals, allocated before threads are spawned
// These will be used in the threaded code
extern std::vector<int64_t> candidates; // Candidate primes
extern std::vector<bool> primeFlags;    // Prime flags

// This is the "thread function" that will be called by a newly created thread
// This provided code currently runs on only 1 thread
// 
// Change this code to subdivide the n primes into disjoint sets
// properly handling the case whtn the number of threads doesn't divide N
//
//
// DO NOT change the signature for this code as we rely on
// it to test your assignment
//
// 
// This function should perform no I/O when you are timing the code
void prime_th(int TID, int NT, int n)
{
    // create function to assign vectors to threads efficiently
    int a = n / NT;
    int b = n % NT;
    int begin;
    int end;

    if (TID < b) {
        begin = TID * (a + 1);
        end = TID * (a + 1) + (a + 1);
    }
    else {
        begin = TID * a + b;
        end = TID * a + a + b;
    }

    // if candidate at i is a prime, set the ith value in primeFlags to true
    for (int i=begin;i<end; i++) {
        primeFlags[i] = isPrime(candidates[i]);
    }
}
