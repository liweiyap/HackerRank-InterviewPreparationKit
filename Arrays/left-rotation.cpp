#include <vector>


// IN: vector and number of left rotations to be done
// OUT: left-rotated vector
std::vector<int> rotLeft(std::vector<int>& a, int d){
    // for each left rotation
    for (int i = 0; i < d; ++i){
        // get value of elem in front of vector
        int front = a.front();
        
        // remove elem from front of vector
        a.erase(a.begin());
        
        // re-add elem to back of vector
        a.push_back(front);
    }
    
    // return left-rotated vector
    return a;
}
