package minsquare;


import java.util.Arrays;

// 시간복잡도: O(n)
class Solution {
    public int solution(int[][] sizes) {
        int answer = 0;
        int w = 0, h = 0;

        // O(n + 3)
        // 1. 정렬을 통해 가장 긴변을 기준으로 정렬합니다.
        for(int i = 0; i < sizes.length; i++) {
            if(sizes[i][0] < sizes[i][1]) {
                int temp = sizes[i][1];
                sizes[i][1] = sizes[i][0];
                sizes[i][0] = temp;
            }
        }

        // O(n)
        for(int i = 0; i < sizes.length; i++) {
            if(w < sizes[i][0]) {
                w =  sizes[i][0];
            }
            if(h < sizes[i][1]) {
                h =  sizes[i][1];
            }
        }

        answer = w * h; // O(1);
        return answer;
    }
}

class Solution2 {
    public int solution(int[][] sizes) {
        int w = 0, h = 0;
        for (int[] size : sizes) {
            w = Math.max(w, size[0]);
            h = Math.max(h, size[1]);
        }
        return w * h;
    }
}

class Solution3 {
    public int solution(int[][] sizes) {
        return Arrays.stream(sizes)
                .reduce((a, b) -> new int[] {
                        Math.max(Math.max(a[0], a[1]),
                                Math.max(b[0], b[1]))

                })
                .map(it -> it[0] * it[1]).get();
    }
}
public class MinSquare {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // 예제 1: 답 4000
        int[][] rects1 = {{60, 50}, {30, 70}, {60, 30}, {80, 40}};

        // 예제 2: 답 120
        int[][] rects2 = {{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}};

        // 예제 3: 답 133
        int[][] rects3 = {{14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11}};

        System.out.println(solution.solution(rects1));
        System.out.println(solution.solution(rects2));
        System.out.println(solution.solution(rects3));
    }
}
