#include <cstdio>

//stu[j][i][input]: j차 신청에서 i번째 학생이 
//                  input번째 과목을 신청해 성공했다면 true, 
//                                  아니라면 false
bool stu[2][1000][1001];

//cls[i]: i번째 수업의 정원
//stu_cls[j][i]: j차 신청에서 i번째 수업을 신청한 학생 수
int cls[1001], stu_cls[2][1001];

//stu_num: 학생 수, cls_num: 과목 수
int stu_num, cls_num;

//time번째 수강바구니 입력
void class_bucket(int time)
{
    //입력을 대신할 버퍼
    int input;

    //각 학생에 대해
    for (int i = 0; i < stu_num; i++)
    {
        //입력 맨 마지막에 -1이 들어가 있으므로
        //먼저 한 번 입력받은 뒤 while문을 실행시킨다
        scanf("%d", &input);
        //아직 신청한 과목이 남아있는 경우
        while (input != -1)
        {
            //time번째에 학생 i가 input번째 과목을 신청했음을 표시한 뒤
            stu[time][i][input] = true;
            //time번째에 input번째 과목을 신청한 학생 수를 1 늘린다
            stu_cls[time][input] += 1;

            //학생 i가 아직 신청한 과목이 있는지 확인
            scanf("%d", &input);
        }
    }
}

//time번째 수강바구니 확인
void bucket_check(int time)
{
    //각 과목에 대해
    for (int i = 1; i <= cls_num; i++)
    {
        //과목의 여석이 time번째 신청한 학생 수보다 적다면
        if(cls[i] < stu_cls[time][i])
            //과목이 터졌으므로 time번째에 i 과목을 신청한 학생들은
            //수강바구니에서 i 과목을 제거해야 한다
            for(int j = 0; j < stu_num; j++) stu[time][j][i] = false;
        //과목의 여석을 신청한 학생 수만큼 줄인다
        cls[i] -= stu_cls[time][i];
    }
}

int main()
{
    //학생 수와 과목 수를 입력받은 뒤
    scanf("%d %d", &stu_num, &cls_num);
    //각 과목의 여석을 입력받는다
    for (int i = 1; i <= cls_num; i++) scanf("%d", &cls[i]);

    //수강바구니는 2회 열리므로
    //수강바구니를 입력받은 뒤 터진 과목이 없는지 확인한다
    for (int i = 0; i < 2; i++)
    {
        class_bucket(i);
        bucket_check(i);
    }
    
    //각 학생에 대해
    for (int i = 0; i < stu_num; i++)
    {
        //한 과목이라도 정상적으로 수강신청 된 경우 true, 아니라면 false
        bool chk = false;

        //각 과목에 대해
        for (int j = 1; j <= cls_num; j++) 
            //1차 혹은 2차 수강바구니 때
            //과목 j를 정상적으로 수강신청 하였다면
            if(stu[0][i][j] || stu[1][i][j])
            {
                //해당 과목을 수강할 것이라고 출력한 뒤
                printf("%d ", j);
                //어느 과목을 정상적으로 수강신청 하였다고 표시한다
                chk = true;
            }
        //만일 이 학생의 수강바구니가 터졌다면 "망했어요"를 출력한다
        if (!chk) printf("망했어요");
        //개행문자를 출력하여 이 학생에 대한 출력을 끝낸다
        printf("\n");
    }

    return 0;
}