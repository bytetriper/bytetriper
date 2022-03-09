#include<bits/stdc++.h>
using namespace std;
const int N=1e7+2;
bool isp[N];
int p[N],cnt=0,n=100;
inline void euler_sieve()
{
	for(int i=2;i<=n;i++)
	{
		if(!isp[i])p[++cnt]=i;
		for(int j=1;j<=cnt&&i*p[j]<=n;j++)
		{
			isp[i*p[j]]=true;
			if(i%p[j]==0)
				break;
		}
	}
}
int main()
{
	memset(isp,0,sizeof(isp));
	int st=clock(); 
	scanf("%d",&n);
	euler_sieve();
	for(int i=1;i<=cnt;i++)
		printf("%d\n",p[i]);
	int en=clock()-st;
//	printf("%d\n",en);
	return 0;
}

