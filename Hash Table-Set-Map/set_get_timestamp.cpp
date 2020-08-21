#include<iostream>
#include<ctime>
#include<vector>
#include<unistd.h>
#include<unordered_map>

using namespace std;

struct key_timestamp {
    string value;
    time_t timestamp;
};

class hmap {
public:
    unordered_map < string, vector < key_timestamp >> umap;
    key_timestamp kt;

    time_t set(string key, string value) { //O(1)
        kt.value = value;
        kt.timestamp = std::time(nullptr);
        if (umap.find(key) == umap.end()) {
            vector < key_timestamp > values;
            values.push_back(kt);
            umap.insert(make_pair(key, values));
        } else {
            umap[key].push_back(kt);
        }
        return kt.timestamp;
    }

    string get(string key) {
        //unordered_map<int,vector<key_timestamp>::iterator it = umap.begin();
        if (umap.find(key) != umap.end()) {
            vector < key_timestamp > temp = umap[key];
            int size = temp.size();
            key_timestamp kt1;
            kt1.value = temp[size - 1].value;
            return kt1.value;
        }
        return "";
    }

    string get(string key, int input_timestamp) { //O(logn)
        //unordered_map<int,vector<key_timestamp>::iterator it = umap.begin();
        if (umap.find(key) != umap.end()) {
            vector < key_timestamp > temp = umap[key];
            for (int i = 0; i < temp.size(); i++) {
                if (input_timestamp == temp[i].timestamp) {
                    return temp[i].value;
                }
            }
        }
        return "";
    }

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    hmap kv;
    time_t timestamp1 = kv.set("foo", "bar1");
    //kv.set<"foo","bar2");
    cout << "with timestamp attempt 1 : " << kv.get("foo", timestamp1) << endl;
    sleep(1);
    time_t timestamp2 = kv.set("foo", "bar2");
    sleep(1);
    //cout << "timestamp1 : " << timestamp1 << "; timestamp 2 : " << timestamp2 << endl;
    cout << "with timestamp attempt 2 : " << kv.get("foo", timestamp2) << endl;
    time_t timestamp3 = kv.set("foo", "bar3");
    cout << "with timestamp attempt 3 : " << kv.get("foo", timestamp3) << endl;
    return 0;
}
