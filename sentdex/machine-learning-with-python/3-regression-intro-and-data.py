import pandas as pd
import quandl
import math

# df -> dataframe
df = quandl.get('WIKI/GOOGL')
#pick only meaninful columns
df = df[['Adj. Open','Adj. High','Adj. Low','Adj. Close','Adj. Volume']]
#generate other interesting data
df['HL_PCT'] = (df['Adj. High'] - df['Adj. Close']) / df['Adj. Close'] * 100.0
df['PCT_change'] = (df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open'] * 100.0

#rewrite dataframe with new calculated data
df = df[['Adj. Close','HL_PCT','PCT_change','Adj. Volume']]

forecast_col = 'Adj. Close'
#in ML you can't work with N/A, so replace with any number
df.fillna(-99999, inplace=True) 
#use only 10% of whole dataframe
forecast_out = int(math.ceil(0.01*len(df)))

df['label'] = df[forecast_col].shift(-forecast_out)
df.dropna(inplace=True)
print(df.head())

df = df.shift(-35)
print(df.head())
