#include <bits/stdc++.h>  //all pre-compiled header files
 
#define INF 1000000007
#define LL long long
 
using namespace std;
 
int a[100050];
int b[100050];
int n;
 
int main ()
{
    int t,c,i,j,k;
 
    cin >> t;
    while (t--)
    {
        cin >> n;
 
        i=0;j=0;
        while (i<n)     cin >> a[i++];
        while (j<n)     cin >> b[j++];
 
        sort (a,a+n);
        sort (b,b+n);
 
        b[n] = INF;
 
        LL ans = 0;
        int one,two;
 
        i=0;
        while (b[i]<=1)
        {
            b[i] = INF;
            i++;
        }
 
        one = i;
 
        while (b[i]<=2)
        {
            b[i] = INF;
            i++;
        }
 
        two = i;
 
        sort(b,b+n);
 
        int m = n-two;
 
        for (int i=0;i<n;i++)
        {
            if (a[i] == 2)
            {
                int pos = upper_bound(b,b+n,4)-b;
 
                pos = m - pos;
                ans += (pos+one);
            }
 
            else if (a[i] == 3)
            {
                int pos = upper_bound(b,b+n,3)-b;
 
                pos = m - pos;
 
                pos += two;
                ans += (pos);
            }
 
            else if (a[i] > 3)
            {
                int pos = upper_bound(b,b+n,a[i])-b;
 
                pos = m - pos;
 
                pos += one;
                ans += pos;
            }
        }
 
        printf ("%.10lf\n",ans*1.0/n);
    }
 
    return 0;
}