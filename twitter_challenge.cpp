#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool is_odd(int n){
        return (n%2 != 0);
    }

    int evenSubarray(vector<int> n, int k){
    int len = n.size(), c = 0; 
    for(int j=0; j<k+1; j++){
        int prefix[len] = {0}, odd = 0;
        for(int i = 0; i<len; i++){
            prefix[odd]++;
            if(is_odd(n[i])) odd++;
            if(odd>=j) c += prefix[odd-j];
        }
    }
    return c;
    }

    int getMinDeletions(string s) {
        map<char, int> m;
        int c = 0;
        for(auto a:s){
            if(m.find(a)==m.end()) m[a] = 0;
            m[a]++;                        
        }
        for(auto a = m.begin(); a!=m.end(); a++) c+= a->second - 1;
        return c;
    }
    
    vector<int> find_max_indices(vector<int> n){
        int m = INT_MIN;
        vector<int> v;
        for(int a:n){
            if(a>m) m = a;
        }
        for(int i=0; i<n.size(); i++){
            if(n[i]==m) v.push_back(i);
        }
        return v;
    }
    long countMoves(vector<int> n) {
        int c=0;
        while(find_max_indices(n).size()<n.size()){
            vector<int> k = find_max_indices(n);
            int l = k.size();
            if(l==1) return -1;
            else{
                for(int a:k){
                    for(int j=0; j<n.size(); j++){
                        if(j!=a) n[j]++;
                    }
                    c++;
                    if(find_max_indices(n).size()==n.size()) goto A;
                }
            }
        }
        A:
        return c;
}
};

int main()
{
    Solution s1;
    vector<int> arr = {1,2,3,4};
    cout<<s1.evenSubarray(arr, 1);
    return 0;
}