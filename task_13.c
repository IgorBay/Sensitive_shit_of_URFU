#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

char* get_word(char* string, int word_number);        // Выдаёт слово из строки (на самом деле, указатель на превую букву этого слова)
_Bool check_match(char* string, int word_number);     // Проверяет совпадение последнего слова с остальными

int main()
{
    char* string_1 = "kjfa abcc bestt igorg bestt.";

    for (int i = 0; i < 5; ++i)
        printf("%c", *(get_word(string_1, 2) + i));
    printf("\n");

    printf("%i\n", check_match(string_1, 3));

    return 0;
}

char* get_word(char* string, int word_number)
{
    int i = 0;
    int j = 0;
    int n = 1;

    char word_array[5];            // Такая параша, потому что массив, который создала функция,
    char* word = word_array;       // нельзя передовать, а указатель можно.

/* Типа идём до указанного слова */
    while(n != word_number)
    {
        while(*(string + j) != ' ')
        {
            if(*(string + j) == '.')
                break;
            ++j;
        }
        while(*(string + j) == ' ')
            ++j;
        ++n;
    }

/* И записываем его отдельно */
    for (; *(string + i + j) != ' '; ++i)
    {
        if(*(string + i + j) == '.')
            break;
        *(word_array + i) = *(string + j + i);
    }

    return word;
}

_Bool check_match(char* string, int word_number)
{
    _Bool match;

    for (int i = 0; i < 5; ++i)
    {
        if(*(get_word(string, word_number) + i) == *(get_word(string, 5) + i))
            match = TRUE;
        else
        {
            match = FALSE;
            break;
        }
    }

    return match;
}