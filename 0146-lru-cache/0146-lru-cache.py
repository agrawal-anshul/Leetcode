class Node:
    def __init__(self, key:int, val:int = None):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        # dummy nodes for tracking
        self.left = Node(0,0)
        self.right = Node(0,0)
        self.left.next = self.right
        self.right.prev = self.left
        self.dict = {}

    def get(self, key: int) -> int:
        if key not in self.dict:
            return -1
        node = self.dict[key]
        self._remove(node)
        self._insert(node)  # move to MRU
        return node.val

    def put(self, key: int, value: int) -> None:       
        # create a new node with value if not already exists
        if key not in self.dict:
            new_node = Node(key, value)
            # update the dictionary
            self.dict[key]= new_node
            # add it to the DLL
            self._insert(new_node)

        else:
            # get existing node
            node = self.dict[key]
            # update its value to new value
            node.val = value
            # unlink remove from end and at to the front
            self._remove(node)
            self._insert(node)
        
        # remove lru if size > capacity
        if len(self.dict) > self.capacity:
            lru = self.right.prev
            self._remove(lru)
            del self.dict[lru.key]
            

    def _insert(self, node:Node):
        """Insert right after left (MRU position)"""
        n = self.left.next
        self.left.next = node
        node.prev = self.left
        node.next = n
        n.prev = node
    
    def _remove(self, node:Node):
        """detach the node from DLL"""
        p, n = node.prev, node.next
        p.next = n
        n.prev = p

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)