#include<bits/stdc++.h>

using namespace std;

bool unique(list<char> l) {
    set<char> s;
    for(auto val: l) {
        s.insert(val);
    }

    return s.size() == 14;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin, line);

    list<char> l;
    int left;
    for(left = 0; left < 14; left++) {
        l.push_back(line[left]);
    }

    if(unique(l)) {
        cout << "4" << endl;
        return 0;
    }

    for(; left < line.size(); left++) {
        l.pop_front();
        l.push_back(line[left]);
        if(unique(l)) {
            cout << left+1 << endl;
            return 0;
        }
    }
}