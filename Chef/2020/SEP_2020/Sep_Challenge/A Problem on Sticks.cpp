#include<iostream>
#include<set>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n,i=0;
        cin>>n;
        long long k;
        set <long long> s;
        while(i<n)
        {
            cin>>k;
            s.insert(k);
            i++;
        }
        cout<<s.size()<<"\n";
        t--;
    }
    return 0;
}