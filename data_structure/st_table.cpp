#include<bits/stdc++.h>//怎么抄洛谷原题.....
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int N=5e5+1;
long long  a[N],f[N][20];
int n;
inline void prermq()
{
    for(int i=1;i<=n;i++)
        f[i][0]=a[i];
    for(int j=1;j<=log2(n)+2;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
inline int rmq(int l,int r)
{
    int x=log2(r-l+1);
    return max(f[l][x],f[r+1-(1<<x)][x]);
}
int main()
{
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    int m;
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    prermq();
    int t1,t2;
    for(int i=1;i<=m;i++)
    {
        t1=read();
        t2=read();
        printf("%lld\n",rmq(t1,t2));
    }
    return 0;
}