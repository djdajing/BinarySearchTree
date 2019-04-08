//
// Created by dj on 2/28/19.
//

#include "BinaryTree.h"

bool DEBUG = false;
//bool DEBUG = true;
BinaryTree::TreeNode *BinaryTree::newNode(string data)
{
    auto new_node =  (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;

    return new_node;
}

BinaryTree::TreeNode *BinaryTree::insert(struct TreeNode* node, string data)
{
    //insertion of first item
    if (node == NULL )
        return newNode(data);

    if (data < node->data)
    {
        TreeNode* Ichild = insert(node->left, data);
        node->left  = Ichild;
        Ichild->parent = node;
    }

    else if (data > node->data)
    {
        TreeNode* rchild =insert(node->right, data);
        node->right = rchild;
        rchild->parent= node;
    }

    return node;
}

void BinaryTree::inorder(BinaryTree::TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<"Node : "<< root->data;
        if (root->parent == NULL)
            cout<<" Parent : NULL"<<endl;
        else
            cout<<" Parent : "<< root->parent->data<<endl;
        inorder(root->right);
    }
}
BinaryTree::TreeNode *BinaryTree::newEmptyNode()
{
    return nullptr;
}
BinaryTree::BinaryTree(){}

//bool BinaryTree::isLeafNode(string right_child_data,string left_child_data)
//{
//    if (right_child_data.empty() && left_child_data.empty())
//        return true;
//}

bool BinaryTree::isLeafNode(TreeNode* node)
{
    if (node->left==NULL &&node->right==NULL)
        return true;
    else
        return false;
}

void BinaryTree::modify_queue(std::queue<bool> &tracker_queue, bool value_larger_than_data)
{
    if (tracker_queue.size()==2)
        tracker_queue.pop();
    tracker_queue.push(value_larger_than_data);
}

string BinaryTree::peek(BinaryTree::TreeNode *node)
{
    string node_data;
    if (node)
        node_data= node->data;
    return node_data;
}

BinaryTree::TreeNode *BinaryTree::lookUp(struct TreeNode *node, string value, std::queue<bool>& tracker_value_larger_than_data_queue)
{
    if (node == NULL)
        return NULL;

    string node_data = node->data;
    if (DEBUG)
        cout <<"Value : "<<value<<". In node : "<<node_data<<" tracker top :"<<tracker_value_larger_than_data_queue.front()<<endl;

    if (node_data==value)
        return node;
    if (isLeafNode(node)) // leave node
    {
        if( value > node_data)
        {
            if (DEBUG)
                cout <<" Value from leaf node "<<endl;
            return node; // IF RESULT IS AT LEAVE NODE
        }
        else
        {
            cout<<"return parent"<<endl;
            //return node->parent;
        }
    }

    // if value is bigger than current data
    if (value > node_data)
    {
        if (DEBUG)
            cout << "Value :" << value << " BIGGER THAN Data :" << node->data << endl;
        modify_queue(tracker_value_larger_than_data_queue, true);
        if (DEBUG)
            cout << "moving right" << endl;
        TreeNode* node_right_child =lookUp(node->right, value, tracker_value_larger_than_data_queue);
        if (node_right_child)
            return node_right_child;
        else
            return node;

    }
    else
    {

        modify_queue(tracker_value_larger_than_data_queue, false);

        string left_node = peek(node->left);
        string right_node = peek (node->right);
        if (DEBUG)
        {
            cout <<"Value :"<<value<<" SMALLER THAN Data :"<<node->data <<endl;
            cout<<"left_node : "<< left_node << " right_node " <<right_node<<endl;
        }

        if (value<=left_node)
        {
            if (DEBUG)cout<<"moving left "<<endl;
            return lookUp(node->left,value,tracker_value_larger_than_data_queue);
        }


        else if (tracker_value_larger_than_data_queue.size()>1 && tracker_value_larger_than_data_queue.front())
        {
            if (DEBUG)
            {
                cout<<"value bigger than previous node : "<< node->parent->data<<endl;
            }
            if (left_node <value)
            {
                if (DEBUG)cout<<"moving left "<<endl;
                return lookUp(node->left,value,tracker_value_larger_than_data_queue);

            }

            else if (right_node > value)
            {
                if (DEBUG)cout<<"moving right "<<endl;
                return lookUp(node->right,value,tracker_value_larger_than_data_queue);
            }
        }
        else
        {
            if (DEBUG)
                cout<< "print left"<<endl;
            return lookUp(node->left,value,tracker_value_larger_than_data_queue);
        }

    }


}