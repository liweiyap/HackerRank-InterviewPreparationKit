#include <vector>
#include <map>


// IN: array of numbers and geometric ratio
// OUT: number of triplets in the correct order
long countTriplets(std::vector<long> arr, long r){
    int n = arr.size();
    
    /*
     create hash map of numbers of the elements required in second and third positions of
     possible triplet, based on the element taht is in first position
     */
    std::map<long, long> nextElemReqInTriplet;
    std::map<long, long> lastElemReqInTriplet;
    long n_triplets = 0;
    
    for (int i = 0; i < n; ++i){
        // do in this order in case r = 1
        if (lastElemReqInTriplet.find(arr[i]) != lastElemReqInTriplet.end()){
            n_triplets += lastElemReqInTriplet[arr[i]];
        }

        if (nextElemReqInTriplet.find(arr[i]) != nextElemReqInTriplet.end()){
            lastElemReqInTriplet[arr[i] * r] += nextElemReqInTriplet[arr[i]];
        }

        ++nextElemReqInTriplet[arr[i] * r];
    }
    
    return n_triplets;
}
