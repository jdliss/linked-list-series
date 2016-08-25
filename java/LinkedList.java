// Linked List basic crud - Java

// Create X
// Read X
// Update X
// Destroy X

class LinkedList {
    public Node head;

    LinkedList(String data) {
        this.head = new Node(data);
    }

    public void print() {
        print(this.head);
    }

    private void print(Node currentNode) {
        System.out.println(currentNode.data);
        if (currentNode.next != null) {
            print(currentNode.next);
        }
    }

    public void insert(String data) {
        insert(data, this.head);
    }

    private void insert(String data, Node currentNode) {
        if (currentNode.next == null) {
            currentNode.next = new Node(data);
        } else {
            insert(data, currentNode.next);
        }
    }

    public Node find(String data) {
        return find(data, this.head);
    }

    private Node find(String data, Node currentNode) {
        if (currentNode.data == data) {
            return currentNode;
        } else {
            return find(data, currentNode.next);
        }
    }

    public boolean update(String findData, String updateData) {
        return update(findData, updateData, this.head);
    }

    private boolean update(String findData, String updateData, Node currentNode) {
        if (currentNode.data == findData) {
            currentNode.data = updateData;
            return currentNode.data == updateData;
        } else if (currentNode.next != null) {
            return update(findData, updateData, currentNode.next);
        } else {
            return false;
        }
    }

    public void destroy(String data) {
        Node parent = findParent(data, this.head);
        Node node = find(data, this.head);

        if (parent == null) {
            this.head = node.next;
        } else {
            parent.next = node.next;
        }
    }

    private Node findParent(String data, Node currentNode) {
        if (this.head.data == data) {
            return null;
        } else if (currentNode.next == null) {
            return null;
        } else {
            if (currentNode.next.data == data) {
                return currentNode;
            } else {
                return findParent(data, currentNode.next);
            }
        }
    }
}
