#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int a, b;
        cin>>a>>b;
        int ans = 0;
        if(a+b<3) ans =1;
        else if(a+b<=10) ans = 2;
        else if(a+b<=60) ans = 3;
        else ans = 4;
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}