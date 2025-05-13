#include<bits/stdc++.h>

using namespace std;
#define ll long long
const ll M = 998244353;

struct node {
    bool endmark;
    node *next[26 + 1];
    node (){
            endmark = false;
            for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};
node *root = new node();

void insert(string &s, ll len) {
    node *cur = root;
    for (int i = 0; i < len; i++) {
        int id = s[i] - 'a';
        if (cur->next[id] == NULL) cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->endmark = true;
}

bool search (string &s, ll len) {
        node *cur = root;
        for (int i = 0; i < len; i++) {
            int id = s[i] - 'a';
            if (cur->next[id] == NULL) return false;
            cur = cur->next[id];
        }
        return cur->endmark;
}

void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

int main() {
    ll t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        insert(s, s.size());
    }
    ll q; cin >> q;
    while (q--) {
        string s; cin >> s;
        if (search(s, s.size())) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    del(root);
}
