#include <vector>


// IN: length of array, vector of queries
// OUT: largest value in result of array additions/manipulations
long arrayManipulation(int n, std::vector<std::vector<int>> queries){
    // initialise all entries of array as 0
    std::vector<long> cumsum(n, 0);
    
    // iterate over all queries
    for (auto queries_it = queries.begin(); queries_it != queries.end(); ++queries_it){
        // first entry of every query is the start of the range to be manipulated
        int lb = (*queries_it)[0]-1;
        
        // second entry of every query is the end of the range to be manipulated
        int ub = (*queries_it)[1]-1;
        
        // third entry of every query is the number to be added to every elem in the range
        long val = static_cast<long>((*queries_it)[2]);
        
        // for efficiency, first add the number only to the elem at the start
        cumsum[lb] += val;
        
        // still for efficiency, subtract the number from the elem after the end
        if (ub+1 < n){
            cumsum[ub+1] -= val;
        }
    }
    
    // now, we do the actual array manipulation
    // initialise max value
    long maxval = 0;
    
    // iterate from start to end of array
    for (int i = 1; i < n; ++i){
        // add the previous number to the current number. lb and ub tell us when the adding stops
        cumsum[i] += cumsum[i-1];
        
        // if current value is larger than max value, update max value
        maxval = max(maxval, cumsum[i]);
    }

    return maxval;
}
