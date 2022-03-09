#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[27];
int ans[27];
void prt(int k)
{
	if(!k)
	{
		for(int i=n;i;i--)
			printf("%c",ans[i]+64);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			ans[k]=i;
			vis[i]=1;
			prt(k-1);
			vis[i]=0;
		}
	return;
}
int main()
{
	memset(vis,0,sizeof(vis));
	n=3;
	prt(n);
	return 0; 
}

