#include <stdio.h>
const int maxlen = 7;
const int numstr = 6;

void sort_str(char [][maxlen]); // char(*)[maxlen] это плюсовая запись, опка не осознал как записывать на си
bool str_is_bigger(char*, char*);
void swap_str(char*, char*);
void print_text(char [][maxlen]);


int main()
{
    char text[numstr][maxlen] = {{"abcd"},{"efghi"},{"j"},{"kl"},{"mno"},{"qrstuv"}};
    printf("%s",text[1]);
    printf("\n%c",text[1][3]);
    printf("\n%d",text[1][3]);
    printf("\n%d",*text[1]+3);
    printf("\n%d",text);       // берем адрес первой строки
    printf("\n%d",text +1);    // берем адрес второй строки
    printf("\n%d",text[0] +1); //берем адрес первой строки 2 эллемента
    sort_str(text);
    print_text(text);

}

void sort_str(char text[][maxlen])
{
    for (int n = 0; n < numstr; n++)                 // номер прохода по всем строкам
    {
        for (int i = 0; i < numstr - 1 - n; i++)     // выбираем пару соседних строк
        {
            if (!str_is_bigger(text[i], text[i + 1])) // возращает true или false
            {
                swap_str(text[i], text[i + 1]);     // если строка по алфавиту должна быть раньше меняем
            }
        }
    }
}

bool str_is_bigger(char* str1, char* str2)
{
    int a = 0;
    for (int i = 0; i < maxlen; i++)
    {
        if (*(str1 + i) > *(str2 + i))
        {
            a = 1;
            break;
        }
        else if (*(str1 + i) < *(str2 + i))
        {
            break;
        }
    }
    if (a = 0)
        return false;
    return true;
}

void swap_str(char* str1, char* str2)
{
    char swapell = {};
    for (int i = 0; i < maxlen; i++)
    {
        swapell = *(str1 + i);
        *(str1 + i) = *(str2 + i);
        *(str2 + i) = swapell;
    }
}

void print_text(char text[][maxlen])
{
    for (int i = 0; i < numstr; i++)
    {
        printf("\n");
        for (int j = 0; j < maxlen; j++)
        {
            //printf("%c", *(text[i]+j)); если память выделяется каллоками
            printf("%c", text[i][j]);
        }
    }
}










