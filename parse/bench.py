#!/usr/bin/python

import sys
import subprocess
import os

def run():
    if len(sys.argv) < 2:
        print('Err: no arguments passed')
        exit(1)
    elif sys.argv[1] == 'build':
        build()

def run_shell(arguments, native=False):
    process = subprocess.Popen(arguments, shell=native)
    out, err = process.communicate()
    return out, err

def build():
    print('BUILDING:')
    run_shell(['mkdir', '-p', 'build'])
    os.chdir('build')
    run_shell(['cmake', '..'])
    _, err = run_shell(['make'])
    os.chdir('..')
    if err is None:
        print('Done!')

run()

