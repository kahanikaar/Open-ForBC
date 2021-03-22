#!/usr/bin/env python3

'''
Python Script for implementing CLI tool for finding intersection between two list of values (common among them) where input is provided as string or random values are used.

Function intersection
   Parameters:
       values: String of lists whose intersection is to be found.

Function intersect
    Parameters:
       args: Getting the string of lists from command line interface.

CLI Instructions:
usage: exercise2.py [-h] [--val [VAL [VAL ...]]] [--random]

intersect

optional arguments:
  -h, --help            show this help message and exit
  --val [VAL [VAL ...]], -v [VAL [VAL ...]]
                        Enter source string of list
  --random, -r          intersect using random values

'''

import argparse
import sys
import json
import random


def intersection(values):
    values=json.loads(values)
    elements=[]
    for i in values:
        elements.append(set(list(map(int,i.split(",")))))
    print(list(elements[0] & elements[1]))


def intersect(args):
    print("intersect Tool started running!")
    if args.val:
        for elements in args.val:
            print("intersecting on input string of lists")
            intersection(elements)

    if args.random:
          print("intersecting on random values")
          a = [str(random.randint(0,100)) for i in range(0, random.randint(5, 15))]
          b = [str(random.randint(0,100)) for i in range(0, random.randint(5, 15))]
          random_input = '['+'"'+', '.join(a)+'"'+', '+'"'+', '.join(b)+'"'+']'
          print("Random Input: "+random_input)
          print("intersect Values: ")
          intersection(random_input)

    return "intersect Successful. Application terminating!"



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='intersect')
    parser.add_argument('--val','-v',type=str, nargs="*", help="Enter source string of list")
    parser.add_argument('--random','-r',action='store_true',help='intersect using random values')

    args=parser.parse_args()
    sys.stdout.write(str(intersect(args)))
