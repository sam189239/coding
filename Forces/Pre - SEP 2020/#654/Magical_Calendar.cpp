#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {   
        long long n,r;
        cin>>n>>r;
        if(n>r)
        {
            cout<<(r*(r+1))/2<<"\n";
        }
        else
        {
            n=n-1;
            cout<<(n*(n+1))/2+1<<"\n";
        }
        
        t--;
    }
    return 0;
}