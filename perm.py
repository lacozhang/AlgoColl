#!env python

def perm(words):
    
    if 1 == len(words):
        return words
    splits = [(words[i], words[:i] + words[i+1:]) for i in range(len(words))]
    res = set()
    for a, b in splits:
        print a, b
        for i in perm(b):
            res.add(a + i)
    return res
