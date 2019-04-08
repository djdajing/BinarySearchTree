//
// Created by dj on 2/28/19.
//

#ifndef CN_SEARCHER_BINARYTREE_H
#define CN_SEARCHER_BINARYTREE_H

#include <iostream>
#include <deque>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

class BinaryTree{
public :
    struct TreeNode
    {
        string data;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
    };
    BinaryTree();
    string peek(struct TreeNode *node);
    struct TreeNode* newNode(string data);
    struct TreeNode* newEmptyNode();
    bool isLeafNode(TreeNode *node);
    void modify_queue(std::queue<bool> &tracker_queue, bool value_larger_than_data);
    struct TreeNode* insert(struct TreeNode* node, string data);
    void inorder (struct TreeNode *root);
    TreeNode *lookUp(struct TreeNode *node, string value, std::queue<bool>& tracker_value_larger_than_data_queue);

};




#endif //CN_SEARCHER_BINARYTREE_H
