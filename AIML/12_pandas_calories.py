
import pandas as pd

# i) Create a pandas data frame for calories_data which displays the list of calories_consumed and  calories_burnt daywise.
calories_data = {
    'Day': ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday'],
    'Calories_Consumed': [2000, 2200, 2100, 2300, 2400],
    'Calories_Burnt': [1800, 2000, 1900, 2100, 2200]
}
df = pd.DataFrame(calories_data)
print("DataFrame for calories_data:")
print(df)

# ii) Add an additional column calories_remaining and calculate it and display
df['Calories_Remaining'] = df['Calories_Consumed'] - df['Calories_Burnt']
print("\nDataFrame with calories_remaining column:")
print(df)

# iii) Display calories_consumed and  calories_burnt daywise. Here, The days should not be a separate column. 
# Days should act as an index to the dataframe.
df.set_index('Day', inplace=True)
print("\nDataFrame with days as index:")
print(df)

# iv) Store the data frame to the csv file.
df.to_csv('calories_data.csv')
print("\nDataFrame has been saved to 'calories_data.csv'.")

# v) Display the pandas version.
print("\nPandas Version:", pd.__version__)
