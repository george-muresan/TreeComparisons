//
//  BST_Tree.h
//  ProjectTwo
//
//  Created by George Muresan on 3/25/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef BST_Tree_h
#define BST_Tree_h
#include "BSTnode.h"

using namespace std;

class BST_Tree
{
    private:
        BSTnode *root;
        long int comparisons;
    
    public:
        BST_Tree()
        {
            root = NULL;
            comparisons = 0;
        }
    
        ~BST_Tree()
        {
            totalDestruction(root);
        }
    void totalDestruction(BSTnode *t)
    {
        if(t != NULL)
        {
            comparisons++;
            totalDestruction(t->left);
            totalDestruction(t->right);
            delete t;
        }
        //t = nullptr;
    }
    
    void insert(int data)
    {
        comparisons++;
        addHelp(root, data);
    }
    
    //ADD METHOD
    void addHelp(BSTnode * &head, int data)
    {
        comparisons++;
        if (head == NULL)
        {
            comparisons++;
            head = new BSTnode(data);
            return;
        }
        comparisons++;
        
        if (data < head->data)
        {
            comparisons++;
            if (head->left != NULL)
            {
                comparisons++;
                addHelp(head->left, data);
            }
            else
            {
                comparisons++;
                head->left = new BSTnode(data);
            }
        }
        else if(data > head->data)
        {
            comparisons++;
            if(head->right != NULL)
            {
                comparisons++;
                addHelp(head->right, data);
            }
            else
            {
                comparisons++;
                head->right = new BSTnode(data);
            }
        }
        else
        {
            comparisons++;
            return;
        }
    }
    
    //REMOVE METHOD
    void remove(int data)
    {
        comparisons++;
        cout << "Removing " << data << "..." << endl;
        removeHelp(root, data);
        return print();
    }
    void removeHelp(BSTnode *&head, int data)
    {
        comparisons++;
        if(head == nullptr)
        {
            comparisons++;
            return;
        }
        if(data < head->data)
        {
            comparisons++;
            removeHelp(head->left, data);
        }
        else if(data > head->data)
        {
            comparisons++;
            removeHelp(head->right, data);
        }
        else if (head->left != nullptr && head->right != nullptr)
        {
            comparisons++;
            head->data = findMin(head->right)->data;
            removeHelp(head->right, head->data);
        }
        else
        {
            comparisons++;
            BSTnode *temp = head;
            head = (head->left != nullptr) ? head->left : head->right;
            delete temp;
        }
    }
    //REMOVE HELPER
    BSTnode *findMin(BSTnode *head)
    {
        comparisons++;
        if (head == nullptr)
        {
            comparisons++;
            return nullptr;
        }
        if(head->left == nullptr)
        {
            comparisons++;
            return head;
        }
        return findMin(head->left);
    }
    
    //PRINT METHOD
    void print()
    {
        comparisons++;
        cout << "BST Tree:" << endl;
        printHelp(root);
        cout << endl;
        cout << "Number of Comparisons: " << comparisons << endl;
        cout << endl;
    }
    
    void printHelp(BSTnode *key)
        {
            comparisons++;
            cout << "[";
            if(key != nullptr)
            {
                comparisons++;
                cout << key->data;
                if(key->left != NULL || key->right != NULL)
                {
                    printHelp(key->left);
                    printHelp(key->right);
                }
        
            }
            cout << "]";
            
        }
    
    
    //SEARCH METHOD
    bool search(int data)
    {
        comparisons++;
        if(searchHelp(root, data))
        {
            comparisons++;
            cout << data << " exists in BST tree..." << endl;
            cout << "Number of Comparisons: " << comparisons << endl;
            return true;
        }
        else
        {
            comparisons++;
            cout << data << " does not exist in BST tree..." << endl;
            cout << "Number of Comparisons: " << comparisons << endl;
            return false;
        }
    }
    bool searchHelp(BSTnode *head, int &data)
    {
        comparisons++;
        if (head == nullptr)
        {
            comparisons++;
            return false;
        }
        else if (data < head->data)
        {
            comparisons++;
            return searchHelp(head->left, data);
        }
        else if (data > head->data)
        {
            comparisons++;
            return searchHelp(head->right, data);
        }
        else
        {
            comparisons++;
            return true;
        }
    }
   

};



#endif /* BST_Tree_h */
