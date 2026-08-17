package fatigue;

class Solution {
    /**
     * 피로도 - 완전탐색
     * @k 현재 피로도,
     * @dungeons {최소 필요 피로도, 소모 피로도}
     */
    // 시간 O(n * n!), 공간 O(n) - n <= 8 이라 사실상 상수
    public int solution(int k, int[][] dungeons) {
        int answer = -1; // 탐색 횟수

        // 사용 가능한 던전의 수
        boolean[] used = new boolean[dungeons.length];
        for(int i = 0; i < dungeons.length; i++){
            used[i] = false; // 모든 던전은 사용 가능합니다.
        }

        answer = dungeonExploration(k, dungeons, used);

        return answer;
    }

    // 던전 탐색 횟수 반환
    // 시간 O(n * n!) - 호출 횟수가 최악에 약 e * n!회 (n=8 이면 109,601회), 호출당 for 루프 n회
    //   피로도가 모자라면 가지가 죽으므로 실제로는 훨씬 적습니다. (예제는 9회)
    private int dungeonExploration(int k, int[][] dungeons, boolean[] used) {
        int length = used.length;
        int count = 0;
        // 완전 탐색
        for(int i = 0; i < length; i++) {
            // 사용중인(true) 경우
            if(used[i]) continue;

            // 1. 요구 최소 피로도(dungeons[i][0])보다 높을 경우
            if(k >= dungeons[i][0]) {
                used[i] = true; // 던전 입장 (true)
                // 2. 탐색 횟수 증가, 피로도 감소
                count = Math.max(count, 1 + dungeonExploration(k - dungeons[i][1], dungeons, used));
            }
            // 4. 던전 아웃
            used[i] = false;
        }
        return count;
    }
}

public class Fatigue {

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] dungeons = {{80, 20}, {50, 40}, {30, 10}};

        System.out.println(sol.solution(80, dungeons)); // 3
    }

}
