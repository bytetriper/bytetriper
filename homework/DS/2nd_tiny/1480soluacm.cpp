#include<bits/stdc++.h>
using namespace std;
const int N=3e6+1;
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
    int *r[27];
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
    rmq(int *b,int l):siz(l)
    {
        a=b; 
        init();
    }
    inline int query(int l1,int r1)
    {
        if(l1>r1)
            return 0;
        int x=log2(r1-l1+1);
        return max(r[x][l1],r[x][r1+1-(1<<x)]);
    }
};
int a[N];
int n[N],y[N],s[N],s2[N];
int main()
{
    int n1,m;
    n1=read();
    m=read();
    y[0]=n[0]=0;
    for(int i=1;i<=n1;i++)
    {
        a[i]=read();
        y[i]=y[i-1]+a[i];
        n[i]=n[i-1]+(a[i]^1);
    }
    for(int i=1;i<=n1+1;i++)
        s[i]=n[i-1]+(y[n1]-y[i-1]);
    rmq R(s,n1+1);
    for(int i=1;i<=n1+1;i++)
        s2[i]=s[i]*(-1);
    rmq R1(s2,n1+1);
    int t1,t2,op;
    for(int i=1;i<=m;i++)
    {
        op=read();t1=read();t2=read();
        if(op==1)
            printf("%d\n",R.query(t1,t2+1)-(y[n1]-y[t2])-n[t1-1]);
        else
        {
            if(R1.query(t1,t2+1)+(y[n1]-y[t2])+n[t1-1]!=0)
                printf("2\n");
            else
                printf("1\n");
        }
    }
}