#include <vector>
#include <algorithm>  // max
#include <cassert>


// IN: vector of integers
// OUT: subset of non-adjacent integers with the maximum sum
int maxSubsetSum(std::vector<int> arr){
    int n = arr.size();
    assert(n > 0);
    
    // base case for n = 1
    if (n == 1){
        return arr[0];
    }
    
    // base case for n = 2
    if (n == 2){
        return std::max(arr[0], arr[1]);
    }
    
    // all remaining cases have n >= 3.
    // run dynamic programming algorithm
    std::vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = std::max(dp[0], arr[1]);
    for (int i = 2; i < n; ++i){
        dp[i] = std::max({dp[i-1], arr[i], dp[i-2] + arr[i]});
    }
    return dp[n-1];
}
