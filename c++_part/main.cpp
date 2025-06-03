#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <stdint.h>
#include <cstdint>

#include "Network.h"

std::unique_ptr<NetEquipment> createNetEquipment()
{
    std::string manufacter;
    unsigned short price;

    std::cout << "Enter manufacter" << std::endl;
    std::cin >> manufacter;
    std::cout << "Enter price" << std::endl;
    std::cin >> price;

    return std::make_unique<NetEquipment>(manufacter, price);
}

std::unique_ptr<WiFi> createWiFi()
{
    auto base = createNetEquipment();
    
    unsigned int countEthernet;
    bool range5ghz;

    std::cout << "Enter countEthernet" << std::endl;
    std::cin >> countEthernet;
    std::cout << "Enter range5ghz" << std::endl;
    std::cin >> range5ghz;

    return std::make_unique<WiFi>(*base, static_cast<uint8_t>(countEthernet), range5ghz);
}

std::unique_ptr<CommutatorSwitch> createCommutator()
{
    auto base = createNetEquipment();
    
    unsigned int portsSpeed;
    bool SupportsPoE;

    std::cout << "Enter portsSpeed" << std::endl;
    std::cin >> portsSpeed;
    std::cout << "Enter SupportsPoE" << std::endl;
    std::cin >> SupportsPoE;

    return std::make_unique<CommutatorSwitch>(*base, portsSpeed, SupportsPoE);
}

enum class MENU
{
    ADDNET, ADDWIFI, ADDCOMMUTATOR, LISTPRINT,  EXIT
};

void action_with_list(std::list<std::unique_ptr<NetEquipment>> &netList, MENU action)
{
    switch (action)
    {
    case MENU::ADDNET:
        netList.push_back(createNetEquipment());
        break;
    case MENU::ADDWIFI:
        netList.push_back(createWiFi());
        break;
    case MENU::ADDCOMMUTATOR:
        netList.push_back(createCommutator());
        break;
    case MENU::LISTPRINT:
        std::cout << "\n================================" << std::endl;
        for (const auto &el : netList)
        {
            el->print();
            std::cout << std::endl;
        }
        std::cout << "================================\n" << std::endl;

    }
}

int main() 
{
    std::list<std::unique_ptr<NetEquipment>> netList;
    
    int menu_choose;

    while(1)
    {
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add NetEquipment" << std::endl;
        std::cout << "2. Add WiFi" << std::endl;
        std::cout << "3. Add CommutatorSwitch" << std::endl;
        std::cout << "4. List print" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "\n>>> ";

        std::cin >> menu_choose;
        menu_choose -= 1;

        if (menu_choose < static_cast<int>(MENU::ADDNET) || menu_choose > static_cast<int>(MENU::EXIT))
            continue;
        
        if (static_cast<MENU>(menu_choose) == MENU::EXIT)
            break;
        
        action_with_list(netList, static_cast<MENU>(menu_choose));
    }

    return 0;
}
