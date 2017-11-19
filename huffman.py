#!/usr/bin/env python

import heapq

class Node(object):
    def __init__(self, char, count, left=None, right=None):
        self.char = char
        self.count = count
        self.left = left
        self.right = right

    def __le__(self, other):
        return self.count <= other.count

    def __lt__(self, other):
        return self.count < other.count

    def __str__(self):
        return '%c:%d' % (self.char, self.count)

def walk(node, code):
    if node.left is None and node.right is None:
        print '%s: %s' % (node.char, ''.join(code))
        return

    if node.left is not None:
        code.append('0')
        walk(node.left, code)
        code = code[0:len(code)-1]
    if node.right is not None:
        code.append('1')
        walk(node.right, code)
        code = code[0:len(code)-1]


def main():
    heap = [Node('a', 5),
            Node('b', 9),
            Node('c', 12),
            Node('d', 13),
            Node('e', 16),
            Node('f', 45)]
    heapq.heapify(heap)

    while len(heap) > 1:
        n1 = heapq.heappop(heap)
        n2 = heapq.heappop(heap)

        n = Node(None, n1.count + n2.count, left=n1, right=n2)
        heapq.heappush(heap, n)

    walk(heap[0], [])


if __name__ == '__main__':
    main()
