//
//  AVL_Tree.h
//  ProjectTwo
//
//  Created by George Muresan on 3/25/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef AVL_Tree_h
#define AVL_Tree_h
#include "AVLnode.h"
using namespace std;

class AVL_Tree
{
private:
    AVLnode *head;
    long int comparisons;
    
public:
    //ADD METHOD
    AVL_Tree()
    {
        head = NULL;
        comparisons = 0;
        
    }
    ~AVL_Tree()
    {
        totalDestruction(head);
    }
    void totalDestruction(AVLnode *t)
    {
        comparisons++;
        if(t != NULL)
        {
            comparisons++;
            totalDestruction(t->left);
            totalDestruction(t->right);
            delete t;
        }
    }
    
    void insert(int data)
    {
        comparisons++;
        insertHelp(head, data);
    }
    
    void insertHelp(AVLnode * &head, const int data)
    {
        comparisons++;
        if(head == nullptr)
        {
            comparisons++;
            head = new AVLnode{data, nullptr, nullptr};
        }
        
        else if( data < head->data)
        {
            comparisons++;
            insertHelp(head->left, data);
        }
        else if(head->data < data)
        {
            comparisons++;
            insertHelp(head->right, data);
        }
        
        balance(head);
        
    }
    
    static const int BalancedAllowed = 1;
    
    void balance(AVLnode * &head)
    {
        comparisons++;
        if (head == nullptr)
        {
            comparisons++;
            return;
        }
        if(height(head->left) - height(head->right) > BalancedAllowed)
        {
            comparisons++;
            if(height( head->left->left) >= height (head->left->right))
            {
                comparisons++;
                rotateWithLeftChild( head );
            }
            else
            {
                comparisons++;
                doubleWithLeftChild( head );
            }
        }
        else
        {
            comparisons++;
            if(height(head->right) - height(head->left) > BalancedAllowed)
            {
                comparisons++;
                if(height(head->right->right) >= height(head->right->left))
                {
                    comparisons++;
                    rotateWithRightChild( head );
                }
                else
                {
                    comparisons++;
                    doubleWithRightChild( head );
                }
            }
        }
        head->height = max(height(head->left), height(head->right)) +1;
    }
    
    void rotateWithLeftChild(AVLnode * &k2)
    {
        comparisons++;
        AVLnode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height (k2->left), height(k2->right) ) + 1;
        k1->height = max(height (k1->left), k2->height) + 1;
        k2= k1;
    }
    void rotateWithRightChild(AVLnode * &k2)
    {
        comparisons++;
        AVLnode *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height (k2->right), height(k2->left) ) + 1;
        k1->height = max(height (k1->right), k2->height) + 1;
        k2 = k1;
    }
    void doubleWithLeftChild(AVLnode * &k3)
    {
        comparisons++;
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(AVLnode * &k3)
    {
        comparisons++;
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }
    
    //REMOVE METHOD
    void remove(int data)
    {
        comparisons++;
        cout << "Removing " << data << "..." << endl;
        removeHelp(data, head);
        return print();
    }
    void removeHelp(const int &x, AVLnode * &head)
    {
        comparisons++;
        if(head == nullptr)
        {
            comparisons++;
            return;
        }
        
        if( x < head->data)
        {
            comparisons++;
            removeHelp(x, head->left);
        }
        else if(head->data < x)
        {
            comparisons++;
            removeHelp(x, head->right);
        }
        else if(head->left != nullptr && head->right != nullptr)
        {
            comparisons++;
            head->data = findMin(head->right)->data;
            removeHelp(head->data, head->right);
        }
        else
        {
            comparisons++;
            AVLnode *temp = head;
            head = (head->left != nullptr) ? head->left : head->right;
            delete temp;
        }
        
        balance(head);
    }
    
    //REMOVE HELPER
    AVLnode* findMin(AVLnode *find)
    {
        comparisons++;
        AVLnode *current = find;
        while(current->left != NULL)
        {
            comparisons++;
            current = current->left;
        }
        return current;
    }
    
    //SEARCH METHOD
    bool search(int data)
    {
        comparisons++;
        if(searchHelp(head, data))
        {
            comparisons++;
            cout << data << " exists in AVL tree..." << endl;
            cout << "Number of Comparisons: " << comparisons << endl;
            return true;
        }
        else
        {
            comparisons++;
            cout << data <<" does not exist in AVL tree..." << endl;
            cout << "Number of Comparisons: " << comparisons << endl;
            return false;
        }
    }
    
    bool searchHelp(AVLnode *head, int &data)
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
    
    
    //PRINT METHOD
    void print()
    {
        comparisons++;
        cout << "AVL Tree:" << endl;
        printTree(head);
        cout << endl;
        cout << "Number of Comparisons: " << comparisons << endl;
    }
    
    void printTree(AVLnode *data)
    {
        comparisons++;
        cout << "[";
        if(data != nullptr)
        {
            comparisons++;
            cout << data->data;
            if(data->left != NULL || data->right != NULL)
            {
                comparisons++;
                printTree(data->left);
                printTree(data->right);
            }
            
        }
        cout << "]";
        
    }
};


#endif /* AVL_Tree_h */
