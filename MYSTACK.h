#include <bits/stdc++.h>

using namespace std;

template <typename N>
class Node
{
public:
    N value;
    Node *prev;
    Node *next;

    Node(N value)
    {
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    // PUSH
    void Push(S value)
    {
        Node<S> *newNode = new Node<S>(value);

        if (head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }

    // POP
    S Pop()
    {
        Node<S> *delNode = top;
        S delVal;
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return delVal;
        }

        if (head == top)
        {
            head = top = NULL;
        }
        else
        {
            top = delNode->prev;
            top->next = NULL;
        }
        delVal = delNode->value;
        delete delNode;
        count--;
        return delVal;
    }

    // SIZE
    int Size()
    {
        return count;
    }

    // TOP
    S Top()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow | There is no element at the Top" << endl;
            //            return -1;
        }
        else
        {
            return top->value;
        }
    }

    // EMPTY
    bool Empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
};