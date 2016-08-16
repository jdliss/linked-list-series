#include "linked_list.h"

// basic CRUD Linked list in C++
// 
// Create X
// Read X
// Update
// Destroy

LinkedList::LinkedList(string data) {
  this->head = new Node(data);
}

void LinkedList::print() {
  print(this->head);
}

void LinkedList::print(Node* currentNode) {
  cout << currentNode->data << endl;
  if (currentNode->next != NULL) print(currentNode->next);
}

void LinkedList::insert(string data) {
  insert(data, this->head);
}

void LinkedList::insert(string data, Node* currentNode) {
  if (currentNode->next == NULL) {
    currentNode->next = new Node(data);
  } else {
    insert(data, currentNode->next);
  }
}

Node* LinkedList::find(string data) {
  return find(data, this->head);
}

Node* LinkedList::find(string data, Node* currentNode) {
  if (currentNode->data == data) {
    return currentNode;
  } else {
    return find(data, currentNode->next);
  }
}

bool LinkedList::update(string toFind, string updateValue) {
  return update(toFind, updateValue, this->head);
}

bool LinkedList::update(string toFind, string updateValue, Node* currentNode) {
  Node* node = this->find(toFind);
  node->data = updateValue;

  return node->data == updateValue;
}
