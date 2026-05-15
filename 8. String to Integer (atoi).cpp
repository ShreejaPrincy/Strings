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
