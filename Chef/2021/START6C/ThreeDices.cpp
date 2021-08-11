#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int x,y;
        float ans = 0;
        cin>>x>>y;
        if(x+y < 6){
            ans = float(6-x-y)/6;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}