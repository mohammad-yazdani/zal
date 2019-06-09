import subprocess
import sys
import os


executable = './hexer'

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

def debug():
    print('DEBUGGING:')
    _, err = run_shell(executable +' < test/SimpleAdd.x', native=True)
    if err is None:
        print('Done!')

def install():
    print('INSTALLING:')
    install_dir = os.path.expanduser('~/bin')
    _, err = run_shell(['cp', executable, install_dir])
    if err is None:
        print('Done!')

try:
    farg = sys.argv[1]
except:
    print('Usage: python testbench.py [build][install][debug]')
    exit(1)
if farg == 'build':
    build()
elif farg == 'debug':
    build()
    debug()
elif farg == 'install':
    build()
    install()
else:
    print('Usage: python testbench.py [build][install][debug]')
    exit(1)
