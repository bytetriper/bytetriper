#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	printf("������n��m��");
	scanf("%d%d",&n,&m);
	if(m%2||2*n<m/2||m/2<n)printf("�޽�");
	else
		printf("����%d���ã�%d",2*n-m/2,m/2-n);
	return 0;
}

