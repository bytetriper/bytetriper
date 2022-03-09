#include<bits/stdc++.h>
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
node *fst=nullptr,*lst=nullptr;
int n,m;
int b[N];
inline void init()
{
    fst=new node(0);
    lst=new node(0);
    node *tmp=fst;
    for(int i=1;i<=n;i++)
    {
        tmp->nxt=new node(b[i]);
        (tmp->nxt)->pre=tmp;
        tmp=tmp->nxt;
    }
    tmp->nxt=lst;
    lst->pre=tmp;
}
inline void add(int x,int y)
{
    node *tmp=fst;
    while(x--)
        tmp=tmp->nxt;
    node *t=tmp->nxt;
    tmp->nxt=new node(y);
    (tmp->nxt)->nxt=t;
    t->pre=tmp->nxt;
    (tmp->nxt)->pre=tmp;
    //for insert
}
inline void del(int x)
{
    node *tmp=fst;
    while(x--)
        tmp=tmp->nxt;
    (tmp->nxt)->pre=tmp->pre;
    (tmp->pre)->nxt=tmp->nxt;
    delete tmp;    
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    init();
    int t1,t2,t3;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&t1,&t2);
        if(t1==1)
        {
            scanf("%d",&t3);
            add(t2,t3);
        }
        else
            del(t2);
    }
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