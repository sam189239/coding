#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        long long n, m, l, nofl;
        cin>>n>>m>>l;
        nofl = m;
        map<long long,long long> mp;
        long long list = 0;
        while(nofl>0){
            long long k;
            cin>>k;
            while(k>0){
                long long n;
                cin>>n;
                mp.insert({n,list});
                k--;
            }
            list++;
            nofl--;
        }
        long long i=0, arr[l], count = 0;
        while(i<l){
            cin>>arr[i];
            i++;
        }
        for(long long i = 0; i<n-1; i++){
            if(mp[arr[i]] == mp[arr[i+1]]) count++;
        }
        cout<<"ANS: "<<l - count<<"\n";
        t--;
    }
    return 0;
}