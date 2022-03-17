#include<bits/stdc++.h>
using namespace std;
#define merge mg
const int N=2e5+1;
class node
{
    public:
    int val,fa,siz,cnt;
    int ch[2];//0 for left son.1 for right
    bool vis;
    node(int v=0):val(v),vis(0),siz(0),cnt(0),fa(0)
    {}//-1 stands for unvisit
};
node c[N];
int cnt=0;
inline bool gets(int k)
{
    return (k==c[c[k].fa].ch[1]);
}
inline void maintain(int x)
{
    c[x].siz=c[c[x].ch[1]].siz+c[c[x].ch[0]].siz+c[x].cnt;
}
class splay
{
    public:
    int root;
    splay(){root=++cnt;}
    inline void rotate(int x)//0 for left 1 for right
    {
        if(!c[x].fa)  return;
        bool op=gets(x);
        int y=c[x].fa,z=c[y].fa;
        if(z)
            c[z].ch[gets(y)]=x;
        c[x].fa=z;
        c[y].ch[op]=c[x].ch[!op];
        c[c[x].ch[!op]].fa=y;
        c[y].fa=x;
        c[x].ch[!op]=y;
        maintain(y);
        maintain(x);
        return;
    }
    inline void adjust(int x)
    {
        while(c[x].fa)
        {
            if(c[c[x].fa].fa)
            {
                if(gets(x)==gets(c[x].fa))
                {
                    rotate(c[x].fa);
                    rotate(x);
                }
                else
                {
                    rotate(x);
                    rotate(x);
                }
            }
            else
                rotate(x);
        }
        root=x;
    }
    inline int findx(int x,int k)
    {
        if(!x)return 0;
        if(c[x].val==k)
        {
            adjust(x);
            return c[c[x].ch[0]].siz+1;
        }
        return findx(c[x].ch[c[x].val<k],k);  
    }
    inline int findk(int x,int k)//(k)^th number
    {
        if(!x)return 0;
        if(c[c[x].ch[0]].siz<k&&c[c[x].ch[0]].siz+c[x].cnt>=k)
        {
            adjust(x);
            return x;
        }
        if(c[c[x].ch[0]].siz>=k)
            return findk(c[x].ch[0],k);
        else
            return findk(c[x].ch[1],k-c[c[x].ch[0]].siz-c[x].cnt);
    }
    inline void insert(int x,int k)
    {
        if(!c[root].vis)
        {
            c[root].vis=1;
            c[root].cnt=c[root].siz=1;
            c[root].val=k;
            return;
        }
        if(c[x].val==k)
        {
            c[x].cnt++;
            c[x].siz++;//test
            adjust(x);
            return;
        }
        int op=c[x].val<k;
        if(!c[x].ch[op])
        {
            c[x].ch[op]=++cnt;
            c[cnt].vis=1;
            c[cnt].fa=x;
            c[cnt].val=k;
            c[cnt].cnt=c[cnt].siz=1;
            adjust(cnt);
            return;
        }
        insert(c[x].ch[op],k);
    }
    inline int gt(int k,bool op)//1 for nxt and 0 for last
    {
        insert(root,k);//tree won't be empty in here
        int tmp=c[root].ch[op];
        if(!tmp)
            return -1;
        while(c[tmp].ch[!op])
            tmp=c[tmp].ch[!op];
        del(k);
        return tmp;
    }
    inline void merge(int x,int y)//max(x)<min(y) && x and y is not empty
    {
        int rtx=findk(x,c[x].siz);
        int rty=findk(y,1);  
        c[rtx].fa=rty;
        c[rty].ch[0]=rtx;
        root=rty;
        maintain(rty);
        return;
    }
    inline void del(int k)
    {
        findx(root,k);
        if(c[root].cnt>1)
        {
            c[root].cnt--;
            c[root].siz--;
            return;
        }
        c[c[root].ch[0]].fa=c[c[root].ch[1]].fa=0;
        if(c[root].ch[0]&&c[root].ch[1])
            merge(c[root].ch[0],c[root].ch[1]);
        else
        {
            if((!c[root].ch[0])&&(!c[root].ch[1]))
                root=++cnt;
            else
                root=abs(c[root].ch[0]-c[root].ch[1]);
        }
        return;
    }
    inline void pr(int x)
    {
        cout<<c[x].val<<" "<<c[c[x].ch[0]].val<<" "<<c[c[x].ch[1]].val<<endl;
        if(c[x].ch[0])
            pr(c[x].ch[0]);
        if(c[x].ch[1])
            pr(c[x].ch[1]);
    }
};
int main()
{
    splay tr;
    int n;
    scanf("%d",&n);
    int op,num;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&op,&num);
        switch (op)
        {
            case 1: tr.insert(tr.root,num);
                break;
            case 2: tr.del(num);
                break;
            case 3: cout<<tr.findx(tr.root,num)<<endl;
                break;
            case 4: cout<<c[tr.findk(tr.root,num)].val<<endl;
                break;
            case 5: cout<<c[tr.gt(num,0)].val<<endl;
                break;
            case 6: cout<<c[tr.gt(num,1)].val<<endl;
                break;
        }
        //tr.pr(tr.root);
         //   cout<<"siz:"<<c[tr.root].siz<<endl;
    }
    return 0;
}/*
10
1 16
1 31
1 46
1 64
1 8
1 9
*/