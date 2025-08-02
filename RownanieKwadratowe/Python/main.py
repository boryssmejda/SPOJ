import sys

def getNumberOfSolutions(a: float, b: float, c: float) -> int:
    delta = b * b - 4 * a * c

    if (delta > 0):
        return 2
    elif (delta < 0):
        return 0
    else:
        return 1

for line in sys.stdin:
    a, b, c = map(float, line.split())
    print(getNumberOfSolutions(a, b, c))

