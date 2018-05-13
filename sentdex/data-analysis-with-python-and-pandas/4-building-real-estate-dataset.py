import quandl
import pandas as pd

##api_key = 'yxhU4tGsGDxBFPwUZxFf'
##df = quandl.get('FMAC/HPI_AK', authtoken=api_key)
##print(df.head())

f_states = pd.read_html('https://simple.wikipedia.org/wiki/List_of_U.S._states')

#this is a list
#print(f_states)

#this is a dataframe
#print(f_states[0])

#this is a column
#print(f_states[0][1])

#this is a line
#print(f_states[0][1][1])

for abbv in f_states[0][1][1:]:
    print("FMAC/HPI_"+str(abbv))
