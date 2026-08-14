package mockexam;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int[] answers) {
        int [][] students = {
                {1, 2, 3, 4 ,5},
                {2, 1, 2, 3, 2, 4, 2, 5},
                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
        };

        int [] answerCount = {0, 0, 0};
        int length = answers.length;
        int studentLength = students.length;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < studentLength; j++) {
                if (answers[i] == students[j][i % students[j].length]) {
                    answerCount[j]++;
                }
            }
        }

        // 가장 높은 점수를 받은 학생이 여럿일 경우 오름차순으로 정렬합니다.
        // 최댓값 계산
        int max = Math.max(answerCount[0], Math.max(answerCount[1], answerCount[2]));

        // 최대 점수를 가진 학생수 저장 - 순서대로 저장
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < studentLength; i++) {
            if(answerCount[i] == max) {
                list.add(i + 1);
            }
        }

        // return list.stream().mapToInt(i -> i.intValue()).toArray();
        int [] answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }
}
public class MockExam {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int [] answers1 = {1, 2, 3, 4, 5};
        int[] solution1 = solution.solution(answers1);
        System.out.print("[");
        for (int sol : solution1) {
            System.out.print(sol) ;
        }
        System.out.println("]");

        int [] answers2 = {1, 3, 2, 4, 2};
        int[] solution2 = solution.solution(answers2);
        System.out.print("[");
        for (int sol : solution2) {
            System.out.print(sol + ",") ;
        }
        System.out.println("]");
    }
}
