#include <cstdio>

//프랙탈 모양을 저장할 클래스
class fractal
{
public:
    //정사각형 모양 프랙탈의 한 변의 길이
    int size;
    //프랙탈의 형태를 bool타입 2차원 배열로 저장
    bool **pattern;

    //초기 상태
    fractal()
    {
        this->size = 1;
        this->pattern = new bool *[this->size];
        this->pattern[0] = new bool[1]{true};
    }

    //입력받은 상태를 한 번 프랙탈화 시킨다
    fractal(fractal *input)
    {
        //사이즈를 3배 늘린 뒤
        this->size = (input->size) * 3;
        //세로 크기를 지정
        this->pattern = new bool *[this->size];

        //모든 행에 대해
        for (int i = 0; i < input->size; i++)
        {
            //각 행의 크기를 지정해준다. 이 때 초기값은 false
            this->pattern[i] = new bool[this->size]{ false, };
            this->pattern[i + input->size] = new bool[this->size]{ false, };
            this->pattern[i + 2 * (input->size)] = new bool[this->size]{ false, };

            //모든 픽셀에 대해 해당 픽셀이 가장자리 값이라면 주어진 상태를 복사, 정중앙 값이라면 비어있는 상태로 둔다
            for (int j = 0; j < input->size; j++)
            {
                this->pattern[i][j] = input->pattern[i][j];
                this->pattern[i][j + input->size] = input->pattern[i][j];
                this->pattern[i][j + 2 * (input->size)] = input->pattern[i][j];

                this->pattern[i + input->size][j] = input->pattern[i][j];
                this->pattern[i + input->size][j + 2 * (input->size)] = input->pattern[i][j];

                this->pattern[i + 2 * (input->size)][j] = input->pattern[i][j];
                this->pattern[i + 2 * (input->size)][j + input->size] = input->pattern[i][j];
                this->pattern[i + 2 * (input->size)][j + 2 * (input->size)] = input->pattern[i][j];
            }
        }
    }

    //각 픽셀에 대해 해당 픽셀값이 true라면 별을, false라면 공백을 출력
    void show()
    {
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
                if (this->pattern[i][j]) printf("*");
                else                     printf(" ");
            }

            printf("\n");
        }
    }
};

int main()
{
	//초기 상태를 지닌 프랙탈 생성
	fractal *ret = new fractal();

	//프랙탈화를 얼마나 시킬지 3^k 형태로 입력받는다
	int input;
	scanf("%d", &input);

	//ret을 k번 프랙탈화시킴
	while (input % 3 == 0)
	{
		ret = new fractal(ret);
		input /= 3;
	}

	//프랙탈을 출력한다
	ret->show();
    
    return 0;
}