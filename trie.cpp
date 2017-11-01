#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace::std;

class Node {
    char c;
    unordered_map<char, Node*> children;
    bool last() {
        return !this->children.size();
    }

    static void suffixes(Node* n, char buf[], int level, vector<string>& out) {
        if (n->c != '\0') {
            buf[level] = n->c;
        }

        string str = string("abcdefghijklmnopqrstuvwxyz");
        for (string::iterator it = str.begin(); it != str.end(); it++) {
            try {
                Node* m = n->children.at(*it);
                Node::suffixes(m, buf, level+1, out);
            } catch (out_of_range) {
                continue;
            }
        }

        // Terminal node?
        if (!n->children.size()) {
            buf[level+1] = '\0';
            out.push_back(string(buf));
        }
    }

    public:
        Node() {
            this->c = '\0';
            this->children = unordered_map<char, Node*>();
        };
        Node(char c) {
            this->c = c;
            this->children = unordered_map<char, Node*>();
        };
        ~Node() {
        };

        void Append(const string& s) {
            Node *n = this;
            for (auto& c: s) {
                try {
                    n->children.at(c);
                    // Child with this character already present.
                } catch (out_of_range) {
                    // No child with this character present, so add it.
                    n->children[c] = new Node(c);
                }
                n = n->children[c];
            }
        }

        bool ValidPrefix(const string& prefix) {
            Node *n = this;
            for (auto& c: prefix) {
                try {
                    n = n->children.at(c);
                } catch (out_of_range) {
                    return false;
                }
            }
            return true;
        }

        vector<string> Suffixes() {
            vector<string> v = vector<string>();
            char buf[256];
            Node::suffixes(this, buf, -1, v);
            return v;
        }
};

string bToStr(bool b) {
    if (b) return string("true");
    return string("false");
}

int main() {
    Node* root = new Node();
    root->Append("px");
    root->Append("pyz");
    root->Append("pz");

    cout << "py is valid prefix: " << bToStr(root->ValidPrefix("py")) << endl;

    for (auto& s: root->Suffixes()) {
        cout << s << endl;
    }

    return 0;
}
