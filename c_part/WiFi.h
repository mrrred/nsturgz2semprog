#pragma once

#include <stdbool.h>

#define STR_LEN 30

typedef struct WiFi
{
    char manufact[STR_LEN]; // Фирма-производитель
    unsigned char countEthernet; // Количество портов Ethernet
    bool range5ghz; // Наличие диапазона Wi-Fi 5 ГГц
    unsigned short price; // Цена
} WiFi;

// Функция, для инициализации полей структуры
void WiFiInit(
    WiFi* wifi, 
    char *manufact, 
    unsigned char countEthernet, 
    bool range5ghz, 
    unsigned short price
);

// Функция, выводящая поля экземпляра структуры
void WiFiprint(WiFi* wifi);

// Функция, для сравнения экземпляров структуры ( wifi1 == wifi2 )
bool isWiFiequal(WiFi* wifi1, WiFi* wifi2);

// Функция, для сравнения экземпляров структуры ( wifi1 < wifi2 )
bool isWiFiless(WiFi* wifi1, WiFi* wifi2);
