#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 210000
#define inf 1<<29
#define LL long long
using namespace std;

int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];

int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}


void da(const char *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;

    for(i=0;i<m;i++) Ws[i]=0;
    for(i=0;i<n;i++) Ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) Ws[i]+=Ws[i-1];
    for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;

    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) Ws[i]=0;
        for(i=0;i<n;i++) Ws[wv[i]]++;
        for(i=1;i<m;i++) Ws[i]+=Ws[i-1];
        for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
 return;
}


int sa[maxn],Rank[maxn],height[maxn];

void calheight(const char *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++) Rank[sa[i]]=i;
    for(i=0;i<n;height[Rank[i++]]=k)
    for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}


char a[maxn],b[maxn];

int main()
{
    scanf("%s%s",a,b);
    int la=strlen(a),lb=strlen(b),l=la+lb+1;
    a[la]='a'-1;
    for(int i=la+1;i<l;i++)
    a[i]=b[i-la-1];
    a[l]=0;
    da(a,sa,l+1,130);
    calheight(a,sa,l);
    LL ret=(LL)la*(la+1)/2+(LL)lb*(lb+1)/2;
    int aa=0,bb=0;
    for(int i=0;i<=l;i++)
    {
        aa=min(aa,height[i]);
        bb=min(bb,height[i]);

        if(sa[i]<la)
        {
            ret-=aa;
            if(bb>aa) ret-=2*(bb-aa);
            aa=inf;
        }
        else
        {
            ret-=bb;
            if(aa>bb) ret-=2*(aa-bb);
            bb=inf;
        }
    }
    
    printf("%lld\n",ret);
    return 0;
} 