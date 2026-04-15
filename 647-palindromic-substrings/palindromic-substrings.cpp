class Solution {
public:
    int expand(string &s, int l, int r) {
        int count = 0;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;   // valid palindrome
            l--;
            r++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            total += expand(s, i, i);     // odd length
            total += expand(s, i, i + 1); // even length
        }

        return total;
    }
};