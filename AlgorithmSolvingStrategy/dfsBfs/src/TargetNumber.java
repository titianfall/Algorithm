// 타겟 넘버 - DFS 완전탐색, 시간 O(2^n) / 공간 O(n)
class Solution {
    private int answer = 0;
    private int[] numbers;
    private int target;
    public int solution(int[] numbers, int target) {
        this.numbers = numbers;
        this.target = target;
        makeTarget(0, 0);

        return answer;
    }

    public void makeTarget(int current, int index) {
        // 기저 사례1: 모든 정수를 사용했으면서 목표 수에 도달했을 경우만
        if(index == numbers.length) {
            if(current == target) answer++;
            return;
        }
        // 덧셈 뺄쎔 모두 dfs
        makeTarget(current + numbers[index], index + 1);
        makeTarget(current - numbers[index], index + 1);
    }
}
public class TargetNumber {
    public static void main(String[] args) {
        // answer가 인스턴스 필드라 테스트마다 새 Solution 필요
        System.out.println(new Solution().solution(new int[]{1, 1, 1, 1, 1}, 3)); // 5
        System.out.println(new Solution().solution(new int[]{4, 1, 2, 1}, 4));    // 2
    }
}
