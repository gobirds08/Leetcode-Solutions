from collections import OrderedDict

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.storage = OrderedDict()
        self.capacity = capacity
        self.curr_index = 0

        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.storage:
            output = self.storage[key]
            self.storage.pop(key)
            self.storage[key] = output
            return output
        
        return -1
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.storage:
            self.storage.pop(key)
            self.curr_index -= 1
        elif self.curr_index >= self.capacity:
            self.storage.popitem(last=False)
        
        self.storage[key] = value
        self.curr_index += 1
            
        


         


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)