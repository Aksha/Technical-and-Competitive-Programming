
/*
 * Complete the function below.
 */
vector<string> restore_path(string& start, string& stop, unordered_map<string, string>& visited_path) {
    deque<string> path;
    path.push_front(stop);
    string current = visited_path[stop];
    
    while (current != start) {
        path.push_front(current);
        current = visited_path[current];
    }
    path.push_front(current);
    
    vector<string> v_path(path.begin(), path.end());
    return v_path;
}

bool one_diff(string& s1, string& s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    
    bool has_diff = false;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (has_diff) return false;
            has_diff = true;
        }
    }
    
    return has_diff;
}

bool add_generated_words(string& current, string& stop, unordered_set<string>& dict, 
                unordered_map<string, string>& visited_path, queue<string>& toVisit) {
    string next = current;
    for (int i = 0; i < next.size(); i++) {
        char old = next[i];
        for (int j = 0; j < 26; j++) {
            char next_char = 'a' + j;
            if (next_char == old) continue;
            next[i] = 'a' + j;
            if (next == stop) {
                visited_path[next] = current;
                return true;
            }
            if (dict.find(next) != dict.end() && visited_path.find(next) == visited_path.end()) {
                toVisit.push(next);
                //cout << "toVisit " << next << endl;
                visited_path[next] = current;
            }
        }
        next[i] = old;
    }
    
    return false;
}

bool add_dict_words(string& current, string& stop, vector<string>& dict, 
                unordered_map<string, string>& visited_path, queue<string>& toVisit) {
    if (one_diff(current, stop)) {
        //cout << "found current " << current << endl;
        visited_path[stop] = current;
        return true;
    }
    for (string& next : dict) {
        //cout << "next " << next << endl;
        /*if (one_diff(next, stop)) {
            visited_path[next] = current;
            visited_path[stop] = next;
            return true;
        }*/
        if (visited_path.find(next) == visited_path.end() && one_diff(current, next) && next != current) {
            toVisit.push(next);
            //cout << "toVisit " << next << endl;
            visited_path[next] = current;
        }
    }
    
    return false;
}

/*
 * Complete the function below.
 */
vector<string> string_transformation(vector<string> words, string start, string stop) {
    vector<string> not_found;
    not_found.push_back("-1");
    
    if (start.size() != stop.size()) {
        return not_found;
    }
    
    unordered_set<string> dict(words.begin(), words.end());
    queue<string> toVisit;
    unordered_map<string, string> visited_path;
    toVisit.push(start);
    visited_path[start] = "";
    
    while (!toVisit.empty()) {
        string current = toVisit.front();
        toVisit.pop();
        //cout << "current " << current << endl;
        if (dict.size() > 26) {
            if (add_generated_words(current, stop, dict, visited_path, toVisit)) {
                return restore_path(start, stop, visited_path);
            }
        } else {
            if (add_dict_words(current, stop, words, visited_path, toVisit)) {
                return restore_path(start, stop, visited_path);
            }
        }
    }
    
    return not_found;
}


