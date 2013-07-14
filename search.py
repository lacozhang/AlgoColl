#!/usr/bin/python

def sample(x):
    return pow(x-1, 2)+3

def dichotomous_search(iL, iR, epsilon, func):
    interval = iR - iL
    size = epsilon*0.01
    cnt = 1
    while abs(interval) > epsilon:
        left = iL + interval/2.0 - size
        right = iL + interval/2.0 + size
        vl = func(left)
        vr = func(right)
        if vl < vr:
            iR = right
        elif vl > vr:
            iL = left
        else:
            iL, iR=left, right
        interval = iR - iL
        cnt += 1
    return (cnt, (iL+iR)/2.0)

def fibonacci(n, seq):
    a,b=1.0,2.0
    i = 2
    seq.extend([1.0, a, b])
    while i <= n:
        c = a + b
        seq.append(c)
        (a, b) = (b, c)
        i += 1
    return None

sequence = []


def fibonacci_search(iL, iR, n, func):

    fibonacci(n, sequence)
    k = 1
    intkp1 = (sequence[n-1]/sequence[n])*(iR-iL)
    (a, b) = (iR-intkp1, iL+intkp1)
    (fa, fb) = (func(a), func(b))
    
    while k < n-2:
        intkp2 = (sequence[n-k-1]/sequence[n-k])*intkp1
        if fa < fb:
            iR = b
            (an, bn) = (iR-intkp2, a)
            (fa, fb) = (func(an), fa)
        elif fa >= fb:
            iL = a
            (an, bn) = (b, iL+intkp2)
            (fa, fb) = (fb, func(fb))
        intkp1 = intkp2
        (a, b) = (an, bn)
        k += 1
    
    return (a, b)
