#include <stdio.h>
#include <string.h>

/* В функцию даёшь саму строку и номер слова, которое хочешь взять.
   Она выдаёт тебе это слово отдельной строкой. */
char* get_word(char* string, int word_number);

int main()
{
    char* string_1 = "kjfh abcc igorg the best.";
    printf("%s\n", get_word(string_1, 2));           // попробуй с разным вторым аргументом
    return 0;
}

char* get_word(char* string, int word_number)
{
    int i = 0;
    int n = 1;

    char word_array[5];            // Такая параша, потому что массив, который создала функция,
    char* word;                    // нельзя передовать, а указатель можно.

/* Типа идём до указанного слова */
    while(n != word_number)
    {
        while((*(string + i) != ' ')/* || (*(string + i) != '.')*/)
            ++i;
        while(*(string + i) == ' ')
            ++i;
        ++n;
    }

/* И записываем его отдельно */
    for (int j = 0; *(string + j + i) != ' '; ++j)
    {
        *(word_array + j) = *(string + j + i);
    }

    word = word_array;

    printf("%s, %s\n", word_array, word);

/* Хз, Игорян, это какая-то дичь.
   Внутри себя она выводит word, а возвращать его не хочет*/

    return word;
}