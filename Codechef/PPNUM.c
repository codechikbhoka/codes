#include <stdio.h>
#include <math.h>
 
int main() 
{
	long long int t,l,x,r,i,d1,d2,sum,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&l,&r);
		d1=log10(l)+1;
		d2=log10(r)+1;
		sum=0;
		if(d1==d2)
		{
			n=r-l;
			sum=((l*(n+1))+(n*(n+1)/2))*d1;
		}
		else
		{
			while(d1!=d2)
			{
				x=pow(10,d1)-1;
				n=x-l;
				sum+=(((l*(n+1))+(n*(n+1)/2))*d1);
				++d1;
				l=x+1;
			}
			n=r-l;
			sum+=(((l*(n+1))+(n*(n+1)/2))*d1);
		}
		printf("%lld\n",sum%1000000007);
	}
	return 0;
}