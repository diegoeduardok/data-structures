#ifndef DirectedMap_h
#define DirectedMap_h

#include "BinarySearchTrees.h"

template <typename KK, typename VV>
class OrderedMap: public SearchTree<Entry<KK,VV>> {
public:
    // Usefull Typedef
    typedef  SearchTree<Entry<KK,VV>> BST;
    typedef typename SearchTree<Entry<KK,VV>>::Iterator BSTIterator;

public:
    OrderedMap(): SearchTree<Entry<KK,VV>>(){}
    int size () const ;
    bool empty () const ;
    BSTIterator find ( const KK& k) const {find(k);}
    BSTIterator put ( const KK& k, const VV& v){return BST::insert(k,v) ;}
    void erase ( const KK& k) ;
    void erase ( const BSTIterator & p);
    BSTIterator begin () {return BST::begin(); }
    BSTIterator end () {return BST::end();}
    
    //Functions defined by student
    BSTIterator firstEntry(){if(empty()) return end(); else return begin();} //Iterator to lowest key
    BSTIterator lastEntry(); //Iterator to highest key
    BSTIterator ceilingEntry(const KK& k); //Iterator to smallest key greater or equal to k
    BSTIterator floorEntry(const KK& k); //Iterator to greatest key smaller or equal to k
    BSTIterator lowerEntry(const KK& k); //Iterator to greatest key smaller to k
    BSTIterator higherEntry(const KK& k); //Iterator to smallest key greater to k
} ;

template <typename KK, typename VV>
int OrderedMap<KK,VV>::size() const {return SearchTree<Entry<KK,VV>>::getSize() ;}

template <typename KK, typename VV>
bool OrderedMap<KK,VV>::empty() const {return SearchTree<Entry<KK,VV>>::isEmpty() ; }

//Functions defined by student

template <typename KK, typename VV>
typename SearchTree<Entry<KK,VV>>::Iterator OrderedMap<KK,VV>::lastEntry(){
    if(empty()) return SearchTree<Entry<KK,VV>>::end();
    BSTIterator p = SearchTree<Entry<KK,VV>>::root();
    while(p.v.isInternal()) p = p.v.right();
    return p.v.parent();
}

template <typename KK, typename VV>
typename SearchTree<Entry<KK,VV>>::Iterator OrderedMap<KK,VV>::ceilingEntry(const KK& k){
    KK largestKey = (*lastEntry().v).key();
    if(largestKey < k) return end();
    BSTIterator iter = SearchTree<Entry<KK,VV>>::root();
    while((*iter.v).key() < k){iter = ++iter;}
    return iter;
}

template <typename KK, typename VV>
typename SearchTree<Entry<KK,VV>>::Iterator OrderedMap<KK,VV>::floorEntry(const KK& k){
    KK smallestKey = (*firstEntry().v).key();
    if(smallestKey > k) return end();
    BSTIterator iterLag = begin();
    BSTIterator iterLead = begin();
    while((*iterLead.v).key() <= k){iterLag = iterLead; iterLead = ++iterLead;}
    return iterLag;
}

template <typename KK, typename VV>
typename SearchTree<Entry<KK,VV>>::Iterator OrderedMap<KK,VV>::lowerEntry(const KK& k){
    KK smallestKey = (*firstEntry().v).key();
    if(smallestKey > k) return end();
    BSTIterator iterLag = begin();
    BSTIterator iterLead = begin();
    while((*iterLead.v).key() < k){iterLag = iterLead; iterLead = ++iterLead;}
    return iterLag;
}

template <typename KK, typename VV>
typename SearchTree<Entry<KK,VV>>::Iterator OrderedMap<KK,VV>::higherEntry(const KK& k){
    KK largestKey = (*lastEntry().v).key();
    if(largestKey < k) return end();
    BSTIterator iter = SearchTree<Entry<KK,VV>>::root();
    while((*iter.v).key() <= k){iter = ++iter;}
    return iter;
}
#endif /* DirectedMap_h */
