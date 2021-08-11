#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {   
        long long n,i=0;
        cin>>n;
        long long a[n];
        while(i<n)
        {   
            cin>>a[i++];
        }
        i = 0;
        long long sum = 0;
        while(i<n-1)
        {
            sum+=abs(a[i]-a[i+1])-1;
        }
        cout<<sum<<"\n";
        t--;
    }
    return 0;
}