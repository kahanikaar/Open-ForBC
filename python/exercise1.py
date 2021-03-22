#!/usr/bin/env python3

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
