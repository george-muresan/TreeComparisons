//
//  SPLAY_Tree.h
//  ProjectTwo
//
//  Created by George Muresan on 3/25/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef SPLAY_Tree_h
#define SPLAY_Tree_h
#include "SPLAYnode.h"
using namespace std;

class SPLAY_Tree
{
private:
    SPLAYnode *root;
    
    void zig(SPLAYnode*);
    void zig_zig(SPLAYnode*);
    void zig_zag(SPLAYnode*);
    
    void splay(SPLAYnode*);
    
    long int comparisons = 0;
    
public:
    SPLAY_Tree();
    SPLAY_Tree(SPLAYnode*);
    SPLAYnode* searchHelp(int);
    void insert(int);
    void Delete(int);
    bool search(int);
    void print()
    {
        cout << "Splay Tree:" << endl;
        printTreehelper(root);
        cout << endl;
        cout << "Number of Comparisons: " << comparisons << endl;
    }
    
    void printTreehelper(SPLAYnode *key)
    {
        cout << "[";
        if(key != nullptr)
        {
            cout << key->data;
            if(key->left != NULL || key->right != NULL)
            {
                printTreehelper(key->left);
                printTreehelper(key->right);
            }
            
        }
        cout << "]";
        
    }
    
};

SPLAY_Tree::SPLAY_Tree()
{
    this->root = NULL;
}

SPLAY_Tree::SPLAY_Tree(SPLAYnode *more)
{
    this->root = more;
}



void SPLAY_Tree::zig(SPLAYnode *x)
{
    comparisons++;
    SPLAYnode *temp = x->head;
    if(temp->left == x)
    {
        comparisons++;
        //SPLAYnode *A = x->left;
        SPLAYnode *B = x->right;
        //SPLAYnode *C = temp->right;
        
        x->head = NULL;
        x->right = temp;
        
        temp->head= x;
        temp->left = B;
        
        if(B != NULL)
        {
            comparisons++;
            B->head = temp;
        }

    }
    else
    {
        comparisons++;
        //SPLAYnode *A = temp->left;
        SPLAYnode *B = x->left;
        //SPLAYnode *C = x->right;
        
        x->head = NULL;
        x->left = temp;
        
        temp->head = x;
        temp->right = B;
        
        if(B != NULL)
        {
            comparisons++;
            B->head = temp;
        }
    }
}

void SPLAY_Tree::zig_zig(SPLAYnode *x)
{
    comparisons++;
    SPLAYnode *temp = x->head;
    SPLAYnode *bref = temp->head;
    
    if(temp->left == x)
    {
        comparisons++;
        //SPLAYnode *A = x->left;
        SPLAYnode *B = x->right;
        SPLAYnode *C = temp->right;
        //SPLAYnode *D = bref->right;
        
        x->head = bref->head;
        x->right = temp;
        
        temp->head = x;
        temp->left = B;
        temp->right = bref;
        
        bref->head = temp;
        bref->left = C;
        
        if(x->head != NULL)
        {
            comparisons++;
            if(x->head->left == bref)
            {
                comparisons++;
                x->head->left = x;
            }
            else
            {
                comparisons++;
                x->head->right = x;
            }
        }
        if(B != NULL)
        {
            comparisons++;
            B->head = temp;
        }
        if(C != NULL)
        {
            comparisons++;
            C->head = bref;
        }
    }
    else
    {
        comparisons++;
        //SPLAYnode *A = bref->left;
        SPLAYnode *B = temp->left;
        SPLAYnode *C = x->left;
        //SPLAYnode *D = x->right;
        
        x->head = bref->head;
        x->left = temp;
        
        temp->head = x;
        temp->left = bref;
        temp->right = C;
        
        bref->head = temp;
        bref->right = B;
        
        if(x->head != NULL)
        {
            comparisons++;
            if(x->head->left == bref)
            {
                comparisons++;
                x->head->left = x;
            }
            else
            {
                comparisons++;
                x->head->right = x;
            }
        }
        if(B != NULL)
        {
            comparisons++;
            B->head = bref;
        }
        if(C != NULL)
        {
            comparisons++;
            C->head = temp;
        }
        
    }
}

void SPLAY_Tree::zig_zag(SPLAYnode *x)
{
    SPLAYnode *temp = x->head;
    SPLAYnode *bref = temp->head;
    comparisons++;
    if(temp->right == x)
    {
        comparisons++;
        //SPLAYnode *A = temp->left;
        SPLAYnode *B = x->left;
        SPLAYnode *C = x->right;
        //SPLAYnode *D = bref->right;
        
        x->head = bref->head;
        x->left = temp;
        x->right = bref;
        
        temp->head = x;
        temp->right = B;
        
        bref->head = x;
        bref->left = C;
        
        if(x->head != NULL)
        {
            comparisons++;
            if(x->head->left == bref)
            {
                comparisons++;
                x->head->left = x;
            }
            else
            {
                comparisons++;
                x->head->right = x;
            }
        }
        if(B != NULL)
        {
            comparisons++;
            B->head = temp;
        }
        if(C != NULL)
        {
            comparisons++;
            C->head = bref;
        }
    }
    else
    {
        comparisons++;
        //SPLAYnode *A = bref->left;
        SPLAYnode *B = x->left;
        SPLAYnode *C = x->right;
        //SPLAYnode *D = temp->right;
        
        x->head = bref->head;
        x->left = bref;
        x->right = temp;
        
        temp->head = x;
        temp->left = C;
        
        bref->head = x;
        bref->right = B;
        
        if(x->head != NULL)
        {
            comparisons++;
            if(x->head->left == bref)
            {
                comparisons++;
                x->head->left = x;
            }
            else
            {
                comparisons++;
                x->head->right = x;
            }
        }
        if (B != NULL)
        {
            comparisons++;
            B->head = bref;
        }
        if(C != NULL)
        {
            comparisons++;
            C->head = temp;
        }
    }
}


void SPLAY_Tree::splay(SPLAYnode *x)
{
    comparisons++;
    while(x->head != NULL)
    {
        comparisons++;
        SPLAYnode *temp = x->head;
        SPLAYnode *bref = temp->head;
        
        if(bref == NULL)
        {
            comparisons++;
            zig(x);
        }
        else if(bref->left == temp && temp->left == x)
        {
            comparisons++;
            zig_zig(x);
        }
        else if(bref->right == temp && temp->right == x)
        {
            comparisons++;
            zig_zig(x);
        }
        else
        {
            comparisons++;
            zig_zag(x);
        }
    }
    this->root = x;
}

bool SPLAY_Tree::search(int x)
{
    comparisons++;
    if(searchHelp(x))
    {
        comparisons++;
        cout << x << " exists in Splay tree..." << endl;
        cout << "Number of Comparisons: " << comparisons << endl;
        return true;
    }
    else
    {
        comparisons++;
        cout << x << " does not exist in Splay tree..." << endl;
        cout << "Number of Comparisons: " << comparisons << endl;
        return false;
    }
}

SPLAYnode* SPLAY_Tree::searchHelp(int x)
{
    
    SPLAYnode *ret = NULL;
    SPLAYnode *current = this->root;
    SPLAYnode *previous = NULL;
    
    while(current != NULL)
    {
        comparisons++;
        previous = current;
        if(x < current->data)
        {
            comparisons++;
            current = current->left;
        }
        else if(x > current->data)
        {
            comparisons++;
            current = current->right;
        }
        else
        {
            comparisons++;
            ret = current;
            break;
        }
    }
    
    if(ret != NULL)
    {
        comparisons++;
        splay(ret);
    }
    else if(previous != NULL)
    {
        comparisons++;
        //cout << "NOT FOUND";
        splay(previous);
    }
    //cout << "FOUND";
    return ret;
}

void SPLAY_Tree::insert(int x)
{
    if(root == NULL)
    {
        comparisons++;
        root = new SPLAYnode(x);
        return;
    }
    
    SPLAYnode *current = this->root;
    while(current != NULL)
    {
        comparisons++;
        if(x < current->data)
        {
            comparisons++;
            if(current->left == NULL)
            {
                comparisons++;
                SPLAYnode *newNode = new SPLAYnode(x);
                current->left = newNode;
                newNode->head = current;
                splay(newNode);
                return;
            }
            else
            {
                comparisons++;
                current = current->left;
            }
        }
        else if(x > current->data)
        {
            comparisons++;
            if(current->right == NULL)
            {
                comparisons++;
                SPLAYnode *newNode = new SPLAYnode(x);
                current->right = newNode;
                newNode->head = current;
                splay(newNode);
                return;
            }
            else
            {
                comparisons++;
                current= current->right;
                
            }
        }
        else
        {
            comparisons++;
            splay(current);
            return;
        }
    }
}

SPLAYnode* subTreeMax(SPLAYnode *subRoot)
{
    SPLAYnode *current = subRoot;
    while(current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

SPLAYnode* subTreeMin(SPLAYnode *subRoot)
{
    SPLAYnode *current = subRoot;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void SPLAY_Tree::Delete(int x)
{
    SPLAYnode *del = searchHelp(x);
    
    if(del == NULL)
    {
        comparisons++;
        return;
    }
    
    SPLAYnode *L = del->left;
    SPLAYnode *R = del->right;
    
    if(L == NULL && R == NULL)
    {
        comparisons++;
        this->root = NULL;
    }
    else if(L == NULL)
    {
        comparisons++;
        SPLAYnode *M = subTreeMin(R);
        splay(M);
    }
    else if(R == NULL)
    {
        comparisons++;
        SPLAYnode *M = subTreeMax(L);
        splay(M);
    }
    else
    {
        comparisons++;
        SPLAYnode *M = subTreeMax(L);
        splay(M);
        M->right = R;
        R->head = M;
    }
    
    delete del;
    
    cout << "Removing " << x << "..." << endl;
    return print();
}








#endif /* SPLAY_Tree_h */
