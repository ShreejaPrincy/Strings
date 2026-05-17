// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>st;
        unordered_map<char,char>ts;

        //s to t
        for(int ch=0;ch<s.size();ch++){
            char c=s[ch];
            if(st.find(c)!=st.end()){
                if(st[c]!=t[ch])   return false;
            }
            st[c]=t[ch];
        }
        //t to s
        for(int ch=0;ch<t.size();ch++){
            char c=t[ch];
            if(ts.find(c)!=ts.end()){
                if(ts[c]!=s[ch])   return false;
            }
            ts[c]=s[ch];
        }
        return true;
    }
};
