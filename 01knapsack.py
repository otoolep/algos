#!/usr/bin/env python

C = 800 # Capacity
W = [200, 175, 80, 150, 200, 350, 75, 5, 15, 60, 10, 20, 30, 40, 60, 35, 72, 64, 10, 50, 110, 5, 85] # Weights
V = [1000, 750, 220, 35, 280, 15, 450, 275, 150, 45, 60, 100, 120, 40, 20, 300, 200, 50, 5, 1, 90, 96, 35] # Values

# Neat trick which allows tuples to be keys, which
# is an effective multi-dim array.
MEMOS = {}

def ks(idx, capacity):
    # No more items left, or no more capacity.
    if idx == 0 or capacity == 0:
        return 0

    # Insufficient capacity to add current item.
    if W[idx] > capacity:
        return 0

    # Value of knapsack with skipping current object.
    opt1 = ks(idx-1, capacity)

    # Value of knapsack adding current object.
    opt2 = V[idx] + ks(idx-1, capacity-W[idx])

    return max(opt1, opt2)

def ks_memoized(idx, capacity):
    try:
        return MEMOS[idx, capacity]
    except KeyError:
        # No more items left, or no more capacity.
        if idx == 0 or capacity == 0:
            return 0

        # Insufficient capacity to add current item.
        if W[idx] > capacity:
            return 0

        # Value of knapsack with skipping current object.
        opt1 = ks(idx-1, capacity)

        # Value of knapsack adding current object.
        opt2 = V[idx] + ks(idx-1, capacity-W[idx])

        MEMOS[idx, capacity] = max(opt1, opt2)

    return MEMOS[idx, capacity]

def main():
    if len(W) != len(V):
        raise Exception('bad data %d %d' % (len(W), len(V)))

    # Call with empty knapsack and last item.
    print ks_memoized(len(W) - 1, C)

if __name__ == '__main__':
    main()
