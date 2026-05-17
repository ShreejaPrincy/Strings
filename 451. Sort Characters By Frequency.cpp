// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string frequencySort(string s) {
        map <char,int> m;
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
      //using bucket sort
        vector<string>bucket(n+1,"");
        for(auto mp:m){
            int index=mp.second;
            char ch=mp.first;
            // repeat char freq times
            bucket[index]+=string(index,ch);
        }
        string ans="";
        for(int i=bucket.size()-1;i>=0;i--){
            if(bucket[i]!=""){
                ans+=bucket[i];
            }
        }
        return ans;
    }
};
