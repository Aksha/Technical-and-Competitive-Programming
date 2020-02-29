Leetcode 404. Frog Jump:

class Solution {
  public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i = 3; i < stones.size(); i++) {
            if(stones[i] > stones[i-1]*2)
                return false;
        }
        
        stack<int> jump;
        stack<int> position;
        set<int> allStones;
        for(int i = 0; i < n; i++) {
            allStones.insert(stones[i]);
        }
        jump.push(1);
        position.push(0);
        int lastStone = stones[n-1];
        while(!position.empty()) {
            int currPosition = position.top();
            position.pop();
            int currJump = jump.top();
            jump.pop();
            for(int i = currJump-1; i <= currJump+1; i++) {
                int nextPosition = currPosition+i;
                if(nextPosition == lastStone) {
                    return true;
                }
                else if(allStones.find(nextPosition) != allStones.end()) {
                    position.push(nextPosition);
                    jump.push(i);
                }
            }
        }
        return false;
    }
};
