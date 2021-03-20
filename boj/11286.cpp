#include <algorithm>
#include <cstdio>
#include <map>

int abs(int num) { return num > 0 ? num : -num; }

int main()
{
    // map을 heap처럼 사용
    std::map<std::pair<int, int>, int> heap;
    std::map<std::pair<int, int>, int>::iterator it;
    int N, num;

    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &num);
        // 숫자가 자연수라면 heap에 push
        if (num) heap[std::pair<int, int>(abs(num), num)]++;
        // 숫자가 0이고 힙에 원소가 없다면 0을 출력
        else if (heap.empty()) printf("0\n");
        // 숫자가 0이고 힙에 원소가 있다면
        else
        {
            // map의 첫번째 원소의 key를 출력
            it = heap.begin();
            printf("%d\n", it->first.second);
            // 첫번째 원소의 값에서 1을 빼고 그 결과가 0이라면 map에서 제거
            if (--(it->second) == 0) heap.erase(it->first);
        }
     }

    return 0;
}