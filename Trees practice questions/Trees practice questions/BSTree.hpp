//
//  BSTree.hpp
//  Trees practice questions
//
//  Created by Diego Kleiman on 4/7/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#ifndef BSTree_hpp
#define BSTree_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include <string>

using namespace std;


class BSTree{
protected:
    struct Node{
        int elem;
        Node* parent;
        Node* left;
        Node* right;
        
        Node(): elem(-1), parent(NULL), left(NULL), right(NULL) {};
    };
    
private:
    Node* _root;
    int numberNodes;
    
public:
    
    class Position{

        friend class BSTree;
        typedef list<Position> PositionList;
        
    private:
        Node* v;
    public:
        Position(Node* _v = NULL) : v(_v) {} //Constructor
        int& operator*() {return v->elem;}
        Position parent() const {return v->parent;}
        PositionList children() const;
        Position left() const {return v->left;}
        Position right() const {return v->right;}
        bool isRoot() const {return v->parent == NULL;}
        bool isExternal() const {return (v->left==NULL && v->right==NULL);}
    };
    
    typedef list<Position> PositionList;
    
    BSTree(){numberNodes = 0; _root = NULL;}
    int size() const {return numberNodes;}
    bool empty() const {return numberNodes == 0;}
    Position root() const {return Position(_root);}
    PositionList positions() const;
    void addRoot(int i) {++numberNodes; _root = new Node; _root->elem = i;}
    void expandExternal(const Position& p);
    void removeAboveExternal(const Position& p);
    void preorder(Node* u, PositionList& pl) const;
    void postorder(Node* u, PositionList& pl) const;
    void inorder(Node* u, PositionList& pl) const;
    void addElement_helper(int i, Node* u);
    void addElement(int i){addElement_helper(i, _root);}
    void printPostOrder();
    void printPreOrder();
    int maxDepth_helper(Node* u);
    int maxDepth(){return maxDepth_helper(_root);}
    void printPaths_helper(Node* u, string &s);
    void printPaths(){string s; printPaths_helper(_root, s);}
};


#endif /* BSTree_hpp */
