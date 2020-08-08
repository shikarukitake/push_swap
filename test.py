#!/Users/sdagger/.brew/bin/python3
import sys
import random
import os

# colors
LIGHT_MAGENTA = "\x1b[95m"
END = "\x1b[0m"

# function to parse flags
def     parse_flags(args):
    flags = []
    for i in range(4, len(args)):
        flags.append(args[i])
    return flags

if __name__ == "__main__":
    if len(sys.argv) >= 4:
        try:
            start = int(sys.argv[1])
            end = int(sys.argv[2])
            count = int(sys.argv[3])
            if start > end:
                step = -1
            elif start == end:
                print("start and end can't be equal")
                exit()
            else:    
                step = 1
            arr_nums = [str(i) for i in range(start, end, step)]
            flags = parse_flags(sys.argv)
            if len(flags) > 0:
                arr_nums += flags
            for i in range(count):
                print(f"{LIGHT_MAGENTA}TEST {i}{END}\n")
                # print("Test " + str(i))
                random.shuffle(arr_nums)
                arr = " ".join(list(arr_nums))
                arr = '"' + arr + '"'
                os.system("./push_swap " + arr + " | ./checker " + arr)
                print()
        except:
            print("Usage: startnum endnum countoftests [flags for push_swap and checker]")
    else:
        print("Usage: startnum endnum countoftests [flags for push_swap and checker]")
