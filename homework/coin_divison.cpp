#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;i+2*j<n;j++)
			if((n-i-2*j)%5==0)
				cnt++;
	printf("%d\n",cnt);
	return 0;
}

