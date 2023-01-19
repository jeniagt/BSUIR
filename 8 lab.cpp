#include <iostream>
#include <cstdio>
using namespace std;

struct Table {
    char FIO[30], group[10];
    double datb, chem, inf, phys, math, average;
}Ask;
int size1 = sizeof(Table);
FILE *Fd;
char File_Data[] = "/Users/evgenijsmolej/desktop/Database.txt";
int main(){
    setlocale(LC_ALL, "Russian");
    int kod, kod2, pos;
    double average_bal;
    while (true) {
        vvd: puts("\n\n \tМеню\n1. Создание \n2. Коррекция \n3. Просмотр \n4. Мое индивидуальное задание \n0. Выход\n\t");
        scanf("%d", &kod);
        switch (kod) {
            case 1:
                if ((Fd = fopen(File_Data, "wb")) == nullptr) {
                    puts("\n Ошибка при создании!");
                    return 0;
                }
                fclose(Fd);
                printf("\n\tФайл %s создан!\n", File_Data);
                break;
            case 2:
                puts("\n\n\tМеню\n1. Добавить \n2. Коррекция \n0. Назад");
                scanf("%d", &kod2);
                switch (kod2) {
                    case 1:
                        Fd = fopen(File_Data, "ab");
                        printf("\n Введите фамилию и имя\n>>>: ");
                        fflush(stdin); //очистка буфера входного потока
                        gets(Ask.FIO);
                        printf("\n Введите год рождения\n>>>: ");
                        scanf("%lf", &Ask.datb);
                        printf("\n Введите группу\n>>>: ");
                        cin >> Ask.group;
                        printf("\n Введите оценку по физике\n>>>: ");
                        scanf("%lf", &Ask.phys);
                        printf("\n Введите оценку по математике\n>>>: ");
                        scanf("%lf", &Ask.math);
                        printf("\n Введите оценку по информатике\n>>>: ");
                        scanf("%lf", &Ask.inf);
                        printf("\n Введите оценку по химии\n>>>: ");
                        scanf("%lf", &Ask.chem);
                        Ask.average = (Ask.phys + Ask.math + Ask.inf + Ask.chem) / 4.0;
                        fwrite(&Ask, 1, size1, Fd);
                        fclose(Fd);
                        break;
                    case 2:
                        puts("\nВведите номер поля для коррекции: "); scanf("%d", &pos); pos--;
                        Fd = fopen(File_Data, "r+b");
                        fseek(Fd, pos*size1, SEEK_SET); // указатель на строчку в файле
                        fread(&Ask, 1, size1, Fd);
                        printf("\n Введите фамилию и имя\n>>>: ");
                        fflush(stdin); //очистка буфера входного потока
                        gets(Ask.FIO);
                        printf("\n Введите год рождения\n>>>: ");
                        scanf("%lf", &Ask.datb);
                        printf("\n Введите группу\n>>>: ");
                        cin >> Ask.group;
                        printf("\n Введите оценку по физике\n>>>: ");
                        scanf("%lf", &Ask.phys);
                        printf("\n Введите оценку по математике\n>>>: ");
                        scanf("%lf", &Ask.math);
                        printf("\n Введите оценку по информатике\n>>>: ");
                        scanf("%lf", &Ask.inf);
                        printf("\n Введите оценку по химии\n>>>: ");
                        scanf("%lf", &Ask.chem);
                        Ask.average = (Ask.phys + Ask.math + Ask.inf + Ask.chem) / 4.0;
                        fseek(Fd, pos*size1, SEEK_SET);
                        fwrite(&Ask, 1, size1, Fd);
                        fclose(Fd);
                        break;
                    case 3:
                        goto vvd; // уходит в меню
                        break;
                }
                break;
            case 3:
                if ((Fd = fopen(File_Data, "rb")) == nullptr) {
                    puts("\n Ошибка открытия");
                    return 0;
                }
                printf("\n\t_______________________Информация о студентах______________________");
                printf("\n\t| Ф.И.         | Год | Группа |Хим|Инф|Физ|Мат|Средний|");
                while (1) {
                    if (!fread(&Ask, size1, 1, Fd)) break;
                    printf(" \n\t|%-15s| %-4.0f| %-6s |%-2.0f |%-2.0f |%-2.0f |%-2.0f | %-2.2f  |", Ask.FIO, Ask.datb, Ask.group, Ask.chem, Ask.inf, Ask.phys, Ask.math, Ask.average);
                }
                fclose(Fd);
                break;
            case 4:
                if ((Fd = fopen(File_Data, "rb")) == nullptr) {
                    puts("\n Ошибка открытия!");
                    return 0;
                }
                int count = 0;
                double sum = 0;
                while (1) {
                    if (!fread(&Ask, size1, 1, Fd)) break;
                    count ++;
                    sum += Ask.average;
                }
                fclose(Fd);
                Fd = fopen(File_Data, "rb");
                average_bal = sum/count;
                printf("Средний бал по группе - %.2f", average_bal);
                printf("\n\t| Ф.И.         | Год | Группа |Хим|Инф|Физ|Мат|Средний|");
                while (1) {
                    if (!fread(&Ask, size1, 1, Fd)) break;
                    if (average_bal < Ask.average) printf(" \n\t|%-15s| %-4.0f| %-6s |%-2.0f |%-2.0f |%-2.0f |%-2.0f | %-2.2f  |", Ask.FIO, Ask.datb, Ask.group, Ask.chem, Ask.inf, Ask.phys, Ask.math, Ask.average);
                }
                fclose(Fd);
                break;
        }
    }
}