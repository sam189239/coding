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
        int i=0,j=0;
        long long a,b;
        while(n>0)
        {
            int s1=0,s2=0;
            cin>>a>>b;
            while(a>0)
            {
                s1+=(a%10);
                a=a/10;
            }
            while(b>0)
            {
                s2+=b%10;
                b/=10;
            }
            if(s1>s2)
                i++;
            else if(s2>s1)
                j++;
            else
            {
                i++;j++;
            }
            n--;
        }
        
        if(i>j)
            cout<<0<<" "<<i<<"\n";
        else if(j>i)
            cout<<1<<" "<<j<<"\n";
        else
            cout<<2<<" "<<j<<"\n";

        t--;
    }
    return 0;
}