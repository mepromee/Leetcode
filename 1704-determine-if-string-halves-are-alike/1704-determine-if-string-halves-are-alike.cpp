class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int aVowels = 0, bVowels = 0;
        
        int n = s.length();
        for(int i = 0, j = n-1; i < j; i++,j--) {
            for(auto vowel: vowels) {
                if(vowel == s[i]) {
                    aVowels++;
                }
                if(vowel == s[j]) {
                    bVowels++;
                }
            }
        }
        
        return aVowels == bVowels;
    }
};
/*
3:14
*/