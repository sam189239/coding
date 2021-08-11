#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long e, k;
        cin>>e>>k;
        // long long ans = (e%k==0)? e/k-1:e/k+1;
        long long ans = log(e - e%k)/log(k) + 1;
        if(e<k) ans = 1;
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}