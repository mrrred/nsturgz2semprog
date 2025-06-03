#include "Network.h"

NetEquipment::NetEquipment(std::string manufact, unsigned short price)
    : manufact{manufact}, price{price} {}

void NetEquipment::print()
{
    std::cout << "Manufact - " << manufact << std::endl;
    std::cout << "Price - " << price << " $" << std::endl;
}

std::string NetEquipment::getManufact() const { return manufact; } 
unsigned short NetEquipment::getPrice() const { return price; }

void NetEquipment::setPrice(unsigned short price) { this->price = price; }



WiFi::WiFi(const std::string& manufact, uint8_t countEthernet, bool range5ghz, unsigned short price)
    : NetEquipment(manufact, price), countEthernet{countEthernet}, range5ghz{range5ghz} {}

void WiFi::print()
{
    std::cout << "Manufact - " << manufact << std::endl;
    std::cout << "Count Ethernet - " << countEthernet << std::endl;
    std::cout << "5Ghz - " << (( range5ghz ) ? "Yes" : "No") << std::endl;
    std::cout << "Price - " << price << " $" << std::endl;
}

uint8_t WiFi::getCountEthernet() const { return countEthernet; }
bool WiFi::getRange5ghz() const { return range5ghz; }

void WiFi::setCountEthernet(uint8_t countEthernet) { this->countEthernet = countEthernet; }
void WiFi::setRange5ghz(bool range5ghz) { this->range5ghz = range5ghz; }



CommutatorSwitch::CommutatorSwitch(const std::string& manufact, unsigned int portsSpeed, bool SupportsPoE, unsigned short price)
    : NetEquipment(manufact, price), portsSpeed{portsSpeed}, SupportsPoE{SupportsPoE} {}

void CommutatorSwitch::print()
{
    std::cout << "Manufact - " << manufact << std::endl;
    std::cout << "Ports Speed - " << portsSpeed << std::endl;
    std::cout << "PoE supports - " << (( SupportsPoE ) ? "Yes" : "No") << std::endl;
    std::cout << "Price - " << price << " $" << std::endl;
}

unsigned int CommutatorSwitch::getPortsSpeed() const { return portsSpeed; }
bool CommutatorSwitch::getSupportsPoE() const { return SupportsPoE; }

void CommutatorSwitch::setPortsSpeed(unsigned int portsSpeed) { this->portsSpeed = portsSpeed; }
void CommutatorSwitch::setSupportsPoE(bool SupportsPoE) { this->SupportsPoE = SupportsPoE; }