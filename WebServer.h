const char* netssid = configwifi.wifissid;
const char* netpassword = configwifi.wifipassword;

const char* ssid = configwifi.ssid;
const char* password = configwifi.password;

int pin_led = 2;


IPAddress local_ip(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress netmask(255, 255, 255, 0);


//----------------------------------------------------------------------
// PENGATURAN WIFI AUTO MODE STATION ATAU ACCESS POINT

void wifiConnect() {

  pinMode(pin_led, OUTPUT);

  WiFi.softAPdisconnect(true);
  WiFi.disconnect();
  delay(1000);

  Serial.println("Wifi Sation Mode");
  WiFi.persistent(false);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.mode(WIFI_STA);
  WiFi.begin(netssid,netpassword);
  unsigned long startTime = millis();
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(pin_led, !digitalRead(pin_led));
    if (millis() - startTime > 3000) break;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    //digitalWrite(pin_led, HIGH);
  } else {
    WiFi.persistent(false);
    WiFi.setSleepMode(WIFI_NONE_SLEEP);
    Serial.println("Wifi AP Mode");
    WiFi.mode(WIFI_AP);
    //WiFi.softAPConfig(local_ip, gateway, netmask);
    WiFi.softAP(ssid, password,1,0,1);
   
  }

  //Serial.println("");
  WiFi.printDiag(Serial);
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

}


ESP8266WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  
  if(type == WStype_TEXT) {
    
    if(payload[0] == '#') {

      Disp.drawRect(16,8,46,14,0,0);
      String data1 = (const char *)payload;
      String data2 = data1.substring(1);
      handleSettingDfUpdate(data2);      
      
    }

    if (strcmp("dplay", (const char *)payload) == 0) {
      mp3.start();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }
    if (strcmp("dpause", (const char *)payload) == 0) {
      mp3.pause();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }
    if (strcmp("dstop", (const char *)payload) == 0) {
      mp3.stop();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }
    if (strcmp("dnext", (const char *)payload) == 0) {
      mp3.nextTrack();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }
    if (strcmp("dprev", (const char *)payload) == 0) {
      mp3.prevTrack();
      delay(200);
      currentTrack = mp3.getCurrentTrack();
    }
    if (strcmp("drandom", (const char *)payload) == 0) {
      mp3.playRandomTrackFromAll();
      delay(200);
      currentTrack = 0;
    }
    if (strcmp("dmodemp3", (const char *)payload) == 0) {
      Disp.clear();
      tmputama = 2;
    }
    if (strcmp("dmodejam", (const char *)payload) == 0) {
      Disp.clear();
      tmputama = 0;
    }
    if (payload[0] == 'p') {

      if (payload[1] == '1') {
        mp3.playRandomTrackFromAll();
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '2') {
        mp3.loopFolder(2);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '3') {
        mp3.loopFolder(3);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '4') {
        mp3.loopFolder(4);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '5') {
        mp3.loopFolder(5);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '6') {
        mp3.loopFolder(6);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '7') {
        mp3.loopFolder(7);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '8') {
        mp3.loopFolder(8);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == '9') {
        mp3.loopFolder(9);
        delay(100);
        currentTrack = 0;
      } else if (payload[1] == 'l') {
        if (payload[2] == '1') {
          mp3.loopFolder(10);
          delay(100);
          currentTrack = 0;
        } else if (payload[2] == '2') {
          mp3.loopFolder(11);
          delay(100);
          currentTrack = 0;
        } else if (payload[2] == '3') {
          mp3.loopFolder(12);
          delay(100);
          currentTrack = 0;
        } else if (payload[2] == '4') {
          mp3.loopFolder(13);
          delay(100);
          currentTrack = 0;
        } else if (payload[2] == '5') {
          mp3.loopFolder(14);
          delay(100);
          currentTrack = 0;
        }
      }
      
      
    }

    if (payload[0] == 'e') {

      if (payload[1] == '1') {
        mp3.setEq(DfMp3_Eq_Normal);
      }
      if (payload[1] == '2') {
        mp3.setEq(DfMp3_Eq_Pop);
      }
      if (payload[1] == '3') {
        mp3.setEq(DfMp3_Eq_Rock);
      }
      if (payload[1] == '4') {
        mp3.setEq(DfMp3_Eq_Jazz);
      }
      if (payload[1] == '5') {
        mp3.setEq(DfMp3_Eq_Classic);
      }
      if (payload[1] == '6') {
        mp3.setEq(DfMp3_Eq_Bass);
      }
      
    }

    if (payload[0] == 't') {

      uint16_t tahun;
      uint8_t bulan;
      uint8_t tanggal;      
      String sd= (const char *)payload;
      String lastSd;
      
      tahun = ((sd[1]-'0')*1000)+((sd[2]-'0')*100)+((sd[3]-'0')*10)+(sd[4]-'0');
      bulan = ((sd[6]-'0')*10)+(sd[7]-'0');
      tanggal = ((sd[9]-'0')*10)+(sd[10]-'0');
      
      if (sd != lastSd){
        RtcDateTime now = Rtc.GetDateTime();
        uint8_t jam = now.Hour();
        uint8_t menit = now.Minute();
        Rtc.SetDateTime(RtcDateTime(tahun, bulan, tanggal, jam, menit, 0));
        lastSd=sd;
      }
      
    }

    if (payload[0] == 'j') {
      
      String st= (const char *)payload;
      String lastSt;
      uint8_t jam = ((st[1]-'0')*10)+(st[2]-'0');
      uint8_t menit = ((st[4]-'0')*10)+(st[5]-'0');
      
      if (st != lastSt){
         RtcDateTime now = Rtc.GetDateTime();
         uint16_t tahun = now.Year();
         uint8_t bulan = now.Month();
         uint8_t tanggal = now.Day();
         Rtc.SetDateTime(RtcDateTime(tahun, bulan, tanggal, jam, menit, 0));
         lastSt=st;
       }

    }

    if(payload[0] == 'i') {
      String data1 = (const char *)payload;
      String data2 = data1.substring(1);
      handleSettingInfoUpdate(data2);
    }

    if(payload[0] == 'c') {

      String data1 = (const char *)payload;
      String data2 = data1.substring(1);
      handleSettingDispUpdate(data2);
      
    }

    if(payload[0] == 's') {

      String data1 = (const char *)payload;
      String data2 = data1.substring(1);
      handleSettingJwsUpdate(data2);
      
    }

    if(payload[0] == 'w') {

      String data1 = (const char *)payload;
      String data2 = data1.substring(1);
      handleSettingWifiUpdate(data2);
      
    }

    if(payload[0] == 'z') {

      ESP.reset();
      
    }

    if (strcmp("dtesled", (const char *)payload) == 0) {
      Disp.clear();
      tmputama = 3;
    }

    
    //for(int i = 0; i < length; i++)
    //  Serial.print((char) payload[i]);
    //Serial.println();
    
  }
}




void handleXML(){
  buildXML();
  server.send(200,"text/xml",XML);
}

void handleRealXML(){
  realXML();
  server.send(200,"text/xml",XML);
}
