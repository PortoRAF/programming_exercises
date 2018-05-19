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
import numpy as np
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

#build the optimal model using Backward Elimination
import statsmodels.formula.api as sm
#statsmodels library needs a column of 1s to be added at the beginning of the
#features matrix to represent x0 from the multiple linear regression formula
X = np.append(arr=np.ones((50,1)).astype(int),values=X,axis=1)
#create an optimal X matrix that will hold the most significant features
X_opt = X[:, [0,1,2,3,4,5]] #matrix with all original columns
SL = 0.05

#create function to remove columns with p > SL
def backwardElimination(X, SL):
    numVars = len(X[0]) #take number of columns
    #apply method until the pvalues of all features are lower than SL
    for i in range(0, numVars):
        regressor_OLS = sm.OLS(endog=y, exog=X).fit()
        maxpVar = max(regressor_OLS.pvalues) #take the largest p value found
        if maxpVar > SL:
            #find the largest p value in features matrix and remove its column
            for j in range(0, numVars - i):
                if regressor_OLS.pvalues[j] == maxpVar:
                    X = np.delete(X, j, 1)
        else: #if all p values are lower than SL, exit loop and return matrix
            break
        
    regressor_OLS.summary()
    return X

#function call
X_modeled = backwardElimination(X_opt, SL)