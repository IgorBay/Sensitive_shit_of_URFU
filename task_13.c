#include <stdio.h>
#include <string.h>

/* В функцию даёшь саму строку и номер слова, которое хочешь взять.
   Она выдаёт тебе это слово отдельной строкой. */
char* get_word(char* string, int word_number);

int main()
{
    char* string_1 = "kjfh abcc igorg the best.";

    for (int i = 0; i < 5; ++i)
        printf("%c", *(get_word(string_1, 2) + i));
    printf("\n");

    return 0;
}

char* get_word(char* string, int word_number)
{
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
    for (int i = 0; *(string + i + j) != ' '; ++i)
    {
        if(*(string + i + j) == '.')
            break;
        *(word_array + i) = *(string + j + i);
    }

    return word;
}