import matplotlib.pyplot as plt
import csv
import sys

for j in sys.argv:
	j=j[1]

x1=[]
y1=[]
with open('db.csv' , 'r',encoding="utf8") as csv_file:
	csv_reader = csv.reader(csv_file, delimiter=',')
	for row in csv_reader:
		x1.append(row[0])
		y1.append(row[1])

for i in range(len(x1)):
	x1[i]=float(x1[i])

for i in range(len(y1)):
	y1[i]=float(y1[i])



# plotting the line 1 points
plt.plot(x1, y1, label = "User 1")

# line 2 points
x2 = [0,30]
y2 = [sum(y1)/(len(y1)+1),sum(y1)/(len(y1)+1)]
# plotting the line 2 points
plt.plot(x2, y2, label = "User 2" ,linestyle='dashed')

x3=[0,30]
y3=[j,j]

plt.plot(x3, y3, label= "Input",linestyle='dashed',markerfacecolor='green')

# naming the x axis
plt.xlabel('x - axis')
# naming the y axis
plt.ylabel('y - axis')
# giving a title to my graph
plt.title('Prediction Graph')

# show a legend on the plot
plt.legend()

# function to show the plot
plt.show()
