package gameshortestpath;

class Solution {
    int[][] maps;
    int answer;
    public int solution(int[][] maps) {
        this.answer = Integer.MAX_VALUE;
        this.maps = maps;
        boolean[][] visited = new boolean[maps.length][maps[0].length];

        // 캐릭터는 0, 0위치에서 dfs 탐색을 시작합니다.
        dfs(0, 0, 1, visited);

        if(answer == Integer.MAX_VALUE) {
            answer = -1;
        }
        return answer;
    }

    // 시간복잡도 O(3^(N * M)) - 시간초과
    // 공간복잡도 O(N * M)
    public void dfs(int row, int col, int count, boolean [][] visited) {
        // 유효한 행, 열이 아닐경우
        if(col < 0 || col >= maps.length ||
                row < 0 || row >= maps[0].length
        ) return;

        // 벽 or 지나온 길
        if(maps[row][col] == 0 || visited[row][col]) return;

        // 기저 사례: 목적지에 도달했을 경우
        if(row == maps.length - 1 && col == maps[0].length - 1) {
            answer = Math.min(answer, count);
            return;
        }
        visited[row][col] = true;

        // 탐색은 동, 서, 남, 북 모두 되어야한다.
        dfs(row, col + 1, count + 1, visited); // 동
        dfs(row, col - 1, count + 1, visited); // 서
        dfs(row + 1, col, count + 1, visited); // 남
        dfs(row - 1, col, count + 1, visited); // 북
        visited[row][col] = false; // 원상복구
    }
}

class GameShortestPathDFS {
    public static void main(String[] args) {
        Solution solution = new Solution();

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
