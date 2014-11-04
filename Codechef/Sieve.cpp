#include<iostream>
using namespace std;
#define MAX_NUM 500000 // 200

// array will be initialized to 0 being global
int primes[MAX_NUM];

void gen_sieve_primes()
{
    for (int p=2; p<MAX_NUM; p++) // for all elements in array
    {
        if(primes[p] == 0) // it is not multiple of any other prime
            primes[p] = 1; // mark it as prime

        // mark all multiples of prime selected above as non primes
        int c=2;
        int mul = p * c;
        for(; mul < MAX_NUM;)
        {
            primes[mul] = -1;
            c++;
            mul = p*c;
        }
    }
}

void print_all_primes()
{
    int c = 0;
    for(int i=0; i<MAX_NUM; i++)
    {
        if(primes[i] == 1)
        {
            cout << " " << i << endl;
                
        }
    }
}

int main()
{
    gen_sieve_primes();

    print_all_primes();

    return 0;
}