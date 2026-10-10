#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    int a[5]={1,2,3,4,5};
    int max=a[0];
    int min=a[0];
    for(int i=0;i<5;i++)
    {
        sum+=a[i];
        cout<<a[i]<<" ";
        if(a[i]>max)
        {
            max=a[i];
        }
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    cout<<(sum-max-min)/3;
    return 0;
}
