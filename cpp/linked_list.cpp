#include "linked_list.h"

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

Node* LinkedList::findParent(string data, Node* currentNode){
  if (currentNode->next->data == data) {
    return currentNode;
  } else {
    return this->findParent(data, currentNode->next);
  }
}

bool LinkedList::destroy(string data) {
  Node* node = this->find(data);
  Node* parent;

  if (node == this->head) {
    parent = this->head;
    this->head = node->next;
  } else {
    parent = this->findParent(data, this->head);
    parent->next = node->next;
  }
  return parent->next == node->next;
}
