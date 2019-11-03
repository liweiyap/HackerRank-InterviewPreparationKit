#include <vector>
#include <unordered_map>


// IN: array of integers, and required difference between any pair of integers
// OUT: number of such pairs with required difference
int pairs(int k, std::vector<int> arr){
    int n = arr.size();
    std::unordered_map<int, int> needed;
    int n_pairs = 0;
    
    /*
     as we iterate over the array, add the two integers that are larger or smaller by the
     required difference to the hash table. If integer is already present in the hash table,
     add the number of its occurrences to the number of pairs required.
     */
    for (int i = 0; i < n; ++i){
        if (needed.find(arr[i]) != needed.end()){
            n_pairs += needed[arr[i]];
            needed.erase(arr[i]);
        }
        ++needed[arr[i] + k];
        ++needed[arr[i] - k];
    }
    return n_pairs;
}
