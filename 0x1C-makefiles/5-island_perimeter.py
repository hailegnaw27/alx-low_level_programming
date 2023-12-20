#!/usr/bin/python3
"""
code for island perimeter
"""


def neighbour(grid, b, a):
    """
       number of neighbour finder
    """
    nb = 4

    if (b > 0) and grid[b - 1][a]:
        nb -= 1
    if (a > 0) and grid[b][a - 1]:
        nb -= 1
    if (b < len(grid) - 1) and grid[b + 1][a]:
        nb -= 1
    if (a < len(grid[0]) - 1) and grid[b][a + 1]:
        nb -= 1
    return nb


def island_perimeter(grid):
    """
        find perimeter of island
    """
    peri = 0
    for b in range(len(grid)):
        for a in range(len(grid[0])):
            if grid[b][a] == 1:
                peri += neighbour(grid, b, a)
    return peri
