#include<bits/stdc++.h>
using namespace std;
inline bool ispn(int n)
{
	int ans=0;
	for(int i=1;i<sqrt(n);i++)
		if(n%i==0)
			ans+=i+n/i;
	if(sqrt(n)*sqrt(n)==n)
		ans+=sqrt(n);
	return ans==2*n;		
}
int main()
{
	int lb,ub;
	scanf("%d%d",&lb,&ub);
	for(int i=lb;i<=ub;i++)
		if(ispn(i))
			printf("%d ",i);
	printf("\n");
	return 0; 
}

