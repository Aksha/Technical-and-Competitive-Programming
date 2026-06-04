https://neetcode.io/problems/buy-and-sell-crypto/solution

Brute force:

class Solution {
public:
// Simple brute force approach
//buy coin everyday and try to sell it everyday
//store max. return max.
//can't change the order of purchase and selling
//[5, 7, 9, 1, 2]
//-> buy at 5, sell at 9 for max profit
// not necessarily the smallest number to pick
// largest difference matters

    int maxProfit(vector<int>& prices) {
        int maximum = 0;
        int n = prices.size();
        for(int i = 0; i < prices.size(); i++) {
            for(int j = i+1; j < n; j++) {
                maximum = max(maximum, prices[j] - prices[i]);
            }
        }
        return maximum;
    }
};

O(n2) and space is O(1)

Two pointer approach: O(n) and O(1)

Intuition:

Intuition
We want to buy at a low price and sell at a higher price that comes after it.
Using two pointers helps us track this efficiently:

l is the buy day (looking for the lowest price)
r is the sell day (looking for a higher price)
If the price at r is higher than at l, we can make a profit — so we update the maximum.
If the price at r is lower, then r becomes the new l because a cheaper buying price is always better.

By moving the pointers this way, we scan the list once and always keep the best buying opportunity.

Algorithm
Set two pointers:
l = 0 (buy day)
r = 1 (sell day)
maxP = 0 to track maximum profit
While r is within the array:
If prices[r] > prices[l], compute the profit and update maxP.
Otherwise, move l to r (we found a cheaper buy price).
Move r to the next day.
Return maxP at the end.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};

Dynamic programming approach: Very similar to finding the max difference in a sequence

Intuition:

Intuition
As we scan through the prices, we keep track of two things:

The lowest price so far → this is the best day to buy.
The best profit so far → selling today minus the lowest buy price seen earlier.
At each price, we imagine selling on that day.
The profit would be:
current price – lowest price seen so far

We then update:

the maximum profit,
and the lowest price if we find a cheaper one.
This way, we make the optimal buy–sell decision in one simple pass.

DP : O(n) and O(1) still.


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minBuy = prices[0];

        for (int& sell : prices) {
            maxP = max(maxP, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxP;
    }
};
