/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

    Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 

    Note: All inputs will be in lower-case. 

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]

cat and tca are anagrams which correspond to index 1 and 4.
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).
*/
class Solution {
public:
    vector<vector<int> > anagrams(const vector<string> &strs) {
        vector<vector<int> > ans;
        map<string, vector<int> > groups;
        for (int i = 0; i < strs.size(); i++) {
            //sort every string and store groups of strings that are anagrams in a map
            string copyString = strs[i];
            sort(copyString.begin(), copyString.end());
            groups[copyString].push_back(i + 1);
        }

        for(map<string, vector<int> >::iterator it = groups.begin(); it != groups.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
