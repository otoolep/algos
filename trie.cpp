#include <stack>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace::std;

const string ALPHA = string("abcdefghijklmnopqrstuvwxyz");

class Node {
    char c;
    unordered_map<char, Node*> children;
    bool last() {
        return !this->children.size();
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

        void Suffixes() {
            stack<Node*> stk = stack<Node*>();
            string out = string();

            stk.push(this);
            while(!stk.empty()) {
                Node* n = stk.top();
                stk.pop();

                if (n->c != '\0') {
                    out.push_back(n->c);
                    if (n->last()) {
                        cout << out << endl;
                        out.pop_back();
                    }
                }

                std::string str("abcdefghijklmnopqrstuvwxyz");
                for (string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit) {
                    try {
                        stk.push(n->children.at(*rit));
                        //cout << "pushing " << *rit << endl;
                    } catch (out_of_range) {
                        //cout << "not pushing " << *rit << endl;
                        continue;
                    }
                }
            }
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

    //cout << "phil is valid prefix: " << bToStr(root->ValidPrefix("phil")) << endl;
    //cout << "philip is valid prefix: " << bToStr(root->ValidPrefix("philip")) << endl;
    //cout << "abc is valid prefix: " << bToStr(root->ValidPrefix("abc")) << endl;
    //cout << "philippp is valid prefix: " << bToStr(root->ValidPrefix("philippp")) << endl;

    root->Suffixes();

    return 0;
}
