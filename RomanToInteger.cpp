#include <string>
#include <iostream>

class Solution {
public:
    int romanToInt(std::string s) {
        unsigned short total = 0;
        unsigned short prev_val = 1001;
        for (char letter : s){
            unsigned short value = romanValue(letter);
            if (value <= prev_val){
                total += value;
            }else{
                total += value - 2 * prev_val;
            }
            prev_val = value;
        }

        return total;
    } 
    
private:
    short romanValue(char s){
        if (s == 'I'){
            return 1;
        } else if (s == 'V'){
            return 5;
        } else if (s == 'X'){
            return 10;
        } else if (s == 'L'){
            return 50;
        } else if (s == 'C'){
            return 100;
        } else if (s == 'D'){
            return 500;
        }else{
            return 1000;
        }
    }
};

int main(){
    Solution solution;
    std::string s = "MCMXCIV";
    std::cout << solution.romanToInt(s) << std::endl;
    return 0;
}