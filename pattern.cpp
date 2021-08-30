#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
};

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> ans(n);
    ans[0] = {1};
    if(n==1) cout<<1<<endl;
    else{
        ans[1] = {1,1};
        int i = 2,curr, count=0, k;
        while(i<n){
            curr = ans[i-1][0];
            count = 1;
            for(int j = 1;j<(ans[i-1]).size();j++){
                if(curr==ans[i-1][j])
                    count++;
                else{
                    ans[i].push_back(count);
                    ans[i].push_back(curr);
                    curr = ans[i-1][j];
                    count=1;
                }
            }
            ans[i].push_back(count);
            ans[i].push_back(curr);
            i++;
        }

        for(auto n:ans){
            for(auto p:n){
                cout<<p<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}