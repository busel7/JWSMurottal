boolean intro = true;

void getyoutubejson() {

  if (getdata == true) {

    timer0_detachInterrupt();

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    client->setFingerprint(fingerprint);
    
    HTTPClient https;    //Declare object of class WiFiClient
  

    //GET Data

  
    if (https.begin(*client, configwifi.youtubeurl)) {  // HTTPS

      //Serial.print("[HTTPS] GET...\n");
      int httpCode = https.GET();

      if (httpCode > 0) {
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          datayoutube = https.getString();
          //Serial.println(datayoutube);
        }
      } else {

        timer0_attachInterrupt(refresh);
        //Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
        Disp.clear();
        if (configdisp.panel == 1) {
          Disp.setFont(ElektronMart5x6);
          textCenter1PKanan(4, "gagal...");
        }
        if (configdisp.panel == 2) {
          Disp.setFont(ElektronMart6x8);
          textCenter(4, "gagal...");
        }
        delay(1000);
        Disp.clear();
        intro=true;
        https.end();
        tmpjws = 0;        
      }

      DynamicJsonDocument doc(1024);
      DeserializationError error = deserializeJson(doc, datayoutube);
    
      if (error) {
        //Serial.println("Gagal parse datayoutube");
        //textCenter(0,"$Youtube");        
      }  
    
      hitungview = doc["items"][0]["statistics"]["viewCount"];
      hitungsubscriber = doc["items"][0]["statistics"]["subscriberCount"];

      if (configdisp.panel == 1) {
        if (hitungsubscriber>=1000)
          snprintf(subs,sizeof(subs),"%ld.%03ld",hitungsubscriber/1000,hitungsubscriber%1000);
        else  
          snprintf(subs,sizeof(subs),"%ld",hitungsubscriber);
      }
      if (configdisp.panel == 2) {
        if (hitungsubscriber>=1000)
          snprintf(subs,sizeof(subs),"$%ld.%03ld",hitungsubscriber/1000,hitungsubscriber%1000);
        else  
          snprintf(subs,sizeof(subs),"$%ld",hitungsubscriber);
      }
      
      
      
      if (hitungview>=1000)
        snprintf(view,sizeof(view),"%%%ld.%03ld",hitungview/1000,hitungview%1000);
      else  
        snprintf(view,sizeof(view),"%%%ld",hitungview);      

      https.end();
      timer0_attachInterrupt(refresh);
      getdata = false;
      
      
    } else {

      timer0_attachInterrupt(refresh);
      Disp.clear();
      if (configdisp.panel == 1) {
        Disp.setFont(ElektronMart5x6);
        textCenter1PKanan(4, "gagal...");
      }
      if (configdisp.panel == 2) {
        Disp.setFont(ElektronMart6x8);
        textCenter(4, "gagal...");
      }
      delay(1000);
      Disp.clear();
      intro=true;
      https.end();
      tmpjws = 0;  
    }

    //pM = millis();
    delay(3000);
  }
}

void TampilYoutubeData()  {  

  static unsigned long pM;
  unsigned long cM = millis();
  static uint8_t y;
  static uint8_t d;  

  if (intro == true) {

    if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart6x8);
      textCenter1PKanan(0,"$");
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(8,"YOUTUBE");
    }
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(4,"$Youtube");
    }
    
  }  
  
  getyoutubejson();

  if(cM - pM > 35) {
    intro = false;
    if(d == 0 and y < 20) {
      pM=cM;
      y++;
    }
    if(d  == 1 and y > 0) {
      pM=cM;
      y--;
    }    
  }
  
  if(cM - pM > 10000 and y == 20) {
    d=1;
  }
  
  if(y == 0 and d == 1) {
    intro = true;
    getdata = true;
    d=0;
    tmpjws = 0;
  }  

  if (configdisp.panel == 1) {
    Disp.drawRect(0, y - 20 + 7, Disp.width(), y - 20 + 7,0,0);
    Disp.setFont(ElektronMart6x8);
    textCenter1PKanan(y - 20, "$");
    Disp.setFont(ElektronMart5x6);
    textCenter1PKanan(y - 20 + 8, subs);
    Disp.drawRect(0, y - 20 + 16, Disp.width(), y - 20 + 16,0,0);
  }
  if (configdisp.panel == 2) {
    Disp.drawRect(0, y - 20 + 7, Disp.width(), y - 20 + 7,0,0);
    Disp.setFont(ElektronMart6x8);
    Disp.drawText(1,y - 20, subs);
    Disp.drawText(1,y - 20 + 8, view);
    Disp.drawRect(0, y - 20 + 16, Disp.width(), y - 20 + 16,0,0);
  }
  
}
