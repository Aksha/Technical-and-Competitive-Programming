/*
Reverse The Ordering Of Words In A String
Given a string s containing a set of words, transform it such that the words appear in the reverse order. Words in s are separated by one or more spaces. 



Example One

Input: “I will do it.”
Output: “it. do will I”

Example Two

Input: "   word1 word2 " (Note: there are 3 spaces in the beginning, 2 spaces between the words and 1 space at the end.)
Output: " word2  word1 " (Note: there is 1 space in the beginning, 2 spaces between the words and 3 spaces at the end.)

Example Three

Input: "word1, word2;" 
Output: "word2; word1,"

Notes
Input Parameters: Function one argument, string s.
Output: Return a string with the answer.
*/

//Solution: Why won't the solution below pass all test cases? 2 won't pass.

string reverse_ordering_of_words_helper(vector <string> reverse_ip) {
    int n = reverse_ip.size();
    for(int i = 0; i < n/2; i++) {
        swap(reverse_ip[i],reverse_ip[n-1-i]);
    }
    string result = "";
    result += reverse_ip[0];
    for(int i = 1; i < n; i++) {
        result += " " + reverse_ip[i];
    }
    return result;
}

string reverse_ordering_of_words(string s) {
    istringstream word(s);
    string eachWord = "";
    vector <string> reverse_ip;
    while(getline(word,eachWord,' ')) {
        reverse_ip.emplace_back(eachWord);
    }
    string result = reverse_ordering_of_words_helper(reverse_ip);
    return result;

}

//Working solution where the spaces between the words are considered correctly:
/*
 * Complete the reverse_ordering_of_words function below.
 */
string reverse_ordering_of_words(string s) {
    /*
     * Write your code here.
     */
    int left = 0;
    int right = s.length() - 1;
    // reverse the string
    while(left < right)
    {
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
    // reverse individual words
    int ptr = 0;
    left = 0;
    right = 0;
    while(ptr < s.length())
    {
        while(ptr < s.length() && s[ptr] == ' ')
        {
            ptr++;
        }
        left = right = ptr;
        while(right < s.length() && s[right] != ' ')
        {
            right++;
        }
        ptr = right;
        right--;
        while(left < right)
        {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

