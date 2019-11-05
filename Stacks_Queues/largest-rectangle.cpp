#include <vector>
#include <stack>
#include <utility>  // pair
#include <algorithm>  // max


// IN: vector storing height of each building
// OUT: area of largest rectangle that can be formed when all buildings are lined up side by side
long largestRectangle(std::vector<int> h){
    int n = h.size();
    
    // initialise stack for storage of left wall and height of each building
    std::stack<std::pair<int, int>> s;
    
    // initialise variables for computing area iteratively
    long maxArea = 0;
    long curHeight = 0;
    long curLeft = 0;
    
    // iterate over remaining buildings
    for (int i = 0; i < n; ++i){
        // if current building is taller than previous building
        if (s.empty() || h[i] >= s.top().second){
            s.push(std::make_pair(i, h[i]));
            
        // if current building is shorter than previous building
        } else{
            // pop until stack is empty or building with shorter height than current building is found
            while (!s.empty() && h[i] < s.top().second){
                curHeight = static_cast<long>(s.top().second);
                curLeft = static_cast<long>(s.top().first);
                s.pop();
                
                // when a building is popped, this means that its right wall has been found, so compute area and compare with max area
                maxArea = std::max(maxArea, curHeight*(static_cast<long>(i)-curLeft));
            }  // end WHILE
            
            // push current building with found left wall to stack
            s.push(std::make_pair(curLeft, h[i]));
            
        }  // end IF
    }  // end FOR
    
    // if stack is not empty, then that means that there is at least one other building that shares the same height as the first
    while (!s.empty()){
        // pop until stack is empty
        curHeight = static_cast<long>(s.top().second);
        curLeft = static_cast<long>(s.top().first);
        s.pop();
        
        // when a building is popped, this means that its right wall has been found, so compute area and compare with max area
        maxArea = std::max(maxArea, curHeight*(static_cast<long>(n)-curLeft));
    }

    return maxArea;
}
