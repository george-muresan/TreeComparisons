//
//  SPLAYnode.h
//  ProjectTwo
//
//  Created by George Muresan on 3/25/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef SPLAYnode_h
#define SPLAYnode_h

using namespace std;

struct SPLAYnode
{

    SPLAYnode *head;
    int data;
    SPLAYnode *left, *right;
    
    SPLAYnode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->head = NULL;
    }
    
    
};

#endif /* SPLAYnode_h */
