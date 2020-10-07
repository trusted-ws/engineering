# *
# Binary to C Array
# *

import sys

def getField(filename: str):
    ic = 0
    with open(filename, 'rb') as info:
        while(byte := info.read(1)):
            ic += 1
    return ic

def main(filename: str):
    col = 0
    byten = 0
    size = getField(filename)

    with open(filename, 'rb') as payload:
        print('unsigned char payload[%s] = {' % str(size))
        sys.stdout.write('    ')
        while(byte := payload.read(1)):
            string = "0x" + ''.join('{:02x}'.format(ord(byte)))
            if(byten == size - 1):
                sys.stdout.write("%s\n" % string)
            else:
                sys.stdout.write("%s, " % string)
            col += 1
            byten += 1
            if(col >= 10):
                sys.stdout.write('\n    ');
                col = 0

        print('};')
        #print(f'{byten} bytes')

if(__name__ == '__main__'):
    if(len(sys.argv) != 2):
        print("Please give me a filename!")
        exit(1)

    main(sys.argv[1])

