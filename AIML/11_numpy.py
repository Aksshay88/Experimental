
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# i) Create a 2-D array with 3 rows and 4 columns using numpy and display its shape, itemsize, and datatype 
arr = np.arange(12).reshape(3, 4)
print("Original Array:")
print(arr)
print("Shape:", arr.shape)
print("Itemsize:", arr.itemsize)
print("Datatype:", arr.dtype)

# Reshape the array as 4 rows and 3 columns
arr_reshaped = arr.reshape(4, 3)
print("\nArray after reshaping:")
print(arr_reshaped)

# ii) Create a 1-D array named profit with set of values. Similarly Create another 1-D array named sales. 
# Calculate Profit Margin Ratio. [Formula: profit/sales]
profit = np.array([1000, 2000, 1500, 1800, 2500])
sales = np.array([5000, 6000, 5500, 7000, 8000])
profit_margin_ratio = profit / sales
print("\nProfit Margin Ratio:", profit_margin_ratio)

# iii) Use matplotlib library to plot a graph by taking any random set of values for x & y.
x = np.random.rand(10)
y = np.random.rand(10)
plt.plot(x, y)
plt.title("Random Plot")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()

# iv) Reading any csv file and storing in a dataframe
df = pd.read_csv('example.csv')
print("\nDataFrame from example.csv:")
print(df)

# v) Use matplotlib library to plot a scatter plot with two different classes specifying different color for classes.
class1_x = np.random.rand(10)
class1_y = np.random.rand(10)
class2_x = np.random.rand(10)
class2_y = np.random.rand(10)

plt.scatter(class1_x, class1_y, color='red', label='Class 1')
plt.scatter(class2_x, class2_y, color='blue', label='Class 2')
plt.title("Scatter Plot with Two Classes")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()
