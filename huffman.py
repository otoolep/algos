#!/usr/bin/env python

import heapq

class Node(object):
    def __init__(self, char, count):
        self.char = char
        self.count = count

    def __le__(self, other):
        return self.count <= other.count

    def __lt__(self, other):
        return self.count < other.count

    def __str__(self):
        return '%c:%d' % (self.char, self.count)


def main():
    heap = [Node('c', 10),
            Node('d', 2),
            Node('f', 12),
            Node('g', 4),
            Node('x', 100),
            Node('a', 7)]
    heapq.heapify(heap)

    while True:
        try:
            print heapq.heappop(heap)
        except IndexError:
            return


if __name__ == '__main__':
    main()
