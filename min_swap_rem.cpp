#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minSwapsToSort(vector<int> arr, int n){
        pair<int, int> arrPos[n];
        for (int i = 0; i < n; i++)
        {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }
        sort(arrPos, arrPos + n);
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] || arrPos[i].second == i)
                continue;
            int cycle_size = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;
                j = arrPos[j].second;
                cycle_size++;
            }
            ans += (cycle_size - 1);
        }
        return ans;
    }

    int minSwapToMakeArraySame(vector<int> a, vector<int> b, int n){
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[b[i]] = i;
        for (int i = 0; i < n; i++)
            b[i] = mp[a[i]];
        return minSwapsToSort(b, n);
    }

    int ans(vector<int> nums){
        map<int,vector<int>> m1;
        for(int i = 0; i<nums.size(); i++){
            m1[nums[i]%3].push_back(i);
            cout<<m1[nums[i]%3].back()<<" ";
        }
        cout<<endl;
        for(int a:nums) cout<<a<<" ";
        cout<<endl;
        vector<int> temp;
        for(int j = 0; j<nums.size(); j++){
            int i = j%3;
            auto it = m1.find(i);
            if(it!=m1.end()){
                if(it->second.empty())return -1;
                // cout<<nums[(it->second).front()]<<" "<<endl;
                temp.push_back(nums[(it->second).front()]);
                it->second.erase(it->second.begin());
            }
            else return -1;
        }
        for(int a:temp) cout<<a<<" ";
        cout<<endl;
        return minSwapToMakeArraySame(nums, temp, nums.size());
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5,12,27,29,28};
    Solution s;
    int a = s.ans(nums);
    cout<<"ANSWER: "<<a;
    return 0;
}