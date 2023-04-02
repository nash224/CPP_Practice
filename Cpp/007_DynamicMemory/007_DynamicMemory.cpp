// 007_DynamicMemory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdlib.h>
#include <iomanip>

// 힙은 우리가 자유롭게 할당하거나 해제할 수 있다.
// 하지만 메모리를 사용한 만큼 해제하지 않으면 공간이 낭비된다.
// 힙은 인간이 다루는 만큼 철저히 다뤄야한다

void heap0()
{
    int SizeOfArray;
    int* arr;

    std::cout << "만들고 싶은 배열의 원소의 수 :" << std::endl;
    // int형의 배열의 원소의 개수를 받는다.
    std::cin >> SizeOfArray;

    // malloc()는 리턴함수가 (void*)형이르모 (int*)로 형변환해주었다.
    // 자신이 할당한 메모리의 '주소'를 리턴해준다.
    //                   malloc(4 * 입력받은 정수 개수)
    arr = (int*)malloc(sizeof(int) * SizeOfArray);

    // 할당받은 메로리영역을 다시 컴퓨터에게 돌려준다 
    // 제대로 해제하지 않으면 메모리 누수가 발생한다.
    free(arr);
}

void heap1()
{
    int student;
    int input;
    int i;
    int studentCurNumber;
    int* score; 
    int sum = 0;

    std::cout << "학생의 수는? : " << std::endl;
    std::cin >> student;

    // 메모리를 동적 할당하여 학생의 수만큼 점수를 보관한다
    score = (int*)malloc(sizeof(int*) * student);

    for (i = 0; i < student; i++){}
    {
        printf_s("학생의 %d 점수 : ", i);
        scanf_s("%d", &input);

        score[i] = input;
    }

    for (studentCurNumber = 0; studentCurNumber < student; studentCurNumber++)
    {
        sum += score[studentCurNumber];
    }
    std::cout << "전체 학생 평균 점수 : " << sum / student << std::endl;
    free(score);
}

int heap2()
{
    int i;
    int x, y;
    int** arr;  // 우리는 arr[x][y] 를 만들 것이다.

    printf("arr[x][y] 를 만들 것입니다.\n");
    scanf("%d %d", &x, &y);

    arr = (int**)malloc(sizeof(int*) * x);
    // int* 형의 원소를 x 개 가지는 1 차원 배열 생성

    for (i = 0; i < x; i++) {
        arr[i] = (int*)malloc(sizeof(int) * y);
    }

    printf("생성 완료! \n");

    for (i = 0; i < x; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

int main()
{
    //heap0();
    //heap1();
    heap2();
}