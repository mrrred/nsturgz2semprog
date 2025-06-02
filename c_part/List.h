#pragma once

#include <stdbool.h>

#include "WiFi.h"

typedef struct List
{
    WiFi wifi;
    struct List* next;
} List;

// Функция для добавления элемента в упорядоченный списко
bool ListAdd(List **list, WiFi* wifi);

// Список для подсчёта колличества элементов в списке
int ListCount(List* list);

// Функция для удаления элемента по индексу в списке
bool ListDelByIndex(List** list, int index);

// Функция, которая возвращает указатель на элемент списка по иднексу
WiFi* ListGetValueByIndex(List* list, int index);