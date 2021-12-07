#include <cstdio>

int main() {
    // X : 분수의 위치를 특정할 때 사용할 변수
    // i: 각 대각선에 있는 분수의 개수
    // up, down : 각각 분수의 분자와 분모
    int X, i = 0, up, down;
    // X가 음수로 변한 대각선에서
    //대각선이 오른쪽 위로 올라가는지 혹은 왼쪽 아래로 내려가는지 판정
    bool isDown = false;

    scanf("%d", &X);

    // X가 양수일 때, 즉 i이 원하는 값보다 작을 때
    while (X > 0) {
        // 대각선 안의 분수가 하나 더 추가되었으므로 i를 1 증가시키고
        // num을 i만큼, 즉 분모와 분자의 합이 i인 분수의 개수만큼 뺀다
        X -= ++i;
        //다음 대각선은 지금 대각선과 분수의 진행 방향이 다르다
        isDown = !isDown;
    }

    // 음수 X의 절댓값은 (목표 분수의 현재 대각선에서의 순서) - 1이고
    // i는 현재 대각선에서의 가장 큰 분모값이다
    // up과 down에 분수의 방향에 맞게끔 분자값과 분모값을 계산해 넣어준다
    if (isDown) { up = 1 - X; down = i + X; }
    else { up = i + X; down = 1 - X; }

    //분수를 출력한다
    printf("%d/%d\n", up, down);

    return 0;
}
