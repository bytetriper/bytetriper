#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
const int INF=1e9+1;
/*
class pr
{
    public:
    int id,val;
    pr(int x=0,int y=0):id(x),val(y){}
    friend void swap();
    bool operator > (const pr &b)const{
        return val>b.val;
    }
    bool operator <(const pr &b)const{
        return val<b.val;
    }
};
void swap(pr &a,pr &b)
{
    pr tmp=a;
    a=b;
    b=tmp;
    return;
};*/
template<class T>//T is required to have *swap* and operator '>'
class hp
{
    public:
    static int cnt;
    int fa[N];
    int root;
    T t[N];
    hp():root(1){fa[1]=0;}
    inline T top()
    {
        return t[root];
    }
    inline void insert(const T &p)
    {
        t[++cnt]=p;
        fa[cnt]=cnt>>1;
        int tmp=cnt;
        while(fa[tmp]&&t[fa[tmp]]>p)
        {
            swap(t[fa[tmp]],t[tmp]);
            tmp=fa[tmp];
        }
        return;
    }
    inline void pop()
    {
        swap(t[cnt--],t[root]);
        int ls,rs,tar,tmp=root;
        while((tmp<<1)<=cnt)
        {
            tar=ls=tmp<<1;
            rs=ls+1;
            if(rs<=cnt)
                tar=t[tar]<t[rs]?ls:rs;
            if(t[tmp]>t[tar])
                swap(t[tmp],t[tar]);
            tmp=tar;
        }
        return;
    }
};
template<class T>
int hp<T>::cnt=0;
int main()
{
    int n;
    hp<int> H;
    scanf("%d",&n);
    int op,t1;
    for(int i=1;i<=n;i++)
    {    
        scanf("%d",&op);
        switch (op)
        {
            case 1:
                scanf("%d",&t1);
                H.insert(t1);
            break;
            case 3:
                H.pop();
                break;
            case 2:
                printf("%d\n",H.top());
        }
    }
    return 0;
}