#include <vector>
#include <unordered_map>


// IN: list of queries
// OUT: vector of output for all the times op 3 is called
std::vector<int> freqQuery(std::vector<std::vector<int>> queries){
    int q = queries.size();
    
    // first hash map is a representation of the array being manipulated
    std::unordered_map<int, int> data_struct;
    
    // second hash map keeps count of only the frequencies for higher efficiency
    std::unordered_map<int, int> freq_table;
    
    // output for all the times op 3 is called
    std::vector<int> output;
    
    // define variables
    int op;
    int data_elem;
    int freq;
    
    // iterate over all queries
    for (int it = 0; it < q; ++it){
        op = queries[it][0];
        data_elem = queries[it][1];
        
        if (op == 1){
            // insert element into array
            freq = ++data_struct[data_elem];
            
            // update table of frequencies
            ++freq_table[freq];
            if (--freq_table[freq-1] <= 0){
                freq_table.erase(freq-1);
            }
        }
        
        if (op == 2){
            // delete element from array
            freq = --data_struct[data_elem];
            if (freq <= 0){
                data_struct.erase(data_elem);
            } else{
                ++freq_table[freq];
            }
            
            // update table of frequencies
            if (--freq_table[freq+1] <= 0){
                freq_table.erase(freq+1);
            }
        }
        
        if (op == 3){
            // fast check for whether that frequency is already present in table of frequencies
            output.push_back(freq_table.find(data_elem) != freq_table.end());
        }
    }
    return output;
}
