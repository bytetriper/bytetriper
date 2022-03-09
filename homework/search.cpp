#include<bits/stdc++.h>
using namespace std;
int tmp[1001];int cnt=0;
inline int *search(const int arr[],int n,int key)
{
//	extern int cnt;
	n--;
	int *p=new int [n+1]; 
	for(int i=1;i<=n;i++)
		if(arr[i]==key)
			p[++cnt]=i;
//	arr[1]=19901;
	return p;
} 

int main()
{
	int m,k;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&tmp[i]);
	scanf("%d",&k);
	int *t=search(tmp,m,k);
	if(!cnt)
		printf("-1\n");
	else
	{
		for(int i=1;i<=cnt;i++)
			printf("%d ",t[i]);
		printf("\n");
	}
	return 0;
}

