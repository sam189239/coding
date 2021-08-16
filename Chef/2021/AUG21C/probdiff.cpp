#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int prob_diff(vector<int> a){
        map<int,int> m;
        for(int i=0; i<4; i++)
        {
            if(m.find(a[i])==m.end()) m.insert({a[i], 1});
            else m[a[i]]++;
        }
        if(m.size()>=3) return 2;
        else if(m.size()==2){
            if(m.begin()->second==2) return 2;
            else return 1;
        }
        else return 0; 
    }
};

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        vector<int> a;
        int b;
        for(int i = 0; i<4; i++){
            cin>>b;
            a.push_back(b);
        }
        Solution s;
        cout<<s.prob_diff(a)<<"\n";
        t--;
    }
    return 0;
}