#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
};

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        string a, b = "";
        getline(cin,a);
        int i=0, j=1, N;
        cin>>N;
        while(j<N){
            putline<<"\nyes "<<a;
            if(a[i]==0 && a[j]==0) b.append("A");
            else if(a[i]==0 && a[j]==1) b.append("T");
            else if(a[i]==1 && a[j]==0) b.append("C");
            else if(a[i]==1 && a[j]==1) b.append("G");
            i+=2;
            j+=2;
        }
        cout<<b<<"\n";
        t--;
    }
    return 0;
}