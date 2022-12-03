#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    long long total = 0;
    while(getline(cin, line)) {
        unordered_set<char> s1;
        unordered_set<char> s2;

        for(int i = 0; i < line.size() / 2; i++) {
            s1.insert(line[i]);
        }

        for(int i = line.size()/2; i < line.size(); i++) {
            s2.insert(line[i]);
        }

        for(char c: s1) {
            if(s2.find(c) != s2.end()) {
                if(isupper(c)) {
                    total += c-38;
                } else {
                    total += c-96;
                }
            }
        }
    }
    cout << total << endl;
}