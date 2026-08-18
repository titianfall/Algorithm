package powergrid;

// 전력망을 둘로 나누기
class Solution {

    private int[][] wires;
    private boolean[] visited;

    // 시간 O(n^3), 공간 O(n) - n <= 100 >> 1,000,000
    /**
     * @Param n 송전탑 개수
     * @Param wires[송전탑v1][송전탑v2]
     * @return 두 전력망이 가지고 있는 송전탑 개수 차이
     */
    public int solution(int n, int[][] wires) {
        this.wires = wires;
        int answer = n; // 가장 큰 값에서 시작

        for(int skip = 0; skip < wires.length; skip++) {
            this.visited = new boolean[n + 1];

            // 1번 송전탑이 속한 쪽의 크기만 세면 반대쪽은 n - size 입니다.
            int size = makePowerGrid(1, skip);
            answer = Math.min(answer, Math.abs(n - 2 * size));
        }

        return answer;
    }

    /**
     * 송전탑의 개수를 반환하는 함수
     * @param now 현재 송전탑 번호
     * @param skip 끊어버린 전선의 인덱스
     */
    private int makePowerGrid(int now, int skip) {
        visited[now] = true;
        int size = 1; // 자기 자신

        for(int i = 0; i < wires.length; i++) {
            if(i == skip) continue; // 끊긴 전선은 없는 셈 칩니다.

            int v1 = wires[i][0];
            int v2 = wires[i][1];
            // 전선은 방향이 없으니 양쪽 다 확인합니다.
            if(v1 == now && !visited[v2]) size += makePowerGrid(v2, skip);
            if(v2 == now && !visited[v1]) size += makePowerGrid(v1, skip);
        }

        return size;
    }
}
public class PowerGrid {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] wires1 = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};
        System.out.println(sol.solution(9, wires1)); // 3

        int[][] wires2 = {{1, 2}, {2, 3}, {3, 4}};
        System.out.println(sol.solution(4, wires2)); // 0

        int[][] wires3 = {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}};
        System.out.println(sol.solution(7, wires3)); // 1
    }
}
