// Time Complexity: O(n)
// We traverse the string only once.

// Space Complexity: O(n)
// In the worst case, the answer string can store almost all characters.

class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        string ans = "";

        for(char str : s) {
            if(str == '(') {
                if(balance > 0) ans += str;
                balance++;
            }
            else {
                balance--;
                if(balance > 0) ans += str;
            }
        }

        return ans;
    }
};
