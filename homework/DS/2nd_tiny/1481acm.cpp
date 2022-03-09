#include<bits/stdc++.h>
//时间复杂度O(n+m),空间复杂度O(n)
//记忆化solution
using namespace std;
const int N=1e5+1;
class node
{
    public:
    node *nxt,*pre;
    int idx;
    node(int x):idx(x),nxt(nullptr),pre(nullptr)
    {}
};
node *a[N],*fst=nullptr,*lst=nullptr;
int n,m;
inline void init()
{
    fst=new node(0);
    lst=new node(0);
    for(int i=1;i<=n;i++)
        a[i]=new node(i);
    a[1]->pre=fst;
    fst->nxt=a[1];
    a[1]->nxt=lst;
    lst->pre=a[1];
}
inline void add(int k,int x,int p)
{
    if(!p)
    {
        a[x]->nxt=a[k];
        a[x]->pre=a[k]->pre;
        a[k]->pre=a[x];
        (a[x]->pre)->nxt=a[x];
    }
    else
    {
        a[x]->pre=a[k];
        a[x]->nxt=a[k]->nxt;
        a[k]->nxt=a[x];
        (a[x]->nxt)->pre=a[x];
    }
}
bool d[N];//decide to delete or not
inline void del()
{
    node *a=fst,*tmp=nullptr;
    while(a!=lst)
    {
        if(d[a->idx])
        {
            d[a->idx]=0;
            (a->pre)->nxt=a->nxt;
            (a->nxt)->pre=a->pre;
            tmp=a;
            a=a->nxt;
            delete tmp;
        }
        else
            a=a->nxt;
    }
}
int main()
{
    scanf("%d",&n);
    init();
    int t1,t2;
    for(int i=2;i<=n;i++)
    {
        scanf("%d%d",&t1,&t2);
        add(t1,i,t2);
    }
    scanf("%d",&m);
    memset(d,0,sizeof(d));
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&t1);
        d[t1]=true;
    }
    del();
    node *a=fst;
    while(1)
    {
        a=a->nxt;
        if(a!=lst)
            printf("%d ",a->idx);
        else
            break;
    }
    return 0;
}