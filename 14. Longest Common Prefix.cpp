// Time Complexity: O(n * m)
// Space Complexity: O(1)
class Solution {
public:
    bool checkk(vector<string>& strs,char ch,int col,int row){
        for(int i=1;i<row;i++){
            if(col>=strs[i].size() || strs[i][col]!=ch) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int row=strs.size();
        int col=strs[0].size();
        for(int i=0;i<col;i++){
                char ch=strs[0][i];
                bool checki=checkk(strs,ch,i,row);

                if(!checki)
                    return strs[0].substr(0,i);
        }
        return strs[0];
    }
};
