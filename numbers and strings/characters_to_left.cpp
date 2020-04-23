/*
Move All Letters To Left Side With Minimizing Memory Writes
You are given a string s, which may contain alphabet letters ('a' - 'z' or 'A' - 'Z') as well as numerical characters ('0' - '9'), in random order. Numerical characters are garbage characters and we don't care about them. Inside the same string, you have to make all alphabet letters appear on the left side though in the same order they appeared originally. Suppose in our architecture, memory write is a very expensive operation, so we have to minimize the number of writes. As digits are garbage, we need not to move them on the right side. Here we can save some memory writes!

Example One
Input: “1x”
Output: “xx”

“xx” is the only correct answer. “x1”, for example, is a wrong answer since reaching that string would have required two memory writes while reaching “xx” requires one.

Example Two
Input: "0a193zbr"
Output: "azbr3zbr" 

In the given string letters are a, z, b and r. We can move all four letters to the left side with 4 write operations and get the string "azbr3zbr". Reaching any other string would have taken more than four writes, so "azbr3zbr" is the only correct answer.
*/

//Solution: 

string move_letters_to_left_side_with_minimizing_memory_writes(string s) {
    /*
     * Write your code here.
     */
    int start = 0;
    int n = s.size();
    if(n == 0 || n == 1)
        return s;
    for(int movingPtr = 0; movingPtr < n; movingPtr++) {
        if(s[movingPtr] >= '0' && s[movingPtr] <= '9') { //You can use the isdigit() or isalpha() methods here
            continue;
        }
        else {
            s[start] = s[movingPtr];
            start++;
        }
    }
    return s;
}

