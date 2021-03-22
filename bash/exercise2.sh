#!/bin/bash
x=$1
python - <<START
import pandas as pd
df=pd.read_csv('$x',delimiter=',',header=None)
row,col=df.shape
for i in range(col):
 print(df[i].mean())
START

