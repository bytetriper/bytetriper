#include<bits/stdc++.h>
using namespace std;
const int N=1e7+2;
bool isp[N];//0 ÎªÊÇËØÊı 
int p[N],cnt=0,n=100;
inline void euler_sieve()
{
	isp[1]=true;
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
	int m,n;
	scanf("%d%d",&m,&n);
	euler_sieve();
	int cnt=0;
	for(int i=m;i<=n;i++)
		if(!isp[i])
			cnt++;
	printf("%d\n",cnt);
	return 0;
}

