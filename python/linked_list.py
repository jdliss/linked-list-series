
# python linked list - basic CRUD

# Create X
# Read
# Update
# Destroy

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self, data):
        self.head = Node(data)

    def print_list(self, current=None):
        if current == None:
            current = self.head

        print current.data
        if current.next:
            self.print_list(current.next)

    def insert(self, data, current=None):
        if current == None:
            current = self.head
            
        if current.next == None:
            current.next = Node(data)
        else:
            self.insert(data, current.next)

    def find(self, data, current=None):
        if current == None:
            current = self.head

        if current.data == data:
            return current
        elif current.next != None:
            return self.find(data, current.next)

ll = LinkedList("first node")
ll.insert("second node")
ll.insert("third node")
# ll.print_list()
node = ll.find("third node")
print node.data
