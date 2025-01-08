#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <conio.h>



int main()
{
    setlocale(LC_ALL, "RUS");
    puts("Курсовой проект по дисцплине \"осовы программирования и алгоритмизации\"\n");
    puts("Тема:\"Реализация многомерно массива\" \n");
    puts("Выполнила: Фурса.Н.П, группа бИД-242\n");
    puts("Программа выводит максимальный индекс строки, состоящей только из элементов, кратных числу A и её саму\n");

    int stroki = 10;
    int stolbci = 10;
    int i, vvod = 0;
    int max_a = -1;
    int kratno = -1;
    int c = 0;
    float buf = 0.0;
    float* Massiv = malloc(stroki * stolbci * sizeof(float)); // выделяем память для одного float
    float a = 0.0;

    do {
        printf("Введите количество строк массива: ");
        scanf_s("%d", &stroki);
        printf("\n Введите количество cтолбцов массива: ");
        scanf_s("%d", &stolbci);


        printf("\n Определите способ ввода массива\n");
        for (i = 0; i < 10; i++)
        {
            printf(" Если вручную - введите 1\n");
            printf(" Если автоматическое заполнение случайными числами - введите 0 \n");
            scanf_s("%d", &vvod);
            if (i == 9)
            {
                printf(" Ваши попытки закончились. Вы достали даже компьютер!\n");
                i = 11;
                getchar();
                goto exit_;
            }
            if (vvod > 1)
            {
                printf(" Неверный ввод. Попробуйте ещё раз.\n ");
            }
            else
                i = 11;
        }
                
        if (vvod == 1)
        {
            //ввод с клавиатуры
            printf("Введите элементы массива через Enter\n ");
            Vvod_s_klaviatury(stroki, stolbci, Massiv);
            //вывод
            Vivod(stroki, stolbci, Massiv);
        }
        else
        {
            //заполнение рандом    
            Zapolnenie_sluchayno(stroki, stolbci, Massiv);
        }

        printf("Введите А для поиска кратных элементов :  ");
        scanf_s("%f", &a);
        // поиск кратных а
        int schet = 0;
        for (int i = 0; i < stroki; i++) //проход вдоль столбцов
        {
            kratno = -1;
            for (int j = 0; j < stolbci; j++) //проход вдоль строк
            {
                buf = *(Massiv + schet);
                if (fmod(buf, a) == 0)
                {
                    kratno++;
                }
                else;
                // j = stolbci + 1;
                schet++;
            }
            if (kratno == stolbci - 1)
            {
                max_a = i;
            }
            else;
        }

        if (kratno == -1)
            printf(" Строк с кратными %3.1f числами не найдено\n", a);
        else
        {
            printf(" Строки с кратными %3.1f числами были найдены\n", a);
            printf(" Максиммальный индекс строки -  %d\n", max_a);
            printf(" Найденная строка - \n");

            //вывод призовой стоки
            Vivod_kratnoy_stroki(stroki, stolbci, Massiv, max_a);
        }
        printf("\nПовторить ? (Да - 1, нет - 0)\n");
        scanf_s("%d", &c);
        system("cls");

    } while (c == 1);
exit_: free(Massiv); //освобождение памяти
}

int Vvod_s_klaviatury(int stroki_l, int stolbci_l, float* Massiv_l)
{
    //ввод с клавиатуры
    float buf = 0.0;
    int schet = 0;
    for (int i = 0; i < stroki_l; i++) //проход столбцов
    {
        for (int j = 0; j < stolbci_l; j++) //проход строк
        {

            scanf_s("%f", &buf);
            *(Massiv_l + schet) = buf;
            schet++;
        }
    }
}

int Vivod(int stroki_l, int stolbci_l, float* Massiv_l)
{
    //вывод
    float buf = 0.0;
    int schet = 0;
    for (int i = 0; i < stroki_l; i++) //проход столбцов
    {
        for (int j = 0; j < stolbci_l; j++) //проход строк

        {
            buf = *(Massiv_l + schet);
            printf(" %3.1f ", buf);
            schet++;
        }
        printf("\n"); //max_a=i;

    }
}

int Zapolnenie_sluchayno(int stroki_l, int stolbci_l, float* Massiv_l)
{
    //заполнение рандом    
    srand(time(NULL)); // чтобы не было одинаковых случайных чисел всегда
    int schet = 0;
    float random = 0.0;

    for (int i = 0; i < stolbci_l; ++i)
    {
        // пробегаем по всем столбцам для данной строки i
        for (int j = 0; j < stroki_l; ++j)
        {
            random = (rand() % 100) / 3.1;
            *(Massiv_l + schet) = random;
            printf(" %5.2f ", random);
            schet++;
        }
        printf("\n");
    }
}

int Vivod_kratnoy_stroki(int stroki_l, int stolbci_l, float* Massiv_l, int max_a_l)
{
    //вывод кратной стоки
    int schet = 0;
    float buf = 0.0;
    for (int i = 0; i < stroki_l; i++) //проход столбцов
    {
        for (int j = 0; j < stolbci_l; j++) //проход строк
        {
            buf = *(Massiv_l + schet);
            if (max_a_l == i)
                printf(" %3.1f ", buf);
            else;
            schet++;
        }
    }
}