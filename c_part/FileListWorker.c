#include "FileListWorker.h"

#include <io.h>
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <stdio.h>
#include <stdlib.h>

// Функция для выведения данных из списка в файл
static void save_list_to_file(int file, List** list)
{
    if (list == NULL)
        return;

	while (*list != NULL)
    {
		_write(file, ListGetValueByIndex(*list, 0), sizeof(WiFi));
        ListDelByIndex(list, 0);
    }
}

void FileListWrite(char *name, List **list)
{
    int file = _open(name, O_WRONLY | O_BINARY | O_CREAT, S_IWRITE);

	if (file == -1) {
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}

    save_list_to_file(file, list);

    _close(file);
}

// Функция для выведения данных из файла в список
static void read_file_to_list(int file, List** list)
{
    WiFi wifi;

    while (_read(file, &wifi, sizeof(WiFi)) != 0)
	{
		ListAdd(list, &wifi);
	}
}

void FileListRead(char *name, List **list)
{
    int file = _open(name, O_RDONLY | O_BINARY);

	if (file == -1) {
		perror("Error opening files");
		exit(EXIT_FAILURE);
	}
	
	read_file_to_list(file, list);

	_close(file);

}