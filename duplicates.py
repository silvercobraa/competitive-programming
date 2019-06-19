import os

d = {}
for root, dirs, files in os.walk('.', topdown=False):
    for name in files:
        fn = os.path.join(root, name)
        basename, extension = os.path.splitext(name)
        basename = basename.lower()
        if basename in d and extension not in {'.txt', '.out', '.md'}:
            print(d[basename])
            print(fn)
        else:
            d[basename] = fn
