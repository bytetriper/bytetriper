#include<bits/stdc++.h>
using namespace std;
const int n=10;
int main()
{
	long long int sig=1,tmp=1;
	for(int i=2;i<=n;i++)
	{
		tmp*=i;
		sig+=tmp;
	}
	printf("%lld\n",sig);
	return 0; 
}

