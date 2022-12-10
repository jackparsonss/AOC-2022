#include<bits/stdc++.h>

using namespace std;

set<int> vals = {20, 60, 100, 140, 180, 220};

int check_reg(int reg, int cycle) {
    if(vals.find(cycle) != vals.end()) {
        return reg * cycle;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    string type;
    int temp;
    int reg = 1;
    int cycle = 0;
    long long total = 0;
    while(getline(cin, line)) {
        type = line.substr(0, 4);

        // noop happens no matter what
        cycle++;
        total += check_reg(reg, cycle);

        if(type == "addx") {
            cycle++;
            total += check_reg(reg, cycle);
            temp = stoi(line.substr(5));
            reg += temp;
        }
    }

    cout << total << endl;
}