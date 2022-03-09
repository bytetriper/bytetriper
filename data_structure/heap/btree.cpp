#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int num;
    bool empty;
    node *fa;
    node *rson,*nxt,*pre;  
    node(node *nxt=NULL,node *pre=NULL,int x=0,bool ety=1){
        fa=NULL;
        empty=ety;
        num=x;
        nxt=nxt;
        pre=pre;
    }
    friend node* merge(node *a,node *b,bool &fg)//O(1)
    {
        if(b->empty)
        {    
            fg=0;
            return a;
        }
        if(a->empty)
        {    
            fg=0;
            a=b;//overload!
            return a;
        }
        fg=1;
        if(b->num>a->num)
        {    
            b->fa=a;
            a->rson->pre=b;
            b->nxt=a->rson;
            a->rson=b;
            return a;
        }
        else
        {    
            a->fa=b;
            b->rson->pre=a;
            a->nxt=b->rson;
            b->rson=a;
            return b;
        }
    }
    friend void swp(node *a,node *b)//tmp for b
    {
        if(a==b)return;
        b->nxt=a->nxt;
        b->pre=a->pre;
        if(a->nxt)
            a->nxt->pre=b;
        if(a->pre)
            a->pre->nxt=b;
        a=b;
    }
};
class bheap
{
    public:
    int siz;//indicates the maximum number of btrees
    node *fst;//rightest son and next brother
    bheap(){}
    bheap(int x)
    {
        fst=new node(NULL,NULL,x,0);
        siz=1;
    }
    inline void init(int x)
    {
        fst=new node(NULL,NULL,x,0);
        siz=1;       
    }
    inline void heapmerge(bheap &b)
    {
        node *t1=fst,*t2=b.fst,*n1=NULL,*n2=NULL,*lft=NULL,*pr=NULL;
        node *tmp=NULL;
        bool fg,ed=0;
        while(1)
        {
            n1=t1->nxt;
            n2=t2->nxt;
            pr=t1->pre;
            if(n1==NULL)
            {
                if(n2==NULL)
                    ed=1;
                t1->nxt=new node(NULL,t1,-1,1);
                n1=t1->nxt;
            }
            if(n2==NULL)
            {
                t2->nxt=new node(NULL,t2,-1,1);
                n2=t2->nxt;
            }
            if(lft!=NULL)
            {
                tmp=merge(lft,t2,fg);
                if(fg)
                    lft=tmp;
                else
                {
                    tmp=merge(t1,tmp,fg);
                    if(fg)//t2 is empty but t1 is not
                    {    
                        lft=tmp;
                        n1->pre=new node(n1,pr,-1,1);
                        if(pr!=NULL)
                            pr->nxt=n1->pre;
                    }
                    else//t1 is empty
                    {
                        swp(t1,tmp);
                        lft=NULL;
                    }

                }                    
                if(ed)
                {
                    if(lft)
                    {
                        lft->pre=n1->pre;
                        n1->pre->nxt=lft;
                        lft->nxt=NULL;
                    }
                    break;
                }
                t1=n1;
                t2=n2;
                continue;
            }
            tmp=merge(t1,t2,fg);
            if(!fg)
                swp(t1,tmp);
            else
            {
                lft=tmp;
                n1->pre=new node(n1,pr,-1,1);
                if(pr!=NULL)
                    pr->nxt=n1->pre;
            }              
            if(ed)
            {
                if(lft)
                {
                    lft->pre=n1->pre;
                    n1->pre->nxt=lft;
                    lft->nxt=NULL;
                }
                break;
            } 
            t1=n1;
            t2=n2;
        }            
        if(lft!=NULL)
        {
            tmp=merge(t2,lft,fg);
        }
        while(t1->pre!=NULL)
            t1=t1->pre;
        fst=t1;//update fst
    }
    ~bheap(){}
};
bheap c[101];
int main()
{
    int n,m,t;
    cin>>n>>m;
    for(int i=1;i<=2;i++)
    {
        cin>>t;
        c[i].init(t);
    }
    c[1].heapmerge(c[2]);
    cout<<c[1].fst->num;
    return 0;
}