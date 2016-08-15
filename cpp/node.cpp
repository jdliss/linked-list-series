#include <string>

using namespace std;

class Node {
public:

  string data;
  Node* next;

  Node(string data) {
    this->data = data;
  }
};
