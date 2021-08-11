#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long n,i=0,c=0,p=1;
        cin>>n;
        long long a[n];
        while(i<n){
            cin>>a[i++];
        }
        for(i = 0;i < n;)
        {
            if(p==1)
            {
                if(a[i]==0)
                {
                    if(a[i+1]==0)
                        i+=2;
                    else
                        i+=1;
                }
                else
                {
                    if(a[i+1]==0)
                        i+=2;
                    else
                        i+=1;
                    c+=1;
                }
                p=2;
            }
            else
            {
                if(a[i]==0)
                {
                    if(a[i+1]==0)
                        i+=1;
                    else
                        i+=2;
                }
                else
                {
                    if(a[i+1]==0)
                        i+=1;
                    else
                        i+=2;
                }
                p=1;
            }
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}