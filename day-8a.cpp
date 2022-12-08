#include<bits/stdc++.h>

using namespace std;

#define SIZE 99

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<vector<int>> g(SIZE, vector<int>(SIZE));
    vector<vector<bool>> visited(SIZE, vector<bool>(SIZE));
    int row = 0;

    while(getline(cin, line)) {
        for(int i = 0; i < line.size(); i++) {
            g[row][i] = line[i] - '0';
        }
        row++;
    }

    for(int i = 0; i < SIZE; i++) {
        if(i == 0) {
            // do full row going down
            for(int j = 1; j < SIZE-1; j++) {
                visited[i][j] = true;
                int temp = i;
                int largest = g[i][j];
                while(temp+1 < SIZE) {
                    if(largest < g[temp+1][j]) {
                        visited[temp+1][j] = true;
                        largest = g[temp+1][j];
                    }
                    temp++;
                }
            }
        } else if(i == SIZE-1) {
            // do last row going up
            for(int j = 1; j < SIZE-1; j++) {
                visited[i][j] = true;
                int temp = i;
                int largest = g[i][j];
                while(temp-1 >= 0) {
                    if(largest < g[temp-1][j]){
                        visited[temp-1][j] = true;
                        largest = g[temp-1][j];
                    }
                    temp--;
                }
            }
        } else {
            // do first col going right
            int temp = 0;
            visited[i][temp] = true;
            int largest = g[i][temp];
            while(temp + 1 < SIZE) {
                if(largest < g[i][temp+1]){
                    visited[i][temp+1] = true;
                    largest = g[i][temp+1];
                }
                temp++;
            }

            // do last col going left
            temp = SIZE-1;
            visited[i][temp] = true;
            largest = g[i][temp];
            while(temp - 1 >= 0) {
                if(largest < g[i][temp-1]) {
                    visited[i][temp-1] = true;
                    largest = g[i][temp-1];
                }
                temp--;
            }
        }

    }

    int count = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(visited[i][j]) {
                count++;
            }
        }
    }

    cout << count + 4 << endl; // +4 since we never process the 4 corners but they are always visible
}