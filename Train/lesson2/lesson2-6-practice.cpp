#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Student
{
    int id;
    int a,b,c;
    int sum;
};

bool cmp(const Student &s1, const Student &s2)
{
    if(s1.sum != s2.sum)
    {
        return s1.sum > s2.sum;
    }
    if(s1.a != s2.a)
    {
        return s1.a > s2.a;
    }
    return s1.id < s2.id;
}

int main()
{
    int n;
    cin>>n;
    vector<Student> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].a>>v[i].b>>v[i].c;
        v[i].id = i+1; //学号从1开始
        v[i].sum = v[i].a + v[i].b + v[i].c;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<5;i++)
    {
        cout << v[i].id << " " << v[i].sum << endl;
    }
    return 0;
}
