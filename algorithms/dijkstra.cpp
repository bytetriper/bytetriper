#include<bits/stdc++.h>
using namespace std;
const int N=10000;
const int INF=1e9+1;
class edge
{
    public:
    int val,st,en;
    edge *nxt;
    edge(int x,int y,int z,edge *p=nullptr):val(z),st(x),en(y),nxt(p)
    {}
    edge(const edge &p)
    {
        st=p.st;
        val=p.val;
        en=p.en;
        nxt=p.nxt;
    }
};
class E
{
    public:
    static int cnt;
    edge *head[N];
    E()
    {}
    inline void addedge(edge p)
    {
        edge *tmp=new edge(p);
        tmp->nxt=head[p.st];
        head[p.st]=tmp;
        tmp=NULL;
        cnt++;
        return;
    }
};
int E::cnt=0;
int n,m;
priority_queue<int,int> q;
inline void dijkstra(int s0)
{
    int d[N];
    for(i=1;i<=n;i++)
        d[i]=s0==i?0:INF;

}
int main()
{
    int t1,t2,t3;
    E e;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t1>>t2>>t3;
        e.addedge(edge(t1,t2,t3));
    }
    for(edge *i=e.head[1];i!=NULL;i=i->nxt)
        cout<<i->en<<endl;
    return 0;
}