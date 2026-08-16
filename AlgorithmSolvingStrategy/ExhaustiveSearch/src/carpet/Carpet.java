package carpet;

import java.util.Arrays;

// 긴 변(width)을 3부터 올리며 찾습니다.
// 시간 O(brown), 공간 O(1)
class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = {-1, -1}; // 에러 확인용
        int totalCount = brown + yellow;

        for(int width = 3; width < brown; width++) {
            if(totalCount % width != 0) continue;

            int height = totalCount / width;
            if(height >= 3 && width >= height && isTotalAmount(width, height, brown)) {
                answer[0] = width;
                answer[1] = height;
                break;
            }
        }

        return answer;
    }

    // 테두리 타일 수가 brown 과 맞는지 확인합니다.
    // 네 모서리가 가로줄과 세로줄에 두 번씩 세어지므로 -4
    private boolean isTotalAmount(int width, int height, int brown) {
        int border = width * 2 + height * 2 - 4;
        return border == brown;
    }
}

// 탐색 없이 이차방정식으로 바로 구합니다.
//   brown = 2w + 2h - 4   ->  합 s = w + h = brown / 2 + 2
//   w * h = brown + yellow ->  곱 p
//   합과 곱을 알면 w, h 는 x^2 - s*x + p = 0 의 두 근
//   x = (s +- √(s^2 - 4p)) / 2   (큰 근이 가로, 작은 근이 세로)
class Solution2 {
    // 시간 O(1), 공간 O(1)
    public int[] solution(int brown, int yellow) {
        int sum = brown / 2 + 2;        // w + h
        int product = brown + yellow;   // w * h

        // 판별식. 문제 조건상 항상 완전제곱수라 정수 제곱근이 딱 떨어집니다.
        int diff = (int) Math.sqrt((long) sum * sum - 4L * product); // w - h

        return new int[]{(sum + diff) / 2, (sum - diff) / 2};
    }
}

// Solution 과 같은 완전탐색이되 짧은 변(height)을 기준으로 돕니다.
// width = totalCount / height 라서 width >= height 가 자동으로 보장되고,
// 그 덕에 height >= 3 / width >= height 조건이 둘 다 사라집니다.
class Solution3 {
    // 시간 O(√(brown + yellow)), 공간 O(1)
    public int[] solution(int brown, int yellow) {
        int totalCount = brown + yellow;

        // 짧은 변은 √넓이를 넘을 수 없습니다.
        for (int height = 3; height * height <= totalCount; height++) {
            if (totalCount % height != 0) continue;

            int width = totalCount / height;
            if (isBrownMatch(width, height, brown)) {
                return new int[]{width, height};
            }
        }

        return new int[]{-1, -1}; // 에러 확인용
    }

    private boolean isBrownMatch(int width, int height, int brown) {
        return width * 2 + height * 2 - 4 == brown;
    }
}

public class Carpet {
    public static void main(String[] args) {
        Solution s = new Solution();
        Solution2 s2 = new Solution2();
        Solution3 s3 = new Solution3();

        // 뒤 셋은 brown 최댓값(5000) 기준의 큰 카펫 (정사각형 / 가로로 긴 / 아주 길쭉한)
        int[][] cases = {{10, 2}, {8, 1}, {24, 24}, {5000, 1560001}, {5000, 999000}, {5000, 2497}};
        for (int[] c : cases) {
            System.out.printf("brown=%-5d yellow=%-8d -> 완전탐색 %-14s 이차방정식 %-14s 짧은변탐색 %s%n",
                    c[0], c[1],
                    Arrays.toString(s.solution(c[0], c[1])),
                    Arrays.toString(s2.solution(c[0], c[1])),
                    Arrays.toString(s3.solution(c[0], c[1])));
        }
    }
}
