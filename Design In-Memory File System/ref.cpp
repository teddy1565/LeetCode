#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class FileSystem {
private:
    struct Node {
        bool isFile = false;
        string content;
        map<string, Node*> children;

        ~Node() {
            for (auto &[_, n] : children) delete n;
        }
    };

    Node* root;

    vector<string> split(string &path) {
        vector<string> splited;
        string f;
        
        for (char c : path) {
            if (c == '/') {
                if (!f.empty()) {
                    splited.push_back(f);
                    f.clear();
                }
            } else {
                f.push_back(c);
            }
        }

        if (!f.empty()) splited.push_back(f);

        return splited;
    }

    Node* traverseTo(string &path) {
        Node* n = root;
        vector<string> splited = split(path);

        for (string &f : splited) {
            if (!n->children.count(f)) {
                n->children[f] = new Node();
            }
            n = n->children[f];
        }

        return n;
    }


public:
    FileSystem() {
        root = new Node();
    }
    
    vector<string> ls(string path) {
        Node *n = traverseTo(path);

        if (n->isFile) {
            return { split(path).back() };
        }

        vector<string> files; files.reserve(n->children.size());
        for (auto &[f, _] : n->children) {
            files.push_back(f);
        }

        return files;
    }
    
    void mkdir(string path) {
        traverseTo(path);
    }
    
    void addContentToFile(string filePath, string content) {
        Node *n = traverseTo(filePath);
        n->isFile = true;
        n->content += content;
    }
    
    string readContentFromFile(string filePath) {
        return traverseTo(filePath)->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */