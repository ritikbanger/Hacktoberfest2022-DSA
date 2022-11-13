f = open('example.txt', 'r')
d = f.readlines()
for i in d:
    print('Before appending text\n', i)
f.close
f = open('example.txt', 'a')
f.write('Added the text now.')
f.close
f = open('example.txt', 'r')
d = f.readlines()
print('After appending text!')
for i in d:
    print(i)