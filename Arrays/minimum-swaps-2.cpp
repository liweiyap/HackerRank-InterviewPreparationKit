#include <vector>


// IN: unordered vector
// OUT: minimum number of swaps required to return vector to correct order
int minimumSwaps(std::vector<int> arr) {
    int n = arr.size();
    int swaps = 0;
    for (int i = 0; i < n; ++i){
        while (arr[i] != i+1){
            std::swap(arr[i], arr[arr[i]-1]);
            ++swaps;
        }
    }
    return swaps;
}
