#!/usr/bin/env python

def stringToBool(s):
    return s == '1'

def countEval(s, result):
    '''
    Takes a string and a bool, returns an int.
    '''
    if len(s) == 0:
        return 0
    if len(s) == 1:
        if stringToBool(s) == result:
            return 1
        return 0

    ways = 0
    for i in range(1, len(s), 2):
        c = s[i]
        left = s[0:i]
        right = s[i+1:len(s)]

        leftTrue = countEval(left, True)
        leftFalse = countEval(left, False)
        rightTrue = countEval(right, True)
        rightFalse = countEval(right, False)
        total = (leftTrue + leftFalse) * (rightTrue + rightFalse)

        totalTrue = 0
        if c == '^':
            totalTrue = leftTrue * rightFalse + leftFalse * rightTrue
        elif c == '&':
            totalTrue = leftTrue * rightTrue
        elif c == '|':
            totalTrue = leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse

        if result:
            subWays = totalTrue
        else:
            subWays = total - totalTrue

        ways+= subWays

    return ways

print countEval('1^0|0|1', False)
print countEval('0&0&0&1^1|0', True)
