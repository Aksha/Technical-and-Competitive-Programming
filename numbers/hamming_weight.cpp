#include <iostream>
#include <vector>

using namespace std;

vector<int> decimalToBinary(vector<int> input) {
    vector<int> count1;
    for(int i = 0; i < input.size(); i++) {
        int count = 0;
        while(input[i] > 0) {
            int n = input[i] % 2;
            if(n==1) {
                count++;
            }
            input[i] = input[i] / 2;
        }
        count1.push_back(count);
    }
    return count1;
}

int main() {
    vector <int> input = {1,2,3};
    //convert from decimal to binary
    vector<int> count1 = decimalToBinary(input);
    int sum = 0;
    for(int i = 0; i < count1.size(); i++) {
        sum += count1[i];
    }
    cout << sum << endl;
    return 0;
}
