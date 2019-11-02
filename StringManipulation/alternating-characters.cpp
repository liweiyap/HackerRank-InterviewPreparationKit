#include <string>


// IN: string
// OUT: number of pairs of adjacent characters that are identical to each other
int alternatingCharacters(std::string s){
    int n_deletions = 0;
    
    // initialise loop iterator
    auto str_it = s.begin();
    
    // end condition of loop
    while (str_it != s.end()){
        // initialise iterator for subregions of string so that we call str_it fewer times
        int substr_it = 1;
        
        while (*str_it == *(str_it+substr_it)){
            ++n_deletions;
            ++substr_it;
        }
        
        // increment loop iterator
        str_it += substr_it;
    }
    
    return n_deletions;
}
