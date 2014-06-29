#ifndef TREE_H
#define TREE_H

#include <iostream>

#include "Macros.h"

using std::cout;


namespace projectEuler
{
//
// Generic tree and node class
//

template <class T>
class Node
{
    public:
        Node(const T& val) 
        {
            mValue     = val;
            mLeftNode  = NULL;    
            mRightNode = NULL;
        }

        ~Node() 
        {
            DeleteNode();
        }
    
        void AddLeft(const T& val)
        {
            mLeftNode = new Node(val);
        }

        void AddRight(const T& val)
        {
            mRightNode = new Node(val);
        }

        Node<T>* GetLeft()
        {
            return mLeftNode;
        }

        Node* GetRight()
        {
            return mRightNode;
        }

        void SetValue(const T& val) 
        { 
            mValue = val; 
        }

        T GetValue() const 
        { 
            return mValue; 
        }

        void DeleteNode()
        {
            delete mLeftNode;
            delete mRightNode;
            mLeftNode  = NULL;    
            mRightNode = NULL;
        }

    private:
        T mValue;
        Node<T>* mLeftNode;
        Node<T>* mRightNode;
};


template <class T>
class Tree
{
    public:
        Tree()
        {
            mHeadNode = NULL;
        }

        ~Tree()
        {
            Clear();
        }

        void AddHead(const T& val)
        {
            mHeadNode = new Node<T>(val);
        }

        Node<T>* GetHead()
        {
            return mHeadNode;       
        }

        void AddMostLeft(const T& val) 
        {
            ASSERT(mHeadNode);
            if(mHeadNode == NULL)
                return;
            
            Node<T>* tempNode = mHeadNode;

            while(tempNode->GetLeft() != NULL)
            {
                // iterate to most left
                tempNode = tempNode->GetLeft();
            }

            tempNode->AddLeft(val);
        }

        void AddMostRight(const T& val) 
        {
            ASSERT(mHeadNode);
            if(mHeadNode == NULL)
                return;
            
            Node<T>* tempNode = mHeadNode;

            while(tempNode->GetRight() != NULL)
            {
                // iterate to most right
                tempNode = tempNode->GetRight();
            }

            tempNode->AddRight(val);
        }

        Node<T>* AddLeft(Node<T>* node, const T& val)
        {
            ASSERT(node);

            node->AddLeft(val);
            return node->GetLeft();
        }

        Node<T>* AddRight(Node<T>* node, const T& val)
        {
            ASSERT(node);

            node->AddRight(val);
            return node->GetRight();
        }

        void Display()
        {
            RecursiveDisplay(mHeadNode);
        }

        void Clear()
        {
            RecursiveClear(mHeadNode);
            delete mHeadNode;
            mHeadNode = NULL;
        }

    private:
        Node<T>* mHeadNode;

        void RecursiveDisplay(Node<T>* node)
        {
            if(node != NULL)
            {
                cout << node->GetValue() <<" ";
                RecursiveDisplay(node->GetLeft());
                RecursiveDisplay(node->GetRight());
            }
        }

        void RecursiveClear(Node<T>* node)
        {
            if(node != NULL)
            {
                RecursiveClear(node->GetLeft());
                RecursiveClear(node->GetRight());
                node->DeleteNode();
            }
        }
};

}

#endif // CEBIR_H
