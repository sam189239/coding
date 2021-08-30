#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i - 1] <= w)
                // finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}
int main()
{
    // int val[] = { 25, -8, 19, 18, 36};
    // int wt[] = { 175, 133, 109, 210, 97};
    int val[] = { 4,4,4,4};
    int wt[] = { 1,2,3,4};
    int W = 10;s
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}