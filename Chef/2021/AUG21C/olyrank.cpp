#include<bits/stdc++.h>
using namespace std;

class Solution{
    
};

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int g1, s1, b1, g2, s2, b2;
        cin>>g1>>s1>>b1>>g2>>s2>>b2;
        ((g1+s1+b1)>(g2+s2+b2))? cout<<1<<"\n"  : cout<<2<<"\n";
        t--;
    }
    return 0;
}