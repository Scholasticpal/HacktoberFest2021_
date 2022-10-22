#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    int n;
    cin>> n;
    std::string tab[n]; std::string ch;
    for (int i=0;i<n;i++)
    {
        cin>>ch;
        tab[i]=ch;
    }
    for (int i=0;i<n;i++)
    {
        if (tab[i].size() <= 10)
            cout<<tab[i]<<endl;
        else
        {
            int taille=tab[i].size();
            int nbre=taille-2;
            char s1=tab[i][0];
 
            char s3=tab[i][taille-1];
            cout<<s1<<nbre<<s3<<endl;
        }
    }
 
    return 0;
}