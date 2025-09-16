#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-1; j++)
        {
            cout<<" ";
        }
        for(int k=1; k<=i; k++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=n-1; i>=1; i--)
    {
        for(int j=1; j<=n-1; j++)
        {
            cout<<" ";
        }
        for(int k=1; k<=i; k++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}