#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "ESP32"                         

const char WIFI_SSID[] = "NOME_WIFI";               
const char WIFI_PASSWORD[] = "SENHA_WIFI";           

const char AWS_IOT_ENDPOINT[] = "ENDPOINT_AWS";      
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
COLE O AWS_CERT_CA AQUI
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                              
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
COLE O AWS_CERT_CRT AQUI
-----END CERTIFICATE-----


)KEY";
 
// Device Private Key                                             
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
COLE O AWS_CERT_PRIVATE AQUI
-----END RSA PRIVATE KEY-----

 
)KEY";
