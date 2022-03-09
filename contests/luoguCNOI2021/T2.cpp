#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod=998244353;
const int N=1e5+1;
lli a[N],b[N];
template<class T>
inline void read(T &x)
{
    x=0;
    char ch=47;
    bool fg=0;
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            fg=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+(ch-'0');
        ch=getchar();
    }
    if(fg)
        x*=-1;
}
inline lli quickmod(lli k,lli x)
{
    if(!k)
        return 1;
    lli tmp=quickmod(k>>1,x);
    if(k%2)
        return (((tmp*tmp)%mod)*x)%mod;
    else
        return (tmp*tmp)%mod;
}//17724700734
int main()
{
    int n;
    lli t;
//    read(n);
//    read(t);
    scanf("%d%lld",&n,&t);
    for(int i=1;i<=n;i++)
    {    
        scanf("%lld",&a[i]);
        a[i]%=mod;
    }
    for(int i=1;i<=n;i++)
    {    
        scanf("%lld",&b[i]); 
        b[i]%=mod;
    }   
    if(!t)
    {
        printf("%d",n);
        return 0;
    }
    lli siga=0,sigb=0,sigab=0;
    for(int i=1;i<=n;i++)
        sigb=(sigb+b[i])%mod;
    for(int i=1;i<=n;i++)
        siga=(siga+a[i])%mod;
    for(int i=1;i<=n;i++)
        sigab=(sigab+a[i]*b[i])%mod;
    printf("%lld\n",((quickmod(t-1,sigab)*siga)%mod*sigb)%mod);
    return 0;
}