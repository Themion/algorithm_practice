#include <cstdio>

//arr[i][j]: 2 * i 크기의 직사각형울
//           j == 0일 때 |로, j == 1일 때 =로, j == 2일 때 ㅁ로 끝내는
//           경우의 수
short arr[1000][3] = {{1, 0, 0}, {1, 1, 1}};

int main()
{
    //idx: 값을 계산할 때 사용할 변수
    //input: 출력할 값의 인덱스를 입력받을 공간
    int idx = 1, input;
    //input을 입력받는다
    scanf("%d", &input);
    //0과 1은 기본적으로 주어져있다
    while (idx++ < input)
    {
        //끝이 |로 끝나는 2 * idx 타일은 2 * (idx - 1) 타일의 맨 끝에 |를 붙이면 된다
        arr[idx][0] = (arr[idx - 1][0] + arr[idx - 1][1] + arr[idx - 1][2]) % 10007;
        //끝이 =로 끝나는 2 * idx 타일은 2 * (idx - 2) 타일의 맨 끝에 =를 붙이면 된다
        arr[idx][1] = (arr[idx - 2][0] + arr[idx - 2][1] + arr[idx - 2][2]) % 10007;
        //끝이 ㅁ로 끝나는 2 * idx 타일은 2 * (idx - 2) 타일의 맨 끝에 ㅁ를 붙이면 된다
        arr[idx][2] = (arr[idx - 2][0] + arr[idx - 2][1] + arr[idx - 2][2]) % 10007;
    }
    //idx++을 이용하여 계산했으니 idx에서 1을 뺀 뒤 input과 같아질 때까지 계산했으니 1을 또 빼야 한다
    //결과적으로 정답이 되는 건 
    //(arr[idx - 2][0] + arr[idx - 2][1] + arr[idx - 2][2])이다
    printf("%d\n", (arr[idx - 2][0] + arr[idx - 2][1] + arr[idx - 2][2]) % 10007);

    return 0;
}