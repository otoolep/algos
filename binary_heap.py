#!/usr/bin/env python

class MinHeap(object):
    def __init__(self):
        # Create heap with empty slot at 0, to simplify math.
        self.heap = [0]
        self.current_size = 0

    def Insert(self, n):
        self.heap.append(n)
        self.current_size += 1
        self.percUp(self.current_size)

    def percUp(self, i):
        # Keep going until the root node.
        while i // 2 > 0:
            # Check if parent node is smaller.
            parent = i/2
            if self.heap[parent] > self.heap[i]:
                tmp = self.heap[parent]
                self.heap[parent] = self.heap[i]
                self.heap[i] = tmp

            # Go up a level and check again.
            i = i / 2

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


h = MaxHeap()

for n in [4,7,6,8,2,4,6,8,2,5,1]:
    print 'Inserting %d' % n
    h.Insert(n)
    print h
    print
