// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int sum=0;
        for(int i=0;i<s.size();i++){
            
            if(i+1<s.size() && m[s[i]]<m[s[i+1]])
                sum=sum-m[s[i]];
            else
                sum=sum+m[s[i]];
        }
        return sum;
    }
};


//method -2 (better)
// Time Complexity: O(n)
// Space Complexity: O(1)
//This version just avoids map overhead.
class Solution {
public:
    int value(char ch) {
        if(ch == 'I') return 1;
        if(ch == 'V') return 5;
        if(ch == 'X') return 10;
        if(ch == 'L') return 50;
        if(ch == 'C') return 100;
        if(ch == 'D') return 500;
        return 1000; // M
    }

    int romanToInt(string s) {
        int sum = 0;

        for(int i = 0; i < s.size(); i++) {
            int curr = value(s[i]);
            int next = 0;

            if(i + 1 < s.size())
                next = value(s[i + 1]);

            if(curr < next)
                sum -= curr;
            else
                sum += curr;
        }

        return sum;
    }
};
