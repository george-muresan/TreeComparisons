//
//  AVLnode.h
//  ProjectTwo
//
//  Created by George Muresan on 3/25/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef AVLnode_h
#define AVLnode_h

using namespace std;

class AVLnode
{
public:
    int data;
    AVLnode *right;
    AVLnode *left;
    int height;
    
    AVLnode(const int &data, AVLnode *lt, AVLnode *rt, int h = 0)
    : data{data}, left{ lt }, right{ rt }, height { h } {}
    
    AVLnode(const int &&data, AVLnode *lt, AVLnode *rt, int h = 0)
    : data{ move(data) }, left{ lt }, right { rt }, height { h } {}
};

int height(AVLnode *head)
{
    return head == nullptr ? -1 : head->height;
    
}

#endif /* AVLnode_h */
