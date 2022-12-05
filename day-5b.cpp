#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<deque<char>> vs(9);

    string line;
    while(getline(cin, line)) {
        if(line[1] == '1') {
            break;
        }

        int idx = 1;
        int curr = 0;
        for(int i = 0; i < 9; i++) {
            if(line[idx] != ' ') {
                vs[curr].push_back(line[idx]);
            }
            idx += 4;
            curr++;
        }
    }

    cin.ignore(); // empty line

    while(getline(cin, line)) {
        char *token;
        token = strtok((char*)line.c_str(), " ");
        token = strtok(NULL, " ");
        int count = stoi(token);

        token = strtok(NULL, " ");
        token = strtok(NULL, " ");
        int from = stoi(token);

        token = strtok(NULL, " ");
        token = strtok(NULL, " ");
        int to = stoi(token);

        stack<char> temp;
        for(int i = 0; i < count; i++) {
            char val = vs[from-1].front();
            temp.push(val);
            // cout << "MOVING " << val << " FROM " << from-1 << endl;
            vs[from-1].pop_front();
        }
        while(!temp.empty()){
            vs[to-1].push_front(temp.top());
            temp.pop();
        }
        // cout << vs[0].top() << " " << vs[1].top() << " " << vs[2].top() << endl;
    }

    for(int i = 0; i < 9; i++) {
        cout << vs[i].front();
    }
    cout << endl;
}