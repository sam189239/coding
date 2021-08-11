#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long pc,pr;
        cin>>pc>>pr;
        int i,j;
        if(pc%9 == 0)
            i = pc/9;
        else
            i = pc/9 +1;
        if(pr%9 == 0)
            j = pr/9;
        else
            j = pr/9 +1;
        if(i<j)
            cout<<0<<" "<<i<<"\n";
        else
            cout<<1<<" "<<j<<"\n";
        t--;
    }
    return 0;
}