class Node
  attr_accessor :data, :next

  def initialize(data)
    @data = data
    @next = nil
  end
end

class LinkedList
  attr_reader :head

  def initialize(data)
    @head = Node.new(data)
  end

  def insert(data, current=@head)
    if current.next
      insert(data, current.next)
    else
      current.next = Node.new(data)
    end
  end

  def find(data, current=@head)
    if current.data == data
      current
    else
      find(data, current.next) if current.next
    end
  end

  def update(find_data, update_data, current=@head)
    node = find(find_data)
    if node
      node.data = update_data
      true
    else
      false
    end
  end

  def find_parent(data, current=@head)
    if current.next && current.next.data == data
      current
    else
      find_parent(data, current.next) if current.next
    end
  end

  def destroy(data)
    node = find(data)
    if node
      parent = find_parent(data)
      if parent
        parent.next = node.next
      else
        @head = node.next
      end
      true
    else
      false
    end
  end

  def print(current=@head)
    puts current.data
    print(current.next) if current.next
  end
end
