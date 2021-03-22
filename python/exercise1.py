#!/usr/bin/env python3

'''
Python script for CLI tool which accepts absolute path of dummy.py file and then imports it relatively.

Function absoluter()
    Parameters:
        args (Contains the path of the file from command line arguments)
    Finds the relative path for the file with respect to the file path and then imports it relatively.

CLI Instructions
$ ./exercise1.py --help
usage: exercise1.py [-h] [--path PATH]

Absoluter - Loading a Python module relatively when absolute path is given

optional arguments:
  -h, --help            show this help message and exit
  --path PATH, -p PATH  Enter Absolute path of your dummy file

'''

import argparse
import sys
import os
from importlib.machinery import SourceFileLoader


def absoluter(args):
    absolute_path=args.path
    relative_path = os.path.relpath(absolute_path, os.getcwd())
    print(relative_path)
    module= SourceFileLoader("dummy",relative_path).load_module()
    module.run()



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Absoluter - Loading a Python module relatively when absolute path is given')
    parser.add_argument('--path','-p',type=str, help="Enter Absolute path of your dummy file")

    args=parser.parse_args()
    sys.stdout.write(str(absoluter(args)))
