#!/usr/bin/env python

import pdb

def _perms(src, out, used):
    if len(out) == len(src):
        print out
        return

    for i in range(0, len(src)):
        if used[i]:
            continue
        out.append(src[i])
        used[i] = True
        _perms(src, out, used)
        used[i] = False
        del out[-1]

def perms(src):
    used = {}
    for i in range(0, len(src)):
        used[i] = False
    out = []

    _perms(src, out, used)

if __name__ == '__main__':
    perms(['a', 'b', 'c'])
