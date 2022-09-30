import math
import os
import random
import re
import sys

def hourglassSum(arr):
    sums = []
    for i in range(len(arr)-2):
        for j in range(len(arr)-2):
            sums.append(arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2])
    return(max(sums))
  
#Link to the question 
#https://www.hackerrank.com/challenges/2d-array/copy-from/260006172  
