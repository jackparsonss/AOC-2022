#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    long long total = 0;
    vector<unordered_set<char>> v(3);
    int counter = 0;
    while(getline(cin, line)) {
        // find common and reset
        if(counter == 3) {
            for(char c: v[0]) {
                if(v[1].find(c) != v[1].end() && v[2].find(c) != v[2].end()) {
                    if(isupper(c)) {
                        total += c-38;
                    } else {
                        total += c-96;
                    }
                }
            }
            counter = 0;
            v[0].clear();
            v[1].clear();
            v[2].clear();
        }

        for(char c: line){
            v[counter].insert(c);
        }

        counter++;
    }
    for(char c: v[0]) {
        if(v[1].find(c) != v[1].end() && v[2].find(c) != v[2].end()) {
            if(isupper(c)) {
                total += c-38;
            } else {
                total += c-96;
            }
        }
    }
    cout << total << endl;
}