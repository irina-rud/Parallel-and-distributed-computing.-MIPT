import sys
import numpy as np
#1. координата x  2. координата y
#3. питательная среда концентрация (целое число unsigned long) 4. вещество 1 концентрация (unsigned long) 5. вещество 2 концентрация (unsigned long)
#6. бактерия вид 1 (0 — нет, 1 - присутствует ) [7. раунды голодания (unsigned int) ]
#8. бактерия вид 2 (0 — нет, 1 — присутствует) предусмотреть возможность коментариев начинающихся символом '#' и пустых строк.
n = 1000
print(str(n) + " x " + str(n))
for i in range(n):
    for j in range(n):
        p = np.random.random_integers(10, size = 6)
        if (p[3] % 2 == 1) & (p[5] % 2 == 1):
            if (p[3] > p[5]):
                p[3]  = 0
            else:
                p[5] = 0
        print(str(i) + " "+ str(j)+ " " + str(p[0])+ " " + str(p[1]) +" " +  str(p[2])
              + " " + str(p[3] % 2)+ " " + str(p[4])+ " " + str(p[5] % 2))