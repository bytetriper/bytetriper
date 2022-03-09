#include<bits/stdc++.h>
using namespace std;
const double ep=1e-6; 
int main()
{
	double x1,y1,x2,y2,x3,y3;
	printf("x1,y1:");
	scanf("%lf%lf",&x1,&y1);
	printf("x2,y2:");
	scanf("%lf%lf",&x2,&y2);
	printf("x3,y3:");
	scanf("%lf%lf",&x3,&y3);	
	if(abs((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1))<ep)
		printf("Yes");
	else
		printf("No");
	return 0;
}

