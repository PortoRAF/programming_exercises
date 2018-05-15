#Simple Linear Regression

#Importing libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#Loading dataset
dataset = pd.read_csv("Salary_Data.csv")
X = dataset.iloc[:,:-1].values
y = dataset.iloc[:,1].values

#Splitting Training and Testing sets
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X,y, 
                                                    test_size=1/3, 
                                                    random_state=0)

'''
Simple Linear Regression
----------------------------------------------
y = b0 + b1 * x1

y: dependent variable
x1: independent variable
b1: coefficient for independent variable (unit change for the variable, how the variable changes)
b0: constant term

In simple linear regression there's only one independent variable

For our dataset:
Salary = b0 + b1 * Experience

    ^
    |  .  /
    | .  /  .
    |  ./  .
    | ./. .
    |./.
    |/  .
    |.
   /|
  __|__________________>
    |
    
b0: point where the line crosses the vertical axis
b1: slope of the line

Ordinary Linear Regression
sum(yi - y)^2 -> minimal
This model tries to find the smallest sum of the squared differences between
the observed data and the estimated line
'''

#Fitting Simple Linear Regression to the Training Set
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(X_train, y_train)

#Predicting the Test Set results
y_pred = regressor.predict(X_test)

#Visualizing the Training Set results
plt.scatter(X_train,y_train,color='red')
plt.plot(X_train,regressor.predict(X_train),color='blue')
plt.title('Salary vc Experience (Training Set)')
plt.xlabel('Years of experience')
plt.ylabel('Salaries')
plt.show()

#Visualizing the Test Set results
plt.scatter(X_test,y_test,color='red')
plt.plot(X_train,regressor.predict(X_train),color='blue')
plt.title('Salary vc Experience (Test Set)')
plt.xlabel('Years of experience')
plt.ylabel('Salaries')
plt.show()

#Visualizing the Predicted Set results
plt.scatter(X_test,y_pred,color='red')
plt.plot(X_train,regressor.predict(X_train),color='blue')
plt.title('Salary vc Experience (Predicted Set)')
plt.xlabel('Years of experience')
plt.ylabel('Salaries')
plt.show()