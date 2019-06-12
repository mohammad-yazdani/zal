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
    elif sys.argv[1] == 'debug':
        build()
        if len(sys.argv) < 3:
            print('Err: no in_stream passed for debug')
            exit(1)
        debug(sys.argv[2])

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
    run_shell(['mv', 'compile_commands.json', '..'])
    os.chdir('..')
    if err is None:
        print('Done!')

def debug(in_stream):
    run_shell(['./bin/scan', '<', in_stream], native=True)

run()

