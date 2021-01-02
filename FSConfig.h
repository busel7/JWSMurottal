// PrayerTimes
double times[sizeof(TimeName)/sizeof(char*)];
int ihti = 2;

uint8_t tmpinfo;

String XML;

// Durasi waktu iqomah
struct ConfigJws {
  int iqmhs;
  int iqmhd;
  int iqmha;
  int iqmhm;
  int iqmhi;
  int durasiadzan;
  int ihti; // Koreksi Waktu Menit Jadwal Sholat
  float latitude;
  float longitude;
  int zonawaktu;  
};

struct ConfigInfo {
  char nama[64];
  char info1[512];
  char info2[512];
};

int iqmh;
int menitiqmh;
int detikiqmh = 60;

struct ConfigWifi {
  char wifissid[64];
  char wifipassword[64];
  char ssid[64];
  char password[64];
};

struct ConfigDisp {
  int kecerahan;
  int panel;
};

// Setting Panel
uint8_t intro1p;

struct ConfigDf {
  int volume;
};

String jsonjws;

const char *fileconfigdisp = "/configdisp.json";
ConfigDisp configdisp;

const char *fileconfigdf = "/configdf.json";
ConfigDf configdf;

const char *fileconfigjws = "/configjws.json";
ConfigJws configjws;

const char *fileconfiginfo = "/configinfo.json";
ConfigInfo configinfo;

const char *fileconfigwifi = "/configwifi.json";
ConfigWifi configwifi;



void LoadDataAwal() {


  if (configjws.iqmhs == 0) {
    configjws.iqmhs = 12;    
  }

  if (configjws.iqmhd == 0) {
    configjws.iqmhd = 8;    
  }

  if (configjws.iqmha == 0) {
    configjws.iqmha = 6;    
  }

  if (configjws.iqmhm == 0) {
    configjws.iqmhm = 5;    
  }

  if (configjws.iqmhi == 0) {
    configjws.iqmhi = 5;    
  }

  if (configjws.durasiadzan == 0) {
    configjws.durasiadzan = 1;    
  }

  if (configjws.ihti == 0) {
    configjws.ihti = 2;    
  }

  if (configjws.latitude == 0) {
    configjws.latitude = -6.16;    
  }

  if (configjws.longitude == 0) {
    configjws.longitude = 106.61;    
  }

  if (configjws.zonawaktu == 0) {
    configjws.zonawaktu = 7;    
  }

  if (strlen(configinfo.nama) == 0) {
    strlcpy(configinfo.nama, "MASJID AL KAUTSAR", sizeof(configinfo.nama));
  }

  if (strlen(configinfo.info1) == 0) {
    strlcpy(configinfo.info1, "www.grobak.net", sizeof(configinfo.info1));
  }

  if (strlen(configinfo.info2) == 0) {
    strlcpy(configinfo.info2, "www.elektronmart.com", sizeof(configinfo.info2));
  }

  if (strlen(configwifi.wifissid) == 0) {
    strlcpy(configwifi.wifissid, "grobak.net", sizeof(configwifi.wifissid));
  }

  if (strlen(configwifi.ssid) == 0) {
    strlcpy(configwifi.ssid, "JWS Murottal", sizeof(configwifi.ssid));
  }

  if (strlen(configwifi.password) == 0) {
    strlcpy(configwifi.password, "1000masjid", sizeof(configwifi.password));
  }


  if (configdisp.kecerahan == 0) {
    configdisp.kecerahan = 100;    
  }

  if (configdisp.panel == 0) {
    configdisp.panel = 1;
  }

  if (configdf.volume == 0) {
    configdf.volume = 20;    
  }
  
}


void loadDispConfig(const char *fileconfigdisp, ConfigDisp &configdisp) {

  File configFileDisp = SPIFFS.open(fileconfigdisp, "r");

  if (!configFileDisp) {
    Serial.println("Gagal membuka fileconfigdisp untuk dibaca");
    return;
  }

  size_t size = configFileDisp.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileDisp.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());

  if (error) {
    Serial.println("Gagal parse fileconfigdisp");
    return;
  }  
  
  configdisp.kecerahan = doc["kecerahan"];
  configdisp.panel = doc["panel"];

  configFileDisp.close();

}



void handleSettingDispUpdate(String datadisp) {

  timer0_detachInterrupt();  
  
  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datadisp);

  File configFileDisp = SPIFFS.open(fileconfigdisp, "w");
  
  if (!configFileDisp) {
    Serial.println("Gagal membuka Display configFile untuk ditulis");
    return;
  }
  
  serializeJson(doc, configFileDisp);

  if (error) {
    
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
    
  } else {
    
    configFileDisp.close();
    Serial.println("Berhasil mengubah configFileDisp");


    loadDispConfig(fileconfigdisp, configdisp);
    
    Disp_init();

    Disp.setBrightness(configdisp.kecerahan);
    Disp.clear();
  
  }  

}


void loadDfConfig(const char *fileconfigdf, ConfigDf &configdf) {  

  File configFileDf = SPIFFS.open(fileconfigdf, "r");

  if (!configFileDf) {
    Serial.println("Gagal membuka fileconfigdf untuk dibaca");
    return;
  }

  size_t size = configFileDf.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileDf.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());  

  if (error) {
    Serial.println("Gagal parse fileconfigdf");
    return;
  }
  
  configdf.volume = doc["volume"];

  configFileDf.close();

}



void handleSettingDfUpdate(String datadf) {

  timer0_detachInterrupt();

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datadf);

  File configFileDf = SPIFFS.open(fileconfigdf, "w");
  
  if (!configFileDf) {
    Serial.println("Gagal membuka DFPlayer configFile untuk ditulis");
    return;
  }
  
  serializeJson(doc, configFileDf);

  if (error) {
    
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
    
  } else {
    
    configFileDf.close();
    Serial.println("Berhasil mengubah configFileDf");


    loadDfConfig(fileconfigdf, configdf);

    timer0_attachInterrupt(refresh);
 
    mp3.setVolume(configdf.volume);
  
  }  

}



void loadInfoConfig(const char *fileconfiginfo, ConfigInfo &configinfo) {  

  File configFileInfo = SPIFFS.open(fileconfiginfo, "r");

  if (!configFileInfo) {
    Serial.println("Gagal membuka fileconfiginfo untuk dibaca");
    return;
  }

  size_t size = configFileInfo.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileInfo.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());

  if (error) {
    Serial.println("Gagal parse fileconfiginfo");
    return;
  }  
  
  strlcpy(configinfo.nama, doc["nama"] | "MASJID AL KAUTSAR", sizeof(configinfo.nama));
  strlcpy(configinfo.info1, doc["info1"] | "Ini adalah isi INFO 1", sizeof(configinfo.info1));
  strlcpy(configinfo.info2, doc["info2"] | "Ini adalah isi INFO 2", sizeof(configinfo.info2));

  configFileInfo.close();

}



void handleSettingInfoUpdate(String datainfo) {

  timer0_detachInterrupt();

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datainfo);

  File configFileInfo = SPIFFS.open(fileconfiginfo, "w");
  
  if (!configFileInfo) {
    Serial.println("Gagal membuka configFileInfo untuk ditulis");
    return;
  }
  
  serializeJson(doc, configFileInfo);

  if (error) {
    
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
    
  } else {
    
    configFileInfo.close();
    Serial.println("Berhasil mengubah configFileInfo");


    loadInfoConfig(fileconfiginfo, configinfo);

    timer0_attachInterrupt(refresh);
  
  }  

}



void loadJwsConfig(const char *fileconfigjws, ConfigJws &configjws) {  

  File configFileJws = SPIFFS.open(fileconfigjws, "r");

  if (!configFileJws) {
    Serial.println("Gagal membuka fileconfigjws untuk dibaca");
    return;
  }

  size_t size = configFileJws.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileJws.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());  

  if (error) {
    Serial.println("Gagal parse fileconfigjws");
    return;
  }
  
  configjws.iqmhs = doc["iqmhs"];
  configjws.iqmhd = doc["iqmhd"];
  configjws.iqmha = doc["iqmha"];
  configjws.iqmhm = doc["iqmhm"];
  configjws.iqmhi = doc["iqmhi"];
  configjws.durasiadzan = doc["durasiadzan"];
  configjws.ihti = doc["ihti"];
  configjws.latitude = doc["latitude"];
  configjws.longitude = doc["longitude"];
  configjws.zonawaktu = doc["zonawaktu"];

  configFileJws.close(); 

}



void handleSettingJwsUpdate(String datajws) {

  timer0_detachInterrupt();

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datajws);

  File configFileJws = SPIFFS.open(fileconfigjws, "w");
  
  if (!configFileJws) {
    Serial.println("Gagal membuka Info configFileJws untuk ditulis");
    return;
  }
  
  serializeJson(doc, configFileJws);

  if (error) {
    
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
    
  } else {
    
    configFileJws.close();
    Serial.println("Berhasil mengubah configFileJws");


    loadJwsConfig(fileconfigjws, configjws);

    timer0_attachInterrupt(refresh);
  
  }  

}



void loadWifiConfig(const char *fileconfigwifi, ConfigWifi &configwifi) {  

  File configFileWifi = SPIFFS.open(fileconfigwifi, "r");

  if (!configFileWifi) {
    Serial.println("Gagal membuka fileconfigwifi untuk dibaca");
    return;
  }

  size_t size = configFileWifi.size();
  std::unique_ptr<char[]> buf(new char[size]);
  configFileWifi.readBytes(buf.get(), size);

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, buf.get());  

  if (error) {
    Serial.println("Gagal parse fileconfigwifi");
    return;
  }
  
  strlcpy(configwifi.wifissid, doc["wifissid"] | "grobak.net", sizeof(configwifi.wifissid));
  strlcpy(configwifi.wifipassword, doc["wifipassword"] | "12345", sizeof(configwifi.wifipassword));
  strlcpy(configwifi.ssid, doc["ssid"] | "grobak.net", sizeof(configwifi.wifissid));
  strlcpy(configwifi.password, doc["password"] | "12345", sizeof(configwifi.wifipassword));

  configFileWifi.close();

}



void handleSettingWifiUpdate(String datawifi) {

  timer0_detachInterrupt();

  DynamicJsonDocument doc(1024);
  DeserializationError error = deserializeJson(doc, datawifi);

  File configFileWifi = SPIFFS.open(fileconfigwifi, "w");
  
  if (!configFileWifi) {
    Serial.println("Gagal membuka Info configFileWifi untuk ditulis");
    return;
  }
  
  serializeJson(doc, configFileWifi);

  if (error) {
    
    Serial.print(F("deserializeJson() gagal kode sebagai berikut: "));
    Serial.println(error.c_str());
    return;
    
  } else {
    
    configFileWifi.close();
    Serial.println("Berhasil mengubah configFileWifi");

    loadWifiConfig(fileconfigwifi, configwifi);

    timer0_attachInterrupt(refresh);    
  
  }

}


void JadwalSholat() {

  /*
    CALCULATION METHOD
    ------------------
    Jafari,   // Ithna Ashari
    Karachi,  // University of Islamic Sciences, Karachi
    ISNA,     // Islamic Society of North America (ISNA)
    MWL,      // Muslim World League (MWL)
    Makkah,   // Umm al-Qura, Makkah
    Egypt,    // Egyptian General Authority of Survey
    Custom,   // Custom Setting

    JURISTIC
    --------
    Shafii,    // Shafii (standard)
    Hanafi,    // Hanafi

    ADJUSTING METHOD
    ----------------
    None,        // No adjustment
    MidNight,   // middle of night
    OneSeventh, // 1/7th of night
    AngleBased, // angle/60th of night

    TIME IDS
    --------
    Fajr,
    Sunrise,
    Dhuhr,
    Asr,
    Sunset,
    Maghrib,
    Isha
  
  */

  RtcDateTime now = Rtc.GetDateTime();
  
  int tahun = now.Year();
  int bulan = now.Month();
  int tanggal = now.Day();
  
  set_calc_method(Karachi);
  set_asr_method(Shafii);
  set_high_lats_adjust_method(AngleBased);
  set_fajr_angle(20);
  set_isha_angle(18);

  get_prayer_times(tahun, bulan, tanggal, configjws.latitude, configjws.longitude, configjws.zonawaktu, times);

}


//----------------------------------------------------------------------
// XML UNTUK JEMBATAN DATA MESIN DENGAN WEB

void realXML(){

  RtcDateTime now = Rtc.GetDateTime();
  RtcTemperature temp = Rtc.GetTemperature();

  XML="<?xml version='1.0'?>";
  XML+="<t>";
    XML+="<rYear>";
    XML+=now.Year();
    XML+="</rYear>";
    XML+="<rMonth>";
    XML+=now.Month();
    XML+="</rMonth>";
    XML+="<rDay>";
    XML+=now.Day();
    XML+="</rDay>";
    XML+="<rHour>";
      if(now.Hour()<10){
        XML+="0";
        XML+=now.Hour();
      }else{    XML+=now.Hour();}
    XML+="</rHour>";
    XML+="<rMinute>";
      if(now.Minute()<10){
        XML+="0";
        XML+=now.Minute();
      }else{    XML+=now.Minute();}
    XML+="</rMinute>";
    XML+="<rSecond>";
      if(now.Second()<10){
        XML+="0";
        XML+=now.Second();
      }else{    XML+=now.Second();}
    XML+="</rSecond>";
    XML+="<rTemp>";
    XML+= temp.AsFloatDegC() - 5;
    XML+="</rTemp>";
    XML+="<rVolume>";
    XML+= configdf.volume;
    XML+="</rVolume>";
    XML+="<rKecerahan>";
    XML+= configdisp.kecerahan;
    XML+="</rKecerahan>";    
  XML+="</t>"; 
}

void buildXML(){

  JadwalSholat();

  static uint8_t i;
  int hours, minutes;
  char jtanbih[14];
  char jsubuh[14];
  char jdzuhur[14];
  char jashar[14];
  char jmaghrib[14];
  char jisya[14];

  get_float_time_parts(times[0], hours, minutes);
  minutes = minutes + configjws.ihti;
  if (minutes < 11) {
    minutes = 60 - minutes;
    hours --;
  } else {
    minutes = minutes - 10 ;
  }
  sprintf(jtanbih,"Tanbih %02d:%02d", hours, minutes);
  
  get_float_time_parts(times[0], hours, minutes);  
  minutes = minutes + configjws.ihti;
  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }  
  sprintf(jsubuh,"Subuh %02d:%02d", hours, minutes);
  
  get_float_time_parts(times[2], hours, minutes);  
  minutes = minutes + configjws.ihti;
  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }  
  sprintf(jdzuhur,"Dzuhur %02d:%02d", hours, minutes);

  get_float_time_parts(times[3], hours, minutes);  
  minutes = minutes + configjws.ihti;
  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }  
  sprintf(jashar,"Ashar %02d:%02d", hours, minutes);

  get_float_time_parts(times[5], hours, minutes);  
  minutes = minutes + configjws.ihti;
  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }  
  sprintf(jmaghrib,"Maghrib %02d:%02d", hours, minutes);

  get_float_time_parts(times[6], hours, minutes);  
  minutes = minutes + configjws.ihti;
  if (minutes >= 60) {
    minutes = minutes - 60;
    hours ++;
  }  
  sprintf(jisya,"Isya %02d:%02d", hours, minutes);

  XML="<?xml version='1.0'?>";
  XML+="<t>";
    XML+="<rWifissid>";
    XML+= configwifi.wifissid;
    XML+="</rWifissid>";
    XML+="<rWifipassword>";
    XML+= configwifi.wifipassword;
    XML+="</rWifipassword>";
    XML+="<rSsid>";
    XML+= configwifi.ssid;
    XML+="</rSsid>";
    XML+="<rPassword>";
    XML+= configwifi.password;
    XML+="</rPassword>";    
    
    XML+="<rIqmhs>";
    XML+= configjws.iqmhs;
    XML+="</rIqmhs>";
    XML+="<rIqmhd>";
    XML+= configjws.iqmhd;
    XML+="</rIqmhd>";
    XML+="<rIqmha>";
    XML+= configjws.iqmha;
    XML+="</rIqmha>";
    XML+="<rIqmhm>";
    XML+= configjws.iqmhm;
    XML+="</rIqmhm>";
    XML+="<rIqmhi>";
    XML+= configjws.iqmhi;
    XML+="</rIqmhi>";
    XML+="<rDurasiAdzan>";
    XML+= configjws.durasiadzan;
    XML+="</rDurasiAdzan>";
    XML+="<rIhti>";
    XML+= configjws.ihti;
    XML+="</rIhti>";
    XML+="<rLatitude>";
    XML+= configjws.latitude;
    XML+="</rLatitude>";
    XML+="<rLongitude>";
    XML+= configjws.longitude;
    XML+="</rLongitude>";
    XML+="<rZonaWaktu>";
    XML+= configjws.zonawaktu;
    XML+="</rZonaWaktu>";
    
    XML+="<rNama>";
    XML+= configinfo.nama;
    XML+="</rNama>";
    XML+="<rInfo1>";
    XML+= configinfo.info1;
    XML+="</rInfo1>";
    XML+="<rInfo2>";
    XML+= configinfo.info2;
    XML+="</rInfo2>";

    XML+="<rTanbih>";
    XML+= jtanbih;
    XML+="</rTanbih>";
    XML+="<rSubuh>";
    XML+= jsubuh;
    XML+="</rSubuh>";
    XML+="<rDzuhur>";
    XML+= jdzuhur;
    XML+="</rDzuhur>";
    XML+="<rAshar>";
    XML+= jashar;
    XML+="</rAshar>";
    XML+="<rMaghrib>";
    XML+= jmaghrib;
    XML+="</rMaghrib>";
    XML+="<rIsya>";
    XML+= jisya;
    XML+="</rIsya>";

    XML+="<rPanel>";
    XML+= configdisp.panel;
    XML+="</rPanel>";
  XML+="</t>"; 
}
