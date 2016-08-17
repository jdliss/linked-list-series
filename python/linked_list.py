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

    def find_parent(self, data, current=None):
        if current == None:
            current = self.head

        if current.next != None:
            if current.next.data == data:
                return current
            else:
                return self.find_parent(data, current.next)
            
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

    def update(self, find_data, update_data, current=None):
        if current == None:
            current = self.head

        if current.data == find_data:
            current.data = update_data
            return current.data == update_data
        elif current.next != None:
            return self.update(find_data, update_data, current.next)
        
    def destroy(self, data):
        if data == self.head.data:
            self.head = self.head.next
        else:
            node = self.find(data)
            parent = self.find_parent(data)
            if node.next != None:
                parent.next = node.next
            else:
                parent.next = None
                
