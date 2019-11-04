#include <vector>
#include <algorithm>  // sort, min
#include <cmath>  // abs
#include <limits>


// IN: array of unsorted integers
// OUT: minimum absolute difference between any pair of integers in array
int minimumAbsoluteDifference(std::vector<int> arr){
    int n = arr.size();
    
    // sort integers
    std::sort(arr.begin(), arr.end());
    
    // greedy algorithm computes each pairwise absolute difference once array is sorted
    int minAbsDiff = std::numeric_limits<int>::max();
    for (int i = 1; i < n; ++i){
        minAbsDiff = std::min(minAbsDiff, std::abs(arr[i]-arr[i-1]));
    }
    return minAbsDiff;
}
