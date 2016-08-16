#include "linked_list.h"

int main() {

  string data = "first node";
  LinkedList ll = LinkedList(data);
  ll.insert("second node");
  ll.insert("third node");

  return 0;
}
