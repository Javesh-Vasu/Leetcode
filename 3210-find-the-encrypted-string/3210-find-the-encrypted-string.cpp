class Solution {
public:
    string getEncryptedString(string s, int k) {
        string encrypted = s;
        int pos;
        for ( int i = 0 ; i < s.length(); ++i )
        {
            pos = i + k;
                pos = pos % s.length();
                encrypted[i] = s[pos];
        }
        return encrypted;
    }
};