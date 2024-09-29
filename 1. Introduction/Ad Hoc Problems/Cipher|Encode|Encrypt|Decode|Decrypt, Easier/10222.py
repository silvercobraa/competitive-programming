import sys

source = "ertyuiop[]dfghjkl;'\\cvbnm,./"
target = "qwertyuiopasdfghjkl;zxcvbnm,"
tr = str.maketrans(source, target)
print(sys.stdin.read().lower().translate(tr), end="")