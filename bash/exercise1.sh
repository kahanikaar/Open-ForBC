#!/bin/bash
x=$1
python - <<START
import os
print(round(eval('$x'),4))
START

