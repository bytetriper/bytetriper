#include<iostream>
using namespace std;
const int imax=2147483647;
#define USE_OS haoye
class error:public std::exception 
{
    private:
        std::string msg;
    public:
        explicit error(const char *_msg_) : msg(_msg_) {}
        const char *toString() 
        {
            return msg.c_str();
        }
};
template<typename T>
class ArrayList
{
    public:
    T* a;
    int siz;
    T type;
    ArrayList(T *arr,int length):siz(length)
    {
        if(length<0)
        {   
            error err("invalid length");
            throw err;
        }
        if(arr!=NULL)
        {
            a=new T [length+1];
            for(int i=0;i<length;i++)
                a[i]=arr[i];
        }
    }
    ArrayList(int length):siz(length)
    {
                
        if(length<0)
        {   
            error err("invalid length");
            throw err;
        }
        a= new T [length+1];
    }
    ArrayList(const ArrayList & B):siz(B.siz)
    {
        a=new T [siz+1];
        for(int i=0;i<siz;i++)
            a[i]=B.a[i];
    }
    int size() const
    {
        return siz;
    }
    T & operator [] (int idx) const
    {
        if(idx<0||idx>=siz)
        {   
            error err("index out of bound");
            throw err;
        }
        return a[idx];
    }//+ = == !=
    ArrayList<T> operator +(const ArrayList &B) const
    {
        ArrayList<T> tmp(*this);
        tmp.siz+=B.siz;
        delete[] tmp.a;
        try{
        tmp.a=new T [tmp.siz+1];}
        catch(...)
        {
            throw error("bad alloc");
        }
        for(int i=0;i<siz;i++)
            tmp.a[i]=a[i];
        for(int i=siz;i<tmp.siz;i++)
            tmp.a[i]=B.a[i-siz];
        return tmp;
    }
    ArrayList & operator =(const ArrayList &B)
    {
        if(B.a==a)
            return *this;
        siz=B.siz;
        delete []a;
        try{
        a=new T [siz+1];}
        catch(...)
        {
            throw error("bad alloc");
        }
        for(int i=0;i<siz;i++)
            a[i]=B.a[i];
        return *this;
    }
    bool operator ==(const ArrayList &B) const
    {
        if(siz!=B.siz)
            return false;
        for(int i=0;i<siz;i++)
            if(!(a[i]==B.a[i]))
                return false;
        return true;
    }
    bool operator !=(const ArrayList &B) const
    {
        return !(*this==B);
    }
    friend ostream & operator <<(ostream &os,const ArrayList &B)
    {
        for(int i=0;i<B.siz-1;i++)
            os<<B.a[i]<<" ";
        os<<B.a[B.siz-1];
        return os;
    }
    virtual ~ArrayList()
    {
        delete[] a;
        //好耶！
    }
};

template<class T>
void printList(ArrayList<T> list) {
#ifdef USE_OS
    std::cout << list << "\n";
#else
    list.print();
    std::cout << "\n";
#endif
}
int main()
{
        try {
        ArrayList<char> list_err(-1);
    } catch (error &e) {
        std::cout << e.toString() << std::endl;
    }

    ArrayList<int> list(5);

    try {
        list[-1];
    } catch (error &e) {
        std::cout << e.toString() << std::endl;
    }
    try {
        list[2000];
    } catch (error &e) {
        std::cout << e.toString() << std::endl;
    }

    for (int i = 0; i < list.size(); i++) list[i] = i;
    printList(list);
    ArrayList<int> temp = list;
    printList(temp);
    temp = list;
    printList(temp);
    if (temp == list) std::cout << "true" << std::endl;
    int arr[5] = {4, 215, 12, 84, 76};
    const ArrayList<int> list_const(arr, 5);
    std::cout << list_const[3] << std::endl;
    printList(list_const);
        printList(list_const + list);

    return 0;
}