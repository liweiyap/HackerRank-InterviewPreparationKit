#include <vector>
#include <unordered_map>
#include <stack>
#include <utility>  // pair
#include <algorithm>  // max
#include <map>


// IN: vector of unsorted integers
// OUT: vector storing maximum value for sliding windows of different lengths
std::vector<long> riddle(std::vector<long> arr){
    int n = arr.size();
    
    // stack for storage of left wall and value of each integer in array
    std::stack<std::pair<int,long>> s;
    
    // hash map for storage of sliding window length and value of each integer in array
    std::unordered_map<long,int> maxWindows;
    
    long curVal;
    int curLeft;
    
    // iterate over all integers in array
    for (int i = 0; i < n; ++i){
        // if current value is larger than previous value
        if (s.empty() || arr[i] > s.top().second){
            s.push(std::make_pair(i, arr[i]));
        
        // if current value is smaller than previous value
        } else{
            // pop until stack is empty or value smaller than current value is found
            while (!s.empty() && arr[i] < s.top().second){
                curVal = s.top().second;
                curLeft = s.top().first;
                s.pop();
                
                // when a value is popped, this mean that the right wall of that integer has been found, so compute length of sliding window
                maxWindows[curVal] = std::max(maxWindows[curVal], i - curLeft);
            }  // end WHILE
            
            // if current value is a replicate of top node of stack, then don't push, since left wall would be exactly the same
            if (s.empty() || arr[i] != s.top().second){
                s.push(std::make_pair(curLeft, arr[i]));
            }  // end IF
        }  // end IF
    }  // end FOR
    
    // pop all remaining values to finalise length of sliding windows
    while (!s.empty()){
        curVal = s.top().second;
        curLeft = s.top().first;
        s.pop();
        
        // when a value is popped, this mean that the right wall of that integer has been found, so compute length of sliding window
        maxWindows[curVal] = std::max(maxWindows[curVal], n - curLeft);
    }  // end WHILE
    
    // invert the hash map by finding the maximum value for the same sliding window length
    std::map<int, long> invWindows;
    for (auto kv:maxWindows){
        invWindows[kv.second] = std::max(invWindows[kv.second], kv.first);
    }  // end FOR
    
    // iterate backwards from size of array to 0 when outputting vector of maximum value for sliding windows of different lengths
    std::vector<long> maxMin(n);
    maxMin[n-1] = invWindows[n];
    for (int i = n-2; i >= 0; --i){
        if (invWindows.find(i+1) != invWindows.end()){
            maxMin[i] = std::max(invWindows[i+1], maxMin[i+1]);
        } else{
            maxMin[i] = maxMin[i+1];
        }  // end IF
    }  // end FOR
    
    return maxMin;
}
