import numpy as np

starts = [1000, 1000]
ends = [1100, 1350]

diff = np.absolute(np.subtract(ends,starts))

print(diff)