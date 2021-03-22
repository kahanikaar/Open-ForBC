#!/usr/bin/env python3

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


def intersept(args):
    print("Intersept Tool started running!")
    if args.val:
        for elements in args.val:
            print("Intersepting on input string of lists")
            intersection(elements)

    if args.random:
          print("Intersepting on random values")
          a = [str(random.randint(0,100)) for i in range(0, random.randint(5, 15))]
          b = [str(random.randint(0,100)) for i in range(0, random.randint(5, 15))]
          random_input = '['+'"'+', '.join(a)+'"'+', '+'"'+', '.join(b)+'"'+']'
          print("Random Input: "+random_input)
          print("Intersept Values: ")
          intersection(random_input)

    return "Intersept Successful. Application terminating!"






if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Intersept')
    parser.add_argument('--val','-v',type=str, nargs="*", help="Enter source string of list")
    parser.add_argument('--random','-r',action='store_true',help='Intersept using random values')

    args=parser.parse_args()
    sys.stdout.write(str(intersept(args)))
