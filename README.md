URL: https://github.com/mozolin/LilyGo_T-Zigbee_TLSR8258  
  
# Example: LilyGo T-Zigbee TLSR8258 (Telink SDK) with 8 endpoints for DS18B20 & BME280 & BH1750 sensors
  
Zigbe2MQTT Settings:  
[Example: Zigbee2MQTT CC2538 settings for ESP32-C3, ESP32-C6 and CC2530](https://github.com/mozolin/Zigbee2MQTT_CC2538)  
  
![](img/esp32c3-tlsr8258_zigbee.jpg)  
![](img/esp32c3-tlsr8258_zigbee.png)  
![](img/ssd1306_tlsr8258-esp32c3.jpg)  
![](img/ssd1306_zigbee.jpg)  
  
# Make firmware for TLSR8258 LilyGo T-ZigBee  
Before firmware update, adjust the DIP switch:  
![](img/upload_mode.png)  
  
1) Install Telink IDE – based on C/C++ Eclipse IDE (https://wiki.telink-semi.cn/wiki/IDE-and-Tools/IDE-for-TLSR8-Chips/)  
![](img/TLink-Eclipse.png)  
  
2) Unpack project zip-file into the folder  
![](img/tlst8258-Router_01.png)  
  
3) Import as Existing Project  
![](img/tlst8258-Router_02.png)  
  
4) Select "tlsr8258" folder, check «…\build\tlsr_tc32» project, DO NOT check «Copy projects into workspace» (path settings for the project may be incorrect!)  
![](img/tlst8258-Router_03.png)  
  
5) Source code can be found in ..\tlsr8258\apps\hciDevice_ZR_8258 folder  
![](img/tlst8258-Router_04.png)  
  
6) Choose under «Build» menu (hammer icon) the item «_hciDevice_ZR_8258 (Route-8258)»  
![](img/tlst8258-Router_05.png)  
  
7) Make sure, that the build was successful  
![](img/tlst8258-Router_06.png)  
  
8) .BIN-file can be found here:  
![](img/tlst8258-Router_07.png)  
  
9) Flash .BIN-file using TlsrComSwireWriter (https://github.com/pvvx/TlsrComSwireWriter)  
![](img/TLSR8258_Flash_01.png)  
![](img/TLSR8258_Flash_02.png)  
![](img/TLSR8258_Flash_03.png)  
![](img/TLSR8258_Flash_04.png)  
  
The LED connected to the TX pin will blink during the erase and flashing processes  
![](img/TLSR8258_Flash_LED.png)  
