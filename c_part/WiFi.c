#include "WiFi.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функция для проверки поля manufact
static bool manufact_check(char *manufact)
{
    if ( manufact == NULL || 
        !( isalpha(*manufact) || isdigit(*manufact)) ) return false;
    
    return true;
}

// Функция для проверки поля countEthernet
static bool countEthernet_check(unsigned char countEthernet)
{
    if ( countEthernet == 0 || countEthernet > 32 ) return false;
    
    return true;
}

// Функция для проверки поля price
static bool price_check(unsigned short price)
{
    if ( price == 0 ) return false;

    return true;
}

void WiFiInit(WiFi* wifi, char *manufact, unsigned char countEthernet, bool range5ghz, unsigned short price)
{
    if ( wifi == NULL ) return;
    
    if ( manufact_check(manufact) ) strncpy(wifi->manufact, manufact, STR_LEN - 1);
    else strcpy(wifi->manufact, "Unknown");

    if ( countEthernet_check(countEthernet) ) wifi->countEthernet = countEthernet;
    else wifi->countEthernet = 1;

    wifi->range5ghz = range5ghz;

    if ( price_check(price) ) wifi->price = price;
    else wifi->price = 5000;
}

void WiFiprint(WiFi* wifi)
{
	if (wifi != NULL)
		printf("Manufact - %s\nCount Ethernet - %d\n5Ghz - %s\nPrice - %d $\n", 
        	wifi->manufact, wifi->countEthernet, ( wifi->range5ghz ) ? "Yes" : "No", wifi->price);
}

bool isWiFiequal(WiFi* wifi1, WiFi* wifi2)
{
	if ( strcmp(wifi1->manufact, wifi2->manufact) != 0 )
		return false;

	if ( wifi1->countEthernet != wifi2->countEthernet )
		return false;

	if ( wifi1->range5ghz != wifi2->range5ghz )
		return false;

	if ( wifi1->price != wifi2->price )
		return false;

	return true;
}

bool isWiFiless(WiFi* wifi1, WiFi* wifi2)
{
	char is_manufact_less,
		is_countEthernet_less,
		is_range5ghz_less,
		is_price_less;

	is_manufact_less = strcmp(wifi1->manufact, wifi2->manufact);

	if ( is_manufact_less < 0 )
		return true;
	else if ( is_manufact_less > 0 )
		return false;


	is_price_less = ( wifi1->price < wifi2->price ) ? 1 : -1;

	if ( is_price_less > 0 )
		return true;
	else if ( is_price_less < 0 )
		return false;

    is_countEthernet_less = ( wifi1->countEthernet < wifi2->countEthernet ) ? 1 : -1;

	if ( is_countEthernet_less > 0 )
		return true;
	else if ( is_countEthernet_less < 0 )
		return false;

	is_range5ghz_less = ( wifi1->range5ghz < wifi2->range5ghz ) ? 1 : -1;

	if ( is_range5ghz_less > 0 )
		return true;
	else if ( is_range5ghz_less < 0 )
		return false;

	return false;
}
