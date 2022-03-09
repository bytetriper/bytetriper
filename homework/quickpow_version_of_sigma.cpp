#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
inline lli quickpow(lli k,int n)
{
	if(n==1)
		return k; 
	lli tmp=quickpow(k,n/2);
	if(n%2)
		return tmp*tmp*k;
	else
		return tmp*tmp;
} 
int main()
{
	lli a;
	int t;
	scanf("%lld %d",&a,&t);
	printf("%lld\n",a*(quickpow(10,t+1)-10-9*t)/81);
	return 0;
}

