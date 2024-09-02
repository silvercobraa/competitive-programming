import sys


def simulate(line):
    stack_size = 0
    idx = 1
    reg = line[0]
    print("L", line[0])
    while idx < len(line):
        if line[idx].isalpha():
            if line[idx+1].isalpha():
                print("ST $" + str(stack_size))
                stack_size += 1
                print("L", line[idx])
                idx += 1
            elif line[idx+1] == "+":
                print("A", line[idx])
                idx += 2
            elif line[idx+1] == "-":
                print("S", line[idx])
                idx += 2
            elif line[idx+1] == "*":
                print("M", line[idx])
                idx += 2
            elif line[idx+1] == "/":
                print("D", line[idx])
                idx += 2
            elif line[idx+1] == "@":
                print("ST $" + str(stack_size))
                print("L", line[idx])
                print("N")
                stack_size += 1
                idx += 2
            else:
                raise NotImplementedError(str(idx))
        else:
            if line[idx] == "@":
                print("N")
            elif line[idx] == "+":
                print("A $" + str(stack_size-1))
                stack_size -= 1
            elif line[idx] == "-":
                print("N")
                print("A $" + str(stack_size-1))
                stack_size -= 1
            elif line[idx] == "*":
                print("M $" + str(stack_size-1))
                stack_size -= 1
            elif line[idx] == "/":
                print("ST $" + str(stack_size))
                print("L $" + str(stack_size-1))
                print("D $" + str(stack_size))
                stack_size -= 1
            else:
                raise NotImplementedError(str(idx))
            idx += 1

print_newline = False    
for case, line in enumerate(sys.stdin):
    # print("CASE:", case)
    if print_newline:
        print("")
    else:
        print_newline = True
    simulate(line.strip())
