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

#load dataset
dataset = pd.read_csv("50_Startups.csv")
X = dataset.iloc[:,:-1].values
y = dataset.iloc[:,4].values

#'State' column is categorical and must be split into dummy variables