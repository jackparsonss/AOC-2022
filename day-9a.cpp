#include<bits/stdc++.h>

using namespace std;

bool close(int hi, int hj, int ti, int tj) {
    return (abs(hi - ti) < 2) && (abs(hj - tj) < 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    set<pair<int, int>> visited; // visited by tail
    int hi = 0;
    int hj = 0;
    int ti = 0;
    int tj = 0;
    while(getline(cin, line)) {
        int dist = stoi(line.substr(2));
        if(line[0] == 'R') {
            for(int i = 0; i < dist; i++) {
                hj++;
                if(!close(hi, hj, ti, tj)) {
                    ti = hi;
                    tj = hj-1;
                }
                visited.insert({ti, tj});
            }
        } else if(line[0] == 'L') {
            for(int i = 0; i < dist; i++) {
                hj--;
                if(!close(hi, hj, ti, tj)) {
                    ti = hi;
                    tj = hj+1;
                }
                visited.insert({ti, tj});
            }
        } else if(line[0] == 'U') {
            for(int i = 0; i < dist; i++) {
                hi++;
                if(!close(hi, hj, ti, tj)) {
                    ti = hi-1;
                    tj = hj;
                }
                visited.insert({ti, tj});
            }
        } else {
            // down
            for(int i = 0; i < dist; i++) {
                hi--;
                if(!close(hi, hj, ti, tj)) {
                    ti = hi+1;
                    tj = hj;
                }
                visited.insert({ti, tj});
            }
        }
    }

    cout << visited.size() << endl;
}