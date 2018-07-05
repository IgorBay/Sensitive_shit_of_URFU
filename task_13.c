#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0




char* get_word(char* string, int word_number);              // Выдаёт слово из строки (на самом деле, указатель на превую букву этого слова), (вспомогательная)
int characters_counter(char* string, int word_number);      // Вылаёт количество букв в слове (вспомогательная)
_Bool check_match(char* string, int word_number);           // Проверяет совпадение последнего слова с остальными
_Bool check_alphabet_order(char* string, int word_number);  // Проверяет на расположение букв в слове по алфавиту
_Bool check_repeat(char* string, int word_number);          // Проверяет на совпадение последней и предпоследней букв в слове
void print_words(char* string);                             // Печатает нужные слова




int main()
{
    char* string_1 = "kja abcc bestt igorg bestt.";

    print_words(string_1);

    return 0;
}




char* get_word(char* string, int word_number)
{
    int i = 0;
    int j = 0;
    int n = 1;

    char word_array[6];            // Такая параша, потому что массив, который создала функция,
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
    *(word_array + i) = '\0';

    return word;
}




int characters_counter(char* string, int word_number)
{
    int char_amount = 0;

    for (; *(get_word(string, word_number) + char_amount) != '\0'; ++char_amount)
    {}

    return char_amount;
}




_Bool check_match(char* string, int word_number)
{
    _Bool match;

    for (int i = 0; *(get_word(string, word_number) + i) != '\0'; ++i)
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




_Bool check_alphabet_order(char* string, int word_number)
{
    _Bool alph_order;

    for (int i = 1; *(get_word(string, word_number) + i) != '\0'; ++i)
    {
        if(*(get_word(string, word_number) + i) >= *(get_word(string, word_number) + i - 1))
            alph_order = TRUE;
        else
        {
            alph_order = FALSE;
            break;
        }
    }

    return alph_order;
}




_Bool check_repeat(char* string, int word_number)
{
    _Bool repeat;

    if(*(get_word(string, word_number) + characters_counter(string, word_number) - 1) == 
       *(get_word(string, word_number) + characters_counter(string, word_number) - 2))
        repeat = TRUE;
    else
        repeat = FALSE;

    return repeat;
}



void print_words(char* string)
{
    for (int i = 1; i != 5 ; ++i)
    {
        if(check_match(string, i) == FALSE && 
           check_alphabet_order(string, i) == TRUE && 
           check_repeat(string, i) == TRUE)
        {
            for (int k = 0; *(get_word(string, i) + k) != '\0'; ++k)
                printf("%c", *(get_word(string, i) + k));
        }
        printf("\n");
    }
}