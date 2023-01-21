# basics/python/src/types/arrays.py


# ------------------------------------------------------------------------
#     arrays  -   arrays in python
# ------------------------------------------------------------------------

# python lists are dynamic and homogenous

a = [1, 2, 3, 4, 5, 6, 7, 8, 9]
b = [1, "2", 3.0]

# index array
c = a[0]

# index from end of array
d = a[-1]

# slice array
e = a[2:5] # inclusive of first index (2) exclusive of second (5)
f = a[:4] # : indicates all elements up to
g = a[3:] # : indicates all elements past

# length of array
h = len(a)

# iterate through array
for el in a:
    print(el)

for i in range(len(a)):
    print(a[i])

# print array
print(a)

# multidimensional array
j = [
    [0, 1, 2, 3, 4],
    [5, 6, 7, 8, 9],
    [10, 11, 12, 13, 14],
    [15, 16, 17, 18, 19],
    [20, 21, 22, 23, 25],
]

for row in j:
    for col in row:
        print(col, end=", ")
    print()

# list comprehension
k = [i * 5 for i in range(10)]

# tuples, immutable
l = (1, 2, 3)

# sets, no duplicates
m = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
m = set(m)
print(m)