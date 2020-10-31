    #include <ESP8266WiFi.h>
    // includes necessaires au fonctionnement de l'OTA :
    #include <WiFiUdp.h>
    #include <ArduinoOTA.h>
    const char* ssid = "mySSID"; // le SSID de votre WiFi
    const char* password = "myPassword"; // le mode de passe de votre WiFi
    void setup() {
      WiFi.begin(ssid, password);
      while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        delay(3000);
        ESP.restart();
      }  
      
      ArduinoOTA.setHostname("myName"); // on donne une petit nom a notre module
      ArduinoOTA.begin(); // initialisation de l'OTA
    }
    void loop() {
      // a chaque iteration, on verifie si une mise a jour nous est envoyee
      // si tel est cas, la lib ArduinoOTA se charge de gerer la suite :)
      ArduinoOTA.handle(); 
    }