MAX = 0x3f3f3f3f

size = 0
graph = []
parent = []

def bfs(s, e):
    visit = [False for _ in range(size)]
    visit[s] = True
    q = [s]

    while len(q) != 0:
        node = q.pop(0)
        for i in range(size):
            if graph[node][i] != 0 and not visit[i]:
                parent[i] = node
                q.append(i)
                visit[i] = True

    return visit[e]

def solution(entrances, exits, path):
    global size
    global graph
    global parent

    size = len(path)
    graph = path
    parent = [-1 for _ in range(size)]

    ans = 0

    for s in entrances:
        for e in exits:
            while bfs(s, e):
                flow = MAX
                node = e
                while node != s:
                    flow = min(flow, graph[parent[node]][node])
                    graph[parent[node]][node] -= flow
                    graph[node][parent[node]] += flow
                    node = parent[node]

                ans += flow
    
    return ans
