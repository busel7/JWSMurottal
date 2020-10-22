#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>
#include <FS.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

#include <SoftwareSerial.h>
#include <DFMiniMp3.h>

#include <Wire.h>
#include <RtcDS3231.h>
RtcDS3231<TwoWire> Rtc(Wire);

#include <HJS589.h>

#include <fonts/ElektronMart6x8.h>
#include <fonts/ElektronMart6x16.h>
#include <fonts/ElektronMart5x6.h>
#include <fonts/ElektronMartArabic6x16.h>
#include <fonts/ElektronMartArabic5x6.h>

#include <PrayerTimes.h>

#include "Display.h"
#include "DFPlayer.h"
#include "WebPage.h"
#include "FSConfig.h"
#include "WebServer.h"
#include "RTC.h"
#include "JWS.h"
#include "YoutubeInfo.h"

unsigned long websocketCount = 0, wait = 0;

void setup() {
  
  Serial.begin(115200);


  //Buzzer
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  delay(50);

  mulaiRTC();

  SPIFFS.begin();
  loadDispConfig(fileconfigdisp, configdisp);
  loadDfConfig(fileconfigdf, configdf);
  loadInfoConfig(fileconfiginfo, configinfo);
  loadJwsConfig(fileconfigjws, configjws);
  loadWifiConfig(fileconfigwifi, configwifi);

  LoadDataAwal();

  wifiConnect();
  
  server.on("/", [](){
    server.send_P(200, "text/html", webpage);
  });

  server.on ( "/xml", handleXML) ;
  server.on ( "/realxml", handleRealXML) ;
  
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);

  // Beri tanda komentar jika tidak menggunakan DFPlayer
  // jika tidak layar tidak akan tampil.
  //mulaiMP3();
  //mp3.setVolume(configdf.volume);
  
  //DMD
  Disp_init();
  
  Disp.setBrightness(configdisp.kecerahan);

}


// LOOP

void loop() {
  
  webSocket.loop();
  server.handleClient();

  if(Serial.available() > 0) {
    char c[] = {(char)Serial.read()};
    webSocket.broadcastTXT(c, sizeof(c));
  }

  //mp3.loop();


  switch(tmputama) {

    case 0 :
      tampiljws();
      break;      

    case 1 :
      Iqomah();
      break;

    case 2 :
      DFPlayer();
      break;

    case 3 :
      TestLED();
      break;

    case 4 :      
      TampilYoutubeData();
      break;
    
  }  

  //webSocket.broadcastTXT(jsonjws);

}

// JWS

void tampiljws() {
  
  switch(tmpjws) {

    case 0 :
      Intro1P();
      break;
      
    case 1 :
      if (configdisp.panel == 1) {        
        TampilInfo();
      }
      if (configdisp.panel == 2) {
        JamBesarInfo();
      }      
      break;

    case 2 :
      TeksBerjalanKananKiri();
      AlarmSholat();
      break;

    case 3 :
      TeksJalanInfo1();
      AlarmSholat();
      break;

    case 4 :
      TeksJalanInfo2();
      AlarmSholat();
      break;

    case 5 :
      if (WiFi.status() == WL_CONNECTED) {
        digitalWrite(pin_led, HIGH);
        TampilYoutubeData();
        intro1p = 0;
        AlarmSholat();
      } else {
        digitalWrite(pin_led, LOW);
        intro1p = 0;
        tmpjws = 0;
      }
      
      break;
    
  }
  
}

void JamBesarInfo() {
  
  JamBesar(1);
  TampilInfo();
  AlarmSholat();
  
}


void Intro1P() {  
  
  switch(intro1p) {
    case 0 :
      animLogoX();
      break;
    case 1 :
      Disp.drawRect(0,0,31,15,0,0);
      JamBesar(32);
      break;
      
  }
}



void TampilInfo() {

  switch(tmpinfo) {

    case 0 :
      TampilTanggal();
      break;

    case 1 :
      TampilSuhu();
      break;

    case 2 :
      TampilJadwalSholat();
      break;
    
  }
  
}

void DFPlayer() {

  char vol[3];
  sprintf(vol, "%02d", configdf.volume);

  char track[4];
  sprintf(track, "%03d", currentTrack);

  Disp.setFont(ElektronMart6x8);
  Disp.drawText(1,0, "Volume");
  Disp.drawText(1,8, vol);
  Disp.drawText(1,8, vol);
  Disp.drawRect(16,8, 16 + (configdf.volume * 24 / 30),14,1,1);

  Disp.drawText(50,0, "TR");
  Disp.drawText(43,8, track);  

}

void TestLED() {
  Disp.drawRect(0, 0, Disp.width(), 16, 1, 1);
}
