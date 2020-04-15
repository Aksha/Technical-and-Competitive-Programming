
/*
 * Solved using the solution discussed in class by instructor Manoj Krishnan @ 3 hours into the IK recursion live class video
 */
void genRes(vector<int>& info, vector<vector<string>>& res) {
    vector<string> ans;
    for (int i = 0; i < info.size(); i++) {
        string str = "";
        for (int j = 0; j < info.size(); j++) {
            if ( j == info[i]) str += "q";
            else str += "-";
        }
        ans.push_back(str);
    }
    res.push_back(ans);       
}

bool isValid(vector<int>& info, int row, int col) {    
    for (int i = 0; i < row; i++) {
        // check col
        if (info[i] == col) return false;
        // check diagonal
        if (abs(info[i]-col) == abs(i-row)) return false;
    }
    return true;   
}

void findQ(int i, vector<int>& info, vector<vector<string>>& res) {

    // base
    if (i == info.size()) {
        genRes(info, res);
    }
    
    for (int j = 0; j < info.size(); j++) {
        if (isValid(info, i, j)) {
            info[i] = j;
            findQ(i+1, info, res);  
        }
    }
}

vector < vector<string> > find_all_arrangements(int n) {
    vector<vector<string>> res;
    vector<int> info(n, -1); //  if info[a] = b, queen is in (a,b)
    findQ(0, info, res);
    return res;
}

