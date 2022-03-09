#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N],b[N];
int main()
{
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {    
        scanf("%d",&b[i]);
        ans+=min(b[i],a[i]);
    } 
    printf("%lld\n",ans);
    return 0;
}