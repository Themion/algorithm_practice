#include <cstdio>

class square {
public:
    int x1, y1, x2, y2;
    square() { scanf("%d %d %d %d", &x1, &y1, &x2, &y2); }
};

int main() {
    // 두 사각형의 각 좌표를 클래스 형식으로 저장
    square a, b;
    // 서로 다른 위치의 좌표가 일치하는 가짓수
    int i = (a.x2 == b.x1) + (a.y2 == b.y1) + (b.x2 == a.x1) + (b.y2 == a.y1);

    // x축 좌표 혹은 y축 좌표가 서로 만나지 않는다면 위치 관계는 NULL
    if (a.x2 < b.x1 || b.x2 < a.x1 || a.y2 < b.y1 || b.y2 < a.y1)
        printf("NULL\n");
    // 서로 다른 위치의 좌표가 일치하는 경우가 없다면 위치 관계는 FACE
    else if (!i) printf("FACE\n");
    // 서로 다른 위치의 좌표가 일치하는 경우가 1이라면 LINE, 2라면 POINT
    else printf("%s\n", i == 1 ? "LINE" : "POINT");
    return 0;
}
