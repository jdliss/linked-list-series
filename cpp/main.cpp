#include "linked_list.cpp"
#include <iostream>

int main() {

  string data = "first node";
  LinkedList ll = LinkedList(data);

  cout << "head value is: " << ll.head->data << endl;

  return 0;
}
