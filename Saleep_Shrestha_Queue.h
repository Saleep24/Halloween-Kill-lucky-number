/*
Name: Saleep Shrestha
Student_ID: w10167735
Program Description: This file defines the Queue class which will be used to simulate the process of eliminating individuals in a circular fashion.
*/

#ifndef SALEEP_SHRESTHA_QUEUE_H
#define SALEEP_SHRESTHA_QUEUE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Queue {
protected:
    struct Node {
        string data;
        Node* next;
    };
    Node* front;
    Node* back;
    int count;

public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    ~Queue() {
        while (count > 0) {
            string dummy;
            Dequeue(dummy);
        }
    }

    void Enqueue(const string& data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (count == 0) {
            front = back = newNode;
            back->next = front;
        } else {
            back->next = newNode;
            back = newNode;
            back->next = front;
        }
        count++;
    }

    bool Dequeue(string& data) {
        if (count == 0) {
            return false;
        }
        data = front->data;
        Node* temp = front;
        if (count == 1) {
            front = back = nullptr;
        } else {
            front = front->next;
            back->next = front;
        }
        delete temp;
        count--;
        return true;
    }

    int GetCount() const {
        return count;
    }
};

#endif
