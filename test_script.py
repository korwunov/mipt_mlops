import numpy as np
import gauss_jordan_ext

A = [[2, 1], [1, 3]]
B = [[3], [4]]

result_ext = gauss_jordan_ext.gauss_jordan(A, B)
print("Результат из биндингов:", result_ext)

A_np = np.array(A)
B_np = np.array(B)
result_np = np.linalg.solve(A_np, B_np)
print("Результат из numpy:", result_np.T[0])
