#include<iostream>
#include<vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(){}
    Interval(int s, int e) {
        start = s;
        end = e;
    }
 };

vector<Interval> merge_overlapping_intervals_merge_sort_way(vector<Interval> list1, vector<Interval> list2) {
    vector<Interval> united;
    int i = 0, j = 0;
    while(i < list1.size() && j < list2.size()) {
        if (list1[i].start <= list2[j].start) {
            united.push_back(list1[i]);
            i++;
        } else {
            united.push_back((list2[j]));
            j++;
        }
    }
    while(i < list1.size()) {
        united.push_back(list1[i]);
        i++;
    }
    while(j < list2.size()) {
        united.push_back(list2[j]);
        j++;
    }

    vector<Interval> result;
    //now the lists are in sorted order of start times {{1,2}, {3,9}, {4,6}, {8,10},{11,12}}
    //merging overlapping subintervals. If back > next one.front, overlap, start will be first's first and end will be the max.
    for(int k = 0; k < united.size(); k++) {
        if(!result.empty() && result.back().end >= united[k].start) {
            Interval temp(result.back().start, max(result.back().end, united[k].end));
            result.pop_back();
            result.push_back(temp);
        }
        else {
            result.push_back(united[k]);
        }
    }
    return result;
}

int main() {

    //i/p:
    vector<Interval> list1 = {{1,2},{3,9}};
    vector<Interval> list2 = {{4,6},{8,10},{11,12}};

    //op: {1,2}, {3,10}, {11,12}

    vector<Interval> merged_list = merge_overlapping_intervals_merge_sort_way(list1, list2);
    for(auto a: merged_list) {
        cout << "{" << a.start << ":" << a.end << "}" << endl;
    }
    return 0;
}
