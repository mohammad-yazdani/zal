import os

def print_enum(sym):
    print("case " + sym + ":\n\tslog(\"" + sym + "\\n\");\n\tbreak;")

print_enum("test")

f = open("src/shared/grammer_0.txt")
lines = f.read().split("\n")

for line in lines:
    print_enum(line)
