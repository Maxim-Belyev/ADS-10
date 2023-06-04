// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

struct Node {
    char ch;
    std::vector<Node*> ptr;
    explicit Node(char ch = '\0') : ch(ch) {}
};

class Tree {
 private:
    Node* root;
    std::vector<std::vector<char>> perm;

    void createPerm(const std::vector<char>& seq) {
        addElem(root, seq);
        readTree(root, {});
    }

    void addElem(Node* rootptr, const std::vector<char>& seq) {
        if (rootptr != nullptr) {
            for (char ch : seq) {
                Node* num = new Node();
                rootptr->ptr.push_back(num);
                std::vector<char> updateSeq(seq);
                updateSeq.erase(std::find(updateSeq.begin(), \
                    updateSeq.end(), ch));
                addElem(num, updateSeq);
            }
        }
    }

 public:
    void readTree(Node* rootptr, std::vector<char> seq) {
        if (rootptr == nullptr) {
            root = rootptr = new Node;
        }
        if (rootptr != nullptr && rootptr->ch != '\0')
            seq.push_back(rootptr->ch);
        if (rootptr->ptr.empty())
            perm.push_back(seq);
        for (Node* ch : rootptr->ptr) {
            readTree(ch, seq);
        }
    }
    explicit Tree(const std::vector<char>s) : root(nullptr) {
        createPerm(s);
    }

    std::vector<std::vector<char>> getPerm() const {
        return perm;
    }
};
#endif  // INCLUDE_TREE_H_
