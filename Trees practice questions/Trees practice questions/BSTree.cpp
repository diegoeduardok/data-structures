//
//  BSTree.cpp
//  Trees practice questions
//
//  Created by Diego Kleiman on 4/7/18.
//  Copyright © 2018 Diego Kleiman. All rights reserved.
//

#include "BSTree.hpp"

BSTree::PositionList BSTree::positions() const{
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}

void BSTree::expandExternal(const BSTree::Position &p){
    if(!p.isExternal()) return;
    Node* l = new Node;
    p.v->left = l;
    l->parent = p.v;
    
    Node* r = new Node;
    p.v->right = r;
    r->parent = p.v;
    
    numberNodes += 2;
}

void BSTree::removeAboveExternal(const BSTree::Position &p){
    if(p.isRoot()) return; //Make sure there is a parent
    //Identify who's the sibling
    Node* par = p.v->parent;
    Node* sib = (p.v == par->left ? par->right : par->left);
    if(par == _root){
        _root = sib;
        sib->parent = NULL;
    }
    else{
        Node* gpar = par->parent; //Get grandparent
        if(par == gpar->left) gpar->left = sib;
        else gpar->right = sib;
        sib->parent = gpar;
    }
    delete p.v; delete par; numberNodes -= 2;
}

void BSTree::preorder(BSTree::Node* u, BSTree::PositionList &pl) const{
    if(empty()) return;
    pl.push_back(u);
    if(u->left != NULL) preorder(u->left, pl);
    if(u->right != NULL) preorder(u->right, pl);
}

void BSTree::postorder(BSTree::Node *u, BSTree::PositionList &pl) const{
    if(empty()) return;
    if(u->left != NULL) postorder(u->left, pl);
    if(u->right != NULL) postorder(u->right, pl);
    pl.push_back(u);
}

void BSTree::inorder(BSTree::Node *u, BSTree::PositionList &pl) const{
    if(empty()) return;
    if(u->left != NULL) postorder(u->left, pl);
    pl.push_back(u);
    if(u->right != NULL) postorder(u->right, pl);
}

void BSTree::addElement_helper(int i, Node* u){
    if(u==NULL) {addRoot(i); return;}
    int num = u->elem;
    if(i<=num){
        if(u->left==NULL) {expandExternal(u); u->left->elem = i; return;}
        if(u->left->elem == -1){u->left->elem = i; return;}
        else{addElement_helper(i, u->left);}
    }
    else if(i>num){
        if(u->right==NULL) {expandExternal(u); u->right->elem = i; return;}
        if(u->right->elem == -1){u->right->elem = i; return;}
        else{addElement_helper(i, u->right);}
    }
}


void BSTree::printPostOrder(){
    PositionList pl;
    postorder(_root, pl);
    while(!pl.empty()){
        int number = pl.front().v->elem;
        if(number > 0) cout << number << ", ";
        pl.pop_front();
    }
    cout << endl;
}

void BSTree::printPreOrder(){
    PositionList pl;
    preorder(_root, pl);
    while(!pl.empty()){
        int number = pl.front().v->elem;
        if(number > 0) cout << number << ", ";
        pl.pop_front();
    }
    cout << endl;
}

int BSTree::maxDepth_helper(BSTree::Node *u){
    if(empty()){return -1;}
    int right_subtree, left_subtree;
    if(u==NULL or u->elem==-1){return 0;}
    else {
        //cout << u->elem << endl;
        left_subtree = maxDepth_helper(u->left);
        right_subtree = maxDepth_helper(u->right);
        return 1+max(right_subtree, left_subtree);
    }
}

void BSTree::printPaths_helper(Node* u, string &s){
    if(u==NULL or u->elem==-1) return;
    s += to_string(u->elem);
    if(u->left==NULL && u->right==NULL) cout << s << endl;
    else{
        printPaths_helper(u->left, s);
        printPaths_helper(u->right, s);
    }
} 
