#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
class rmq
{
    public:
    int *a;//1-b
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
int a[N],b[N],d[N],sum[N];
int main()
{
    int n,q;
    n=read();
    q=read();
    a[0]=b[0]=d[0]=sum[0]=0;
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=n;i++)
    {    b[i]=read();
        d[i]=a[i]-b[i];
        sum[i]=sum[i-1]+d[i];
        d[i]=-sum[i];//reverse sum to let the minimum become maximum
    }
    rmq R1(d,n),R2(sum,n);
    R1.init();
    R2.init();
    int l,r;
    for(int i=1;i<=q;i++)
    {
        l=read();r=read();
        if(R2.query(l,r)-sum[l-1]>0||sum[r]-sum[l-1]!=0)
            printf("-1\n");
        else
        {
            printf("%d\n",R1.query(l,r)+sum[l-1]);
        }
    }
    return 0;
}