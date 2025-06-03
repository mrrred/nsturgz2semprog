#pragma once

#include <iostream>
#include <string>
#include <stdint.h>
#include <cstdint>

class NetEquipment
{
protected:
    std::string manufact; // Фирма-производитель
    unsigned short price; // Цена
public:
    NetEquipment(std::string manufact = "Unknown", unsigned short price = 5000);
    virtual void print();

    std::string getManufact() const; 
    unsigned short getPrice() const; 

    void setPrice(unsigned short price);
};

class WiFi : public NetEquipment
{
private:
    uint8_t countEthernet; // Количество портов Ethernet
    bool range5ghz; // Наличие диапазона Wi-Fi 5 ГГц
public:
    WiFi(const std::string& manufact = "Unknown", uint8_t countEthernet = 1, bool range5ghz = 0, unsigned short price = 5000);
    WiFi(const NetEquipment &net = NetEquipment(), uint8_t countEthernet = 1, bool range5ghz = 0);

    void print();

    uint8_t getCountEthernet() const;
    bool getRange5ghz() const;

    void setCountEthernet(uint8_t countEthernet);
    void setRange5ghz(bool range5ghz);
};

class CommutatorSwitch : public NetEquipment
{
private:
    unsigned int portsSpeed; // Скорость (в Mbps)
    bool SupportsPoE; // Поддерживается ли Power over Ethernet
public:
    CommutatorSwitch(const std::string& manufact = "Unknown", unsigned int portsSpeed = 100, bool SupportsPoE = 0, unsigned short price = 5000);
    CommutatorSwitch(const NetEquipment &net = NetEquipment(), unsigned int portsSpeed = 100, bool SupportsPoE = 0);

    void print();

    unsigned int getPortsSpeed() const;
    bool getSupportsPoE() const;

    void setPortsSpeed(unsigned int portsSpeed);
    void setSupportsPoE(bool SupportsPoE);
};