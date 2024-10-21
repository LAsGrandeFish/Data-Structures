import unittest
from singly_linked_list import SinglyLinkedList, Node

class TestSinglyLinkedList(unittest.TestCase):

    def setUp(self):
        """Set up a linked list for testing"""
        self.ll = SinglyLinkedList()

    def test_is_empty(self):
        """Test if the linked list is empty"""
        self.assertTrue(self.ll.is_empty())
        self.ll.append(10)
        self.assertFalse(self.ll.is_empty())

    def test_append(self):
        """Test appending elements to the linked list"""
        self.ll.append(1)
        self.ll.append(2)
        self.ll.append(3)
        self.assertEqual(self.ll.display(), [1, 2, 3])

    def test_prepend(self):
        """Test prepending elements to the linked list"""
        self.ll.prepend(1)
        self.ll.prepend(2)
        self.ll.prepend(3)
        self.assertEqual(self.ll.display(), [3, 2, 1])

    def test_insert_after_node(self):
        """Test inserting a node after a specific node"""
        self.ll.append(1)
        self.ll.append(2)
        self.ll.append(3)
        self.ll.insert_after_node(2, 4)
        self.assertEqual(self.ll.display(), [1, 2, 4, 3])

    def test_delete_node(self):
        """Test deleting a specific node"""
        self.ll.append(1)
        self.ll.append(2)
        self.ll.append(3)
        self.ll.delete_node(2)
        self.assertEqual(self.ll.display(), [1, 3])

    def test_delete_node_at_position(self):
        """Test deleting a node at a specific position"""
        self.ll.append(1)
        self.ll.append(2)
        self.ll.append(3)
        self.ll.delete_node_at_position(1)
        self.assertEqual(self.ll.display(), [1, 3])

    def test_search(self):
        """Test searching for a node by its value"""
        self.ll.append(1)
        self.ll.append(2)
        self.ll.append(3)
        self.assertTrue(self.ll.search(2))
        self.assertFalse(self.ll.search(4))

    def test_get_length(self):
        """Test getting the length of the linked list"""
        self.ll.append(1)
        self.ll.append(2)
        self.ll.append(3)
        self.assertEqual(self.ll.get_length(), 3)

    def test_display(self):
        """Test displaying the linked list"""
        self.ll.append(1)
        self.ll.append(2)
        self.ll.append(3)
        self.assertEqual(self.ll.display(), [1, 2, 3])

    def test_reverse(self):
        """Test reversing the linked list"""
        self.ll.append(1)
        self.ll.append(2)
        self.ll.append(3)
        self.ll.reverse()
        self.assertEqual(self.ll.display(), [3, 2, 1])

if __name__ == '__main__':
    unittest.main(verbosity=2)
