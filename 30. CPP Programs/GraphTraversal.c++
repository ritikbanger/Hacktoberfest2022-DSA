BFS(V):
visit virtualmark V as visited.
poush V on q (queue).
whiole q not empty:
u=pop(q)
for each node w adjacent to u and not yet visited.
    visit w and mark w as visited
    push w on q 

DFS(V):
    visit V and mark V as visited.
    push V on s (stack)

    while s not empty:
        u=stack.top()
         if u has no adjacent that is not visited, then pop u and continue the next iteration q = any node adjacent to u and not yet visited.
         visit w and mark w as visited
         push w on stack

         //recursive depth first search fo graphs.
         DFS(V):
         visit v and mark v as visited.
         for each w adjacent to V and not yet visited:
         DFS(w)