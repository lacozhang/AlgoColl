#!/usr/bin/python

def getallpos(n,m):
    a = []
    while n:
        a.append(n%m)
        n = n/m
    a.reverse()
    return a

def rnot0(a):
    for i in reversed(range(len(a))):
        if a[i] != 0:
            return i

def firstuse(n, level):

    if 1 == level :
        return [n]
    c = [0]
    c.extend(firstuse(n, level-1))
    return c

def nextnumber(n):
    
    a = getallpos(n,10)
    i = rnot0(a)
    if i == 0:
        return n
    level = len(a)-i
    s1 = sum(a)
    s2 = sum(a[:i])
    a[i-1] = a[i-1] + 1
    j = firstuse(s1-s2-1, level)
    c = a[:i]
    c.extend(j)
    return c
    
