//method 1
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        string str=s+s;
        
        return str.find(goal)!=string::npos;
    }
};





//method 2
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size())
            return false;

        string str = s + s;

        int n = str.size();
        int m = goal.size();

        // try every possible starting index
        for(int i = 0; i <= n - m; i++) {

            int j = 0;

            // match characters one by one
            while(j < m && str[i + j] == goal[j]) {
                j++;
            }

            // full match found
            if(j == m)
                return true;
        }

        return false;
    }
};
