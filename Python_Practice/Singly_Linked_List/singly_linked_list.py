class Node:
    def __init__(self, data):
        """Initialize a node with data and set the next pointer to None."""
        # pass
        self.data = data
        self.next_node = None 

    def get_data(self):
        return self.data
    
    def get_next(self):
        return self.next_node
    
    def set_next(self, next_node):
        self.next_node = next_node



class SinglyLinkedList:
    def __init__(self):
        """Initialize the linked list. Set the head of the list to None."""
        # pass
        self.head = None
        self.tail = None
        self.size = 0

    def is_empty(self):
        """
        Check if the linked list is empty.
        Returns:
            True if the list is empty, otherwise False.
        """
        # pass
        return self.size == 0 

    def append(self, data):
        """
        Add a new node with the specified data at the end of the linked list.
        If the list is empty, the new node becomes the head.
        """
        # pass
        new_node = Node(data)
        if self.size == 0:
            self.head = new_node
        else:
            self.tail.set_next(new_node)
        self.tail = new_node
        self.size += 1

    def prepend(self, data):
        """
        Add a new node with the specified data at the beginning of the linked list.
        The new node becomes the head of the list.
        """
        # pass
        new_node = Node(data)
        if self.size == 0:
            self.tail = new_node
        else: 
            new_node.set_next(self.head)
        self.head = new_node
        self.size += 1

    def insert_after_node(self, prev_node_data, data):
        """
        Insert a new node with the specified data after the node with the given prev_node_data.
        If the previous node is not found, do nothing or handle it appropriately.
        """
        # pass
        if self.size == 0:
            return None
        else:
            curr = self.head
            for i in range(0, self.size):
                if curr.get_data() == prev_node_data & i == self.size - 1:
                    self.append(data)
                else:
                    if curr.get_data() == prev_node_data:
                        new_node = Node(data)
                        new_node.set_next(curr.get_next())
                        curr.set_next(new_node)
                        self.size += 1
                        return
                curr = curr.get_next()

    def delete_node(self, data):
        """
        Delete the first node in the linked list that contains the specified data.
        If the node is not found, do nothing or handle it appropriately.
        """
        # pass
        if self.size == 0:
            return None
        if self.head.get_data() == data:
            self.head = self.head.get_next()
            return
        prev = self.head
        curr = self.head.get_next() # could be more effiecent by not starting here since this case is alreadyed checked 
        while curr != None:
            if curr.get_data() == data:
                prev.set_next(curr.get_next())
                if self.tail.get_data() == curr.get_data():
                    self.tail = prev
                self.size -= 1
                return
            prev = prev.get_next()
            curr = curr.get_next()

    def delete_node_at_position(self, position):
        """
        Delete the node at the specified position (0-based index) in the linked list.
        If the position is invalid, do nothing or handle it appropriately.
        """
        # pass
        if position < 0 | position >= self.size:
            return
        if position == 0:
            self.head = self.head.get_next()
        prev = self.head
        curr = self.head.get_next()
        for i in range(1, self.size - 1):
            if i == position:
                prev.set_next(curr.get_next())
                if i == self.size - 1:
                    self.tail = prev
                self.size -= 1
                return
            prev = prev.get_next()
            curr = curr.get_next()

    def search(self, key):
        """
        Search for a node with the specified key (data) in the linked list.
        Returns:
            True if the node is found, otherwise False.
        """
        # pass
        curr = self.head
        while curr != None:
            if curr.get_data() == key:
                return True
            curr = curr.get_next()
        return False

    def get_length(self):
        """
        Calculate and return the total number of nodes in the linked list.
        """
        # pass
        return self.size

    def display(self):
        """
        Return a list of all the elements (data) in the linked list in the order they appear.
        """
        # pass
        list_of_elements = []
        if self.size == 0:
            return list_of_elements
        else:
            curr = self.head
            while curr != None:
                list_of_elements.append(curr.get_data())
                curr = curr.get_next()
            return list_of_elements

    def reverse(self):
        """
        Reverse the order of nodes in the linked list.
        The last node becomes the head, and the head becomes the last node.
        """
        # pass
        self.tail = self.head

        prev = None
        curr = self.head
        while curr is not None:
            next_node  = curr.get_next()
            curr.set_next(prev)
            prev = curr
            curr = next_node
        self.head = prev
