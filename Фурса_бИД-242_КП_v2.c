#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <conio.h>



int main()
{
    setlocale(LC_ALL, "RUS");
    puts("�������� ������ �� ��������� \"����� ���������������� � ��������������\"\n");
    puts("����:\"���������� ���������� �������\" \n");
    puts("���������: �����.�.�, ������ ���-242\n");
    puts("��������� ������� ������������ ������ ������, ��������� ������ �� ���������, ������� ����� A � � ����\n");

    int stroki = 10;
    int stolbci = 10;
    int i, vvod = 0;
    int max_a = -1;
    int kratno = -1;
    int c = 0;
    float buf = 0.0;
    float* Massiv = malloc(stroki * stolbci * sizeof(float)); // �������� ������ ��� ������ float
    float a = 0.0;

    do {
        printf("������� ���������� ����� �������: ");
        scanf_s("%d", &stroki);
        printf("\n ������� ���������� c������� �������: ");
        scanf_s("%d", &stolbci);


        printf("\n ���������� ������ ����� �������\n");
        for (i = 0; i < 10; i++)
        {
            printf(" ���� ������� - ������� 1\n");
            printf(" ���� �������������� ���������� ���������� ������� - ������� 0 \n");
            scanf_s("%d", &vvod);
            if (i == 9)
            {
                printf(" ���� ������� �����������. �� ������� ���� ���������!\n");
                i = 11;
                getchar();
                goto exit_;
            }
            if (vvod > 1)
            {
                printf(" �������� ����. ���������� ��� ���.\n ");
            }
            else
                i = 11;
        }
                
        if (vvod == 1)
        {
            //���� � ����������
            printf("������� �������� ������� ����� Enter\n ");
            Vvod_s_klaviatury(stroki, stolbci, Massiv);
            //�����
            Vivod(stroki, stolbci, Massiv);
        }
        else
        {
            //���������� ������    
            Zapolnenie_sluchayno(stroki, stolbci, Massiv);
        }

        printf("������� � ��� ������ ������� ��������� :  ");
        scanf_s("%f", &a);
        // ����� ������� �
        int schet = 0;
        for (int i = 0; i < stroki; i++) //������ ����� ��������
        {
            kratno = -1;
            for (int j = 0; j < stolbci; j++) //������ ����� �����
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
            printf(" ����� � �������� %3.1f ������� �� �������\n", a);
        else
        {
            printf(" ������ � �������� %3.1f ������� ���� �������\n", a);
            printf(" ������������� ������ ������ -  %d\n", max_a);
            printf(" ��������� ������ - \n");

            //����� �������� �����
            Vivod_kratnoy_stroki(stroki, stolbci, Massiv, max_a);
        }
        printf("\n��������� ? (�� - 1, ��� - 0)\n");
        scanf_s("%d", &c);
        system("cls");

    } while (c == 1);
exit_: free(Massiv); //������������ ������
}

int Vvod_s_klaviatury(int stroki_l, int stolbci_l, float* Massiv_l)
{
    //���� � ����������
    float buf = 0.0;
    int schet = 0;
    for (int i = 0; i < stroki_l; i++) //������ ��������
    {
        for (int j = 0; j < stolbci_l; j++) //������ �����
        {

            scanf_s("%f", &buf);
            *(Massiv_l + schet) = buf;
            schet++;
        }
    }
}

int Vivod(int stroki_l, int stolbci_l, float* Massiv_l)
{
    //�����
    float buf = 0.0;
    int schet = 0;
    for (int i = 0; i < stroki_l; i++) //������ ��������
    {
        for (int j = 0; j < stolbci_l; j++) //������ �����

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
    //���������� ������    
    srand(time(NULL)); // ����� �� ���� ���������� ��������� ����� ������
    int schet = 0;
    float random = 0.0;

    for (int i = 0; i < stolbci_l; ++i)
    {
        // ��������� �� ���� �������� ��� ������ ������ i
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
    //����� ������� �����
    int schet = 0;
    float buf = 0.0;
    for (int i = 0; i < stroki_l; i++) //������ ��������
    {
        for (int j = 0; j < stolbci_l; j++) //������ �����
        {
            buf = *(Massiv_l + schet);
            if (max_a_l == i)
                printf(" %3.1f ", buf);
            else;
            schet++;
        }
    }
}