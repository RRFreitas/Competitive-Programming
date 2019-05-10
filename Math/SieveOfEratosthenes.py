n = int(input())

p = 2

primes = [True] * (n + 1)

while p * p < n:
    if primes[p]:
        for i in range(p * p, n + 1, p):
            primes[i] = False
    p += 1

print()
for i in range(2, n+1):
    if primes[i]: print(i)
