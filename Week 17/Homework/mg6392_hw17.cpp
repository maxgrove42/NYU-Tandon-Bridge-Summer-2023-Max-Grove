/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions.
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    cout << "DCCR" << endl;
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    cout << "DCR" << endl;
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    
    //move parent's right child to grandparent's left child.
    if (parent->right != nullptr) {
        parent->right->parent = grandparent;
    }
    grandparent->left = parent->right;
    
    //move parent to be child of grandparent's parent.
    parent->parent = grandparent->parent;
    //grandparent was root if it did not have a parent
    if ((grandparent->parent) == nullptr)
        root = parent;
    //if grandparent was left child
    else if (grandparent->parent->left == grandparent)
        grandparent->parent->left = parent;
    //if grandparent was right child
    else
        grandparent->parent->right = parent;
    
    //finalize rotation. parent's right becomes grandparent
    parent->right = grandparent;
    grandparent->parent = parent;
    
    swapColor(parent);
    swapColor(grandparent);
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    
    
    //move parent's left child to grandparent's right child.
    if (parent->left != nullptr) {
        parent->left->parent = grandparent;
    }
    grandparent->right = parent->left;
    
    //move parent to be child of grandparent's parent.
    parent->parent = grandparent->parent;
    //grandparent was root if it did not have a parent
    if ((grandparent->parent) == nullptr)
        root = parent;
    //if grandparent was right child
    else if (grandparent->parent->right == grandparent)
        grandparent->parent->right = parent;
    //if grandparent was left child
    else
        grandparent->parent->left = parent;
    
    //finalize rotation. parent's left becomes grandparent
    parent->left = grandparent;
    grandparent->parent = parent;
    
    swapColor(parent);
    swapColor(grandparent);
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
                                          // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        
        //if parent is null, this is the root.
        if (parent == nullptr) {
            point->color =  BLACK;
            return;
        }
        
        //otherwise put the new red node in the correct spot.
        if (toInsert < parent->data)
            parent->left = curr_node;
        else
            parent->right = curr_node;
        
        //if parent is root, just ensure that the root is black and return.
        if (parent->parent == nullptr) {
            parent->color = BLACK;
            return;
        }
        
        //begin checking RBT rules:
        while (getColor(curr_node->parent) == RED) {
            //going down left path.
            if (curr_node->parent == curr_node->parent->parent->left) {
                RBTNode<T> *uncle = curr_node->parent->parent->right;
                //uncle and parent are same color
                if (getColor(uncle) == RED) {
                    swapColor(curr_node->parent);
                    swapColor(uncle);
                    swapColor(curr_node->parent->parent);
                    curr_node = curr_node->parent->parent;
                }
                //uncle / parent are diff colors.
                //left left insertion
                else if (curr_node == curr_node->parent->left) {
                    curr_node = curr_node->parent->parent;
                    singleCR(curr_node);
                }
                //left right insertion
                else {
                    curr_node = curr_node->parent->parent;
                    doubleCR(curr_node);
                }
            }
            //going down right path
            else {
                RBTNode<T> *uncle = curr_node->parent->parent->left;
                if (getColor(uncle) == RED) {
                    swapColor(curr_node->parent);
                    swapColor(uncle);
                    swapColor(curr_node->parent->parent);
                    curr_node = curr_node->parent->parent;
                }
                //uncle / parent are diff colors.
                //right right insertion
                else if (curr_node == curr_node->parent->right) {
                    curr_node = curr_node->parent->parent;
                    singleCCR(curr_node);
                }
                //right left insertion
                else {
                    curr_node = curr_node->parent->parent;
                    doubleCCR(curr_node);
                }
            }
            root->color = BLACK;
        }
    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */
    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
    cout<<endl;
    cout<<"---------------------"<<endl;
    cout<<endl;
    RBT<int> c;
    count = 5;
    for (int i = count; i > 0; i--) {
        c.insert(i);
    }
    c.prettyPrint();
    /* EXPECTED OUTPUT:
                    Data: 5
                    COLOR: BLACK
    Data: 4
    COLOR: BLACK
                                    Data: 3
                                    COLOR: RED
                    Data: 2
                    COLOR: BLACK
                                    Data: 1
                                    COLOR: RED
    */
    height = c.height();
    assert(height <= 2 * log2(count));
}
