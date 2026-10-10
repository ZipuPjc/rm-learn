#include<iostream>
#include<string>
using namespace std;
int main()
{
    pair<int,int> p(0,0);
    char ch;
    while(cin>>ch)
    {
        if(ch=='U')
            p.second++;
        else if(ch=='D')
            p.second--;
        else if(ch=='L')
            p.first--;
        else if(ch=='R')
            p.first++;
    }
    if(p.first==0 && p.second==0)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}