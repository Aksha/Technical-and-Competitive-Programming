/*
Generate Numeronyms



Given a string word of length n, generate all possible numeronyms.

What is a Numeronym?

A numeronym is a word where a number is used to form an abbreviation.

For a given string word, a numeronym is a string with few or more contiguous letters between the first letter and last letter of word replaced with a number representing the count of letters omitted. Only one set of contiguous letters are replaced by a number.

e.g. “L10n” is called a numeronym of the word “Localization”, where 10 stands for the count of letters between the first

letter 'L' and the last letter 'n' in the word.



Example

Input: “nailed”

 

Output: ["n4d", "na3d", "n3ed", "n2led", "na2ed", "nai2d"]



“n4d” is an abbreviation of given string “nailed” where “aile” string letters are omitted and replaced by count of letters, i.e. 4.

“na3d” is an abbreviation of given string “nailed” where “ile” string letters are omitted and replaced by count of letters, i.e. 3.

And so on.
*/

//Solution:
vector<string> neuronyms(string word) {
    if(word.length() < 4)
		return {};

	vector<string> result;
	int n = word.length();
	for(int pos = 1; pos < n - 1; pos++){
		for(int len = 2; len <= n - 2 - pos + 1; len++){
			string temp = word.substr(0, pos) + to_string(len) + word.substr(pos + len);
	        result.emplace_back(temp);
		}
	}
	return result;
}
