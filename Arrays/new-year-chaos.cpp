#include <vector>
#include <iostream>


void minimumBribes(std::vector<int> q) {
    // get number of people standing in line
    int n = q.size();
    
    // initialise number of bribes
    int bribes = 0;
    
    // iterate from back of queue
    for (int i = n-1; i >= 0; --i){
        // if index of current person is too much greater than what it was originally in order
        if (q[i] - (i+1) > 2){
            // then queue is too chaotic. Break.
            std::cout << "Too chaotic\n";
            return;
        }
        
        // else, iterate the following from two positions ahead
        for (int j = max(0, q[i]-2); j < i; ++j){
            // if position ahead has larger number than current position, increment no. of bribes
            if (q[j] > q[i]) ++bribes;
        }
    }
    
    // print number of bribes
    std::cout << bribes << "\n";
}
