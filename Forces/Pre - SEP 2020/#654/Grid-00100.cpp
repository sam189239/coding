#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long n,k,p,i,j,l;
        cin>>n>>k;
        long long a[n][n];
        if(k==0)
        {
            cout<<0<<"\n";
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                   cout<<0;
                }
                cout<<"\n";
            }
        }
        else if(n*n==k)
        {
            cout<<0<<"\n";
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                   cout<<1;
                }
                cout<<"\n";
            }
        }
        else if(k<n)
        {
            cout<<2<<"\n";
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {   
                    if(i==j && k>0)
                    {
                        cout<<1;
                        k--;
                    }
                    else
                        cout<<0;
                }
                cout<<"\n";
            }
        }
        else if(k==n)
        {
            cout<<0<<"\n";
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {   
                    if(i==j && k>0)
                    {
                        cout<<1;
                        k--;
                    }
                    else
                        cout<<0;
                }
                cout<<"\n";
            }
        }
        else if(k%n==0)
        {
            p = k/n;
            cout<<0<<"\n";
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {   
                    if(i==j)
                        l=0;
                    if(l<p && k>0)
                    {
                        cout<<1;
                        k--;l++;
                    }
                    else
                        cout<<0;
                }
                cout<<"\n";
            }
        }
        else
        {
            p = k/n;
            cout<<2<<"\n";
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {   
                    if(i==j)
                        l=0;
                    if(l<p && k>0)
                    {
                        cout<<1;
                        k--;l++;
                    }
                    else
                        cout<<0;
                }
                cout<<"\n";
            }
        }
        
        
        
        t--;
    }
    return 0;
}