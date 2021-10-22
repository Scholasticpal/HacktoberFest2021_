#include<iostream>
using namespace std;
main()
{
    int a,b,c,d;
    cout<<"enter number";
    cin>>a;
    for(int i=a;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"   *";
        }
        cout<<endl;
    }
    return 0;
}
