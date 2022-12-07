#include<bits/stdc++.h>

using namespace std;

#define MAX 100000

struct node {
    unordered_map<string, node*> children;
    node* parent;
    long long size;
    node() {
        size = 0;
    }
};

void calculate_values(node* root, long long *out) {
    if(root->children.size() == 0) {
        if(root->size <= MAX) {
            (*out) += root->size;
        }
        return;
    }

    for(auto child: root->children) {
        calculate_values(child.second, out);
    }

    // add all dirs values
    for(auto child: root->children) {
        root->size += child.second->size;
    }
    if(root->size <= MAX) {
        (*out) += root->size;
    }
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
    long long total = 0;
    calculate_values(root, &total);

    cout << total << endl;
}