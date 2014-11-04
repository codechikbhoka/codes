#include <iostream>
#include <string.h>
#include <climits>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
#include <sstream>
#include <vector>
#include <map>
#define MOD 1000000007
#define getcx getchar_unlocked
using namespace std;


long long int f[100],fact[100],invfact[100];
long long int powmod(long long int base, long long int expo)
{
    if (expo == 0)
                return 1;
        else if (expo & 1)
                return (long long) base *powmod(base, expo - 1) % MOD;
        else {
                long long int root = powmod(base, expo >> 1);
                return (long long) root *root % MOD;
        }
 
}
 
long long int inverse(long long int x)
{
        return powmod(x, MOD - 2);
 
}
 
void init()
{
        fact[0] = 1;
        for (int i = 1; i <= 100; i++)
                fact[i] = (long long) i *fact[i - 1] % MOD;
        invfact[100] = inverse(fact[100]);
        for (int i = 100; i > 0; i--)
                invfact[i - 1] = (long long) i *invfact[i] % MOD;
 
}
 
long long int comb(long long n,long long k)
{
        return (((fact[n]*invfact[n-k])%MOD)*invfact[k])%MOD;
}



inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
int main()
{
        init();
        int n;
        for (int i = 0; i < 100; ++i)
        {
                f[i]=0;
        }
        f[0]=1;
        f[1]=1;
        for (int i = 2; i <= 100; ++i)
        {
                for(int j=1;j<=i;j++)
                {
                        f[i]=(f[i]+((((comb(i-1,j-1)*powmod(2,i-j)%MOD)*fact[i-j]%MOD)*f[j-1]%MOD)))%MOD;
                }
        }
        int testcases;
        inp(testcases);
        while(testcases--)
        {
                inp(n);
                if (n==0)
                {
                	cout<<"0"<<endl;
                }
                else
                {
                	printf("%lld\n",f[n]);
                }
                
        }
        return 0;
}