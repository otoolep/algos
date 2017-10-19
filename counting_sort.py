#!/usr/bin/env python


def counting_sort(a, n):
    buckets = {}

    keys = [i for i in range(0, n)]

    # Get a count of each value.
    for i in a:
        try:
            buckets[i] +=1
        except KeyError:
            buckets[i] = 1

    # Now dump them out.
    for i in keys:
        try:
            c = buckets[i]
        except KeyError:
            continue

        for j in range(0, c):
            print i,


def main():
    counting_sort([3, 6, 2, 4, 4, 7, 2, 3, 9, 5, 2, 1, 2, 9, 4, 3, 8], 10)


if __name__ == '__main__':
    main()
