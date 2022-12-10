#include<bits/stdc++.h>

using namespace std;

void update(vector<pair<int, int>>& rope, int j) {
    if(rope[j].second - rope[j+1].second < -1) {
        // difference going left
        rope[j+1].second = rope[j].second+1;
    } else if(rope[j].second - rope[j+1].second > 1) {
        // difference going right
        rope[j+1].second = rope[j].second-1;
    } else if(rope[j].first - rope[j+1].first < -1) {
        // difference going up
        rope[j+1].first = rope[j].first+1;
    } else if(rope[j].first - rope[j+1].first > 1) {
        // difference going down
        rope[j+1].first = rope[j].first-1;
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    set<pair<int, int>> visited; // visited by tail
    vector<pair<int, int>> rope(10);

    while(getline(cin, line)) {
        int dist = stoi(line.substr(2));
        if(line[0] == 'R') {
            for(int i = 0; i < dist; i++) {
                rope[0].second++;
                for(int j = 0; j < 9; j++) {
                    update(rope, j);
                }
                visited.insert(rope[9]); // insert tail
            }
        } else if(line[0] == 'L') {
            for(int i = 0; i < dist; i++) {
                rope[0].second--;
                for(int j = 0; j < 9; j++) {
                   update(rope, j); 
                }
                visited.insert(rope[9]); // insert tail
            }
        } else if(line[0] == 'U') {
            for(int i = 0; i < dist; i++) {
                rope[0].first++;
                for(int j = 0; j < 9; j++) {
                    update(rope, j);
                }
                visited.insert(rope[9]); // insert tail
            }
        } else {
            // down
            for(int i = 0; i < dist; i++) {
                rope[0].first--;
                for(int j = 0; j < 9; j++) {
                    update(rope, j);
                }
                visited.insert(rope[9]); // insert tail
            }
        }

        cout << "---\n" << line << ":" << endl;
        for(int i = 0; i < 10; i++) {
            cout << rope[i].first << " " << rope[i].second << endl;
        }
        cout << "---\n";
    }

    cout << visited.size() << endl;
}