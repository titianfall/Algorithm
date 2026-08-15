package decimalfind;

import java.util.HashSet;
import java.util.Set;

// numbers: 숫자가 적힌 문자열
// 만들수 있는 소수 개수
class Solution {
    private String numbers;
    private boolean[] used;
    private Set<Integer> made;

    // 숫자는 앞으로 뒤로 모두 붙을수있다.
    // 시간 O(n! * √(10^n)), 공간 O(n!) - n <= 7 이라 사실상 상수
    public int solution(String numbers) {
        this.numbers = numbers;
        this.used = new boolean[numbers.length()];
        this.made = new HashSet<>();

        makeNumbers(""); // '' + '' 산술 연산 방지

        int answer = 0;
        for (int number : made) {
            if (isDecimal(number)) {
                answer++;
            }
        }
        return answer;
    }

    // 조각을 통해 숫자를 만듭니다.
    // 시간 O(n * n!) - 만들어지는 수가 약 e * n!개 (n=7 이면 13,700개)
    private void makeNumbers(String buffer) {
        // 아직 아무 조각도 안 붙인 최초 진입은 수가 아니므로 건너뜁니다.
        if (!buffer.isEmpty()) {
            made.add(Integer.parseInt(buffer)); // Integer.parseInt("011")시 11이 되므로 0 예외처리는 패스
        }

        for (int i = 0; i < numbers.length(); i++) {
            // 기저 사례: 모든 수를 사용하고 있을경우
            if (used[i]) continue;

            used[i] = true; // 조각 사용
            makeNumbers(buffer + numbers.charAt(i));
            used[i] = false; // 반환
        }
    }
    // 소수 판정
    // 시간 O(√n)
    public boolean isDecimal(int n) {
        if (n < 2) return false;
        // 약수는 i * i <= n 까지만 확인하면 됩니다.
        for (int i = 2; i * i <= n; i++) {
            if ((n % i) == 0) return false;
        }
        return true;
    }
}

public class IsDecimal {
    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.solution("17")); // 3
        System.out.println(solution.solution("011")); // 2

    }
}
