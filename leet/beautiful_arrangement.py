#!/usr/bin/env python

def ba(n, k):
    next_k = 1
    result = []
    for i in range(0,n):
        if len(result) == 0:
            result.append(i)
        else:
            result.append(result[i-1]+next_k)

        next_k += 1
        if next_k > k:
            next_k = 1

    return result


if __name__ == '__main__':
    print ba(10,3)
