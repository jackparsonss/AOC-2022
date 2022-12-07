#include<bits/stdc++.h>

using namespace std;

struct node {
    unordered_map<string, node*> children;
    node* parent;
    long long size;
    node() {
        size = 0;
    }
};

void calculate_values(node* root, vector<int> &dirs) {
    if(root->children.size() == 0) {
        dirs.push_back(root->size);
        return;
    }

    for(auto child: root->children) {
        calculate_values(child.second, dirs);
    }

    // add all dirs values
    for(auto child: root->children) {
        root->size += child.second->size;
    }
    dirs.push_back(root->size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    node* root = new node();

    // build tree
    while(getline(cin, line)) {
        if(line[0] == '$') {
            if(line[2] == 'c' && line[3] == 'd') {
                string dir = line.substr(5);
                if(dir == "/") {
                    while(root->parent) {
                        root = root->parent;
                    }
                }else if(dir == "..") { 
                    root = root->parent;
                } else {
                    node* temp = root;
                    if(root->children[dir] == nullptr) {
                        root->children[dir] = new node();
                    }
                    root = root->children[dir];
                    root->parent = temp;
                }
            }
            continue; // skip line on "ls"
        }

        string amount;
        amount = strtok((char*)line.c_str(), " ");
        if(amount != "dir") {
            root->size += stoi(amount);
        }
    }

    while(root->parent) {
        root = root->parent;
    }
    
    vector<int> dirs;
    calculate_values(root, dirs);
    sort(dirs.begin(), dirs.end());

    int goal = 70000000 - root->size;
    goal = 30000000 - goal;
    for(int i = 0; i < dirs.size(); i++) {
        if(dirs[i] < goal && dirs[i+1] > goal) {
            cout << dirs[i+1] << endl;
            return 0;
        }
    }
}