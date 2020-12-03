'''
    Advent of Code 2020 Day 3
    Author: Ethan Gingrich

    I have decided to scrap Javascript because I don't really feel like setting it
    up in html and such, I'll find another language to learn instead and tack it on 
    to the end. Had trouble with this one because I didn't really understand the file
    format (input) and how to traverse it, so I looked up some help from some classmates
    who also so AOC. Pretty happy with this overall, learned a lot about file traversing,
    something I hadn't done a lot of in python before. :)
'''

with open ("input.txt") as slope:
    lines = [[c for c in line.strip()] for line in slope.readlines()]

def count_trees(dx, dy):
    x, y = 0, 0
    count = 0
    for y in range (0, len(lines), dy):
        if lines[y][x%len(lines[0])] == '#':
            count += 1
        x += dx
    return count

slopes = [(1,1), (3,1), (5,1), (7,1), (1,2)]
total = 1
for dx, dy in slopes:
    total *= count_trees (dx, dy)
print (count_trees (3,1)) # For part 1
print (total)             # For part 2
slope.close ()
