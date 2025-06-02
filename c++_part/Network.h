#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

class WiFi
{
private:
    std::string manufact; // Фирма-производитель
    uint8_t countEthernet; // Количество портов Ethernet
    bool range5ghz; // Наличие диапазона Wi-Fi 5 ГГц
    unsigned short price; // Цена
public:
    WiFi(const std::string& manufact = "Unknown", uint8_t countEthernet = 1, bool range5ghz = 0, unsigned short price = 5000);

    void print();

    std::string getManufact() const;
    uint8_t getCountEthernet() const;
    bool getRange5ghz() const;
    unsigned short getPrice() const;

    void setCountEthernet(uint8_t countEthernet);
    void setRange5ghz(bool range5ghz);
    void setPrice(unsigned short price);
};

class CommutatorSwitch
{
private:
    std::string manufact; // Фирма-производитель
    unsigned int portsSpeed; // Скорость (в Mbps)
    bool SupportsPoE; // Поддерживается ли Power over Ethernet
    unsigned short price; // Цена
public:
    CommutatorSwitch(const std::string& manufact = "Unknown", unsigned int portsSpeed = 100, bool SupportsPoE = 0, unsigned short price = 5000);

    void print();

    std::string getManufact() const;
    unsigned int getPortsSpeed() const;
    bool getSupportsPoE() const;
    unsigned short getPrice() const;

    void setPortsSpeed(unsigned int portsSpeed);
    void setSupportsPoE(bool SupportsPoE);
    void setPrice(unsigned short price);
};