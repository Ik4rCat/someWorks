class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    
    def search(self, target):
        current = self.head
        index = 0
        
        while current:
            if current.data == target:
                return index
            current = current.next
            index += 1
        
        return -1
    
    def search_with_sentinel(self, target):
        sentinel = Node(target)
        
        if not self.head:
            return -1
        
        current = self.head
        while current.next:
            if current.data == target:
                return self._get_index(current)
            current = current.next
        
        current.next = sentinel
        current = self.head
        
        index = 0
        while current.data != target:
            current = current.next
            index += 1
        
        if current == sentinel:
            current = self.head
            while current.next != sentinel:
                current = current.next
            current.next = None
            return -1
        else:
            return index
    
    def _get_index(self, node):
        current = self.head
        index = 0
        while current:
            if current == node:
                return index
            current = current.next
            index += 1
        return -1

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

def linear_search_with_barrier(arr, target):
    arr_with_barrier = arr.copy()
    arr_with_barrier.append(target)
    
    i = 0
    while arr_with_barrier[i] != target:
        i += 1
    
    return i if i < len(arr) else -1

def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

def interpolation_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right and target >= arr[left] and target <= arr[right]:
        if arr[right] == arr[left]:
            pos = left
        else:
            pos = left + ((target - arr[left]) * (right - left)) // (arr[right] - arr[left])
        
        pos = min(max(pos, left), right)
        
        if arr[pos] == target:
            return pos
        elif arr[pos] < target:
            left = pos + 1
        else:
            right = pos - 1
    
    return -1

def test_all_searches():
    print("=" * 50)
    print("SEARCH ALGORITHMS TESTING")
    print("=" * 50)
    
    unsorted_arr = [5, 2, 8, 1, 9, 3, 7, 4, 6]
    sorted_arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    uniform_arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    
    ll = LinkedList()
    for data in [5, 2, 8, 1, 9, 3]:
        ll.append(data)
    
    test_cases = [
        (4, "existing element"),
        (10, "non-existing element"),
        (1, "first element"),
        (9, "last element")
    ]
    
    for target, description in test_cases:
        print(f"\nSearching for element {target} ({description}):")
        print(f"Linear Search: {linear_search(unsorted_arr, target)}")
        print(f"Barrier Search: {linear_search_with_barrier(unsorted_arr, target)}")
        print(f"Binary Search: {binary_search(sorted_arr, target)}")
        print(f"Interpolation Search: {interpolation_search(uniform_arr, target)}")
        print(f"Linked List Search: {ll.search(target)}")
        print(f"Linked List Sentinel Search: {ll.search_with_sentinel(target)}")

if __name__ == "__main__":
    test_all_searches()
    
    print("\n" + "=" * 50)
    print("INDIVIDUAL ALGORITHM DEMONSTRATION")
    print("=" * 50)
    
    arr1 = [5, 2, 8, 1, 9, 3]
    target1 = 8
    print(f"Linear Search in {arr1} for {target1}: {linear_search(arr1, target1)}")
    
    arr2 = [1, 2, 3, 5, 8, 9, 12, 15, 18]
    target2 = 8
    print(f"Binary Search in {arr2} for {target2}: {binary_search(arr2, target2)}")
    
    arr3 = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    target3 = 60
    print(f"Interpolation Search in {arr3} for {target3}: {interpolation_search(arr3, target3)}")