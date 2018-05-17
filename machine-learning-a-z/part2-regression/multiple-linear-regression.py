#Multiple Linear Regression
'''
Multiple Linear Regression model

y = b0 + b1 * x1 + b2 * x2 + b3 * x3 + ...

y: dependent variable
b0: constant
bn: coefficients
xn: independent variables

Assumptions of a linear regression:
1. Linearity
2. Homoscedasticity
3. Multivariate normality
4. Independence of errors
5. Lack of multicollinearity

Methods of building models:
1. All-in
2. Backward Elimination       \
3. Forwards Selection          > Stepwise Regression
4. Bidirectional Elimination  /
5. Score Comparison - comparer all possible models
'''
#import libraries
import pandas as pd
import numpy as nd
import matplotlib.pyplot as plt

#load dataset
dataset = pd.read_csv("50_Startups.csv")
X = dataset.iloc[:,:-1].values
y = dataset.iloc[:,4].values

#encode categorical data
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
labelencoder_X = LabelEncoder()
X[:,3] = labelencoder_X.fit_transform(X[:,3])
onehotencoder = OneHotEncoder(categorical_features=[3])
X = onehotencoder.fit_transform(X).toarray()

#avoid the Dummy Variable Trap
#Remove the first column to avoid redundant dependencies
#Python library for linear regression takes care for the Dummy Variable Trap, 
#but that's not the case for other libraries
X = X[:, 1:]

#split the data
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y,
                                                    test_size=0.2,
                                                    random_state=0)

'''
There's no need to use feature scaling in multiple linear regression, Python
library deals with it automatically
'''

#fit Multiple Linear Regression to the Training Set
from sklearn.linear_model import LinearRegression
regressor = LinearRegression() #create a linear regression object
regressor.fit(X_train, y_train) #fit the object to the training set

#predict the Test Set results
y_pred = regressor.predict(X_test)