class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        int i = 0;
        while ( i < s.length() ){
            set<char> characters;
            while ( i < s.length() && (characters.find(s[i]) == characters.end())){
                characters.insert(s[i]);
                i++;
            }
            count++;
        }
         return count;
    }
   
};




