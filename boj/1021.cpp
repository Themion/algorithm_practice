#include <cstdio>
#include <vector>

int main()
{
    //size: 초기 큐의 크기, num: pop할 원소의 수
    //fnd: 각 횟수마다 pop할 원소의 인덱스, ptr: 각 탐색을 시작할 지점
    //ret: 각 탐색의 이동 시간을 전부 더해 저장할 공간
    int size, num, fnd, ptr = 0, ret = 0;
    //q: 큐를 저장할 컨테이너
    std::vector<int> q;

    //큐의 크기와 pop할 원소의 수를 입력받는다
    scanf("%d %d", &size, &num);

    //주어진 정보에 따라 q를 초기화한다
    q = std::vector<int>(size);
    for (int i = 0; i < size; i++) q[i] = i + 1;

    //각 pop할 원소마다
    for (int i = 0; i < num; i++) 
    {
        //pop할 원소를 찾고
        scanf("%d", &fnd);

        //큐의 크기가 최대 50이므로 선형 탐색을 사용할 수 있다
        for (int j = 0; j <= size; j++)
        {
            //ptr부터 한 칸씩 탐색하며 pop할 원소를 발견하면
            //해당 지점을 ptr로 지정하고 원소를 pop한 뒤 이동한 횟수를 ret에 더한다
            if (q[(ptr + j) % size] == fnd)
            {
                q.erase(q.begin() + (ptr + j) % size);
                ptr = (ptr + j) % size;
                ret += j;
                break;
            }
            else if (q[(ptr - j + size) % size] == fnd)
            {
                q.erase(q.begin() + (ptr - j + size) % size);
                ptr = (ptr - j + size) % size;
                ret += j;
                break;
            }
        }

        //큐에서 원소를 pop했으므로 큐의 크기를 갱신한다
        size = q.size();
    }

    //총 이동 횟수를 출력한다
    printf("%d\n", ret);

    return 0;
}