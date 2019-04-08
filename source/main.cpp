#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include "BinaryTree.h"
//#include "/home/dj/lib/boost_1_65_1/boost/filesystem.hpp"

void search(BinaryTree bst ,BinaryTree::TreeNode *root, string word)
{
    queue<bool> tracker_queue;
    struct BinaryTree::TreeNode *answer =bst.lookUp(root,word,tracker_queue);
    cout<<word<<" FROM: "<<answer->data<<endl;
}

void test(list<string>mylist)
{
    BinaryTree bst = BinaryTree();
    struct BinaryTree::TreeNode *root=bst.newEmptyNode();
//    string mylist[] = {"a","b","c","d","e","f","g","h","i","j"};
//    root = bst.insert(root, "e");
//    bst.insert(root, "c");
//    bst.insert(root, "h");
//    bst.insert(root, "b");
//    bst.insert(root, "d");
//    bst.insert(root, "a");
//    bst.insert(root, "g");
//    bst.insert(root, "j");
//    bst.ins ert(root, "i");
//    bst.insert(root, "f");
//    bst.insert(root, "k");


    ///TODO: make list insert from middle by middle //




    // print inoder traversal of the BST
    bst.inorder(root);


    queue<bool> tracker_queue;

    search(bst,root,"apple");
    search(bst,root,"a");
    search(bst,root,"boy");
    search(bst,root,"b");
    search(bst,root,"cat");
    search(bst,root,"c");
    search(bst,root,"dog");
    search(bst,root,"d");
    search(bst,root,"elephant");
    search(bst,root,"e");
    search(bst,root,"fun");
    search(bst,root,"f");
    search(bst,root,"goaway");
    search(bst,root,"g");
    search(bst,root,"hello");
    search(bst,root,"h");
    search(bst,root,"joy");
    search(bst,root,"j");
    search(bst,root,"interesting");
    search(bst,root,"i");
    search(bst,root,"kill");
    search(bst,root,"k");

}

void check_listitem(list<string>mylist)
{
    std::cout << "mylist contains:";
    for (auto it=mylist.begin(); it!=mylist.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

list<string>  dir_to_list(string dir)
{
    list<string> list_list;
    boost::filesystem::path dir_path(dir);
    for (auto i = boost::filesystem::directory_iterator(dir_path); i != boost::filesystem::directory_iterator(); i++)
    {
        if (!is_directory(i->path()))
        {
            string filename = i->path().stem().string();
            list_list.push_back(filename);
        }
        else
            continue;
    }
    list_list.sort();
    return list_list;

}

int main()
{
    list<string> mylist = dir_to_list("/home/dj/Multilanguage PIS/BinarySearchTree/test_folder");
    check_listitem(mylist);
    //test(mylist);

    return 0;
}