/* 
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.

*/


class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        int begin = 0;
        while (begin < words.size()) {
            int last = begin;
            int linesize = words[begin++].size();
            while (begin < words.size() && linesize + 1 + words[begin].size() <= L) {
                linesize += 1 + words[begin].size();
                begin++;
            }
            
            int spaces = 1, extra = 0;
            if (begin < words.size() && begin != last + 1) {
                spaces = (L - linesize) / (begin - last - 1) + 1;
                extra = (L - linesize) % (begin - last - 1);
            }
            
            ans.push_back(words[last++]);
            while (extra--) {
                ans.back().append(spaces+1, ' ');
                ans.back().append(words[last++]);
            }
            while (last < begin) {
                ans.back().append(spaces, ' ');
                ans.back().append(words[last++]);
            }
            ans.back().append(L-ans.back().size(), ' ');
        }
        return ans;
    }
};
