
import pandas as pd

# i) Create a pandas data frame for the string “He is a good person” and display the dataframe.
string_data = "He is a good person"
df_string = pd.DataFrame(list(string_data.split()), columns=['Letters'])
print("DataFrame for string 'He is a good person':")
print(df_string)

# ii) Create a pandas data frame for car_data which displays the list of car names and their corresponding prices.
car_data = {
    'Car': ['Toyota', 'Honda', 'Ford', 'Tesla'],
    'Price': [25000, 28000, 23000, 60000]
}
df_cars = pd.DataFrame(car_data)
print("\nDataFrame for car_data:")
print(df_cars)

# Display list of car names and display the details of the second car using index.
print("\nList of car names:")
print(df_cars['Car'])

print("\nDetails of the second car:")
print(df_cars.iloc[1])

# iii) Append the new car_data to the existing data frame.
new_car_data = {
    'Car': ['BMW', 'Mercedes'],
    'Price': [45000, 55000]
}
df_new_cars = pd.DataFrame(new_car_data)
df_cars = df_cars.append(df_new_cars, ignore_index=True)
print("\nDataFrame after appending new car_data:")
print(df_cars)

# iv) Update any of the data in data frame.
df_cars.loc[2, 'Price'] = 24000  # Update the price of Ford
print("\nDataFrame after updating the price of Ford:")
print(df_cars)

# v) Store the data frame to the csv file.
df_cars.to_csv('car_data.csv', index=False)
print("\nDataFrame has been saved to 'car_data.csv'.")

# vi) Reading a csv file and storing in another dataframe and display it.
df_read = pd.read_csv('car_data.csv')
print("\nDataFrame read from 'car_data.csv':")
print(df_read)
