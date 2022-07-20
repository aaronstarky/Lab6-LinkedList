//
// Created by Aaron on 7/19/2022.
//

#ifndef MAIN_CPP_LINKEDLIST_H
#define MAIN_CPP_LINKEDLIST_H



#pragma once
#include "LinkedListInterface.h"
#include <set>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;



template<class T>
class LinkedList : public LinkedListInterface<T>
{
private:
    struct Node
    {
        T data; // The data we are storing
        Node* next; //ptr to the next node in the list

        // Struct constructor
        Node(const T& the_data, Node* next_val = NULL) :
            data(the_data) {next = next_val;}
    };

    // todo: create Set that holds the values of each node that is added to the list so that duplicates can be detected
    // todo: edit all functions to exclude dupes from being added in any form


    Node *myList;
    int num_items;
public:
    LinkedList(void)
    {
        myList = NULL;
        num_items = 0;
    };
    virtual ~LinkedList(void) {};

    int size()
    {
        return num_items;
    }

    //******************************************************************************************************************

    /* todo: finish this
at

Returns the value of the node at the given index. The list begins at
index 0.

If the given index is out of range of the list, throw an out of range exception.
*/
    virtual T at(int index)
    {
        /*
         * iterate through, starting at 0;
         *      if (ptr->data == value)
         *          print "aha!"
         *          return ptr->data
         *      else
         *          continue looping until ptr == NULL
         *
         */
        cout << "In at()" << endl;
        if (index < 0 || index >= num_items)
        {
            cout << "   AT:   ERROR: index is out of range. Throwing a fat exception" << endl;
            throw std::out_of_range ("yikes, that index sucked");
        }
        int tracker = 0;
        for (Node *ptr = myList; ptr != NULL; ptr = ptr->next)
        {
            cout << "   AT: ptr = " << ptr << " ptr value = " << ptr->data << endl;
            if (tracker == index)
            {
                cout << "   AT: aha! found your index's value! val at(" << index << ") = " << ptr->data << endl;
                return ptr->data;
            }
            else
            {
                tracker++;
                cout << "   AT:   CONTINUING. tracker = " << tracker << " looking for index = " << index << endl;
                continue;
            }
        }

    }

    //******************************************************************************************************************

    string toString()
    {
        stringstream ss;
//        string stringRep;
        for (Node *ptr = myList; ptr != NULL; ptr = ptr->next)
        {
//            ss << "ptr = " << ptr << " val = " << ptr->data << " next = " << ptr->next << endl; // todo: comment out this line and uncomment the next line
            if (ptr->next == NULL)
            {
                ss << ptr->data;
            }
            else
            {
                ss << ptr->data << " ";
            }
        }
//        stringRep.erase(stringRep.begin() + stringRep.size()-1);
        return ss.str();
    }

    //******************************************************************************************************************

    bool DupeCheck(T value) // returns true if dupe is fond, false if no duplicates were found
    {
        /*
         * iterate through
         *      check ptr->data compared to value
         *      if they are the same, a dupe exists
         *          return true;
         *      else
         */
        cout << "   In DupeCheck()" << endl;
        for (Node *ptr = myList; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->data == value)
            {
                cout << "      DUPECHECK: value is a dupe or is different type. Not adding to list" << endl;
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }

    //******************************************************************************************************************

    void insertHead(T value)
    {
        cout << "In insertHead()" << endl;
        if (DupeCheck(value))
        {
            cout << "   INSERTHEAD: dang... dupe found. Awaiting termination" << endl;
        }
        else
        {
            Node *ptr = myList;
            myList = new Node(value);
//        cout << "value of Node trying to be added: " << myList->data << ". Calling the bouncers..." << endl;
//        for (Node *itr = ptr; itr != NULL; itr = itr->next)
//        {
//            if (myList->data == itr->data)
//            {
//                cout << "itr = " << itr << " val = " << itr->data << " next = " << itr->next << endl;
//                cout << "aha! dupe found. Exiting function" << endl;
//                break;
//            }
//            else if (itr->next == NULL && myList->data != itr->data)
//            {
//                cout << "celebrate! we're at the end of the list and there were no dupes. Adding node to head" << endl;
//                myList->next = ptr;
//            }
//            else
//            {
//                continue;
//            }
//        }
            myList->next = ptr;
            num_items++;
        }

    }

    //******************************************************************************************************************

    void insertTail(T value)
    {
        /*
         * declare ptr "newNode" to new Node(value);
         * set newNode->next = NULL;
         * iterate through list until lastElement->next == NULL.
         * set lastElement->next to *newNode;
         * delete newNode;
         */

        cout << "In insertTail()" << endl;
        if (num_items == 0) // if there are no nodes, insert a head instead.
        {
            insertHead(value);
        }
        else if (DupeCheck(value)) // if a dupe exists, do nothing
        {
            cout << "   INSERTTAIL: dupe failed, awaiting termination" << endl;
        }
        else // if no dupes exist and there are more than 0 items, add a tail :)
        {
            Node *newNode = new Node(value);
            newNode->next = NULL;
            for (Node *ptr = myList; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = newNode;
                    num_items++;
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    //******************************************************************************************************************

    void insertAfter(T value, T insertionNode)
    {
        /*
         * declare new *Node
         * set newNode->next = NULL;
         * iterate through list till insertionNode value is found using ptr;
         * set newNode->next = ptr->next to get it into the correct train position;
         * set ptr->next = newNode;
         */

        cout << "In insertAfter()" << endl;
        if (DupeCheck(value))
        {
            cout << "   INSERTAFTER: dang... a dupe was found. Awaiting termination" << endl;
        }
        else
        {
            Node *newNode = new Node(value);
            newNode->next = NULL;
            for (Node *ptr = myList; ptr != NULL; ptr = ptr->next)
            {
                cout << "   INSERTAFTER: ptr = " << ptr << " ptr->data = " << ptr->data
                     << " val to be inserted = " << value << endl;
                if (ptr->data != insertionNode)
                {
                    continue;
                }
                else if (ptr->data == insertionNode)
                {
                    cout << "   INSERTAFTER: aha! found a match, inserting new Node!" << endl;
                    newNode->next = ptr->next;
                    ptr->next = newNode;
                    ++num_items;
                    break;
                }
            }
        }
    }

    //******************************************************************************************************************

    /*
    remove

    The node with the given value should be removed from the list.

    The list may or may not include a node with the given value.
    */
    void remove(T value)
    {
        // fixme: needs to be able to remove the first element in the linked list. Watch video about that
        // fixme: is losing elements prior to remove. 0 9999 1 -1 2 3 4 5 6 7 8 9 10 12 --> 0 2 3 4 5 6 7 8 9 10 12
        /*
         * declare Node *bridgeOverTroubledWaters
         * Iterate through till value is found, while incrementing a tracker int.
         * When value is found, set bridgeOverTroubledWaters = ptr-next
         *      begin another for loop to re-iterate over the same list the num of times as the tracker int - 1
         *      delete ptr->next;
         *      set ptr->next = 0;
         *      set that ptr->next = bridgeOverTroubledWaters;
         */
        cout << "In remove()" << endl;
        Node *bridgeOverTroubledWaters = NULL;
        if (myList == NULL)
        {
            cout << "   REMOVE: oh no! The list is empty. Nothing to remove i guess..." << endl;
            delete bridgeOverTroubledWaters;
        }
        else if (myList->data == value) // if the value to be deleted is found in head
        {
            cout << "   REMOVE: hahaha... tricky... found the node at the head" << endl;
            bridgeOverTroubledWaters = myList;
            myList = myList->next;
            delete bridgeOverTroubledWaters;
            --num_items;
        }
        else
        {
            for (Node *ptr = myList; ptr != NULL; ptr = ptr->next)
            {
                cout << "   REMOVE: ptr = " << ptr << " ptr->data = " << ptr->data
                     << " val to be removed = " << value << endl;
                if (ptr->next == NULL)
                {
                    break;
                }
                else if (ptr->next->data != value)
                {
                    continue;
                }
                else if (ptr->next->data == value)
                {
                    cout << "   REMOVE: aha! Found the value!" << endl;
                    bridgeOverTroubledWaters = ptr->next;
                    cout << "   REMOVE: bridgeOverTroubledWaters = ptr->next" << endl;
                    ptr->next = ptr->next->next;
                    delete bridgeOverTroubledWaters;
                    --num_items;
                }
            }
        }
//        for (Node *ptr = myList; ptr != NULL; ptr = ptr->next)
//        {
//            cout << "   REMOVE: ptr = " << ptr << " ptr->data = " << ptr->data
//                 << " val to be removed = " << value << endl;
//            if (ptr->next == NULL)
//            {
//                break;
//            }
//            else if (ptr->data != value)
//            {
//                continue;
//            }
//            else if (ptr->data == value)
//            {
//                cout << "   REMOVE: aha! Found the value!" << endl;
//                bridgeOverTroubledWaters = ptr->next;
//                cout << "   REMOVE: bridgeOverTroubledWaters = ptr->next" << endl;
//                Node *previousNode = myList;
//                cout << "   REMOVE: entering for loop" << endl;
//                for (int i = 0; i <= tracker; ++i)
//                {
//                    cout << "clkr = " << previousNode << " clkr->data = " << previousNode->data << endl;
//                    previousNode = previousNode->next;
//                }
//                cout << "   REMOVE: setting clkr->next = " << bridgeOverTroubledWaters << endl;
////                delete clkr->next;
//                previousNode->next = bridgeOverTroubledWaters;
//                --num_items;
//            }
//        }
    }

    /* todo: finish this
    clear

    Remove all nodes from the list.
    */
    void clear()
    {
        cout << "In clear()" << endl;
        while (myList != NULL)
        {
            Node* bigEvilPointerEaterMonster = myList;
            cout << "   CLEAR: bigEvilPointerEaterMonster is gobbling up " << myList->data << endl;
            myList = myList->next;
            delete bigEvilPointerEaterMonster;
            --num_items;
        }
    }




};



#endif //MAIN_CPP_LINKEDLIST_H
