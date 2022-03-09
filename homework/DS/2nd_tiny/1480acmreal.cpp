#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int a[N];
int n[N],y[N];
struct node
{
    int ls,rs;
    int l,r;
    int n0,n1;
    int mx;
}c[N];
int cnt=1;
inline void build(int k,int l,int r)
{
    c[k].l=l;
    c[k].r=r;
    if(l==r)
    {
        c[k].mx=1;
        c[k].n0=a[l]^1;
        c[k].n1=a[l];
        return;
    }
    int mid=(l+r)>>1;
    c[k].ls=++cnt;
    build(c[k].ls,l,mid);
    c[k].rs=++cnt;
    build(c[k].rs,mid+1,r);
    c[k].n0=c[c[k].ls].n0+c[c[k].rs].n0;
    c[k].n1=c[c[k].ls].n1+c[c[k].rs].n1;
    c[k].mx=max(c[k].n0,max(c[c[k].ls].n0+c[c[k].rs].mx,c[c[k].ls].mx+c[c[k].rs].n1));
}
inline int search(int k,int l,int r)
{
    if(c[k].l>r||c[k].r<l)
        return 0;
    if(c[k].l==c[k].r)
        return c[k].mx;
    int mid=(c[k].l+c[k].r)>>1;
    if(r<=mid)
        return search(c[k].ls,l,mid);
    if(l>mid)
        return search(c[k].rs,mid+1,r);
    int t1=n[mid]-n[l-1]+search(c[k].rs,mid+1,r);
    int t2=y[r]-y[mid]+search(c[k].ls,l,mid);
    return max(t1,t2);
}
inline int search1(int l,int r)
{
    if(l==r)
        return 1;
    int mid=(l+r)>>1;
    if(y[r]-y[mid]&&n[mid]-n[l-1])
        return 2;
    if(n[mid]-n[l-1]==0)
        return search1(mid+1,r);
    else
        return search1(l,mid);
}
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
    build(1,1,n1);
    int l,r,op;
    for(int i=1;i<=m;i++)
    {
        op=read();
        l=read();
        r=read();
        if(op==1)
        {
            printf("%d\n",search(1,l,r));
        }
        else
            printf("%d\n",search1(l,r));
    }
    return 0;
}