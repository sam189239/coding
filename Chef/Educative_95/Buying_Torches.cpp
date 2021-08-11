#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long x,y,k;
        cin>>x>>y>>k;
        long long r = k+(y*k+k-1)/(x-1);
        if((y*k+k-1)%(x-1)!=0)
            r+=1;
        cout<<r<<"\n";
        t--;
    }
    return 0;
}