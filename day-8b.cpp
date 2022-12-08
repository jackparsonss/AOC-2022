#include<bits/stdc++.h>

using namespace std;

#define SIZE 99

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<vector<int>> g(SIZE, vector<int>(SIZE));
    vector<vector<int>> visited(SIZE, vector<int>(SIZE));
    int row = 0;

    while(getline(cin, line)) {
        for(int i = 0; i < line.size(); i++) {
            g[row][i] = line[i] - '0';
        }
        row++;
    }

    for(int i = 1; i < SIZE-1; i++) {
        for(int j = 1; j < SIZE-1; j++) {
            int score = 1;

            // left
            int temp = 1;
            int idx = j;
            while(idx-1 >= 0 && g[i][idx-1] < g[i][j]) {
                temp++;
                idx--;
            }
            if(idx == 0) {
                temp--;
            }
            score *= temp;

            // right
            temp = 1;
            idx = j;
            while(idx+1 < SIZE && g[i][idx+1] < g[i][j]) {
                temp++;
                idx++;
            }
            if(idx == SIZE-1) {
                temp--;
            }
            score *= temp;
            
            // up
            temp = 1;
            idx = i;
            while(idx-1 >= 0 && g[idx-1][j] < g[i][j]) {
                temp++;
                idx--;
            }
            if(idx == 0) {
                temp--;
            }
            score *= temp;

            // down
            temp = 1;
            idx = i;
            while(idx+1 < SIZE && g[idx+1][j] < g[i][j]) {
                temp++;
                idx++;
            }
            if(idx == SIZE-1) {
                temp--;
            }

            score *= temp;
            visited[i][j] = score;
        }
    }

    int mx = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(visited[i][j] > mx) {
                mx = visited[i][j];
            }
        }
    }

    cout << mx << endl;
}
