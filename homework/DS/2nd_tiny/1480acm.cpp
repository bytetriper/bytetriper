#include<bits/stdc++.h>
using namespace std;
const int N=8e5+1;
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
int st[N],en[N],len[N];
int cnt=0;
int a[N],d[N],idx[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m); 
    a[0]=2;
    for(int i=1;i<=n;i++)
    {    scanf("%d",&a[i]);
        d[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]>=0)
        {
            st[++cnt]=i-1;
            while(d[i]>0)
                idx[i++]=cnt;
            len[cnt]=i-st[cnt];
            en[cnt]=i-1;
        }
        else
            idx[i]=0;
    }
    st[0]=N;
    en[0]=0;
    rmq R(len,cnt);
    R.init();
    int t1,t2,op;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&op,&t1,&t2);
        t1+=1;
        if(op==1)
        {
            int t=max(en[idx[t1]]-t1+1,t2-st[idx[t2]]+1);
            printf("%d\n",max(max(t,1),R.query(idx[t1]+1,idx[t2]-1))); 
        }
    }
    return 0;
}