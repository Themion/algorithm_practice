#include <algorithm>
#include <cstdio>

using namespace std;

#define DICE_LEN 5
#define MIN_NUM 1
#define MAX_NUM 6

#define FOR_EACH_DICE(i) for (i = 0; i < DICE_LEN; i++)
#define FOR_EACH_NUM(i) for (i = MIN_NUM; i <= MAX_NUM; i++)

int max(int a, int b) { return a > b ? a : b; }

void set_bool(bool& b) {
    char c;
    scanf("%c", &c);
    b = c == 'Y';   
}

int single_score(bool single[MAX_NUM + 1], int dice[DICE_LEN]) {
    int ret = 0;
    int score = 0;

    int i, j;

    FOR_EACH_NUM(i) if (single[i]) {
        score = 0;
        FOR_EACH_DICE(j)
            score += dice[j] == i;
        ret = max(ret, score * i);
    }

    return ret;
}

int four_kind_score(bool four_kind, int dice[DICE_LEN]) {
    if (!four_kind) return 0;

    int count[MAX_NUM + 1] = { 0, };
    int i;

    FOR_EACH_DICE(i) count[dice[i]]++;
    FOR_EACH_NUM(i) if (count[i] >= 4)
        return i * 4;
    
    return 0;
}

int full_house_score(int full_house, int dice[DICE_LEN]) {
    if (!full_house) return 0;

    int count[MAX_NUM + 1] = { 0, };
    int three = 0, two = 0;
    int i;

    FOR_EACH_DICE(i) count[dice[i]]++;

    FOR_EACH_NUM(i) {
        if (count[i] == 3) three = i;
        if (count[i] == 2) two = i;
    }

    return (three && two) ? (three * 3 + two * 2) : 0;
}

int straight_score(bool straight[2], int dice_[5]) {
    int dice[DICE_LEN] = { 0, };
    int i;

    FOR_EACH_DICE(i) dice[i] = dice_[i];
    sort(dice, dice + DICE_LEN);

    FOR_EACH_DICE(i) 
        if (i && (dice[i] - dice[i - 1] != 1)) return 0;

    if (!straight[0] && dice[0] == 1) return 0;
    if (!straight[1] && dice[0] == 2) return 0;

    return 30;
}

int yacht_score(bool yacht, int dice[DICE_LEN]) {
    if (!yacht) return 0;
    int i;
    FOR_EACH_DICE(i) if (dice[0] != dice[i]) return 0;

    return 50;
}

int choice_score(bool choice, int dice[DICE_LEN]) {
    if (!choice) return 0;
    int ret = 0;
    int i;
    FOR_EACH_DICE(i) ret += dice[i];
    return ret;
}

int main () {
    bool single[MAX_NUM + 1] = { 0, };
    bool four_kind;
    bool full_house;
    bool straight[2];
    bool yacht;
    bool choice;

    int dice[DICE_LEN];

    int ans = 0;

    int i, j;

    FOR_EACH_NUM(i)
        set_bool(single[i]);
    set_bool(four_kind);
    set_bool(full_house);
    for (int i = 0; i < 2; i++) 
        set_bool(straight[i]);
    set_bool(yacht);
    set_bool(choice);

    for (int i = 0; i < 3; i++)
        scanf("%d", dice + i);   

    FOR_EACH_NUM(i) {
        dice[3] = i;

        FOR_EACH_NUM(j) {
            dice[4] = j;

            ans = max(ans, single_score(single, dice));
            ans = max(ans, four_kind_score(four_kind, dice));
            ans = max(ans, full_house_score(full_house, dice));
            ans = max(ans, straight_score(straight, dice));
            ans = max(ans, yacht_score(yacht, dice));
            ans = max(ans, choice_score(choice, dice));
       }
    }

    printf("%d\n", ans);

    return 0;
}
