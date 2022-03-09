#include<bits/stdc++.h>//sb luogu!
using namespace std;
typedef long int lli;
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
    int cnt;//节点数
    segtr():cnt(0)//root node
    {
        root=new int [25010001];
        c=new node [25010001];    
    }
    inline void build(int k,int ld,int rd);
    inline int change(int k,int org,lli cg,int pos,bool id,int l,int r);
//  inline void query(int k,int tg,int pos);
    ~segtr()
    {
        delete[] root;
        delete[] c;
    }
};
lli *a;
void segtr::build(int k,int ld,int rd)
{
    if(ld==rd)
    {
        c[k].num=a[ld];
        return;
    }
    int mid=(ld+rd)>>1;
    c[k].ls=++cnt;
    c[k].rs=++cnt;
    build(c[k].ls,ld,mid);
    build(c[k].rs,mid+1,rd);
}
int segtr::change(int k,int org,lli cg,int pos,bool id,int l,int r)//id==1为修改
{
    c[k]=c[org];
    if(l==r)
    {
        if(pos==l)
        {
            if(id)
                c[k].num=cg;
            return c[k].num;
        }
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
    {
        c[k].ls=++cnt;    
        return change(c[k].ls,c[org].ls,cg,pos,id,l,mid);
    }
    else
    {
        c[k].rs=++cnt;
        return change(c[k].rs,c[org].rs,cg,pos,id,mid+1,r);
    }
}
template<class T>
inline void read(T &x){
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
    a=new lli [1000003];
    for(int i=1;i<=n;i++)
        read(a[i]);
        //scanf("%d",&a[i]);
    segtr C;
    C.root[0]=++C.cnt;
    C.build(C.root[0],1,n);
    int op,v,loc;
    lli val;
    for(int i=1;i<=m;i++)
    {
        read(v);read(op);read(loc);
        //scanf("%d%d%d",&v,&op,&loc);
        C.root[i]=++C.cnt;
        if(op==1)
        {
            read(val);                       
            //scanf("%lld",&val);
            C.change(C.root[i],C.root[v],val,loc,1,1,n);
        }
        else
            printf("%d\n",C.change(C.root[i],C.root[v],0,loc,0,1,n));
    }
    delete[] a;
    return 0;
}