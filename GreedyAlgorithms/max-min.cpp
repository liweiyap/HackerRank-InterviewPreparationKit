#include <vector>
#include <algorithm>  // sort, min
#include <limits>


// IN: full array of integers; length of potential subarray
// OUT: minimum difference between smallest and largest elements of any subarray of given length
int maxMin(int k, std::vector<int> arr){
    int n = arr.size();
    
    // sort array to start greedy algorithm
    std::sort(arr.begin(), arr.end());
    int minUnfairness = std::numeric_limits<int>::max();
    
    for (int i = 0; i <= n-k; ++i){
        minUnfairness = std::min(minUnfairness, arr[i+k-1] - arr[i]);
    }
    
    return minUnfairness;
}
