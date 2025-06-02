#include "Network.h"

WiFi::WiFi(const std::string& manufact, uint8_t countEthernet, bool range5ghz, unsigned short price)
    : manufact{manufact}, countEthernet{countEthernet}, range5ghz{range5ghz}, price{price} {}

void WiFi::print()
{
    std::cout << "Manufact - " << manufact << std::endl;
    std::cout << "Count Ethernet - " << countEthernet << std::endl;
    std::cout << "5Ghz - " << (( range5ghz ) ? "Yes" : "No") << std::endl;
    std::cout << "Price - " << price << " $" << std::endl;
}

std::string WiFi::getManufact() const { return manufact; }
uint8_t WiFi::getCountEthernet() const { return countEthernet; }
bool WiFi::getRange5ghz() const { return range5ghz; }
unsigned short WiFi::getPrice() const { return price; }

void WiFi::setCountEthernet(uint8_t countEthernet) { this->countEthernet = countEthernet; }
void WiFi::setRange5ghz(bool range5ghz) { this->range5ghz = range5ghz; }
void WiFi::setPrice(unsigned short price) { this->price = price; }



CommutatorSwitch::CommutatorSwitch(const std::string& manufact, unsigned int portsSpeed, bool SupportsPoE, unsigned short price)
    : manufact{manufact}, portsSpeed{portsSpeed}, SupportsPoE{SupportsPoE}, price{price} {}

void CommutatorSwitch::print()
{
    std::cout << "Manufact - " << manufact << std::endl;
    std::cout << "Ports Speed - " << portsSpeed << std::endl;
    std::cout << "PoE supports - " << (( SupportsPoE ) ? "Yes" : "No") << std::endl;
    std::cout << "Price - " << price << " $" << std::endl;
}

std::string CommutatorSwitch::getManufact() const { return manufact; }
unsigned int CommutatorSwitch::getPortsSpeed() const { return portsSpeed; }
bool CommutatorSwitch::getSupportsPoE() const { return SupportsPoE; }
unsigned short CommutatorSwitch::getPrice() const { return price; }

void CommutatorSwitch::setPortsSpeed(unsigned int portsSpeed) { this->portsSpeed = portsSpeed; }
void CommutatorSwitch::setSupportsPoE(bool SupportsPoE) { this->SupportsPoE = SupportsPoE; }
void CommutatorSwitch::setPrice(unsigned short price) { this->price = price; }