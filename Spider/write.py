
import os
filename='test.txt'

if os.path.exists(filename):
    os.remove(filename)

def writefiles(data):
    with open(filename, 'a') as f:
        f.write(data)


str='''\t%s
    %s
    %s
'''%(18,19,50)
writefiles(str)