#include<bits/stdc++.h>

using namespace std;

unordered_map<char, char> win = {
    {'A', 'C'},
    {'B', 'A'},
    {'C', 'B'},
};

unordered_map<char, char> lose = {
    {'C', 'A'},
    {'A', 'B'},
    {'B', 'C'},
};

unordered_map<char, int> points = {
    {'A', 1},
    {'B', 2},
    {'C', 3},
};

// 0 - loss, 3 - draw, 6 - win
int calc(char op, char play) {
    if(play == 'Y') {
        return 3 + points[op];
    }

    // win
    if(play == 'Z') {
        return 6 + points[lose[op]];
    }

    return points[win[op]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    long long total = 0;

    while(getline(cin, line)) {
        char op = line[0];
        char play = line[2];
        total += calc(op, play);
    }

    cout << total << endl;
}