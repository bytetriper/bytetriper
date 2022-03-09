#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int nxt[N],pre[N]; 
inline void josephus(int *arr, int n)
{
	int tmp=0;
	for(int i=0;i<n;i++)
		nxt[i]=(i+1)%n; 
	for(int i=0;i<n;i++)
		pre[i]=(i+n-1)%n;
	int i;
	for(i=0;nxt[i]!=i;i=nxt[i])
	{
		tmp++;
		if(tmp==3)
		{
			nxt[pre[i]]=nxt[i];
			pre[nxt[i]]=pre[i];
			tmp=0;
		}
	}
	printf("%d\n",i+1);
	return; 
}
int main()
{
	int tmp; 
	scanf("%d",&tmp);
	josephus(NULL,tmp);
	return 0;
}

