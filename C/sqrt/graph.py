import matplotlib.pyplot as plt

colord = ['red', 'green', 'blue', 'orange','yellow','purple','pink']
c = 0;

allx = []
ally = []
while True:
    ex = []
    why = []
    a = input()
    while not a in ['out','nex']:
        temp = a.split(" ")
        ex.append(float(temp[0]))
        why.append(float(temp[1]))
        a = input()

    print('ex:')
    print(ex)
    print('why:')
    print(why)
    print()
    print(colord[c])
    if a == 'nex':
        allx.append(ex)
        ally.append(why)
        for i in range(len(allx)):
            plt.scatter(allx[i],ally[i],s=1,c=colord[i%len(colord)])
        plt.show()
        continue
    elif a == 'out':
        break

#print(ex)
#print(why)
