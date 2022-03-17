#include<bits/stdc++.h>
using namespace std;
const int N=4e6+1;
struct node
{
    int fa,ls,rs;
    int l,r,dep;
    node():dep(1),ls(0),rs(0){}
    node& operator =(const node b)
    {
        if(!ls)
            ls=b.ls;
        if(!rs)
            rs=b.rs;
        l=b.l;
        r=b.r;
        dep=b.dep;
        fa=b.fa;
        return *this;
    }
}c[N];
int root[N],rt2[N],rcnt=0,cnt=0;//node
inline void build(int l,int r,int k)
{
    c[k].l=l;
    c[k].r=r;
    if(l==r)
    {    
        c[k].fa=l;
        return;
    }
    int mid=(l+r)>>1;
    c[k].ls=++cnt;
    c[k].rs=++cnt;
    build(l,mid,c[k].ls);
    build(mid+1,r,c[k].rs);
}
inline void change(int p,int org,int k,int md,bool op=0)
{
    c[k]=c[org];
    if(c[k].l==c[k].r)
    {
        if(!op)
            c[k].fa=md;
        else
            c[k].dep+=md;
        return;
    }
    int mid=(c[k].l+c[k].r)>>1;
    if(p<=mid)
    {
        c[k].ls=++cnt;
        change(p,c[org].ls,c[k].ls,md,op);
    }
    else
    {
        c[k].rs=++cnt;
        change(p,c[org].rs,c[k].rs,md,op);
    }
}
inline int qr(int p,int k)//query
{
    if(c[k].l==c[k].r)
        return k;
    int mid=(c[k].l+c[k].r)>>1;
    if(p<=mid)
        return qr(p,c[k].ls);
    else
        return qr(p,c[k].rs); 
}
inline int fd(int k)
{
    int tmp=qr(k,root[rcnt]);
    if(c[tmp].fa==k)
        return tmp;
    return fd(c[tmp].fa);
}//bcj
inline void mg(int id1,int id2,int k=rcnt)//merge
{
    int f1=fd(id1),f2=fd(id2);
    int d1=c[qr(c[f1].l,rt2[rcnt])].dep;
    int d2=c[qr(c[f2].l,rt2[rcnt])].dep;
    if(c[f1].l==c[f2].l)
    {
        rcnt++;
        root[rcnt]=root[rcnt-1];
        rt2[rcnt]=rt2[rcnt-1];
        return;
    }
    root[++rcnt]=++cnt;
    rt2[rcnt]=rt2[rcnt-1];
    if(d1>d2)
        change(c[f2].l,root[k],root[rcnt],c[f1].l);
    else
    {
        change(c[f1].l,root[k],root[rcnt],c[f2].l);        
        if(d1==d2)
        {  
            rt2[rcnt]=++cnt;
            change(c[f2].l,rt2[rcnt-1],rt2[rcnt],1,1);
        }
    }
    return;
}//lnt
int main()
{
    int n,m;
    int op,t1,t2;
    scanf("%d%d",&n,&m);
    root[0]=++cnt;
    build(1,n,root[0]);
    rt2[0]=root[0];
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&op,&t1);
        if(op==1)
        {
            scanf("%d",&t2);
            mg(t1,t2,rcnt);
        }
        if(op==2)
        {
            rcnt++;
            root[rcnt]=root[t1];
            rt2[rcnt]=rt2[t1];
        }
        if(op==3)
        {
            scanf("%d",&t2);
            if(c[fd(t1)].l==c[fd(t2)].l)
                printf("1\n");
            else
                printf("0\n");
            rcnt++;
            root[rcnt]=root[rcnt-1];
            rt2[rcnt]=rt2[rcnt-1];
        }
    }
    
}