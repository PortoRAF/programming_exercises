import pandas as pd

##df = pd.read_csv('ZILLOW-Z77006_ZRISFRR.csv')
##df.set_index('Date',inplace=True)
##print(df.head())
##
###save dataframe in a new csv file
##df.to_csv('newcsv2.csv')
##df = pd.read_csv('newcsv2.csv')
###index set on original df is not passed to new file
##print(df.head())
##
###inform 'col 0' as index instead of setting it by name
##df = pd.read_csv('newcsv2.csv',index_col=0)
##print(df.head())
##
###set column name
##df.columns = ['Austin_HPI']
##print(df.head())
##
###new column name is carried to new file
##df.to_csv('newcsv3.csv')
##
###eliminate headers
##df.to_csv('newcsv4.csv', header=False)
##
###load df, name columns and set index
##df = pd.read_csv('newcsv4.csv', names=['Date','Austin_HPI'], index_col = 0)
##print(df.head())
##
###save df to new format
##df.to_html('example.html')

df = pd.read_csv('newcsv4.csv', names=['Date','Austin_HPI'])
print(df.head())

#rename column name
df.rename(columns={'Austin_HPI':'77006_HPI'}, inplace=True)
print(df.head())
