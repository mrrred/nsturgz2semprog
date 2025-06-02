#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "WiFi.h"
#include "List.h"
#include "FileListWorker.h"
    
// Тестирующая функция
int main(int argc, char const *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // А1
    WiFi router1;
    strcpy(router1.manufact, "TP-Link");
    router1.countEthernet = 4;
    router1.range5ghz = true;
    router1.price = 2500;

    WiFi router2 = 
    {
        .manufact = "ASUS",
        .countEthernet = 5,
        .range5ghz = true,
        .price = 8999 
    };

    WiFi router3 = {"Xiaomi", 2, false, 1800};


    
    // A2
    WiFiInit(&router1, "TP-Link", 4, true, 2500);
    WiFiInit(&router2, "-ASUS", 5, 87, 8999);
    WiFiInit(&router3, "Xiaomi", 99, false, 0);


    
    // A3
    WiFiprint(&router1);
    putc('\n', stdout);
    WiFiprint(&router2);
    putc('\n', stdout);
    WiFiprint(&router3);
    putc('\n', stdout);



    // A4
    WiFi router1_copy = router1;
    printf("router2 == router3  -  %d\n", isWiFiequal(&router2, &router3));
    printf("router1 == router1_copy  -  %d\n", isWiFiequal(&router1, &router1_copy));



    // A5
    printf("router2 < router3  -  %d\n", isWiFiless(&router2, &router3));
    printf("router1 < router4  -  %d\n", isWiFiless(&router3, &router1));
    printf("router1 < router1_copy  -  %d\n", isWiFiless(&router1, &router1_copy));



    printf("\n------------------------------------------\n\n");
    


    // Б и В часть
    List *list = NULL;

    FileListRead("file.bin", &list);

    int choice;

    do 
    {
        printf("\nМеню:\n");
        printf("1. Добавить элемент\n");
        printf("2. Вывести список\n");
        printf("3. Удалить элемент по индексу\n");
        printf("4. Выход\n");
        printf("Выберите действие: ");
        if (scanf("%d", &choice) != 1) 
        {
            while (getchar() != '\n');
            printf("Ошибка ввода. Введите число от 1 до 4.\n");
            continue;
        }

        switch(choice) {
            case 1: 
            {
                char manufact[STR_LEN];
                unsigned char countEthernet;
                char rangeInput;
                bool range5ghz;
                unsigned short price;

                printf("Введите производителя: ");
                scanf("%29s", manufact);
                printf("Количество портов Ethernet (0-255): ");
                scanf("%hhu", &countEthernet);
                printf("Наличие диапазона 5 ГГц (0 - нет, 1 - да): ");
                scanf(" %c", &rangeInput);
                range5ghz = (rangeInput == '1');
                printf("Цена: ");
                scanf("%hu", &price);

                WiFi wifi;
                WiFiInit(&wifi, manufact, countEthernet, range5ghz, price);
                ListAdd(&list, &wifi);
                printf("Элемент добавлен.\n");
                break;
            }
            case 2: 
            {
                int count = ListCount(list);
                if (count == 0) {
                    printf("Список пуст.\n");
                } else {
                    printf("Элементы списка (%d):\n", count);
                    for (int i = 0; i < count; ++i) {
                        WiFi *wifi = ListGetValueByIndex(list, i);
                        printf("[%d] ", i);
                        WiFiprint(wifi);
                    }
                }
                break;
            }
            case 3: 
            {
                int index;
                printf("Введите индекс для удаления: ");
                if (scanf("%d", &index) != 1) {
                    printf("Неверный ввод индекса.\n");
                    while (getchar() != '\n');
                    break;
                }
                int count = ListCount(list);
                if (index < 0 || index >= count) {
                    printf("Неверный индекс. Допустимый диапазон: 0-%d\n", count - 1);
                } else {
                    ListDelByIndex(&list, index);
                    printf("Элемент %d удален.\n", index);
                }
                break;
            }
            case 4: 
            {
                FileListWrite("file.bin", &list);
                printf("Память освобождена. Завершение работы.\n");
                break;
            }
            default: 
            {
                printf("Неверный выбор. Попробуйте снова.\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
