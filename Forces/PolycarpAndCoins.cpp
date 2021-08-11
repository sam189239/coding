#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {   
        long long n;
        cin>>n;
        long long i=0, j=0, extra=0;
        extra = n % 3;
        // cout<<extra;
        if(extra == 1){
            i = n/3 + 1;
            j = n/3;
        }
        else if(extra == 2){
            j = n/3 + 1;
            i = n/3;
        }
        else{
            i = n/3;
            j = n/3;
        }
        cout<<i<<" "<<j<<"\n";
        t--;
    }
    return 0;
}