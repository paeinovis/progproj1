#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#ifndef PROGPROJ1_LINKEDLIST_H
#define PROGPROJ1_LINKEDLIST_H
using namespace std;

template <typename T>
class LinkedList {

    public:
        struct Node {
            T data;
            Node* next;
            Node* prev;
        };

    unsigned int num_nodes;
    Node* head_ptr;
    Node* tail_ptr;

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
        delete[] node_array;
    }
    //void PrintForwardRecursive(const Node* node) const;
    //void PrintReverseRecursive(const Node* node) const;

    // Accessors
    unsigned int NodeCount() const {
        return num_nodes;
    }
    void FindAll(vector<Node*>& outData, const T& value) const{
        Node* current_node = head_ptr;
        Node* prev_node = nullptr;
        while (current_node != nullptr) {
            if (current_node->data == value) {
                outData.push_back(current_node);
                current_node->prev = prev_node;
            }
            if (current_node == head_ptr) {
                prev_node = head_ptr;
            }
            else {
                prev_node = prev_node->next;
            }
            current_node = current_node->next;
        }
    }
    const Node* Find(const T& data) const {
        Node* current_node = head_ptr;
        while (current_node != nullptr) {
            if (current_node->data == data) {
                return current_node;
            }
            current_node = current_node->next;
        }
        return nullptr;
    }
    Node* Find(const T& data) {
        Node* current_node = head_ptr;
        while (current_node != nullptr) {
            if (current_node->data == data) {
                return current_node;
            }
            current_node = current_node->next;
        }
        return nullptr;
    }
    const Node* GetNode(unsigned int index) const {
        Node *current_node = head_ptr;
        for (unsigned int i = 0; i < index; i++) {
            current_node = current_node->next;
            if (current_node == nullptr) {
                throw out_of_range ("e");
            }
        }
        return current_node;
    }
    Node* GetNode(unsigned int index) {
        Node* current_node = head_ptr;
        for (unsigned int i = 0; i < index; i++) {
            current_node = current_node->next;
            if (current_node == nullptr) {
                throw out_of_range ("e");
            }
        }
        return current_node;
    }
    Node* Head(){
        return head_ptr;
    }
    const Node* Head() const {
        return head_ptr;
    }
    Node* Tail(){
        return tail_ptr;
    }
    const Node* Tail() const{
        return tail_ptr;
    }

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
    const T& operator[](unsigned int index) const {
        try {
            const Node *op_ptr = GetNode(index);
            return op_ptr->data;
        } catch (exception) {
            throw out_of_range ("e");
        }
    }
    T& operator[](unsigned int index){
        try {
            Node *op_ptr = GetNode(index);
            return op_ptr->data;
        } catch (exception) {
            throw out_of_range ("e");
        }
    }
    //bool operator==(const LinkedList<T>& rhs) const;
    //LinkedList<T>& operator=(const LinkedList<T>& rhs);

    // Constructor
        LinkedList()
        {
            num_nodes = 0;
            head_ptr = nullptr;
            tail_ptr = nullptr;
        }
    // Copy Constructor
        LinkedList(const LinkedList <T> &list){
            int num_iter = num_nodes - 1;
            this->num_nodes = list.num_nodes;
            this->head_ptr = list.head_ptr;
            this->tail_ptr = list.tail_ptr;
            for (int i = 1; i < num_iter; i++) {
                AddTail(list.GetNode(i)->data);
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
//for (int i = 1; i < (int) num_nodes - 1; i++) {
//                current_node = list.GetNode(i);
//                current_node = current_node->next;
//                num_nodes++;
//            }
//for (int i = 1; i < (int) num_nodes - 1; i++) {
//                AddTail(list[i]);
//                current_node = current_node->next;
//            }
//while(current_node != nullptr){
//                AddTail(current_node->data);
//                current_node = current_node->next;
//            }
//num_nodes = list.size();
//            AddHead(list[0]);
//            AddTail(list[(int) num_nodes - 1]);
//            Node* current_node = head_ptr;
//            for (int i = 1; i < (int) num_nodes - 1; i++) {
//                current_node->next = list[i];
//                current_node = current_node->next;
//            }


#endif //PROGPROJ1_LINKEDLIST_H
