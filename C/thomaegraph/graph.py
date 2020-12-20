import matplotlib.pyplot as plt
ex = []
why = []
a = input()
while a != 'out':
    temp = a.split(" ")
    ex.append(float(temp[0]))
    why.append(float(temp[1]))
    a = input()
print(ex)
print(why)
plt.scatter(ex, why, s=1)
plt.show()
