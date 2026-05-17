// Time Complexity: O(n^2 * 26) = O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            vector<int>f(26,0);
            
            for(int j=i;j<s.size();j++){
                f[s[j]-'a']++;

                int maxi=0,mini=INT_MAX;
                for(int x:f){
                    if(x>0){
                        maxi=max(maxi,x);
                        mini=min(mini,x);
                    }
                }
                
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};
