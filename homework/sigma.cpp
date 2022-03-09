#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,n;
	long long ans=0,tmp=0;
	scanf("%d%d",&a,&n); 
	for(int i=1;i<=n;i++)
	{
		tmp=tmp*10+a;
		ans+=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}

