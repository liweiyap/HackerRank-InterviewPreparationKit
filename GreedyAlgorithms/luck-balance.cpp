#include <vector>
#include <algorithm>  // sort, min
#include <functional>  // greater


// IN: maximum number of contests that can be lost; matrix of 2 columns, one for luck value and the other for importance
// OUT: maximum amount of luck that can be won
int luckBalance(int k, std::vector<std::vector<int>> contests){
    int n = contests.size();
    int maxLuck = 0;
    
    // initialise vector of important contests
    std::vector<int> important;
    
    // iterate over all contests first
    for (int i = 0; i < n; ++i){
        // if the contest is not important, then lose it to gain more luck
        if (contests[i][1] == 0){
            maxLuck += contests[i][0];
            
        // if the contest is important, store its luck value
        } else{
            important.push_back(contests[i][0]);
        }
    }
    
    if (!important.empty()){
        // sort the important contests in descending order of their luck value
        std::sort(important.begin(), important.end(), std::greater<int>());
        
        // we are allowed to lose up to k contests to gain more luck
        for (int j = 0; j < std::min(k, static_cast<int>(important.size())); ++j){
            maxLuck += important[j];
        }
        
        // any remaining contests must be won so luck is lost
        for (int j = k; j < important.size(); ++j){
            maxLuck -= important[j];
        }
    }
    
    return maxLuck;
}
