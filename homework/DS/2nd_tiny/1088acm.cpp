#include<bits/stdc++.h>
using namespace std;
const int N=8e5+1;
struct node
{
    int ls,rs,num;
    int l,r;
}c[N];
int cnt=1,root;
int a[N],n;
inline int upd(int k)//not for the leaf node!
{
    c[k].num=c[c[k].ls].num+c[c[k].rs].num;
    return c[k].num;
}
inline void build(int k,int l,int r)
{
    c[k].l=l;
    c[k].r=r;
    if(l==r)
    {
        c[k].num=1;
        return;
    }
    int mid=(l+r)>>1;
    c[k].ls=++cnt;
    build(c[k].ls,l,mid);
    c[k].rs=++cnt;
    build(c[k].rs,mid+1,r);
    upd(k);
}
inline int getbd(int k,int l1,int r1)
{
    if(c[k].l>r1)
        return 0;
    if(c[k].r<l1)
        return 0;
    if(c[k].l>=l1&&c[k].r<=r1)
        return c[k].num;
    return getbd(c[k].ls,l1,r1)+getbd(c[k].rs,l1,r1);
}
inline int findm(int k,int m,int dir)//find the mth number in corrsponding direct
{//m is supposed to be smaller than the c[root].sum
    c[k].num--;
    if(c[k].l==c[k].r)
    {
        return c[k].l;
    }
    if(dir)
    {
        if(c[c[k].ls].num<m)
            return findm(c[k].rs,m-c[c[k].ls].num,dir);
        else
            return findm(c[k].ls,m,dir);
    }
    else
    {
        if(c[c[k].rs].num<m)
            return findm(c[k].ls,m-c[c[k].rs].num,dir);
        else   
            return findm(c[k].rs,m,dir);
    }
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    m%=2*n-1;
    build(root=1,1,n);
    int pos=1,lft,tmp=m,dr=1;
    while(c[root].num>1)
    {

        if(dr)
            lft=getbd(root,pos,n);
        else    
            lft=getbd(root,1,pos);
        if(tmp==lft)
        {
            pos=findm(root,c[root].num,dr);
            dr^=1;
            //cout<<pos<<endl;
            continue;
        }
        if(tmp>lft)
        {   
            tmp-=lft-1;
            dr^=1;
            pos=n;
            continue;
        }
        pos=findm(root,tmp+c[root].num-lft,dr); 
        m%=2*c[root].num-1; 
        tmp=m;
        //cout<<pos<<endl;
    }
    //cout<<"test3"<<endl;
    printf("%d\n",findm(root,1,dr));
}