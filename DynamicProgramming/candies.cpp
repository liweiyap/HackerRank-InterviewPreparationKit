#include <vector>


// IN: vector of ratings
// OUT: minimum total number of candies, given that the child with the higher rating in each adjacent pairing must be given more candies
long candies(int n, std::vector<int> arr){
    // initialise dp table of the same size
    std::vector<long> dp(n, 1);
    
    // forward sweep: account for pairs in which the first child has a higher rating than the second child
    for (int i = 1; i < n; ++i){
        if (arr[i] > arr[i-1]){
            dp[i] += dp[i-1];
        }
    }
    
    // backward sweep: account for pairs in which the second child has a higher rating than the first child but that have not been accounted for in forward sweep
    long minCandies = dp[n-1];
    for (int i = n-2; i >=0; --i){
        if (arr[i] > arr[i+1] && dp[i] < dp[i+1]+1){
            dp[i] = dp[i+1]+1;
        }
        minCandies += dp[i];
    }
    return minCandies;
}
