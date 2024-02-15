#include <iostream>
#include "BST.h"
#include "dsexceptions.h"


template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( ) : root{ nullptr }
{
}

/**
 * Copy constructor
 */
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr}
{
    root = clone(rhs.root);
}

/**
* Move constructor
*/
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree( BinarySearchTree && rhs ) : root{ rhs.root }
{
    rhs.root = nullptr;
}

/**
 * Destructor for the tree
 */
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
    makeEmpty();
}

/**
 * Copy assignment
 */
template <typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=( const BinarySearchTree & rhs )
{
    BinarySearchTree copy = rhs;
    std::swap( *this, copy );
    return *this;
}
    
/**
 * Move assignment
 */
template <typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=( BinarySearchTree && rhs )
{
    std::swap( root, rhs.root );       
    return *this;
}

/**
 * Find the smallest item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin( ) const
{
    if( isEmpty( ) )
        throw UnderflowException{ };
    return findMin( root )->element;
}

/**
 * Find the largest item in the tree.
 * Throw UnderflowException if empty.
 */
template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax( ) const
{
    if( isEmpty( ) )
        throw UnderflowException{ };
    return findMax( root )->element;
}

/**
 * Returns true if x is found in the tree.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x) const
{
    return contains(x, root);
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty( ) const
{
    return root == nullptr;
}

/**
* Print the tree contents in sorted order.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(std::ostream &out = std::cout) const
{
    if (isEmpty())
        out << "Empty tree" << std::endl;
    else
        printTree(root, out);
}

/**
* Make the tree logically empty.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty( )
{
    makeEmpty( root );
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x)
{
    insert(x, root);
}

/**
* Insert x into the tree; duplicates are ignored.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::insert( Comparable && x )
{
    insert( std::move( x ), root );
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x)
{
    remove(x, root);
}

//////////////////////////////////////////////////////////////////////////

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x, BinarySearchTree<Comparable>::BinaryNode *&t)
{
    if (t == nullptr)
        t = new BinaryNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
    else
        ; // Duplicate; do nothing
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert by moving.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable &&x, BinarySearchTree<Comparable>::BinaryNode *&t)
{
    if (t == nullptr)
        t = new BinaryNode{std::move(x), nullptr, nullptr};
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (t->element < x)
        insert(std::move(x), t->right);
    else
        ; // Duplicate; do nothing
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x, BinarySearchTree<Comparable>::BinaryNode *&t)
{
    if (t == nullptr)
        return;
    // Item not found; do nothing
    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr) // Two children
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else
    {
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMin(BinarySearchTree<Comparable>::BinaryNode *t) const
{
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMax(BinarySearchTree<Comparable>::BinaryNode *t) const
{
    if (t != nullptr)
        while (t->right != nullptr)
            t = t->right;
    return t;
}

/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the subtree.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x, BinarySearchTree<Comparable>::BinaryNode *t) const
{
    if (t == nullptr)
        return false;
    else if (isLessThan(x, t->element))
        return contains(x, t->left);
    else if (isLessThan(t->element, x))
        return contains(x, t->right);
    else
        return true;
    // Match
}

/****** NONRECURSIVE VERSION*************************
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains( const Comparable & x, BinaryNode *t ) const
{
    while( t != nullptr )
        if( x < t->element )
            t = t->left;
        else if( t->element < x )
            t = t->right;
        else
            return true;    // Match

    return false;   // No match
}
*****************************************************/

/**
 * Internal method to make subtree empty.
 */
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinarySearchTree<Comparable>::BinaryNode *&t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

/**
* Internal method to print a subtree rooted at t in sorted order.
*/
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinarySearchTree<Comparable>::BinaryNode *t, std::ostream & out ) const
{
    if( t != nullptr )
    {
        printTree( t->left, out );
        out << t->element << std::endl;
        printTree( t->right, out );
    }
}

/**
 * Internal method to clone subtree.
 */
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::clone(BinarySearchTree<Comparable>::BinaryNode *t) const
{
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}







