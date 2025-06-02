#include "List.h"

#include <stdio.h>
#include <stdlib.h>

// Функция для создания списка с одним элементом
static List* create_list(WiFi* wifi)
{
    List* new_list = (List*)malloc(sizeof(List));

    if (new_list == NULL)
        return NULL;

    new_list->next = NULL;
    new_list->wifi = *wifi;

    return new_list;
}

bool ListAdd(List **list, WiFi* wifi)
{
    if ( list == NULL || wifi == NULL)
        return false;

    if (*list == NULL) // Если список пустой, создаём новый
        *list = create_list(wifi);
    else
    {
        List* new_ellement = (List*)malloc(sizeof(List));

        if (new_ellement != NULL)
        {
            new_ellement->wifi = *wifi;

            if ( isWiFiless(wifi, &(( *list )->wifi)) ) // Проверка: новый элемент меньше 1-го элемента списка?
            {
                // Добавляем элемент в начало списка
                new_ellement->next = *list;
                *list = new_ellement;
            }
            else
            {
                List* next_ptr = *list; // Указатель на элемент списка

                /*  
                Сравниваем со следующим элементом от next_ptr
                пока не дойдём до большего эелемента,
                или пока не дойдём до конца
                */

                while (next_ptr->next != NULL && !isWiFiless(wifi, &(next_ptr->next->wifi)))
                    next_ptr = next_ptr->next;

                // Вставляем элемент в позицию, после next_ptr
                new_ellement->next = next_ptr->next;
                next_ptr->next = new_ellement;
            }

        }
        else return false;
    }

    return true;
}

int ListCount(List* list)
{
    int element_count = 0;

    while (list != NULL)
    {
        element_count++;

        list = list->next;
    }

    return element_count;
}

// Функция, для удаления элемента из начала списка
static void list_del_begin(List** list)
{
    if (*list != NULL)
    {
        List* list_buff = (*list)->next;

        free(*list);

        *list = list_buff;
    }
}

bool ListDelByIndex(List** list, int index)
{
    if (list == NULL || *list == NULL) return false;

    List* next = *list;
    List* prev_next = NULL;

    if (index <= 0 || (*list)->next == NULL)
        list_del_begin(list);
    else
    {
        for (int current_index = 0; current_index != index && next->next != NULL; current_index++)
        {
            prev_next = next;
            if (current_index + 1 != index)
                next = next->next;
        }

        if (next->next == NULL)
        {
            prev_next->next = NULL;
            free(next);
        }
        else
        {
            List* next_after_deleted = next->next->next;
            free(next->next);
            next->next = next_after_deleted;
        }
    }

    return true;
}

WiFi* ListGetValueByIndex(List* list, int index) // Добавить ошибки
{
    WiFi* wifi;

    if (list != NULL)
    {
        wifi = &(list->wifi);

        for (int index_now = 0; index_now != index; index_now++)
        {
            if (list->next == NULL) 
                return wifi;

            list = list->next;
            wifi = &(list->wifi);
        }

        return wifi;
    }
    else
        return NULL; 
}

