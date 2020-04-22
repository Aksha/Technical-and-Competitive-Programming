
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

/*
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
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;
/*
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
unordered_map <char, vector<char>> get_edges(vector <string> words) {
    unordered_map <char, vector<char>> edges;
    for(int i = 0; i < words.size()-1; i++) {
        int j = 0;
        int k = 0;
        while(j < words[i].size() && k < words[i+1].size()) {
            cout << " character 1 : " << words[i][j] << "; character 2 : " << words[i+1][k] << endl;
            if(words[i][j] != words[i+1][k]){
                if(edges.find(words[i][j]) == edges.end()) {
                    vector <char> temp = {words[i+1][k]};
                    edges.insert(make_pair(words[i][j], temp));
                }
                else
                    edges[words[i][j]].push_back(words[i+1][k]);
                break;
            }
            else {
                j++;
                k++;
            }
        }
    }
    cout << "Edges size: " << edges.size() << endl;
    for(auto vertex : edges) {
        for(auto it : vertex.second) {
            cout << vertex.first << " : " << it << endl;
        }
    }
    return edges;
}

void topological_sort(unordered_map <char, vector<char>> edges, char vertex,  unordered_set<char> &visited, stack <char> &S) {
    visited.insert(vertex);
    for(vector<char>::iterator V = edges[vertex].begin(); V != edges[vertex].end(); ++V) {
        if(visited.find(*V) == visited.end()) {
            topological_sort(edges, *V, visited, S);
        }
    }
    S.push(vertex);
}

string find_order(vector <string> words) {
    unordered_map <char, vector<char>> edges = get_edges(words);
    unordered_set <char> visited;
    stack <char> S;
    string result = "";
   for(unordered_map <char, vector<char>>::iterator vertex = edges.begin(); vertex != edges.end(); ++vertex) {
        if(visited.find(vertex->first) == visited.end())
            topological_sort(edges,vertex->first,visited,S);
    }
    while(!S.empty()) {
        result += S.top();
        S.pop();
    }
    return result;
}



int main() {
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    string result = find_order(words);
    cout <<"the output is : "  << result << endl;
    return 0;
}

//Solution that handles corner and edge cases:

/*
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
unordered_map <char, vector<char>> get_edges(vector <string> words) {
    unordered_map <char, vector<char>> edges;
    for(int i = 0; i < words.size()-1; i++) {
        int j = 0;
        int k = 0;
        while(j < words[i].size() && k < words[i+1].size()) {
            //cout << " character 1 : " << words[i][j] << "; character 2 : " << words[i+1][k] << endl;
            if(words[i][j] != words[i+1][k]){
                if(edges.find(words[i][j]) == edges.end()) {
                    vector <char> temp = {words[i+1][k]};
                    edges.insert(make_pair(words[i][j], temp));
                }
                else
                    edges[words[i][j]].push_back(words[i+1][k]);
                break;
            }
            else {
                j++;
                k++;
            }
        }
    }
    /*cout << "Edges size: " << edges.size() << endl;
    for(auto vertex : edges) {
        for(auto it : vertex.second) {
            cout << vertex.first << " : " << it << endl;
        }
    }*/
    return edges;
}

void topological_sort(unordered_map <char, vector<char>> edges, char vertex,  unordered_set<char> &visited, stack <char> &S) {
    visited.insert(vertex);
    for(vector<char>::iterator V = edges[vertex].begin(); V != edges[vertex].end(); ++V) {
        if(visited.find(*V) == visited.end()) {
            topological_sort(edges, *V, visited, S);
        }
    }
    S.push(vertex);
}

string find_order(vector <string> words) {
    if(words.size() == 1) {
         string result = "";
         result += words[0][0];
         return result;
    }
    unordered_map <char, vector<char>> edges = get_edges(words);
    if(edges.size() == 0) {
         string result = "";
         result += words[0][0];
         return result;
    }
    unordered_set <char> visited;
    stack <char> S;
    string result = "";
   for(unordered_map <char, vector<char>>::iterator vertex = edges.begin(); vertex != edges.end(); ++vertex) {
        if(visited.find(vertex->first) == visited.end())
            topological_sort(edges,vertex->first,visited,S);
    }
    while(!S.empty()) {
        result += S.top();
        S.pop();
    }
    return result;
}
