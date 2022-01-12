#include <cstdio>

#define SIZE 10001

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// 큰 수를 클래스에 넣어서 저장
class Number {
public:
    // 이 클래스에 저장된 수가 음수인지를 prefix하여 저장
    bool is_minus = false;
    // 입력된 수를 각 자리수별로 나누어서 저장
    char dgt[SIZE] = { 0, };

    // 수를 입력받으며 값을 저장하는 생성자
    Number() {
        // 각 자리를 입력할 때 사용할 공간
        char buf;
        // l: 수를 입력받을 때 사용할 인덱스
        // r: 입력받은 수는 역순으로 저장되므로 
        // 투포인터를 이용해 수를 뒤집을 때 쓸 인덱스
        int l = SIZE - 1, r = l;

        // while문을 이용해 수를 입력받는다
        scanf("%c", &buf);
        // 버퍼에 공백 문자가 나올 때까지
        while (buf != ' ' && buf != '\n') {
            // 만일 - 기호가 들어왔다면 이 수가 음수임을 표시한다
            if (buf == '-') this->is_minus = true;
            // - 기호 이외에 들어온 값, 즉 각 자리 수를 역순으로 배열에 저장
            else this->dgt[l--] = buf - '0';
            // 다음 문자를 입력받는다
            scanf("%c", &buf);
        }

        // 역순으로 저장된 수를 다시 뒤집는다
        while (l < r) swap(this->dgt[++l], this->dgt[r--]);
        // 이 수가 음수라면 10의 보수 기법을 이용해 양수로 저장
        if (this->is_minus) this->complement();
    }

    // 수를 입력받지 않고 값을 1로 설정
    Number(int i) { this->dgt[SIZE - 1] = 1; }

    // 수 x를 10의 보수를 이용하여 절댓값을 바꾸지 않으면서 부호를 전환
    void complement() {
        // 각 자리 수 d를 9 - d로 변환하여 x를 ~x로 변환
        for (int i = 0; i < SIZE; i++) this->dgt[i] = 9 - this->dgt[i];

        // ~x에 1을 더해 -x를 완성시킨다
        this->add(new Number(1));
    }

    // 현재 수에 other를 더한다
    void add(Number* other) {
        // carry: 각 자리 덧셈에서 발생한 carry
        // temp_minus: 수의 범위가 ±10^10000을 포함하므로
        // 예외처리를 위해 각 자리 수를 검토하는 변수
        bool carry = false, temp_minus = false;

        // 각 자리의 덧셈
        for (int i = SIZE - 1; i >= 0; i--) {
            // 두 수의 i번째 자리를 직전 수의 carry와 함께 더한 뒤
            this->dgt[i] += other->dgt[i] + carry;
            // 덧셈에서 발생한 carry를 따로 저장하고
            carry = this->dgt[i] / 10;
            // 나며지 연산으로 각 자리 수를 저장
            this->dgt[i] %= 10;

            // 가장 큰 자리가 아닌 자리의 수가 0이 아니라면 temp_minus를 true로 설정
            if (i != 0) temp_minus = temp_minus || this->dgt[i];
        }

        // 가장 큰 자리의 수가 2 초과거나, 2이면서 temp_minus라면
        // 이 덧셈의 결과는 음수이므로 이를 is_minus에 저장
        this->is_minus = (this->dgt[0] > 2) || (this->dgt[0] == 2 && temp_minus);
    }
};

int main() {
    // 출력을 위해 각 자리가 0인지 확인
    bool chk = false;
    // 두 수 a, b를 생성자를 통해 입력받아 저장
    Number a, b;
    // a += b
    a.add(&b);

    // a가 음수라면 - 기호를 출력한 뒤 a에 10의 보수를 취해 절댓값을 복원
    if (a.is_minus) {
        printf("-");
        a.complement();
    }
    // a의 각 자리의 수 a'에 대해
    for (int i = 0; i < SIZE; i++) {
        // 출력 앞에 자리만 차지하는 0이 있어서는 안되므로
        // a를 탐색하며 처음 0이 아닌 수를 발견했을 때부터 a를 출력
        chk = chk || a.dgt[i];
        // 0이 아닌 수를 발견한 적이 있거나 i가 SIZE - 1일 때, 즉 a의 값이 0일 때
        // a의 각 자리 수 a'를 출력
        if (chk || i == SIZE - 1) printf("%d", a.dgt[i]);
    }

    // 개행 문자를 출력하여 출력을 종료
    printf("\n");

    return 0;
}
