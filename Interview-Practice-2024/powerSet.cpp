#include <iostream>
#include <vector>

using namespace std;

void generate_power_set(vector<int> &arr, int i, vector<int> output_arr) {
    if(i == arr.size()) {
        cout << "{";
        for(auto o:output_arr) {
            cout << o << ",";
        }
        cout << "}";
        return;
    }
    output_arr.push_back(arr[i]);
    generate_power_set(arr,i+1,output_arr);
    output_arr.pop_back();
    generate_power_set(arr,i+1,output_arr);
    return;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<int> output_arr;
    generate_power_set(arr, 0, output_arr);
    return 0;
}
