 #include<bits/stdc++.h>
using namespace std;
int n,*a,*ans;
inline void sort1()//—°‘Ò≈≈–Ú 
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]>a[i])
				swap(a[j],a[i]);
} 
inline void sort2()//√∞≈›≈≈–Ú
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]); 
} 
void mergesort(int l,int r)//πÈ≤¢≈≈–Ú
{
	if(l==r)return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	int t1=l,t2=mid+1,cnt=t1;
	while(t1<=mid&&t2<=r)
	{
		while(a[t1]>a[t2]&&t1<=mid)
			ans[cnt++]=a[t1++];
		ans[cnt++]=a[t2++];
	}
	while(t1<=mid)
		ans[cnt++]=a[t1++];
	while(t2<=r)
		ans[cnt++]=a[t2++];
	for(int i=l;i<=r;i++)
		a[i]=ans[i];
	return;
} 
int main()
{
	scanf("%d",&n);
//	sort(a+1,a+n+1);
	a=new int [n+10]{};
	ans=new int [n+10]{};
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);	
//	printf("which sort do you want to use?");
//  sort1();
//    sort2();
    mergesort(1,n);
    for(int i=1;i<=n;i++)
    	printf("%d ",ans[i]);
    printf("\n"); 
	return 0; 
}

