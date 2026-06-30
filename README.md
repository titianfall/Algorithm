# Algorithm

최소 하루 한 문제씩 꾸준히 풀고, 풀이에서 배운 핵심을 다시 찾기 쉽게 정리하는 저장소입니다.

## README 업데이트 방식

새 문제를 풀면 아래 세 곳만 필요에 따라 수정합니다.

1. **최근 풀이 요약**에 문제 한 줄 추가
2. **주제별 문제 바로가기**에서 비슷한 유형 아래에 링크 추가
3. 나중에 다시 볼 만한 실수나 개념이면 **다시 볼 포인트**에 짧게 기록

## 최근 풀이 요약

| 날짜 | 문제 | 핵심 주제 | 요약 | 파일 |
| --- | --- | --- | --- | --- |
| 2026-06-30 | 피크닉 | 완전 탐색, 중복 제거 | 짝짓기 문제에서 중복 세기 오류 원인과 가장 번호 빠른 학생 고정으로 해결 | [picnic.cpp](<AlgorithmSolvingStrategy/BruteForce/picnic.cpp>), [explain.md](<AlgorithmSolvingStrategy/BruteForce/explain.md>) |
| 2026-06-30 | 무식하게 풀기 | 완전 탐색, 재귀 | 완전 탐색의 의미와 재귀 호출의 기본 구조를 정리 | [explain.md](<AlgorithmSolvingStrategy/BruteForce/explain.md>) |
| 2026-06-27 | BOGGLE | 완전 탐색, DFS, 8방향 탐색 | 5x5 보드에서 단어를 만들 수 있는지 모든 시작점과 8방향으로 탐색 | [boggle.cpp](<AlgorithmSolvingStrategy/BruteForce/boggle.cpp>) |
| 2026-06-27 | 음식 고르기 | 부분집합, 백트래킹 | 각 음식을 선택하거나 선택하지 않는 모든 경우를 탐색해 모두가 먹을 수 있는 최소 메뉴 수 계산 | [selectFood.cpp](<2026.06/27/selectFood.cpp>) |
| 2026-06-27 | 조합 선택 연습 | 재귀, 조합 | n개 중 k개를 고르는 선택 과정을 재귀로 연습 | [findToPick.cpp](<2026.06/27/findToPick.cpp>) |
| 2026-06-06 | 롤케이크 자르기 | 해시, 카운팅 | 왼쪽 종류 수와 오른쪽 종류 수를 유지하며 공평한 자르기 위치 계산 | [rollCakeCut.cpp](<2026.06/06/rollCakeCut.cpp>) |
| 2026-06-04 | 전화번호 목록 | 정렬, 문자열 접두어 | 정렬 후 인접한 번호만 비교해 접두어 관계 확인 | [phoneBookList.cpp](<2026.06/04/phoneBookList.cpp>) |
| 2026-06-03 | 행렬 곱셈 | 구현, 2차원 배열 | 행렬의 곱셈 조건과 인덱스 계산 연습 | [matrixMultiplication.cpp](<2026.06/03/matrixMultiplication.cpp>) |
| 2026-06-03 | 거스름돈 | 그리디 | 큰 단위부터 차례대로 사용해 필요한 동전 수 계산 | [cash.cpp](<2026.06/03/cash.cpp>) |
| 2026-06-02 | 기능개발 | 큐, 묶음 처리 | 배포까지 남은 날짜를 계산하고 앞 작업 기준으로 함께 배포되는 개수 묶기 | [functionDev.cpp](<2026.06/02/functionDev.cpp>) |
| 2026-06-01 | 피로도 | DFS, 완전 탐색 | 가능한 던전 방문 순서를 모두 시도해 최대 방문 수 계산 | [fatiuge.cpp](<2026.06/01/fatiuge.cpp>) |

## 주제별 문제 바로가기

### 완전 탐색 / DFS / 백트래킹

- [boggle.cpp](<AlgorithmSolvingStrategy/BruteForce/boggle.cpp>): 모든 시작점에서 8방향 재귀 탐색, 시간복잡도 O(8^n) 분석 포함
- [picnic.cpp](<AlgorithmSolvingStrategy/BruteForce/picnic.cpp>): 짝짓기 중복 세기 오류 → 가장 번호 빠른 학생 고정으로 해결
- [pick.cpp](<AlgorithmSolvingStrategy/BruteForce/pick.cpp>): 무식하게 풀기 예제
- [selectFood.cpp](<2026.06/27/selectFood.cpp>): 음식 선택/미선택 부분집합 탐색
- [findToPick.cpp](<2026.06/27/findToPick.cpp>): 조합을 재귀로 생성
- [fatiuge.cpp](<2026.06/01/fatiuge.cpp>): 던전 방문 순서 완전 탐색
- [targetNumber.cpp](<2026.05/20260514/targetNumber.cpp>): 더하기/빼기 선택 DFS
- [dfs.cpp](<2026.05/20260514/dfs.cpp>): DFS 기본 연습
- [expressNumber.cpp](<2026.05/20260512/expressNumber.cpp>): 숫자 표현 경우의 수 탐색

### 해시 / 맵 / 집합

- [rollCakeCut.cpp](<2026.06/06/rollCakeCut.cpp>): `unordered_map`, `unordered_set`으로 토핑 종류 수 비교
- [clothes.cpp](<2026.05/20260530/clothes.cpp>): 의상 종류별 경우의 수 계산
- [sale.cpp](<2026.05/20260528/sale.cpp>): 할인 품목 카운팅
- [selectTangerine.cpp](<2026.05/20260516/selectTangerine.cpp>): 귤 크기별 개수 세기

### 스택 / 큐 / 시뮬레이션

- [functionDev.cpp](<2026.06/02/functionDev.cpp>): 앞 작업 기준 배포 묶음 만들기
- [process.cpp](<2026.06/05/process.cpp>): 프로세스 우선순위 큐 시뮬레이션
- [deletePair.cpp](<2026.05/20260518/deletePair.cpp>): 스택으로 짝 제거
- [isParentheses.cpp](<2026.05/20260508/isParentheses.cpp>): 괄호 유효성 검사
- [rotateParenthese.cpp](<2026.05/20260513/rotateParenthese.cpp>): 회전한 괄호 문자열 검사
- [predictedBracket.cpp](<2026.05/20260528/predictedBracket.cpp>): 토너먼트 라운드 진행 시뮬레이션
- [serverIncreaseCount.cpp](<2026.05/20260510/serverIncreaseCount.cpp>): 서버 증설 횟수 시뮬레이션

### 정렬 / 그리디

- [phoneBookList.cpp](<2026.06/04/phoneBookList.cpp>): 정렬 후 인접 문자열 접두어 비교
- [cash.cpp](<2026.06/03/cash.cpp>): 큰 동전부터 사용하는 그리디
- [lifeboat.cpp](<2026.05/20260525/lifeboat.cpp>): 정렬 후 투 포인터로 구명보트 수 계산
- [makeMin.cpp](<2026.05/20260508/makeMin.cpp>): 두 배열을 정렬해 곱의 합 최소화
- [H-index.cpp](<2026.05/20260531/H-index.cpp>): 정렬 기반 H-index 계산
- [arrayCut.cpp](<2026.05/20260529/arrayCut.cpp>): 배열 구간 처리
- [flexibleWork.cpp](<2026.05/20260505/flexibleWork.cpp>): 출근 인정 조건 계산
- [notEqualNums.cpp](<2026.05/20260505/notEqualNums.cpp>): 연속으로 같은 숫자 제거

### 문자열

- [phoneBookList.cpp](<2026.06/04/phoneBookList.cpp>): 문자열 접두어 비교
- [JadenCase.cpp](<2026.05/20260508/JadenCase.cpp>): 단어별 대소문자 변환
- [binaryTranslation.cpp](<2026.05/20260508/binaryTranslation.cpp>): 이진 변환 반복
- [wordChain.cpp](<2026.05/20260528/wordChain.cpp>): 끝말잇기 규칙 검사
- [translate.cpp](<2026.05/20260506/translate.cpp>): 문자열 변환
- [UpperLowercase.cpp](<2026.05/20260503/UpperLowercase.cpp>): 대소문자 처리
- [strInStr.cpp](<2026.05/20260503/strInStr.cpp>): 부분 문자열 확인
- [stringToInt.cpp](<2026.05/20260503/stringToInt.cpp>): 문자열을 정수로 변환
- [deleteGather.cpp](<2026.05/20260503/deleteGather.cpp>): 모음 제거
- [letter.cpp](<2026.05/20260503/letter.cpp>): 문자열 길이 활용

### 그래프 / 경로

- [EscapeMaze.cpp](<2026.05/20260507/EscapeMaze.cpp>): 미로 탈출 경로 탐색
- [hidingCactus.cpp](<2026.05/20260509/hidingCactus.cpp>): 숨바꼭질 계열 이동 탐색

### 수학 / 구현

- [matrixMultiplication.cpp](<2026.06/03/matrixMultiplication.cpp>): 행렬 곱셈 구현
- [nextBigNum.cpp](<2026.05/20260512/nextBigNum.cpp>): 다음 큰 숫자 찾기
- [sumOfDivisors.cpp](<2026.05/20260511/sumOfDivisors.cpp>): 약수 합
- [isSqrt.cpp](<2026.05/20260511/isSqrt.cpp>): 제곱수 판별
- [sumOfDigits.cpp](<2026.05/20260511/sumOfDigits.cpp>): 자릿수 합
- [reverseDigitToArr.cpp](<2026.05/20260511/reverseDigitToArr.cpp>): 자연수 뒤집어 배열 만들기
- [descendingOrder.cpp](<2026.05/20260511/descendingOrder.cpp>): 자릿수 내림차순 정렬
- [LCM.cpp](<2026.05/20260525/LCM.cpp>): 최소공배수
- [fibo.cpp](<2026.05/20260517/fibo.cpp>): 피보나치 수
- [jump.cpp](<2026.05/20260525/jump.cpp>): 점프 경우의 수
- [jumpAndTeleport.cpp](<2026.05/20260520/jumpAndTeleport.cpp>): 순간이동과 건전지 사용량
- [carpet.cpp](<2026.05/20260520/carpet.cpp>): 카펫 가로세로 찾기
- [sequence.cpp](<2026.05/20260526/sequence.cpp>): 연속 부분 수열 처리
- [advance.cpp](<2026.05/20260509/advance.cpp>): 진법/수열 구현 연습
- [maxMin.cpp](<2026.05/20260507/maxMin.cpp>): 최댓값과 최솟값 처리

### 기초 문제

- [addDigits.cpp](<2026.05/20260503/addDigits.cpp>): 자릿수 더하기
- [ant.cpp](<2026.05/20260503/ant.cpp>): 개미 군단
- [bacterial.cpp](<2026.05/20260503/bacterial.cpp>): 세균 증식
- [cutVector.cpp](<2026.05/20260503/cutVector.cpp>): 배열 자르기
- [diceNumber.cpp](<2026.05/20260503/diceNumber.cpp>): 주사위 개수
- [duplicatedNumber.cpp](<2026.05/20260503/duplicatedNumber.cpp>): 중복 개수 세기
- [evenadd.cpp](<2026.05/20260503/evenadd.cpp>): 짝수 합
- [factor.cpp](<2026.05/20260503/factor.cpp>): 약수 구하기
- [findMax.cpp](<2026.05/20260503/findMax.cpp>): 최댓값 찾기
- [getQuadrant.cpp](<2026.05/20260503/getQuadrant.cpp>): 사분면 구하기
- [isSquareNumber.cpp](<2026.05/20260503/isSquareNumber.cpp>): 제곱수 판별
- [makeMax.cpp](<2026.05/20260503/makeMax.cpp>): 최댓값 만들기
- [multiple.cpp](<2026.05/20260503/multiple.cpp>): 배수 판별
- [onlyNumberAdd.cpp](<2026.05/20260503/onlyNumberAdd.cpp>): 없는 숫자 더하기
- [orderedPair.cpp](<2026.05/20260503/orderedPair.cpp>): 순서쌍 개수
- [rockSisserPaper.cpp](<2026.05/20260503/rockSisserPaper.cpp>): 가위바위보
- [similarity.cpp](<2026.05/20260503/similarity.cpp>): 배열 유사도
- [triangleAC.cpp](<2026.05/20260503/triangleAC.cpp>): 삼각형 조건
- [vectorLength.cpp](<2026.05/20260503/vectorLength.cpp>): 벡터 길이 계산

## 다시 볼 포인트

- C++ range-based for는 `vector`, `string`, 배열처럼 순회 가능한 대상에만 사용할 수 있다.
- 완전 탐색은 먼저 가능한 모든 경우를 정확히 세우고, 느릴 때 최적화를 붙인다.
- 재귀 함수는 항상 기저 사례를 먼저 정한다.
- 백트래킹은 `선택 -> 재귀 호출 -> 선택 취소` 흐름을 지킨다.
- 문자열 접두어 문제는 정렬하면 비교 대상이 인접하게 모이는 경우가 많다.
- 큰 입력에서는 `erase`, 중첩 반복, 문자열 복사처럼 숨어 있는 비용을 먼저 의심한다.

## 문제 추가 템플릿

```md
| YYYY-MM-DD | 문제 이름 | 핵심 주제 | 한 줄 요약 | 파일 링크 |
```
