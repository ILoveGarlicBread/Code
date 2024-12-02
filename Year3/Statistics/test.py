import statistics
import math

num = [
    21.06,
    22.24,
    20.62,
    21.66,
    21.23,
    23.86,
    23.82,
    20.30,
    21.52,
    21.52,
    21.91,
    23.14,
    20.02,
    22.20,
    21.20,
    22.37,
    22.19,
    22.34,
    23.36,
    23.44,
]
sum = 20
mean = round(statistics.mean(num), 3)
stdev = round(statistics.stdev(num), 3)
me = round(1.96 * stdev / math.sqrt(sum), 3)
print("Mean ", mean)
print("Standard deviation: ", stdev)
print("Margin of Error: ", me)
