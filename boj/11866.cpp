#include <cstdio>
#include <vector>

int main()
{
    int n, k, idx = 0;      //n: 수열의 길이, k: 점프 거리
    std::vector<int> v;     //idx: 빠질 항목의 인덱스, v: 수열을 만들 배열
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) v.push_back(i);    //수열의 항목을 입력

    printf("<");

    while (v.size())
    {
        idx = (idx + k - 1) % v.size(); //다음으로 제거할 항목의 인덱스 게산
        printf("%d", v[idx]);           //제거할 항목을 출력
        v.erase(v.begin() + idx);       //항목 제거
        if(v.size()) printf(", ");      //출력 양식 맞추기
    }

    printf(">\n");

    return 0;
}