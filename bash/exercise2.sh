#!/bin/bash
awk -F"," '{
             for (i=1;i<=NF;i++)
              { sum[i]+=$i;
                count[i]=count[i]+length($i);
              }}
            END{ 
            for (i=1;i<=NF;i++)
            { printf sum[i]/count[i]"," }; 
              printf "\n"
            }' < $1
