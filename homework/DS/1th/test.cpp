#include<bits/stdc++.h>
#include<fstream>
using namespace std;
template<class T>
void wrt(T c)
{
	fstream file;
	file.open("tes.txt",fstream::in|fstream::out);
	//file.write(reinterpret_cast<char *>(&c),sizeof(int));
	file<<c;
	cout<<file.tellg()<<endl;
	file<<c;
	cout<<file.tellg()<<endl;
	file.seekg(0,ios::end);
	
	file.seekg(0);
	c=c+c;
	file.read(reinterpret_cast<char *>(&c),sizeof(int));
	cout<<c<<endl;	
}
int main()
{
	
	long long  t=4000;
	wrt(t);
	return 0;
}