import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

dataset = pd.read_csv("Position_Salaries.csv")
X = dataset.iloc[:,1:2].values
y = dataset.iloc[:,2].values

#Dataset is too small to be split into training and test sets
'''
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y,
                                                    test_size=0.2,
                                                    random_size=0)
'''

#fit Linear Regression to dataset
from sklearn.linear_model import LinearRegression
linear_regressor = LinearRegression()
linear_regressor.fit(X, y)

#fit Polynomial Regression to dataset
from sklearn.preprocessing import PolynomialFeatures
poly_regressor = PolynomialFeatures(degree=4)
X_poly = poly_regressor.fit_transform(X)
linear_regressor_2 = LinearRegression()
linear_regressor_2.fit(X_poly, y)

#plot Linear Regression results
plt.scatter(X, y, color = 'red')
plt.plot(X, linear_regressor.predict(X), color = 'blue')
plt.title('Polynomial demonstration (Linear Regression Model)')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()

#plot Polynomial Regression results
X_grid = np.arange(min(X), max(X), 0.1)
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(X, y, color = 'red')
plt.plot(X_grid, linear_regressor_2.predict(poly_regressor.fit_transform(X_grid)), color = 'blue')
plt.title('Polynomial demonstration (Polynomial Regression Model)')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()

#predict a new result with Linear Regression model
linear_regressor.predict(6.5)

#predict a new result with Polynomial Regression model
linear_regressor_2.predict(poly_regressor.fit_transform(6.5))