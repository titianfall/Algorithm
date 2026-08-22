package networkcount;

import java.util.ArrayDeque;
import java.util.Queue;
// 시간복잡도: Θ(n²) (최선, 평균, 최악 모두 동일하다는 기호)
class Solution2 {
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
                answer++;
                bfs(i);
            }
        }
        return answer;
    }

    public void bfs(int index) {
        Queue<Integer> queue = new ArrayDeque<>(); // ArrayList 보다 빠르다고합니다.

        visited[index] = true;
        queue.offer(index);
        while(!queue.isEmpty()) {
            int current = queue.poll();

            for(int i = 0; i < n; i++) {
                if(!visited[i] && computers[current][i] == 1) {
                    visited[i] = true; // 재귀호출이 아님
                    queue.offer(i);
                }
            }
        }

    }
}
public class NetworkCountBFS {
    public static void main(String[] args) {
        int sol1 = new Solution2().solution(3, new int[][]{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});
        System.out.println(sol1); // 2

        int sol2 = new Solution2().solution(3, new int[][]{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}});
        System.out.println(sol2); // 1
    }
}
