./bench.py build
cp ./build/compile_commands.json .
gdb --args ./build/scan ./misc/simple_add.c 

valgrind --log-fd=1 ./build/scan ./misc/simple_add.c | grep lost

