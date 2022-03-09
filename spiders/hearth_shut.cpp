#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
    const char *s,*s1;
    s=new char[100];
    s1=new char[100];
    s="netsh advfirewall firewall add rule name=\"Hearthstone.exe\" dir=in program=\"C:\\Program Files (x86)\\Hearthstone\\Hearthstone.exe\" action=block";
    s1="netsh advfirewall firewall delete rule name=\"Hearthstone.exe\"";
    system(s);
    Sleep(1500);
    system(s1);
    Sleep(3000);
    return 0;
}