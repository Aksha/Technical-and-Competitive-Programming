/*
Possible To Achieve Target Sum?



Problem Statement:



Given an array of integers arr and a target integer value k, determine whether there exists a non-empty group of numbers in arr such that their sum equals k. Numbers in the group need not be contiguous elements of arr.



The purpose of this problem is to learn recursion and not DP. Write at least one recursive solution. Feel free to write a DP solution after that.



Input Format:



Function has two arguments: arr and k.



Output Format:



Function must return a boolean value.



Constraints:

1 <= size of arr <= 18
-10^17 <= arr[i], k <= 10^17


Sample Input 1:



arr = [2 4 8]

k = 6



Sample Output 1:



True



Because arr[0] + arr[1] = 6.





Sample Input 2:



arr = [2 4 6]

k = 5



Sample Output 2:



False



Because no group of numbers in arr sums up to 5.





Custom Input Format:



First line of input contains integer n, size of arr.

Next n lines contain integer elements of arr.

Next line contains integer k.



If arr = [2, 4, 8] and k = 6, custom input would be:



3

2

4

8

6



Custom Output Format:



Valid output consists of a single character on a single line: 0 for False or 1 for True.



For input arr = [2, 4, 8] and k = 6, correct output would be:



1
*/

bool check_if_sum_possible_helper(vector <long long int> arr, long long int sum, long long int pos, bool selected) {
    if(sum == 0 && selected)
        return true;
    if(pos == arr.size())
        return false;
    return check_if_sum_possible_helper(arr,sum-arr[pos],pos+1, true) || check_if_sum_possible_helper(arr,sum,pos+1, selected);
}

bool check_if_sum_possible(vector <long long int> arr, long long int k) {
    return check_if_sum_possible_helper(arr,k,0,false);
}
