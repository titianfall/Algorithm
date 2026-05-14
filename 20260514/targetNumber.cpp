// 깊이/너비 우선 탐색(DFS/BFS) - 타겟 넘버
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void bfs(vector<int>& numbers, int target, int sum, int vertex){
    if(vertex == numbers.size()){
        if(sum == target) answer++;
        return; // target 값이 아닐때 더이상 진행하지 않도록 막음
    }
    bfs(numbers, target, sum + numbers[vertex], vertex + 1);
    bfs(numbers, target, sum - numbers[vertex], vertex + 1);
}
int solution(vector<int> numbers, int target){
    bfs(numbers, target, 0, 0);
    return answer;
}

int main(){
    cout <<solution({1, 1, 1, 1, 1}, 3);
    return 0;
}