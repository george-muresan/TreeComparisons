//
//  BSTnode.h
//  ProjectTwo
//
//  Created by George Muresan on 3/25/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef BSTnode_h
#define BSTnode_h

using namespace std;

class BSTnode
{
public:
    int data;
    BSTnode *left, *right;
    BSTnode(int &data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
};


#endif /* BSTnode_h */
