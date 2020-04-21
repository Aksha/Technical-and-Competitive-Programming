
/*

Find Order Of Characters From Alien Dictionary
Given a sorted dictionary of an alien language, find the order of characters in the alphabet.
Example One
Input: ["baa", "abcd", "abca", "cab", "cad"]
Output: "bdac" 

Example Two
Input: words = ["caa", "aaa", "aab"]
Output: "cab"

Notes
Input Parameters: Function has one argument, array of strings, the dictionary sorted in the lexicographical order of the alien language.
Output: Return a string consisting of all the characters of the alien alphabet, in order.

Constraints:
1 <= characters in all the words in the dictionary <= 10^5
Input will consist of lowercase latin characters only.
Input will be such that it is possible to determine the alphabet order uniquely.
The dictionary may contain duplicate words.

Custom Input
Input Format: The first line of input should contain an integer n, denoting size of input array words. In next n lines, i-th line should contain a string words[i], denoting a value at index i of words.

If n = 5 and words = ["baa", "abcd", "abca", "cab", "cad"], then input should be:

5

baa

abcd

abca

cab

cad



Output Format: There will be only one line of output, containing a string ordered, denoting the result returned by solution function. For input n = 5 and words = ["baa", "abcd", "abca", "cab", "cad"], output will be:

bdac


##### Solution Discussion : ######
Why topological sort? 

 * When we can do a normal character to character comparison in this function, why do we need to use DFS/topological sort?
 Imagine the case where we have words  = {"caa", "aaa", "dab"}. A normal character to character comparison only gives us the following result = cad but the actual answer here is cadb. All nodes have to be visited. This is where topological sort helps/comes in.
 
 Better example: {"caa", "aaa", "aad", "bad", "da"}
 c->a
 a->b
 a->d
 b->d
 How will I write this in an output array?
  c,a,d is wrong, the actual answer is c,a,b,d. Hence, we need to use DFS on a Directed Acylic graph , i.e., topological sort. Try out to check if this graph is acylic.
  
  Now to use topological sort. 
  1) We need a hashmap of edges
  2) DFS (generates helper method) on every node if not visited (have a set or boolean array to keep track of visited)
  3) recursive call on the helper method for all of the neighbours of the current node/edges, in this case, character
  4) Finally, add this node to a stack (recursive)
  
 */
string find_order(vector <string> words) {
    
}

