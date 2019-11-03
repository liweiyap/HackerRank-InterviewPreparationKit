#include <string>
#include <stack>
#include <iterator>  // prev
#include <cassert>


// IN: string of parentheses
// OUT: YES/NO string stating whether string of parentheses is balanced
std::string isBalanced(std::string s){
    std::stack<char> brackets;
    for (auto str_it = s.begin(); str_it != s.end(); ++str_it){
        if (*str_it == '(' || *str_it == '[' || *str_it == '{'){
            if (str_it == std::prev(s.end(), 1)){
                return "NO";
            }
            brackets.push(*str_it);
        }
        if (*str_it == ')'){
            if (brackets.empty() || brackets.top() != '('){
                return "NO";
            }
            brackets.pop();
        }
        if (*str_it == ']'){
            if (brackets.empty() || brackets.top() != '['){
                return "NO";
            }
            brackets.pop();
        }
        if (*str_it == '}'){
            if (brackets.empty() || brackets.top() != '{'){
                return "NO";
            }
            brackets.pop();
        }
    }
    assert(brackets.empty());
    return "YES";
}
