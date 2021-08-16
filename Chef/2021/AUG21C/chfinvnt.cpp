#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int chf_invnt(int n, int p, int k){
        int c = 0, i = 0, m = 0, j = 0;
        for(j=0; i*k+j < n; j++){
            for(i=0;i*k+j < n; i++){
                m = i * k + j;
                if(m!=p){
                    c++;
                }
                else break;
            }
            if(m==p) break;
            i=0;

        }
        return c+1;
    }

    int chf_invnt2(int n, int p, int k){
        int ans = 0, a, b,i;
        a = p%k - 1;
        b = ((n-1)/k)*k;
        b = n - 1 - b;
        
        if(a>b) ans += (b+1)*((n-1)/k + 1) +(a-b)*((n-1)/k);
        else ans += ((n-1)/k + 1)*(a+1);
            
        for(i = 0; i<=a; i+=k){
            ans += 1;
            if (i==p) return ans;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        Solution s;
        int n, p, k;
        cin>>n>>p>>k;
        int a = s.chf_invnt2(n,p,k);
        cout<<a<<"\n";
        t--;
    }
    return 0;
}