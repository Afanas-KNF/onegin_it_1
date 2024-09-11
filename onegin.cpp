#include <stdio.h>
#include <ctype.h> //чтобы пользоваться isalpha()
//#include "onegin.txt"
const int maxlen = 50;// максимальная длина строки
const int numstr = 13;  // количетсов строк
const int numsimb = 1000; // количество символов скопированных из файла

void sort_str(char [][maxlen]); // char(*)[maxlen] что означает эта запись?
bool str_is_bigger(char*, char*);
void swap_str(char*, char*);
void print_text(char [][maxlen]);
void fill_text(char [],char [][maxlen]);


int main()
{
    FILE *file;
    file = fopen("onegin.txt", "r"); //открываем файл для чтения
    if (file == NULL)               // проверка того смогли ли мы открыть файл
    {
      printf("Error: Failed to open file\n");
      return 1;
    }
    char copytxt[numsimb] = {};       // в этот массив будем копировать текст из файла onegin.txt
    int count = 0;
    for(int i = 0, c; (c = fgetc(file)) != EOF; i++)// будем записывать с помощью функции fgetc посимвольно пока не встртим EndOfFIle
    {                                               // символы \n тоже записываются
        count++;
        copytxt[i] = c;
    }
    printf("%d\n", count);  // выводит количество символов записанных в массив
    for(int i = 0; i < numsimb; i++)
    {
        printf("%c", copytxt[i]); //выводит то что скопировали из текста
    }

    //fgets(copytxt, numsimb, file);   // будет читать только одну строку так как функция считывает до первого символа \n

    char text[][maxlen] = {};   // в этот массив будем записывать все алфавитные символы и пробелы а если встречается \n
    fill_text(copytxt, text);
    sort_str(text);
    print_text(text);
    // printf("%s",text[1]);
    // printf("\n%c", text[1][3]);
    // printf("\n%d", text[1][3]);
    // printf("\n%d", *text[1]+3);
    // printf("\n%d", text);         // берем адрес первой строки
    // printf("\n%d", text +1);      // берем адрес второй строки
    // printf("\n%d", text[0] +1);   //берем адрес первой строки 2 эллемента
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

void fill_text(char copytxt[], char text[][maxlen])
{
    for (int i = 0; i < numstr; i++)
    {
        int a = 0;
        for (int j = 0; j  < maxlen; j++)
        {

            if (isalpha(copytxt[i*maxlen + j]) || copytxt[i*maxlen + j] == ' ')
            {
                text[i][a] = copytxt[i*maxlen + j];
                printf("%c", text[i][a]);
                a++;
            }
            else if (copytxt[i*maxlen + j] == '\n')
            {
                printf("%c", text[i][a]);
                break;
            }
        }
    }
    // print_text(text);
}
