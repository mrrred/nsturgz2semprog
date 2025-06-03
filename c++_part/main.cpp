#include <iostream>

#include "Network.h"

int main() 
{
    // Создание объектов с инициализацией
    WiFi wifi1("TP-Link", 4, true, 8000);
    WiFi wifi2("Asus"); // Остальные параметры по умолчанию
    
    CommutatorSwitch switch1("Cisco", 1000, true, 15000);
    CommutatorSwitch switch2("HP", 100, false, 3000);

    // Вывод информации о созданных объектах
    std::cout << "=== Initial state ===" << std::endl;
    wifi1.print();
    std::cout << std::endl;
    wifi2.print();
    std::cout << std::endl;
    switch1.print();
    std::cout << std::endl;
    switch2.print();
    std::cout << std::endl;

    // Изменение значений характеристик
    wifi1.setPrice(7500);
    wifi2.setCountEthernet(2);
    wifi2.setRange5ghz(true);
    
    switch1.setPortsSpeed(2500);
    switch2.setSupportsPoE(true);
    switch2.setPrice(3500);

    // Вывод информации об измененных объектах
    std::cout << "\n=== After modifications ===" << std::endl;
    wifi1.print();
    std::cout << std::endl;
    wifi2.print();
    std::cout << std::endl;
    switch1.print();
    std::cout << std::endl;
    switch2.print();
    std::cout << std::endl;

    // Тестирование базового класса
    std::cout << "=== Test base class ===\n" << std::endl;

    NetEquipment net1{"HP", 300};
    NetEquipment net2{"ASUS", 500};

    net1.print();
    std::cout << std::endl;
    net2.print();

    net1.setPrice(700);
    std::cout << std::endl;
    net1.print();

    // Б4
    std::cout << "\n\nBase class ptr test\n" << std::endl;

    NetEquipment* netptr;

    netptr = &net1;
    netptr->print();
    std::cout << std::endl;

    netptr = &wifi1;
    netptr->print();
    std::cout << std::endl;

    netptr = &switch1;
    netptr->print();
    std::cout << std::endl;

    return 0;
}
