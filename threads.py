import threading
import random

def fillMatrix (matrix, row, cols):
    for i in range(cols):
        matrix[row][i] = random.randint(1, 100)

matrix = [[0] * 3 for _ in range(3)]

threads = []

for i in range(3):
    thread = threading.Thread(target=fillMatrix, args=(matrix, i, 3))
    threads.append(thread)
    thread.start()

for thread in threads:
    thread.join()

for row in matrix:
    print(row)
