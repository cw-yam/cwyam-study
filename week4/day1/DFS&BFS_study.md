# DFS와 BFS기초 공부 정리
- DFS(깊이 우선 탐색)와 BFS(너비 우선 탐색)의 개념, 특징, 구현에 대해 공부하고 정리한 내용입니다.

## 그래프 탐색
- 하나의 정점으로부터 시작하여 차례대로 모든 정점들을 한 번씩 방문하는 것

---
# DFS
## DFS(깊이 우선 탐색)의 개념
- 그래프 탐색 알고리즘 중 하나
- 루트 노드(혹은 다른 임의의 노드)에서 시작해서 다음 분기(branch)로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법
- 모든 노드를 방문 하고자 하는 경우 이 방법을 선택

## DFS(깊이 우선 탐색)의 특징
- 자기 자신을 호출하는 순환 알고리즘의 형태를 가지고 있음
- 그래프 탐색을 할 경우 어떤 노드를 방문했었는지 여부를 반드시 검사해야한다. (검사하지 않을 경우 무한루프)
- 시간 복잡도 --> 인접 리스트로 표현된 그래프: O(N+E), 인접 행렬로 표현된 그래프: O(N^2)


## DFS(깊이 우선 탐색)의 구현
### 1. 순환 호출 이용

```cpp
void search(Node root) {
  if (root == null) return;
  // 1. root 노드 방문
  visit(root);
  root.visited = true; // 1-1. 방문한 노드를 표시
  // 2. root 노드와 인접한 정점을 모두 방문
  for each (Node n in root.adjacent) {
    if (n.visited == false) { // 4. 방문하지 않은 정점을 찾는다.
      search(n); // 3. root 노드와 인접한 정점 정점을 시작 정점으로 DFS를 시작
    }
  }
}
```

### 2. 스택 이용 (pseudocode)

```cpp
function DFS_stack(start):
    create empty stack S
    push start into S

    while S is not empty:
        node = S.pop()

        if node is not visited:
            mark node as visited
            process(node)  // (예: 출력)

            for each neighbor in reversed(adj[node]):
                if neighbor is not visited:
                    S.push(neighbor)
```
---
# BFS
## BFS(너비 우선 탐색)의 개념
- 그래프 탐색 알고리즘 중 하나
- 루트 노드(혹은 다른 임의의 노드)에서 시작해서 인접한 노드를 먼저 탐색하는 방법
- 두 노드 사이의 최단 경로나 임의의 경로를 찾고 있을 때 선택

## BFS(너비 우선 탐색)의 특징
- 재귀적으로 작동하지 않고 직관적이지 않다
- 그래프 탐색을 할 경우 어떤 노드를 방문했었는지 여부를 반드시 검사해야한다. (검사하지 않을 경우 무한루프)
- 시간 복잡도 --> 인접 리스트로 표현된 그래프: O(N+E), 인접 행렬로 표현된 그래프: O(N^2)

## BFS(너비 우선 탐색)의 구현
### 큐 이용

```cpp
void search(Node root) {
  Queue queue = new Queue();
  root.marked = true; // (방문한 노드 체크)
  queue.enqueue(root); // 1-1. 큐의 끝에 추가

  // 3. 큐가 소진될 때까지 계속한다.
  while (!queue.isEmpty()) {
    Node r = queue.dequeue(); // 큐의 앞에서 노드 추출
    visit(r); // 2-1. 큐에서 추출한 노드 방문
    // 2-2. 큐에서 꺼낸 노드와 인접한 노드들을 모두 차례로 방문한다.
    foreach (Node n in r.adjacent) {
      if (n.marked == false) {
        n.marked = true; // (방문한 노드 체크)
        queue.enqueue(n); // 2-3. 큐의 끝에 추가
      }
    }
  }
}
```
## 출처
- https://gmlwjd9405.github.io/2018/08/14/algorithm-dfs.html
- https://gmlwjd9405.github.io/2018/08/15/algorithm-bfs.html
