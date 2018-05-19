import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

dataset = pd.read_csv("")
X = dataset.iloc[:,:-1].values
y = dataset.iloc[:,2].values

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y,
                                                    test_size=0.2,
                                                    random_size=0)

#fit Polynomial Regression to dataset
#Create your regressor here

#predict a new result with Polynomial Regression model
y_pred = regressor.predict(6.5)

#plot Polynomial Regression results
plt.scatter(X, y, color = 'red')
plt.plot(X, regressor.predict(X), color = 'blue')
plt.title('Regression Model')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()

#plot Polynomial Regression results (for higher resolution)
X_grid = np.arange(min(X), max(X), 0.1)
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(X, y, color = 'red')
plt.plot(X_grid, regressor.predict(X_grid), color = 'blue')
plt.title('Regression Model')
plt.xlabel('Position Level')
plt.ylabel('Salary')
plt.show()