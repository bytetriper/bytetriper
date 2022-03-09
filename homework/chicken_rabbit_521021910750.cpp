#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	printf("«Î ‰»În£¨m£∫");
	scanf("%d%d",&n,&m);
	if(m%2||2*n<m/2||m/2<n)printf("ŒﬁΩ‚");
	else
		printf("º¶£∫%d£¨Õ√£∫%d",2*n-m/2,m/2-n);
	return 0;
}

