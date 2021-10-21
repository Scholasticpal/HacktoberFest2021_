#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter array size \n";
    cin>>n;
    int a[n];
    cout<<"Enter array \n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int b[n+1];
    b[0]=0;
    int max=INT_MIN;
    int j=1,sum=0;
    int k,c;
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        while(j<=n)
        {
            b[j]=b[j]-a[i-1];
            if(max<=b[j])
            {
                max=b[j];
                k=i;
                c=j;
            }
            j++;
        }
        j=i+1;
    }
    cout<<"Maximum sum = "<<max<<"\n";
    cout<<"Maximum subarray \n";
    for(int i=k;i<c;i++)
    {
        cout<<a[i]<<" ";
    }
}
