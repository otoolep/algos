#!/usr/bin/env python

class MinHeap(object):
    def __init__(self):
        # Create heap with empty slot at 0, to simplify math.
        self.heap = [0]
        self.current_size = 0

    def Empty(self):
        return self.current_size == 0

    def Insert(self, n):
        self.heap.append(n)
        self.current_size += 1
        self.percUp(self.current_size)

    def Pop(self):
        # Get value at top of heap.
        n = self.heap[1]

        # Replace with value at end of heap.
        self.heap[1] = self.heap[self.current_size]
        self.current_size -= 1
        self.heap.pop()

        self.percDown(1)
        return n

    def percUp(self, i):
        '''
        Takes the node at position i in the array, and moves it
        up the heap if necessary.
        '''
        # Keep going both child nodes are larger.
        while i / 2 > 0:
            # Check if parent node is smaller.
            parent = i/2
            if self.heap[parent] > self.heap[i]:
                tmp = self.heap[parent]
                self.heap[parent] = self.heap[i]
                self.heap[i] = tmp

            # Go up a level and check again.
            i = i / 2


    def percDown(self, i):
        while 2 * i <= self.current_size:
            if 2 * i + 1 > self.current_size:
                min = 2 * i
            else:
                if self.heap[2 * i] > self.heap[2 * i + 1]:
                    min = 2 * i + 1
                else:
                    min = 2 * i

            if self.heap[i] > self.heap[min]:
                tmp = self.heap[i]
                self.heap[i] = self.heap[min]
                self.heap[min] = tmp
            i = min

    def __str__(self):
        return 'Heap: %s' % str(self.heap[1:])

class MaxHeap(MinHeap):
    def percUp(self, i):
        # Keep going until the root node.
        while i // 2 > 0:
            # Check if parent node is larger.
            parent = i/2
            if self.heap[parent] < self.heap[i]:
                tmp = self.heap[parent]
                self.heap[parent] = self.heap[i]
                self.heap[i] = tmp

            # Go up a level and check again.
            i = i / 2

    def __str__(self):
        return 'Heap: %s' % str(self.heap[1:])


h = MinHeap()

for n in [4,7,6,8,2,4,6,8,2,5,1]:
    print 'Inserting %d' % n
    h.Insert(n)
    print h
    print

while not h.Empty():
    print 'Min is %d' % h.Pop()
    print h
    print
