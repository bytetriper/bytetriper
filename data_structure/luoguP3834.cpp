#include<bits/stdc++.h>//sb luogu!
using namespace std;
typedef long int lli;
const lli maxn=1e9+1;
int n,m;
class node
{
    public:
    int ls,rs;
    lli num;
    node():ls(0),rs(0),num(0){}
/*    node & opetator =(const node &b)
    {
        ls=b.ls;
        rs=b.rs;
        l=b.l;
        r=b.r;
        num=b.num;
        return *this;
    }
*/
};
class segtr
{
    public:
    node *c; 
    public:
    int *root;
    int cnt;//½ÚµãÊý
    segtr():cnt(0)//root node
    {
        root=new int [n+3];
        c=new node [m*40];    
    }
//    inline void build(int k,int ld,int rd);
    inline void change(int k,int org,lli pos,lli l,lli r);
    inline int query(int k,int org,lli l,lli r,int idx);
    ~segtr()
    {
        delete[] root;
        delete[] c;
    }
};
lli *a;
void segtr::change(int k,int org,lli pos,lli l,lli r)
{
    c[k]=c[org];
    if(l==r)
    {
        if(pos==l)
        {
            c[k].num++;
            return;
        }
    }
    lli mid=(l+r)>>1;
    if(pos<=mid)
    {
        c[k].ls=++cnt;    
        change(c[k].ls,c[org].ls,pos,l,mid);
    }
    else
    {
        c[k].rs=++cnt;
        change(c[k].rs,c[org].rs,pos,mid+1,r);
    }
    c[k].num=c[c[k].ls].num+c[c[k].rs].num;
}
int segtr::query(int k,int org,lli l,lli r,int idx)
{
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    if(c[c[k].ls].num-c[c[org].ls].num>=idx)
        return query(c[k].ls,c[org].ls,l,mid,idx);
    else
        return query(c[k].rs,c[org].rs,mid+1,r,idx-c[c[k].ls].num+c[c[org].ls].num);
}
template<class T>
inline void read(T &x)
{
    x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){
        if(c=='-')
            flag=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    if(flag)
        x=-x;
}
int main()
{
   read(n);read(m);
    //scanf("%d%d",&n,&m);
    a=new lli [n+3];
    for(int i=1;i<=n;i++)
        read(a[i]);
 //   cout<<a[2]<<endl;
    segtr C;
    C.root[0]=++C.cnt;
    for(int i=1;i<=n;i++)
        C.change(C.root[i]=++C.cnt,C.root[i-1],a[i],-maxn,maxn);
    lli t1,t2;
    int idx;
    for(int i=1;i<=m;i++)
    {
        read(t1);read(t2);read(idx);
        printf("%d\n",C.query(C.root[t2],C.root[t1-1],-maxn,maxn,idx));
    }
    delete[] a;
    return 0;
}
/*
5 5
4 3 2 1 0
2 2 1
3 4 1
4 5 1
1 2 2
4 4 1
4 4
5933 27023 26153 31496 
1 4 4
1 4 4
1 4 1
1 4 4
*/