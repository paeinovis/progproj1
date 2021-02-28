#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#ifndef PROGPROJ1_LINKEDLIST_H
#define PROGPROJ1_LINKEDLIST_H
using namespace std;

template <typename T>
class LinkedList {

    public:
        struct Node {
            T data;
            Node* next;
        };

    unsigned int num_nodes;
    Node* head_ptr;
    Node* tail_ptr;
    Node* next;

    // Behaviors
    void PrintForward() const {
        Node* current_node = head_ptr;
        while (current_node != nullptr) {
            cout << current_node->data << endl;
            current_node = current_node->next;
        }
    }

    void PrintReverse() const {
        T* node_array = new T[(int) NodeCount()];
        Node* current_node = head_ptr;
        for (int i = (int) num_nodes - 1; i >= 0; i--) {
            node_array[i] = current_node->data;
            current_node = current_node->next;
        }
        for (int i = 0; i < (int) num_nodes; i++) {
            cout << node_array[i] << endl;
        }
    }
    //void PrintForwardRecursive(const Node* node) const;
    //void PrintReverseRecursive(const Node* node) const;

    // Accessors
    unsigned int NodeCount() const {
        return num_nodes;
    }
    //void FindAll(vector<Node*>& outData, const T& value) const;
    //const Node* Find(const T& data) const;
    //Node* Find(const T& data);
    //const Node* GetNode(unsigned int index) const;
    //Node* GetNode(unsigned int index);
    //Node* Head(){
    //    return head_ptr;
    //}
    //Const Node* Head() const; // FIXME
    //Node* Tail(){
    //    return tail_ptr;
    //}
    //const Node* Tail() const; // FIXME

    // Insertion
    void AddHead(const T &data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = head_ptr;
        head_ptr = new_node;
        num_nodes++;
    }

    void AddTail(const T &data) {
        if (head_ptr == nullptr) {
            AddHead(data);
        }
        else {
            Node* current_node = head_ptr;
            Node* new_node = new Node;
            new_node->data = data;
            new_node->next = nullptr;
            while (current_node->next != nullptr){
                current_node = current_node->next;
            }
            tail_ptr = new_node;
            current_node->next = new_node;
            num_nodes++;
        }
    }

    void AddNodesHead(const T* data, unsigned int count){
        for (int i = (int) count - 1; i >= 0; i--) {
            AddHead(data[i]);
        }
    }
    void AddNodesTail(const T* data, unsigned int count){
        for (int i = 0; i < (int) count; i++) {
            AddTail(data[i]);
        }
    }
    //void InsertAfter(Node* nose, const T& data);
    //void InsertBefore(Node* node, const T& data);
    //void InsertAt(const T& data, unsigned int index);
    //
    //// Removal
    //bool RemoveHead();
    //bool RemoveTail();
    //unsigned int Remove(const T&data);
    //bool RemoveAt(unsigned int index);
    //void Clear();
    //
    //// Operators
    //const T& operator[](unsigned int index) const;
    //T& operator[](unsigned int index);
    //bool operator==(const LinkedList<T>& rhs) const;
    //LinkedList<T>& operator=(const LinkedList<T>& rhs);

    // Constructor
        LinkedList()
        {
            num_nodes = 0;
            head_ptr = nullptr;
            tail_ptr = nullptr;
        }
        LinkedList(const LinkedList <T> &list){
            num_nodes = list.size();
            AddHead(list[0]);
            AddTail(list[(int) num_nodes - 1]);
            Node* current_node = head_ptr;
            for (int i = 1; i < (int) num_nodes - 1; i++) {
                current_node->next = list[i];
                current_node = current_node->next;
            }
        }


    // Destructor
    ~LinkedList(){
        Node* current_node = head_ptr;
        while(head_ptr != nullptr) {
            head_ptr = head_ptr->next;
            delete current_node;
            current_node = head_ptr;
        }
        delete head_ptr;
    }
};



#endif //PROGPROJ1_LINKEDLIST_H
