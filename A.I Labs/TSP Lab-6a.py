# Implementation of Traveling Salesman Problem
# ____________________________________________
from sys import maxsize

# total number of cities 
V = 4 

def travellingSalesmanProblem(graph, s):
    # store all the cities except starting point city
    vertex = []
    for i in range(V):
        if i != s:
            vertex.append(i)
    # store minimum weight Hamiltonian Cycle
    min_path = maxsize

    while True:
        # store current Path weight(cost)
        current_pathweight = 0
    # compute current path weight
        k = s
        for i in range(len(vertex)):
            current_pathweight += graph[k][vertex[i]]
            k = vertex[i]
        current_pathweight += graph[k][s]
    # update minimum
        min_path = min(min_path, current_pathweight)
        if not next_permutation(vertex):
            break
    return min_path
   # next_permutation implementation


def next_permutation(L):
    n = len(L)
    i = n - 2
    while (i >= 0) and (L[i] >= L[i + 1]):
        i -= 1
    if (i == -1):
        return False
    j = i + 1
    while (j < n) and (L[j] > L[i]):
        j += 1
    j -= 1
    L[i], L[j] = L[j], L[i]
    left = i + 1
    right = n - 1
    while left < right:
        L[left], L[right] = L[right], L[left]
        left += 1
        right -= 1
    return True


# Driver Code
# ___________
if __name__ == "__main__":
    # matrix representation of graph
    graph = [[0, 10, 15, 20], [10, 0, 35, 25],
             [15, 35, 0, 30], [20, 25, 30, 0]]
    starting_point = 0
    print( "\nThe shortest path that salesman should take to traverse through a list of cities = ",travellingSalesmanProblem(graph, starting_point))
