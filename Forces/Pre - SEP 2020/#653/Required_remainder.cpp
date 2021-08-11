#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int x,y,n;
        cin>>x>>y>>n;
        int r;
        r = n%x;
        if(r>y)
        n=n-(r-y);
        else if(r<y)
        n=n-(x-y+r);
        t--;
        cout<<n<<"\n";
    }
    return 0;
}