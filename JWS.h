// BUZZER
const int buzzer = 3; // Pin GPIO Buzzer - RX


//----------------------------------------------------------------------
// FORMAT TEKS

void textCenter(int y,String Msg) {
  
  int center = int((Disp.width()-Disp.textWidth(Msg)) / 2);
  Disp.drawText(center,y,Msg);
  
}

void textCenter1PKanan(int y,String Msg) {
  
  int center = ((Disp.width()-Disp.textWidth(Msg)) / 2) + (Disp.width() / 4);
  Disp.drawText(center,y,Msg);
  
}


//----------------------------------------------------------------------
//TAMPILKAN JADWAL SHOLAT




//----------------------------------------------------------------------
// BUNYIKAN BEEP BUZZER

void BuzzerPanjang() {
  
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(3000);
  
}

void BuzzerPendek() {
  
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(3000);
  
}

void BunyiBeep() {

  static uint32_t pMBuz;
  uint32_t cM = millis();
  static boolean beep;  
  
  if (cM - pMBuz >= 200) {
   
    pMBuz = cM;

    beep = !beep;    
        
  }

  if (beep) {

    digitalWrite(buzzer, HIGH);
    
  } else {
    
    digitalWrite(buzzer, LOW);
    
  }
 
}



//----------------------------------------------------------------------
// ALARM SHOLAT BERJALAN SAAT MASUK WAKTU SHOLAT

void AlarmSholat() {

  RtcDateTime now = Rtc.GetDateTime();  

  int Hari = now.DayOfWeek();
  int Hor = now.Hour();
  int Min = now.Minute();
  int Sec = now.Second();
  int durasiadzan = configjws.durasiadzan * 60000;

  JadwalSholat();

  int hours, minutes, seconds;

  // Tanbih Imsak
  get_float_time_parts(times[0], hours, minutes);
  minutes = minutes + configjws.ihti;

  if (minutes < 10) {
    
    minutes = 60 - minutes;
    hours --;
    
  } else {
    
    minutes = minutes - 10 ;
    
  }

  if (Hor == hours && Min == minutes) {

    mp3.stop();    
    Disp.clear();
    
    if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "TANBIH");
      textCenter1PKanan(8, "IMSAK");
    }
    
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(0, "TANBIH");
      textCenter(8, "IMSAK");
    }
    
    mp3.playFolderTrack(1, 2);
    delay(1000);
    mp3.playFolderTrack(1, 2);
    delay(1000);
    mp3.playFolderTrack(1, 2);
    delay(1000);
    mp3.stop();
    delay(configjws.durasiadzan);    
    Disp.clear();

  }

  // Subuh
  get_float_time_parts(times[0], hours, minutes);
  minutes = minutes + configjws.ihti;

  if (minutes >= 60) {
    
    minutes = minutes - 60;
    hours ++;
    
  }

  if (Hor == hours && Min == minutes) {

    mp3.stop();
    //BuzzerPendek();
    Disp.clear();
    
    if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "ADZAN");
      textCenter1PKanan(8, "SUBUH");
    }
    
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(0, "ADZAN");
      textCenter(8, "SUBUH");
    }
    
    mp3.playFolderTrack(1, 1);
    delay(durasiadzan);
    mp3.stop();
    Disp.clear();
    menitiqmh = configjws.iqmhs - 1;
    tmputama = 1;
    
  }


  // Dzuhur
  get_float_time_parts(times[2], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    
    minutes = minutes - 60;
    hours ++;
    
  }

  if (Hor == hours && Min == minutes && Hari != 5) {

    mp3.stop();
    //BuzzerPendek();
    Disp.clear();
    
    if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "ADZAN");
      textCenter1PKanan(8, "DZUHUR");
    }
    
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(0, "ADZAN");
      textCenter(8, "DZUHUR");
    }
    
    mp3.playFolderTrack(1, 1);
    delay(durasiadzan);
    mp3.stop();
    Disp.clear();
    menitiqmh = configjws.iqmhd - 1;
    tmputama = 1;

  } else if (Hor == hours && Min == minutes && Hari == 5) {

    mp3.stop();
    //BuzzerPendek();
    Disp.clear();
    Disp.setFont(ElektronMart6x8);
    if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "ADZAN");
      textCenter1PKanan(8, "JUM'AT");
    }
    
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(0, "ADZAN");
      textCenter(8, "JUM'AT");
    }
    mp3.playFolderTrack(1, 1);
    delay(durasiadzan);
    mp3.stop();
    tmputama = 1;

  }


  // Ashar
  get_float_time_parts(times[3], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    
    minutes = minutes - 60;
    hours ++;
    
  }

  if (Hor == hours && Min == minutes) {

    mp3.stop();
    //BuzzerPendek();
    Disp.clear();
    
    if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "ADZAN");
      textCenter1PKanan(8, "ASHAR");
    }
    
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(0, "ADZAN");
      textCenter(8, "ASHAR");
    }

    mp3.playFolderTrack(1, 1);
    delay(durasiadzan);
    mp3.stop();
    Disp.clear();
    menitiqmh = configjws.iqmha - 1;
    tmputama = 1;
    
  }

  // Maghrib
  get_float_time_parts(times[5], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    
    minutes = minutes - 60;
    hours ++;
    
  }

  if (Hor == hours && Min == minutes) {

    mp3.stop();
    //BuzzerPendek();
    Disp.clear();
    
    if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "ADZAN");
      textCenter1PKanan(8, "MAGHRIB");
    }
    
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(0, "ADZAN");
      textCenter(8, "MAGHRIB");
    }

    mp3.playFolderTrack(1, 1);
    delay(durasiadzan);
    mp3.stop();
    Disp.clear();
    menitiqmh = configjws.iqmhm - 1;
    tmputama = 1;
    
  }

  // Isya'
  get_float_time_parts(times[6], hours, minutes);
  minutes = minutes + ihti;

  if (minutes >= 60) {
    
    minutes = minutes - 60;
    hours ++;
    
  }

  if (Hor == hours && Min == minutes) {

    mp3.stop();
    //BuzzerPendek();
    Disp.clear();
    
    if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "ADZAN");
      textCenter1PKanan(8, "ISYA");
    }
    
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(0, "ADZAN");
      textCenter(8, "ISYA");
    }

    mp3.playFolderTrack(1, 1);
    delay(durasiadzan);
    mp3.stop();
    Disp.clear();
    menitiqmh = configjws.iqmhi - 1;
    tmputama = 1;
    
  }  
  
}


//----------------------------------------------------------------------
// HITUNG MUNDUR WAKTU SETELAH ADZAN SAMPAI MULAI IQOMAH

void Iqomah() {

  static uint32_t pMIqmh;
  uint32_t cM = millis();
  static char hitungmundur[6];

  if (configdisp.panel == 1) {
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "IQOMAH");
    }
    
    if (configdisp.panel == 2) {
      Disp.setFont(ElektronMart6x8);
      textCenter(0, "IQOMAH");
    }

  if (detikiqmh == 60) {
    detikiqmh = 0;
  }  

  if(cM - pMIqmh >= 1000) {
    
    pMIqmh = cM;    
    detikiqmh--;
    
    if (menitiqmh <= 0 && detikiqmh <= 0){
        Disp.clear();

        if (configdisp.panel == 1) {
          Disp.setFont(ElektronMart5x6);
          textCenter1PKanan(0, "LURUS");
          textCenter1PKanan(8, "RAPATKAN");
        }
        
        if (configdisp.panel == 2) {
          Disp.setFont(ElektronMart5x6);
          textCenter(0, "LURUSKAN DAN");
          textCenter(8, "RAPATKAN SHAF");
        }
        
        //BuzzerPanjang();
        mp3.playFolderTrack(1, 2);    
        delay(1000);
        mp3.playFolderTrack(1, 2);    
        delay(1000);
        mp3.playFolderTrack(1, 2);    
        delay(1000);
        mp3.stop();        
        delay(10000);        
        detikiqmh = 59;
        Disp.clear();
        delay(3000);
        menitiqmh = 0;
        tmputama = 0;
    }

    if (detikiqmh < 0) {
      detikiqmh = 59;
      menitiqmh--;            
    }
    
  }

  sprintf(hitungmundur, "%02d:%02d", menitiqmh, detikiqmh);

  if (configdisp.panel == 1) {
    Disp.setFont(ElektronMart5x6);
    textCenter1PKanan(8, hitungmundur);
  }
  
  if (configdisp.panel == 2) {
    Disp.setFont(ElektronMart6x8);
    textCenter(8, hitungmundur);
  }
  
}



void TampilJadwalSholat() {

  JadwalSholat();

  static uint8_t i;
  static uint32_t pM;
  uint32_t cM = millis();
  
  char sholat[7];
  char jam[5];
  char TimeName[][8] = {"SUBUH","TERBIT","DZUHUR","ASHAR","TRBNM","MAGHRIB","ISYA"};
  int hours, minutes;  

  if (cM - pM >= 3000) {
    
    pM = cM;
    Disp.drawRect(31,0,64,15,0,0);

    if (i == 1) {i = 2;} // Abaikan Terbit
    if (i == 4) {i = 5;} // Abaikan Terbenam

    get_float_time_parts(times[i], hours, minutes);
  
    minutes = minutes + ihti;

    if (minutes >= 60) {
      minutes = minutes - 60;
      hours ++;
    }

    String sholat = TimeName[i];
    sprintf(jam,"%02d:%02d", hours, minutes);     
    
    Disp.setFont(ElektronMart5x6);
    textCenter1PKanan(0, sholat);
    textCenter1PKanan(8, jam);

    i++;

    if (i > 7) {
      get_float_time_parts(times[0], hours, minutes);
      minutes = minutes + ihti;
      if (minutes < 11) {
        minutes = 60 - minutes;
        hours --;
      } else {
        minutes = minutes - 10 ;
      }
      sprintf(jam,"%02d:%02d", hours, minutes);
      Disp.drawRect(32,0,63,15,0,0);
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, "TANBIH");
      textCenter1PKanan(8, jam);
      
      if (i > 8) {
        i = 0;
        Disp.drawRect(0,0,63,15,0,0);
        tmpinfo = 0;
        tmpjws = 2;
      }
      
    }      
    
  }
  
}



//----------------------------------------------------------------------
//TAMPILKAN TANGGAL

void TampilTanggal() {

  RtcDateTime now = Rtc.GetDateTime();

  char hari[8];
  char tanggal[7]; // 21 SEP

  static uint32_t pM;
  uint32_t cM = millis();

  static uint8_t flag;

  if(cM - pM > 3000) {
    
    pM = cM;
    flag++;

    sprintf(hari, "%s", weekDay[now.DayOfWeek()]);
    sprintf(tanggal, "%02d %s", now.Day(), monthYear[now.Month()]);
  
    Disp.setFont(ElektronMart5x6);
    textCenter1PKanan(0, hari);
    textCenter1PKanan(8, tanggal);

    if (flag >= 2) {
      flag = 0;
      Disp.drawRect(32,0,63,15,0,0);
      tmpinfo = 1;
      
    }
    
  } 
  
}



//----------------------------------------------------------------------
// TAMPILKAN SUHU

void TampilSuhu() {

  RtcTemperature temp = Rtc.GetTemperature();
  int celsius = temp.AsFloatDegC();

  char suhu[3];
  int koreksisuhu = 5; // Perkiraan selisih suhu mesin dengan suhu ruangan

  static uint32_t pM;
  uint32_t cM = millis();

  static uint8_t flag;

  if(cM - pM > 3000) {
    
    pM = cM;
    flag++;

    sprintf(suhu, "%02d*C", celsius - koreksisuhu);
    
    Disp.setFont(ElektronMart5x6);
    textCenter1PKanan(0, "SUHU");
    textCenter1PKanan(8, suhu);

    if (flag >= 2) {
      flag = 0;
      Disp.drawRect(32,0,64,15,0,0);
      tmpinfo = 2;
      
    }
  
  }
  
}



//----------------------------------------------------------------------
// TAMPILKAN JAM

void JamBesar(uint16_t x) {

  RtcDateTime now = Rtc.GetDateTime();

  char jam[3];
  char menit[3];
  char detik[3];

  sprintf(jam, "%02d", now.Hour());
  sprintf(menit, "%02d", now.Minute());
  sprintf(detik, "%02d", now.Second());

  static boolean huruf;

  static uint8_t y;
  static uint8_t d;           
  static uint32_t pM;
  uint32_t cM = millis();

  static uint32_t pMPulse;
  static uint8_t pulse;

  if (cM - pMPulse >= 100) {
    pMPulse = cM;
    pulse++;
  }
  
  if (pulse > 8) {
    pulse=0;
  }

  if(cM - pM > 35) { 
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
  
  if(y == 20) {
    Disp.drawRect(x+15,3+pulse,x+18,11-pulse,0,1);       
  }
  
  if(y < 20) {
    Disp.drawRect(x+15,3,x+18,11,0,0);
  }
   
  if(y == 0 and d == 1) {
    d=0;
    huruf = !huruf;
    if (configdisp.panel == 1) {
      tmpjws = 1;
    }
  }
  
  //JAM
  if (huruf) {
    Disp.setFont(ElektronMart6x16);
  } else {
    Disp.setFont(ElektronMartArabic6x16);
  }  
  Disp.drawText(x+1, y - 20, jam);

  //MENIT
  if (huruf) {
    Disp.setFont(ElektronMart5x6);
  } else {
    Disp.setFont(ElektronMartArabic5x6);
  }  
  Disp.drawText(x+20, y - 20, menit);

  //DETIK          
  if (huruf) {
    Disp.setFont(ElektronMart5x6);
  } else {
    Disp.setFont(ElektronMartArabic5x6);
  }  
  Disp.drawText(x+20, y - 20 + 8, detik);
  
}


void JamBesar2(uint16_t x) {

  RtcDateTime now = Rtc.GetDateTime();

  char jam[3];
  char menit[3];

  sprintf(jam, "%02d", now.Hour());
  sprintf(menit, "%02d", now.Minute());

  static boolean huruf;

  static uint8_t y;
  static uint8_t d;           
  static uint32_t pM;
  uint32_t cM = millis();

  static uint32_t pMPulse;
  static uint8_t pulse;

  if (cM - pMPulse >= 100) {
    
    pMPulse = cM;
    pulse++;
    
  }

  if (pulse > 8) {
    pulse=0;
  }

  if(cM - pM > 35) { 
    
    if(d == 0 and y < 20) {
      pM = cM;
      y++;
    }
    
    if(d  == 1 and y > 0) {
      pM = cM;      
      y--;
    }

  }

  if(cM - pM > 10000 and y == 20) {
    d=1;
  }

  if(y == 20) {
    Disp.drawRect(x+14,3+pulse,x+17,11-pulse,0,1);       
  }

  if(y < 20) {
    Disp.drawRect(x+14,3,x+18,17,0,0);
  }

  if(y == 0 and d == 1) {
    d=0;
    huruf = !huruf;
    Disp.clear();
  }

  //JAM
  if (huruf) {
    Disp.setFont(ElektronMart6x16);
  } else {
    Disp.setFont(ElektronMartArabic6x16);
  }  
  Disp.drawText(x+1, y - 20, jam);


  //MENIT
  if (huruf) {
    Disp.setFont(ElektronMart6x16);
  } else {
    Disp.setFont(ElektronMartArabic6x16);
  }  
  Disp.drawText(x+18, y - 20, menit);

  
  
  
}


void TampilJamKecil() {

  static uint32_t pMJam;
  uint32_t cM = millis();
  
  RtcDateTime now = Rtc.GetDateTime();
  char jam[9];
  
  if (cM - pMJam >= 1000) {
   
    pMJam = cM;
    
    //JAM
    if (configdisp.panel == 1) {
      sprintf(jam,"%02d:%02d", now.Hour(), now.Minute());
      Disp.setFont(ElektronMart5x6);
      textCenter1PKanan(0, jam);
    }
    if (configdisp.panel == 2) {
      sprintf(jam,"! %02d:%02d:%02d", now.Hour(), now.Minute(), now.Second());
      Disp.setFont(ElektronMart5x6);
      textCenter(0, jam);
    }    
        
  }
 
}



//----------------------------------------------------------------------
// ANIMASI LOGO

void LogoA(uint32_t x) {

  static const uint8_t LogoA[] PROGMEM = {

    16, 16,

    0x00, 0x00, 0x7f, 0xfe, 0x7f, 0xfe, 0x00, 0x00, 0x7e, 0x66, 0x7e, 0x66, 0x06, 0x66, 0x06, 0x66, 0x7e, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7f, 0xfe, 0x7f, 0xfe, 0x00, 0x00

  };
  
  Disp.drawBitmap(x, 0, LogoA);
}


void LogoM(uint32_t x) {

  static const uint8_t LogoM[] PROGMEM = {

    16, 16,

    0x00, 0x00, 0x66, 0x7e, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x7e, 0x7e, 0x7e, 0x60, 0x60, 0x60, 0x60, 0x7e, 0x7e, 0x7e, 0x7e, 0x66, 0x06, 0x66, 0x06, 0x7f, 0xfe, 0x7f, 0xfe, 0x00, 0x00

  };
  
  Disp.drawBitmap(x, 0, LogoM);
}

void animLogoX() {

  static uint8_t x;
  static uint8_t s; // 0=in, 1=out
  static uint32_t pM;
  uint32_t cM = millis();
  int margin;

  if (configdisp.panel == 1) {
    margin = 32;
  }

  if (configdisp.panel == 2) {
    margin = 0;
    JamBesar2(16);
  }
  

  if (cM - pM > 35) {
    
    if (s == 0 and x < 16) {
      
      pM = cM;
      x++;
      
    }
    
    if (s == 1 and x > 0) {
      
      pM = cM;
      x--;
      
    }
    
  }
  
  if (cM - pM > 10000 and x == 16) {
    
    s = 1; 
       
  }

  if (x == 0 and s == 1) {    
    
    s = 0;
    if (configdisp.panel == 1) {
      Disp.clear();      
      intro1p = 1;
    }

    if (configdisp.panel == 2) {
      Disp.clear();
      tmpjws = 1;
    }    
     
  }

  LogoA(Disp.width() - x);
  LogoM(x - 16 + margin);  

}



//----------------------------------------------------------------------
//TAMPILKAN RUNNING TEKS


static char *nama1[] = {configinfo.nama};

void TeksBerjalanKananKiri() {

  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t Kecepatan = 50;
  static uint32_t x;
  int width = Disp.width();
  int margin;

  int fullScroll = Disp.textWidth(nama1[0]) + width;

  Disp.setFont(ElektronMart6x8);
  
  if (configdisp.panel == 1) {
    textCenter1PKanan(0,"#");
    margin = 32;
    Disp.drawRect(0,0,31,15,0,0);
  }
  
  if (configdisp.panel == 2) {
    textCenter(0,"#");
    margin = 0;
  }
  
  Disp.drawRect(0,6,Disp.width(),6,1,1);

  if(cM - pM > Kecepatan) {

    pM = cM;

    if (x < fullScroll - margin) {

      ++x;
      
    } else {

      x = 0;
      Disp.clear();
      tmpjws = 3;
      
    }

    Disp.drawText(width - x, 8, nama1[0]);
    
  }
  
}



//-------------------------------------------------------
// TAMPILKAN SCROLLING TEKS INFO1

static char *info1[] = {configinfo.info1};

void TeksJalanInfo1() {

  TampilJamKecil();
  
  static uint32_t pM;
  static uint32_t x;
  static uint32_t Speed = 50;
  int width = Disp.width();
  int margin;

  if(configdisp.panel == 1) {
    margin = 32;
    Disp.drawRect(0,0,31,15,0,0);
  }
  if(configdisp.panel == 2) {
    margin = 0;
  }
  
  Disp.setFont(ElektronMart6x8);
  
  int fullScroll = Disp.textWidth(info1[0]) + width;
  
  if((millis() - pM) > Speed) { 
    pM = millis();
    if (x < fullScroll - margin) {
      ++x;
    } else {
      x = 0;
      tmpjws = 4;
    }
    Disp.drawText(width - x, 8, info1[0]);
  }  

}



//-------------------------------------------------------
// TAMPILKAN SCROLLING TEKS INFO2

static char *info2[] = {configinfo.info2};

void TeksJalanInfo2() {

  TampilJamKecil();

  static uint32_t pM;
  static uint32_t x;
  static uint32_t Speed = 50;
  int width = Disp.width();
  int margin;

  if(configdisp.panel == 1) {
    margin = 32;
    Disp.drawRect(0,0,31,15,0,0);
  }
  if(configdisp.panel == 2) {
    margin = 0;
  }
  
  Disp.setFont(ElektronMart6x8);
  int fullScroll = Disp.textWidth(info2[0]) + width;
  if((millis() - pM) > Speed) { 
    pM = millis();
    if (x < fullScroll - margin) {
      ++x;
    } else {
      x = 0;
      Disp.clear();
      tmpinfo = 0;
      tmpjws = 5;
    }
    Disp.drawText(width - x, 8, info2[0]);
  }

}
