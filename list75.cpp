#include<bits/stdc++.h>
using namespace std;

class Arrays{
    public:

    // https://leetcode.com/problems/two-sum - 2021/08/16
    vector<int> twoSum(vector<int>& a, int n) {
        int i, j;
        map<int, int> m1;
        vector<int> ans;
        for(int i=0; i<a.size(); i++){
            if(m1.find(n-a[i]) != m1.end()){
                ans.push_back(i);
                ans.push_back(m1.find(n-a[i])->second);
                return ans;
            }
            else m1.insert({a[i], i});
        }
        return ans;
    }
};

int main(){
    return 0;
}