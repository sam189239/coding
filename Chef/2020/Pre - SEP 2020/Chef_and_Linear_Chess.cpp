#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long n,k,i=0;
        cin>>n>>k;
        long long p[n];
        for(i=0;i<n;i++)
            cin>>p[i];
        long long o=10000000000;
        int q = -1;
        for(i=0;i<n;i++)
        {
            if(k%p[i]==0)
            {
                if((k/p[i])<=o)
                {
                    o = k/p[i]; 
                    q = i;
                }
            }
        }
        if(q!=-1)
            cout<<p[q]<<"\n";
        else
            cout<<q<<"\n";
        t--;
    }
    return 0;
}