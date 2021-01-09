/*
Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 

Constraints:

1 <= beginWord.length <= 100
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.

*/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) {
            return 0;
        }
        if (find(begin(wordList), end(wordList), endWord) == wordList.end()) {
            return 0;
        }
        unordered_set<string> D;
        for (auto w : wordList) {
            D.insert(w);
        }
        int lvl = 0, len = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        while (not q.empty()) {
            ++lvl;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                string word = q.front();
                q.pop();
                for (int pos = 0; pos < len; ++pos) {
                    char orig_char = word[pos];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        word[pos] = ch;
                        if (word == endWord) {
                            return lvl + 1;
                        }
                        if (D.find(word) != D.end()) {
                            D.erase(word);
                            q.push(word);
                        }
                    }
                    word[pos] = orig_char;
                }
            }
        }
        return 0;
    }
};
