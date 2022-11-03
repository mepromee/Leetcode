class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        bool isOneTaken = false;
        int ans = 0;
        string curWord, reverseWord;
        
        for(auto &word: words) {
            cnt[word]++;
        }
        for(auto word: words) {
            
            if(cnt[word] == 0) continue;
            
            reverseWord = word;
            reverse(reverseWord.begin(),reverseWord.end());

            if(word != reverseWord && cnt[reverseWord] > 0) {
                ans += 4;
                cnt[word]--;
                cnt[reverseWord]--;
            }
            else if(cnt[reverseWord] > 1) {
                ans += 4;
                cnt[word]-=2;
            } 
            else if(cnt[reverseWord] == 1 && !isOneTaken) {
                isOneTaken = true;
                ans += 2;
                cnt[reverseWord]--;
            }
            
        }
        
        return ans;
        
    }
};
/*
9:31
*/