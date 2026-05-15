// Time Complexity: O(n)
// Space Complexity: O(n) because recursion stack is used
class Solution {
public:
    int fatoi(string s,int index,int sign,int result){
        if(index>=s.size())     return sign*result;

        char ch=s[index];

        if(ch-'0'>=0 && ch-'0'<=9){
            int d=ch-'0';
//...
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && d > 7)) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
//...
            result = result * 10 + d;

            return fatoi(s,index+1,sign,result);
        }
        else    return fatoi(s,s.size(),sign,result);
    }
    int myAtoi(string s) {
        int i=0;
        char ch=s[i];
        int sign = +1;
        while(i+1<s.size() && ch==' '){
            i++;
            ch=s[i];
        }
        
        if(ch=='-'){
            sign*=-1;
            i++;
            ch=s[i];
        }
        else if(ch=='+'){
            sign*=+1;
            i++;
            ch=s[i];
        }
        while(i+1<s.size() && ch-'0'==0){
            i++;
            ch=s[i];
        }
        return fatoi(s,i,sign,0);
    }
};



//method2
class Solution {
public:

    int solve(string s, int n, int i, long long num, int sign)
    {
        if(i >= n || !isdigit(s[i]))
            return num * sign;

        num = num * 10 + (s[i] - '0');

        if(sign == -1 && -num < INT_MIN)
            return INT_MIN;

        if(sign == 1 && num > INT_MAX)
            return INT_MAX;

        return solve(s, n, i + 1, num, sign);
    }

    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // remove leading spaces
        while(i < n && s[i] == ' ')
            i++;

        if(i == n)
            return 0;

        int sign = 1;

        if(s[i] == '+' || s[i] == '-')
        {
            if(s[i] == '-')
                sign = -1;

            i++;
        }

        return solve(s, n, i, 0LL, sign);
    }
};
