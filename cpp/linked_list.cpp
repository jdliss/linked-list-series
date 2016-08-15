#include "node.cpp"

// C++ basic CRUD Linked List Attempt
// 
// Create
// Read
// Update
// Destroy

class LinkedList {
public:

  Node* head;

  LinkedList(string data) {
    this->head = new Node(data);
  }
};
