Directory contains Bash Scripts for the following tasks:
1. Exercise 1 : For evaluating an input string having mathematical expressions and rounding off to 4 decimal places.  
    Instructions to run:  
       ` $ ./exercise1.sh '5+50*3/20 + (17*2)/7'`  
         `17.3571`

2. Exercise 2 : For taking input as files having columns of numbers and print its Average. test.csv file was created for testing purposes.  
   Instructions to run:  
           `./exercise2.sh test.csv`  
            `1.3333333333333333`    
            `2.6666666666666665`    


For both the task, the Python Environment was used under BASH, where the eval() function was used for evaluating the mathematical expression,
and Pandas Dataframe was used in importing the values fromt he file whose average is need to be found.
