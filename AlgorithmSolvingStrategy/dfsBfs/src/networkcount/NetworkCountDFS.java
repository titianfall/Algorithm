package networkcount;

// 시간복잡도 최악 최선 평균 모두 O(n^2)
class Solution {
    int n;
    int[][] computers;
    boolean[] visited;
    int answer = 0;
    public int solution(int n, int[][] computers) {
        this.n = n;
        this.computers = computers;
        visited = new boolean[n];

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                answer++; // 네트워크 개수 증가
                dfs(i); // 이어진 네트워크 탐색 및 표기
            }
        }
        return answer;
    }

    public void dfs(int index) {
        visited[index] = true;

        for(int i = 0; i < n; i++) {
            // 방문 안했으면서, 연결되어있다면
            if(!visited[i] && computers[index][i] == 1) {
                dfs(i); // 나와 상대방을 연결
            }
        }
    }
}
public class NetworkCountDFS {
    public static void main(String[] args) {
        int sol1 = new Solution().solution(3, new int[][]{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});
        System.out.println(sol1); // 2

        int sol2 = new Solution().solution(3, new int[][]{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}});
        System.out.println(sol2); // 1
    }
}
