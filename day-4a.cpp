#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    long long total = 0;
    while(getline(cin, line)) {
        char *token;
        
        token = strtok((char*)line.c_str(), "-");
        int x = stoi(token);
        token = strtok(NULL, ",");
        int y = stoi(token);
        token = strtok(NULL, "-");
        int a = stoi(token);
        token = strtok(NULL, ",");
        int b = stoi(token);

        if(x >= a && y <= b) {
            total++;
        } else if(a >= x && b <= y) {
            total++;
        }
    }

    cout << total << endl;
}