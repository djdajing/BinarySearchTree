#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include "BinaryTree.h"
//#include "/home/dj/lib/boost_1_65_1/boost/filesystem.hpp"

bool DEBUG_MAIN = false;
void search(BinaryTree bst ,BinaryTree::TreeNode *root, string word)
{
    queue<bool> tracker_queue;
    struct BinaryTree::TreeNode *answer =bst.lookUp(root,word,tracker_queue);
    cout<<word<<" FROM: "<<answer->data<<endl;
}


BinaryTree::TreeNode * dirvec_to_BST(BinaryTree &bst, vector<string> files_in_dir)
{
    struct BinaryTree::TreeNode *root;
    cout<<"Inserting  ... "<<endl;
    root = bst.insert_by_sorted_vec(files_in_dir, 0, files_in_dir.size());
    return root;
}

void test_dir_to_BST(vector<string> files_in_dir)
{
    BinaryTree bst = BinaryTree();
    struct BinaryTree::TreeNode *root;
    cout<<"Inserting  ... "<<endl;
    root = bst.insert_by_sorted_vec(files_in_dir, 0, files_in_dir.size());

//    string files_in_dir[] = {"a","b","c","d","e","f","g","h","i","j"};
//    root = bst.insert_by_string_data(root, "e");
//    bst.insert_by_string_data(root, "c");
//    bst.insert_by_string_data(root, "h");
//    bst.insert_by_string_data(root, "b");
//    bst.insert_by_string_data(root, "d");
//    bst.insert_by_string_data(root, "a");
//    bst.insert_by_string_data(root, "g");
//    bst.insert_by_string_data(root, "j");
//    bst.ins ert(root, "i");
//    bst.insert_by_string_data(root, "f");
//    bst.insert_by_string_data(root, "k");


    cout<<"Printing order  ... "<<endl;
    bst.inorder(root,true);


    queue<bool> tracker_queue;

    cout<<"Testing  ... "<<endl;
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

void print_files_in_dir(vector<string> files_in_dir)
{
    std::cout << "dir contains:";
    for (auto it=files_in_dir.begin(); it!=files_in_dir.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

vector<string>  dir_to_vec(string dir)
{
    vector<string> files_vec;
    boost::filesystem::path dir_path(dir);
    for (auto i = boost::filesystem::directory_iterator(dir_path); i != boost::filesystem::directory_iterator(); i++)
    {
        if (!is_directory(i->path()))
        {
            string filename = i->path().stem().string();
            files_vec.push_back(filename);
        }
        else
            continue;
    }
    sort(files_vec.begin(),files_vec.end());
    return files_vec;

}

void match(vector<string>& files_in_dir, BinaryTree& bst)
{
    bst.inorder(bst.tree,false);
    if (files_in_dir.size()!= bst.numNode)
    {
        cerr <<"ERROR FILE NODE MISMATCHED :  "<< files_in_dir.size() << " files but "<<bst.numNode<< " nodes"<<endl;
        exit(EXIT_FAILURE);
    }
}

void genBst(string & path,BinaryTree& bst)
{

    vector<string> files_in_dir_vec = dir_to_vec(path);
    bst.tree = dirvec_to_BST(bst, files_in_dir_vec); //convert dir to binary tree
    match(files_in_dir_vec,bst); // check if num node match num files

    if (DEBUG_MAIN)
    {
        print_files_in_dir(files_in_dir_vec);
        cout << "num of files :"<<files_in_dir_vec.size() << endl;
        cout << "num node : "<<bst.numNode<<endl;
    }
}

int main()
{
    BinaryTree bst = BinaryTree();
    string p = "/home/dj/Multilanguage PIS/BinarySearchTree/test_folder";
    genBst(p,bst);

}
