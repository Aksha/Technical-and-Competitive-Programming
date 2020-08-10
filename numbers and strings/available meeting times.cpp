#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*

person 1 : [{15, 16} ,{9 , 10), {16,17}]
person 2 :  [{15,17},{14,15}]
person 3 : [{10, 12}, {15,16}]

	1. get the vector<pair<int,int>> meeting times of all people and store it in one array
	2. sort this array based on start time
	3. merge_overlapping_subintervals;
	4. return result
*/

vector<pair<int,int>> merge_overlapping_intervals(vector<pair<int,int>> person_calendar) {
    vector<pair<int,int>> merged_list;
    int i = 0;
    while(i < person_calendar.size() - 1) {
        if(person_calendar[i].second >= person_calendar[i+1].first) { // {{9,1}, {11,12}, {12,1}}
            merged_list.push_back(make_pair(min(person_calendar[i].first, person_calendar[i+1].first),max(person_calendar[i].second, person_calendar[i+1].second)));
            i++;
        }
        else {
            merged_list.push_back(make_pair(person_calendar[i].first, person_calendar[i].second));
        }
        i++;
    }
    return merged_list;
}

vector<pair<int,int>> available_meeting_time(vector<vector<pair<int,int>>> people_calendar) { //{{{15, 16} ,{9 , 10), {16,17}},{{15,17},{14,15}},{ {10, 12}, {15,16}}}
    vector<pair<int,int>> meeting_times;
    for(int i = 0; i < people_calendar.size(); i++) {
        for(int j = 0; j < people_calendar[i].size(); j++) {
            meeting_times.push_back(people_calendar[i][j]);
        }
    }
    sort(meeting_times.begin(), meeting_times.end()); // [{9 , 10), {15,16}, {16,17} ]
    meeting_times = merge_overlapping_intervals(meeting_times);
    return meeting_times;
}

int main() {
    vector<vector<pair<int,int>>> people_calendar = {{{15, 16} ,{9 , 10}, {16,17}},{{15,17},{14,15}},{{10, 12}, {15,16}}};
    vector<pair<int,int>> meeting_times = available_meeting_time(people_calendar);
   /* for(int i = 0; i < meeting_times.size(); i++) {
        cout << meeting_times[i].first << " , " << meeting_times[i].second << endl;
    }*/
   cout << "People are available to meet at : " << endl;
    for(int i = 0; i < meeting_times.size()-1; i++) {
        if(meeting_times[i].second < meeting_times[i+1].first) {
            cout << "[" << meeting_times[i].second << " , " << meeting_times[i+1].first << "]" << endl;
        }
    }
    return 0;
}
