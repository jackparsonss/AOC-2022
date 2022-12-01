#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long curr = 0;
    string line;
    priority_queue<long long> pq;

    while(getline(cin, line)) {
        if(line == "") {
            pq.push(curr);
            curr = 0;
            continue;
        }
        curr += stoi(line);
    }
    pq.push(curr);

    long long max = 0;
    for(int i = 0; i < 3; i++) {
        max += pq.top();
        pq.pop();
    }
    
    cout << max << endl;
}