#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int num;
    int count = 0;
    cin >> num;
    while(num != 0)
    {
        a[count] = num;
        count++;
        cin >> num;
    }
    for(int i = count - 1; i >= 0; i--)
    {
        cout << a[i];
        if(i > 0)
        {
            cout << " ";
        }
    }
    return 0;
}
