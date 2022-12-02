#include<bits/stdc++.h>

using namespace std;

unordered_map<char, char> game = {
    {'A', 'Y'},
    {'B', 'Z'},
    {'C', 'X'},
};

unordered_map<char, int> points = {
    {'X', 1},
    {'Y', 2},
    {'Z', 3},
};

unordered_map<char, char> same = {
    {'A', 'X'},
    {'B', 'Y'},
    {'C', 'Z'},
};

// 0 - loss, 3 - draw, 6 - win
int calc(char op, char play) {
    if(same[op] == play) {
        return 3 + points[play];
    }

    if(game[op] == play) {
        return 6 + points[play];
    }

    return points[play];
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