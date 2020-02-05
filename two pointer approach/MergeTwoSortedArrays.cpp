Merge First Sorted Array Into Second Sorted Array



Problem Statement:



Given two arrays:



1) arr1 of size n, which contains n positive integers sorted in increasing order.

2) arr2 of size (2*n) (twice the size of first), which contains n positive integers sorted in increasing order in its first half. Second half of this array arr2 is empty. (Empty elements are marked by 0).



Write a function that takes these two arrays, and merges the first one into second one, resulting in an increasingly sorted array of (2*n) positive integers.



Input Format:



There are two arguments. First one is an integer array denoting arr1 and second one is also an integer array denoting arr2.



Output Format:



You don't have to return anything. You just need to modify the given array arr2.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer n, denoting size of input array arr1. In next n lines, ith line should contain an integer arr1[i], denoting value at index i of arr1.

In next line, there should be an integer (2*n), denoting size of input array arr2. In next (2*n) lines, ith line should contain an integer arr2[i], denoting value at index i of arr2.



If n = 3, arr1 = [1, 3, 5] and arr2 = [2, 4, 6, 0, 0, 0], then input should be:



3

1

3

5

6

2

4

6

0

0

0



Output Format:



There will (2*n) lines of output, where ith line contains an integer arr2[i], denoting value at index i of arr2.



For input n = 3, arr1 = [1, 3, 5] and arr2 = [2, 4, 6, 0, 0, 0], output will be:



1

2

3

4

5

6



Constraints:



1 <= n <= 10^5
1 <= arr1[i] <= 2 * 10^9
1 <= arr2[i] <= 2 * 10^9 (for the first half)
arr2[i] = 0 (for the second half)
You can use only constant extra space.
0 denotes an empty space.


Sample Test Case:



Sample Input:



n = 3

arr1 = [1 3 5]

arr2 = [2 4 6 0 0 0]



Sample Output:



arr2 = [1 2 3 4 5 6]


Solution:

void merger_first_into_second(vector<int>& arr1, vector<int>& arr2)
{
	int n = arr1.size();
	// Start merging from the end. 
	int last1 = n - 1;
	int last2 = n - 1;
	int last = n + n - 1;
	// At least one element reamining. 
	while (last >= 0)
	{
		// If no elements remaining in arr1.
		if (last1 < 0)
		{
            // Think about the case when arr1 = [4, 5, 6] arr2 = [1, 2, 3, 0, 0, 0].
            // Once last1 = -1, arr2 will be [1, 2, 3, 4, 5, 6]. So, we can stop here.
            break;
		}
		// If no elements remaining in arr2.
		else if (last2 < 0)
		{
			arr2[last--] = arr1[last1--];
		}
		// Priority to larger element, as we are merging from the end. 
		else if (arr1[last1] <= arr2[last2])
		{
			arr2[last--] = arr2[last2--];
		}
		else
		{
			arr2[last--] = arr1[last1--];
		}
	}
}
