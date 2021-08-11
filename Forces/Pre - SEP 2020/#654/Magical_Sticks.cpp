#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        if(n%2==0)
            cout<<((n-1)/2)+1<<"\n";
        else 
            cout<<n/2+1<<"\n";
        t--;
    }
    return 0;
}