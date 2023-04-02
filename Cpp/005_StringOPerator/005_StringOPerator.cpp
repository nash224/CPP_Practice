
#include <iostream>

void String_Copy(char* _Subject, char* _source);
int ArrayNumberCount(char* _str);
int BiggerStrNumber(char* _str1, char* _str2);
void String_Sum(char* _Subject, char* _source);
void String_Add(char* _Subject, char* _source);
void StringCharacter_Compare(char* _Subject, char* _source);
int String_Compare(char* _Subject, char* _source);
void StringComparePrint(char* _Subject, char* _source);




int main()
{
    char str1[20] = "My";
    char str2[20] = "Project";


    std::cout << "str1 바꾸기 전 : " << str1 << std::endl;

    String_Copy(str1, str2);

    std::cout << "str1 바꾼 후 : " << str1 << std::endl;



    char str3[20] = "My";
    char str4[20] = "Project";

    String_Sum(str3, str4);

    std::cout << "합치기 : " << str3 << std::endl;


    char str5[50] = "My Project Name is ";
    char str6[50] = "StringOperactor";

    String_Add(str5, str6);

    std::cout << "합치기 : " << str5 << std::endl;


    char str7[] = "MyLooper";
    char str8[] = "MyProject";

    StringCharacter_Compare(str7, str8);

    char str9[] = "Hello";
    char str10[] = "Hello Wrold";
    char str11[] = "Hello 53";
    char str12[] = "Hello";

    StringComparePrint(str9, str10);
    StringComparePrint(str9, str11);
    StringComparePrint(str9, str12);

}




int ArrayNumberCount(char* _str)
{
    int count = 0;
    int currentString = _str[count];

    while (currentString != 0)
    {
        count++;
        currentString = _str[count];
    }
    return count;
}

int BiggerStrNumber(char* _str1, char* _str2)
{
    int Str1Count = ArrayNumberCount(_str1);
    int Str2Count = ArrayNumberCount(_str2);

    if (Str1Count > Str2Count)
    {
        return Str1Count;
    }
    else
    {
        return Str2Count;
    }
}

void String_Sum(char* _Subject, char* _source)
{
    int SubjectNumberCount = ArrayNumberCount(_Subject);
    int SourceNumberCount = ArrayNumberCount(_source);

    int currentNumber = 0;

    int Loop = SourceNumberCount;

    while (Loop--)
    {
        _Subject[SubjectNumberCount] = _source[currentNumber];
        char value = _Subject[SubjectNumberCount];
        SubjectNumberCount++;
        currentNumber++;
    }
    _Subject[SubjectNumberCount] = '\0';
}

void String_Add(char* _Subject, char* _source)
{
    while (*_Subject)
    {
        _Subject++;
    }

    while (*_source)
    {
        *_Subject = *_source;
        _Subject++;
        _source++;
    }
    *_Subject = '\0';
}

void String_Copy(char* _Subject, char* _source)
{
    int Loop = BiggerStrNumber(_Subject, _source);


    while (Loop--)
    {
        *_Subject = *_source;
        _Subject++;
        _source++;
    }
    *_Subject = '\0';
}

void StringCharacter_Compare(char* _Subject, char* _source)
{
    int count = 0;
    while (*_Subject)
    {
        count++;
        if (*_Subject == *_source)
        {
            std::cout << count << "번째 배열이 서로 같습니다" << std::endl;
        }
        else
        {
            std::cout << count << "번째 배열이 서로 다릅니다" << std::endl;
        }
        _Subject++;
        _source++;
    }
}

int String_Compare(char* _Subject, char* _source)
{
    while (*_Subject)
    {
        if (*_Subject != *_source)
        {
            return false;
        }
        _Subject++;
        _source++;
    }
    
    if(*_source == '\0')
    {
        return true;
    }
    return false;
}

void StringComparePrint(char* _Subject, char* _source)
{
    bool value = String_Compare(_Subject, _source);

    if (value)
    {
        std::cout << _Subject << "와 " << _source << "는 같습니다." << std::endl;
    }
    else
    {
        std::cout << _Subject << "와 " << _source << "는 다릅니다." << std::endl;
    }
}
