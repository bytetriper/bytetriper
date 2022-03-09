#include<cstdio>
using namespace std;
typedef long long int lli;
lli mod=998244353;
lli n,k;
int main()
{
    scanf("%lld%lld",&n,&k);
    lli ans=(k*((n*n)%mod-1)+1)%mod;
    printf("%lld\n",ans);
    return 0;
}