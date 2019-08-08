#include <bits/stdc++.h>

#define endl '\n'
#define left abc
#define right aba

using namespace std;

struct node {
    char letter;
    int freq;
    node* left;
    node* right;

    node() {}
    node(char _letter, int _freq, node* _left, node* _right) {
        letter = _letter;
        freq = _freq;
        left = _left;
        right = _right;
    }
};

struct order {
    bool operator() (const node* aa, const node* bb) {
        return aa->freq > bb->freq;
    }
};

string s;
map<char, int> m;
map<char, string> code;
priority_queue<node*, vector<node*>, order> q;
node* root;

void extract_freq() {
    for(const char& i : s) {
        m[i]++;
    }

    for(auto it : m) {
        cout << it.first << ' ' << it.second << endl;
    }
}

void build_tree() {
    for(auto it : m) {
        node* a = new node(it.first, it.second, nullptr, nullptr);
        q.push(a);
    }

    while((int)q.size() > 1) {
        node* a = q.top(); q.pop();
        node* b = q.top(); q.pop();
        node* c = new node('[', a->freq + b->freq, a, b);
        q.push(c);
    }

    root = q.top();
    q.pop();
    assert(q.empty());
}

void traverse_tree(string path, node* current) {
    if(current == nullptr) {
        return;
    }

    if(current->left == nullptr && current->right == nullptr) {
        code[current->letter] = path;
        cout << current->letter << ": " << path << endl;
        return;
    }

    traverse_tree(path + '0', current->left);
    traverse_tree(path + '1', current->right);
}

void decode() {
    for(const char& i : s) {
        cout << code[i];
    }
    cout << endl;
}

int main() {
    getline(cin, s);
    extract_freq();
    build_tree();
    traverse_tree("", root);
    decode();
	return 0;
}

/*
Huffman coding is a data compression algorithm.
*/
