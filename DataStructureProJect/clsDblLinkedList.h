#pragma once
#include <iostream>
using namespace std;

//Osman Bey Ghazi 


template <class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;

public:

    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;

    }

    // Print the linked list
    void PrintList()

    {
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
        delete Current;

    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }
    //حاسس اني عايز اضرب السعيد
    void InsertAfter(Node* current, T value) {


        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;

    }

    void InsertAtEnd(T value) {


        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;

    }

    void DeleteNode(Node*& NodeToDelete) {

        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;

        _Size--;
    }

    void DeleteFirstNode()
    {

        if (head == NULL) {
            return;
        }
        Node* Current = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete Current;
        _Size--;
    }

    void DeleteLastNode() {

        

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
       current->prev->next = NULL;
        delete current;
        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return _Size == 0 ? true : false;
    }

    void Clear()
    {
        while (!IsEmpty())//Or _Size!=0
        {
            DeleteFirstNode();
        }
    }

    void  Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;//4
            current->prev = current->next;//null
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    Node* GetNode(int index)
    {
        if (_Size = 0 && index < 0)
            return NULL;

        int count = 0;
        Node* current = head;

        while (current != NULL)
        {
            if (index == count)
            {
                return current;
            }

            count++;
            current = current->next;
        }

    }

    T GetItem(int index)
    {
      

        int count = 0;
        Node* current = head;

        while (current != NULL)
        {
            if (index == count)
            {
                return current->value;
            }

            count++;
            current = current->next;
        }

    }

    

    T GetItems(int Index)
    {

        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return NULL;
        else
            return ItemNode->value;

    }


    bool UpdateItem(int Index ,T Value)
    {

        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return 0;
        else
            ItemNode->value = Value;
        return 1;
    }


    bool InsertAfter(int Index, T Value)
    {

        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return 0;
        else
            InsertAfter(ItemNode, Value);
        return 1;
    } 

};






