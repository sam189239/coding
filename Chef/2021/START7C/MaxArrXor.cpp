#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long n, k;
        cin>>n>>k;
        cout<<(pow(2,n) -1) * 2 *k<<"\n";
        t--;
    }
    return 0;
}