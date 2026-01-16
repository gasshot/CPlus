#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1️⃣ 함수 선언
void simpleConditionExample();
void multiConditionExample();
void doubleConditionExample();
void ternaryOperatorExample();

int main()
{
    //simpleConditionExample();  // 단순 조건문 예시 함수 호출
    //multiConditionExample();
    //doubleConditionExample();
    ternaryOperatorExample();
    return 0;
}

// 2️⃣ 함수 정의
void simpleConditionExample()
{
    int a;
    printf("입력하고 싶은 숫자를 써 주세요 : ");
    scanf("%d", &a);

    if (a == 7)
    {
        printf("행운의 숫자입니다.\n");
    }
    else
    {
        printf("숫자 %d를 입력하셨습니다.\n", a);
    }
}
void multiConditionExample() 
{
    int score;
    printf("당신의 영어 점수를 써 주세요 : ");
    scanf("%d", &score);

    if (score >= 90)
    {
        printf("A학점입니다.");
    }
    else if (score >= 80)
    {
        printf("B학점입니다.");
    }
    else if (score >= 70)
    {
        printf("C학점입니다.");
    }
    else if (score >= 60)
    {
        printf("D학점입니다.");
    }
    else
    {
        printf("F학점입니다.");
    }
}
void doubleConditionExample() 
{
    int score;
    printf("학생의 점수를 입력하세요: ");
    (void)scanf("%d", &score); // C6031 경고 방지

    if (score >= 90) // 1차 조건
    {
        if (score >= 95) // 2차 조건
        {
            printf("최우수 학생입니다.\n");
        }
        else
        {
            printf("우수 학생입니다.\n");
        }
    }
    else
    {
        printf("보통 학생입니다.\n");
    }

}
void ternaryOperatorExample() 
{
    int number;
    printf("숫자를 입력하세요: ");
    (void)scanf("%d", &number); // C6031 경고 방지

    // 3항 연산자 한 번만 사용
    const char* result = (number % 2 == 0) ? "짝수입니다." : "홀수입니다.";

    printf("%s\n", result);
}