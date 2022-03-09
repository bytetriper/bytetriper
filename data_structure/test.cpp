#include<bits/stdc++.h>
using namespace std;
const int N=8e5+1;
class rmq
{
    public:
    int *a;//1-based
    int siz;
    int *r[21];
    rmq(int *b,int l):siz(l)
    {
        a=b; 
    }
    inline void init()
    {
        int lim=log2(siz)+2;//2 is the modifier
        for(int i=0;i<=lim;i++)
            r[i]=new int [siz+1];
        for(int i=1;i<=siz;i++)
            r[0][i]=a[i];    
        for(int j=1;j<=lim;j++)
            for(int i=1;i+(1<<j)-1<=siz;i++)
                r[j][i]=max(r[j-1][i],r[j-1][i+(1<<(j-1))]);
    }
    inline int query(int l1,int r1)
    {
        if(l1>r1)
            return 0;
        int x=log2(r1-l1+1);
        return max(r[x][l1],r[x][r1+1-(1<<x)]);
    }
};
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m;
int a[N];
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    rmq R(a,n);
    R.init();
    int t1,t2;
    for(int i=1;i<=m;i++)
    {
        t1=read();
        t2=read();
        printf("%d\n",R.query(t1,t2));
    }
    return 0;
}