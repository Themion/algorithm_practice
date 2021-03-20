#include <cstdio>

//사람의 키와 몸무게를 저장할 클래스
class Person { public: int w = 0, h = 0; };

int main()
{
    //p: 각 사람의 키와 몸무게
    Person p[50];
    //n: 사람의 수, rank: 각 사람의 순위를 임시로 저장할 공간
    int n, rank;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i].w, &p[i].h);

    //입력받은 모든 사람에 대해
    for (int i = 0; i < n; i++) 
    {
        //순위가 1등이라고 가정한 뒤
        rank = 1;
        
        //자신을 제외한 다른 사람들이 자신보다 덩치가 크다면 순위를 1 내림
        for (int j = 0; j < n; j++) 
            if (p[i].w < p[j].w && p[i].h < p[j].h) rank++;

        //계산한 등수를 출력
        printf("%d ", rank);
    }

    //출력을 마치기 위해 개행문자를 출력
    printf("\n");

    return 0;
}