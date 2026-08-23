package gameshortestpath;

import java.util.*;

class Solution2 {
    int[][] maps;
    int answer;
    int[] dr = {0, 0, 1, -1}; // 동, 서, 남, 북
    int[] dc = {1, -1, 0, 0}; // 동, 서, 남, 북

    public int solution(int[][] maps) {
        this.answer = -1;
        this.maps = maps;
        boolean[][] visited = new boolean[maps.length][maps[0].length];

        // 캐릭터는 0, 0위치에서 bfs 탐색을 시작합니다.
        answer = bfs(visited);

        return answer;
    }

    // 시간복잡도 O(N * M) = O(방향(4) * 칸수(N * M)) 최대 40,000 탐색
    // 공간복잡도 O(N * M) 큐
    // 반드시 최단경로가 된다.(DFS와의 차이)
    public int bfs(boolean[][] visited) {
        Queue<int []> queue = new ArrayDeque<>();

        queue.offer(new int[]{0, 0, 1}); // 행, 열, 거리
        visited[0][0] = true;

        while(!queue.isEmpty()) {
            int[] cur =  queue.poll();
            int row = cur[0];
            int col = cur[1];
            int count = cur[2];

            if(row == maps.length - 1 && col == maps[0].length - 1) {
                return count;
            }

            for(int i = 0; i < 4; i++) {
                int nextRow = row + dr[i];
                int nextCol = col + dc[i];

                if(nextRow < 0  || nextRow >= maps.length ||
                        nextCol < 0 || nextCol >= maps[0].length) {
                    continue;
                }

                if(maps[nextRow][nextCol] == 0 || visited[nextRow][nextCol]) {
                    continue;
                }

                visited[nextRow][nextCol] = true;
                queue.offer(new int[]{nextRow, nextCol, count + 1});
            }
        }
        return -1;
    }
}

class GameShortestPathBFS {
    public static void main(String[] args) {
        Solution2 solution = new Solution2();

        int[][] maps1 = {
                {1, 0, 1, 1, 1},
                {1, 0, 1, 0, 1},
                {1, 0, 1, 1, 1},
                {1, 1, 1, 0, 1},
                {0, 0, 0, 0, 1}
        };

        int[][] maps2 = {
                {1, 0, 1, 1, 1},
                {1, 0, 1, 0, 1},
                {1, 0, 1, 1, 1},
                {1, 1, 1, 0, 0},
                {0, 0, 0, 0, 1}
        };

        System.out.println(solution.solution(maps1)); // 11
        System.out.println(solution.solution(maps2)); // -1
    }
}
