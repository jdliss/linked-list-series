#include "node.h"
#include <iostream>
#include <string>

class LinkedList {
 public:

  Node* head;

  LinkedList(string);

  void print();
  void print(Node*);
  
  void insert(string);
  void insert(string, Node*);

  Node* find(string);
  Node* find(string, Node*);

  bool update(string, string);
  bool update(string, string, Node*);
};
