#include "WiFi.h"
#include "List.h"

// Функция для записи списка в файл
void FileListWrite(char *name, List **list);

// Функция для чтения списка из файла
void FileListRead(char *name, List **list);