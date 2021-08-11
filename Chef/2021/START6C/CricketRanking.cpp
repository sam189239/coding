#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int r1, w1, c1, r2, w2, c2;
        cin>>r1>>w1>>c1>>r2>>w2>>c2;
        char ans = 'B';
        if((r1>r2 && c1>c2) || (r1>r2 && w1>w2) || (c1>c2 && w1>w2)) ans = 'A';
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}