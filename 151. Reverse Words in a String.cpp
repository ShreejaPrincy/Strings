// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string reverseWords(string s) {
        string str="";
        string word="";
        for(int i=s.size()-1;i>=0;i--){
            char ch=s[i];
            if(ch!=' ' )   word+=s[i];
            else{
                if(word!="" && word!=" "){
                    reverse(word.begin(),word.end());
                    //Add space BEFORE a word,not AFTER a word
                    if(str != "")
                        str += " ";
                    str+=word;
                }
                word="";
            }
        }
        if(word!="" && word!=" "){
            reverse(word.begin(),word.end());
            //Add space BEFORE a word,not AFTER a word
            if(str != "")
                str += " ";
            str+=word;
        }
        return str;
    }
};
