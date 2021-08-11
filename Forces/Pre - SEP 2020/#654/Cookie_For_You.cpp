#include<iostream>
using namespace std;

int min(int a, int b)
{
    if(a>=b)
        return b;
    else
        return a;
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {   
        long long a,b,n,m;
        cin>>a>>b>>n>>m;
        if(n+m>a+b)
        {
            cout<<"No"<<"\n";
        }
        else if((m>min(a,b)))
        {
            cout<<"No"<<"\n";
        }
        else
            cout<<"Yes"<<"\n";
        t--;
    }
    return 0;
}