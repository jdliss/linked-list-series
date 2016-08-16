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

