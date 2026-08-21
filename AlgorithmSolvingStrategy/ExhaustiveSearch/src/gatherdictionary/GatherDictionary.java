package gatherdictionary;

class Solution {
    private final String[] VOWELS = {"A", "E", "I", "O", "U"};
    private static final int MAX_LENGTH = 5;

    private int count = 0;
    private int answer = 0;

    public int solution(String word) {
        count = 0;
        answer = 0;
        findOrder("", word);
        return answer;
    }

    // 사전 순서 = DFS 방문 순서. 단어를 만들 때마다 count를 올리고, 목표와 같으면 그 값이 답.
    private void findOrder(String current, String target) {
        // 단어를 찾은경우
        if (current.equals(target)) {
            answer = count;
            return;
        }
        // 예외: 단어를 찾지 못한경우
        if (current.length() == MAX_LENGTH) {
            return;
        }
        for (String vowel : VOWELS) {
            count++;
            findOrder(current + vowel, target);
        }
    }
}

public class GatherDictionary {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.solution("AAAAE"));
    }
}
