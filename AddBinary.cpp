#include <string>

class Solution {
    public:
        std::string addBinary(std::string a, std::string b) {
            std::string output = "";

            bool carry = false;

            while (true) {
                if (!a.empty() && !b.empty()) {
                    output = addNums(a[a.size() - 1], b[b.size() - 1], carry) + output;
                    a.pop_back();
                    b.pop_back();
                } else if (!a.empty()) {
                    output = addNums(a[a.size() - 1], '0', carry) + output;
                    a.pop_back();
                } else if (!b.empty()) {
                    output = addNums('0', b[b.size() - 1], carry) + output;
                    b.pop_back();
                } else {
                    if (carry) {
                        output = "1" + output;
                    }
                    break;
                }
            }

            return output;
        }

    private:
        std::string addNums(char a, char b, bool& carry) {
            int num = (a - '0') + (b - '0');
            if (carry) {
                num++;
            }

            if (num == 3) {
                carry = true;
                return "1";
            } else if (num == 2) {
                carry = true;
                return "0";
            } else if(num == 1) {
                carry = false;
                return "1";
            } else {
                carry = false;
                return "0";
            }
            
        }
};