const char webpage[] PROGMEM = 
R"=====(

<!DOCTYPE HTML>
<html>

<meta name='viewport' content='width=device-width, initial-scale=1'>

<head>

<title>JWS Murottal ElektronMart.Com</title>

<style>

input[type=range] { -webkit-appearance: none; margin: 18px 0; width: 87%; 
  border:none; background:none; box-shadow:none;}
input[type=range]:focus { outline: none; }
input[type=range]::-webkit-slider-runnable-track { width: 100%; height: 8.4px;
  cursor: pointer; animate: 0.2s; box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d;
  background: #d62020; border-radius: 1.3px; border: 0.2px solid #010101; }
  
input[type=range]::-webkit-slider-thumb { box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d;
  border: 1px solid #000000; height: 36px; width: 16px; border-radius: 3px;
  background: #ffffff; cursor: pointer; -webkit-appearance: none; margin-top: -14px; }
  
input[type=range]:focus::-webkit-slider-runnable-track { background: #c43e27; }

input[type=range]::-moz-range-track { width: 100%; height: 8.4px; cursor: pointer;
  animate: 0.2s; box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d; 
  background: #d62020; border-radius: 1.3px; border: 0.2px solid #010101; }
  
input[type=range]::-moz-range-thumb { box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d;
  border: 1px solid #000000; height: 36px; width: 16px; border-radius: 3px;
  background: #ffffff; cursor: pointer; }
  
input[type=range]::-ms-track { width: 100%; height: 8.4px; cursor: pointer; animate: 0.2s;
  background: transparent; border-color: transparent; border-width: 16px 0;
  color: transparent; }
  
input[type=range]::-ms-fill-lower { background: #c43e27; border: 0.2px solid #010101;
  border-radius: 2.6px; box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d; }
  
input[type=range]::-ms-fill-upper { background: #d62020; border: 0.2px solid #010101;
  border-radius: 2.6px; box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d; }
  
input[type=range]::-ms-thumb { box-shadow: 1px 1px 1px #000000, 0px 0px 1px #0d0d0d;
  border: 1px solid #000000; height: 36px; width: 16px; border-radius: 3px;
  background: #ffffff; cursor: pointer; }

input[type=range]:focus::-ms-fill-lower { background: #d62020; }

input[type=range]:focus::-ms-fill-upper { background: #c43e27; }

input, textarea, select {
  display: inline-block;
  -webkit-box-sizing: content-box;
  -moz-box-sizing: content-box;
  box-sizing: content-box;
  padding: 10px 20px;
  border: 1px solid #b7b7b7;
  -webkit-border-radius: 3px;
  border-radius: 3px;
  font: normal normal bold 17px/normal "Times New Roman", Times, serif;
  color: rgba(150,30,30,1);
  -o-text-overflow: clip;
  text-overflow: clip;
  background: rgba(252,252,252,1);
  -webkit-box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2) ;
  box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2) ;
  text-shadow: 1px 1px 0 rgba(255,255,255,0.66) ;
  -webkit-transition: all 200ms cubic-bezier(0.42, 0, 0.58, 1);
  -moz-transition: all 200ms cubic-bezier(0.42, 0, 0.58, 1);
  -o-transition: all 200ms cubic-bezier(0.42, 0, 0.58, 1);
  transition: all 200ms cubic-bezier(0.42, 0, 0.58, 1);
}

textarea{
  width : 80%;
  height : 77px;
}

input#nama {
    width: 80%;
}

button {
  display: inline-block;
  -webkit-box-sizing: content-box;
  -moz-box-sizing: content-box;
  box-sizing: content-box;
  cursor: pointer;
  padding: 15px 20px;
  margin-top:50px;
  border: none;
  -webkit-border-radius: 7px;
  border-radius: 25px;
  font: normal normal bold 17px/normal "Times New Roman", Times, serif;
  color: rgba(255,255,255,1);
  -o-text-overflow: clip;
  text-overflow: clip;
  background: #e06666;
  -webkit-box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2);
  box-shadow: 1px 1px 2px 0 rgba(0,0,0,0.2);
  -webkit-transition: all 300ms cubic-bezier(0.42, 0, 0.58, 1);
  -moz-transition: all 300ms cubic-bezier(0.42, 0, 0.58, 1);
  -o-transition: all 300ms cubic-bezier(0.42, 0, 0.58, 1);
  transition: all 300ms cubic-bezier(0.42, 0, 0.58, 1);
}


.play { background-color:#e4685d; -webkit-border-radius:28px; -moz-border-radius:28px;
  border-radius:28px; border:1px solid #ffffff; display:inline-block; cursor:pointer;
  color:#ffffff; font-size:17px; padding:16px 31px;
  text-decoration:none; text-shadow:0px 1px 0px #b23e35; }
  
.play:hover { background-color:#eb675e; }

.play:active { position:relative; top:1px; }

.tombol { background-color:#75986c; -webkit-border-radius:28px; -moz-border-radius:28px;
  border-radius:28px; border:1px solid #ffffff; display:inline-block; cursor:pointer;
  color:#ffffff; font-size:17px; padding:16px 31px;
  text-decoration:none; text-shadow:0px 1px 0px #737373; }

.tombol:hover { background-color:#75986c; }

.tombol:active { position:relative; top:1px; }

label { margin-top: 30px; margin-bottom: 10px; display: block; }

form { text-align: center; }

table { text-align: center; }

hr {
    margin: 47px 10px 47px 10px;
    border: 2px solid #eee;
}

.info { background-color: #eee; border-radius: 25px; padding-top: 17px; margin: 5px;}

p.info {
    padding: 7px;
}

.tautan {
  text-decoration:none;
  color : #ad0303;
}

.footer {
  color : #777777;
}

.footer a{
  text-decoration:none;
  color : #777777;
}

</style>

</head>

<body onload="updateData()">
<center>

  <h1>JWS Murottal</h1>
  <h4><a class ='tautan' href="http://elektronmart.com/" target="_blank">ElektronMart.Com</a></h4>
  <div class='info'>
    <span id='day'></span>/<span id='month'></span>/<span id='year'></span><span> </span>
    <span id='hour'></span>:<span id='minute'></span>:<span id='second'></span><span> </span>
    <span id='temp'></span><span>C</span><br><br>
  </div>
  <h3>Volume</h3>
  <div>
    <input type="range" min="0" max="30" value="15" id="volume" oninput="sendVolume()" />
  </div>
  <br/>
  <div>
    <a href="#" class="play" id="play" onclick="sendPlay()">Play</a>
    <a href="#" class="play" id="pause" onclick="sendPause()">Pause</a>
    <a href="#" class="play" id="stop" onclick="sendStop()">Stop</a>
  </div>
  <br/>
  <div>
    <a href="#" class="play" id="prev" onclick="sendPrev()">Prev</a>
    <a href="#" class="play" id="random" onclick="sendRandom()">Random</a>
    <a href="#" class="play" id="next" onclick="sendNext()">Next</a>   
  </div>
  <br/>
  <div>
    <a href="#" class="tombol" id="modejam" onclick="sendModeJam()">JWS</a>
    <a href="#" class="tombol" id="modemp3" onclick="sendModeMP3()">Murottal</a>    
  </div>

  <hr/>
  <h3>Playlist</h3>
  <div>
    <select id="playlist" onchange="sendPlaylist()">
      <option value="p1">Al Quran Dibacakan Oleh...</option>
      <option value="p2">Al Quran - Saad Alghamdi</option>
      <option value="p3">Juz Amma - Saad Alghamdi</option>
      <option value="p4">Al Quran - Mishary Rasyid</option>
      <option value="p5">Juz Amma - Mishary Rasyid</option>
      <option value="p6">Al Quran - As Sudais</option>
      <option value="p7">Juz Amma - As Sudais</option>
      <option value="p8">Al Quran - Al Budair</option>
      <option value="p9">Juz Amma - Al Budair</option>
      <option value="pl1">Al Quran - Al Muaiqly</option>
      <option value="pl2">Juz Amma - Al Muaiqly</option>
      <option value="pl3">Al Quran - Al Hudhaifi</option>
      <option value="pl4">Juz Amma - Al Hudhaifi</option>
      <option value="pl5">Lain-lain</option>
    </select>
  </div>
  <br/>
  <h3>Equalizer</h3>
  <div>
    <select id="equalizer" onchange="sendEqualizer()">
      <option value="e0">Pilih Equalizer...</option>
      <option value="e1">Normal</option>
      <option value="e2">Pop</option>
      <option value="e3">Rock</option>
      <option value="e4">Jazz</option>
      <option value="e5">Classic</option>
      <option value="e6">Bass</option>
    </select>
  </div>

  <hr/>
  <h3>Informasi</h3>  
  <div>
    <label for = "info1">Informasi 1</label>
    <textarea id="info1" placeholder="Info1" onchange="sendNama()"></textarea>
  </div>
  <div>
    <label for = "info2">Informasi 2</label>
    <textarea id="info2" placeholder="Info2" onchange="sendNama()"></textarea>
  </div>
  <div>
    <label for = "nama">Nama Masjid</label>
    <textarea id="nama" placeholder="Nama Masjid" onchange="sendNama()"></textarea>
  </div>

  <hr/>
  <h3>Jadwal Sholat</h3>
  <table width='100%'>
    <tr>
      <td><p id="jtanbih" class="info"></p></td>
      <td><p id="jsubuh" class="info"></p></td>
      <td><p id="jdzuhur" class="info"></p></td>
    </tr>
    <tr>
      <td><p id="jashar" class="info"></p></td>
      <td><p id="jmaghrib" class="info"></p></td>
      <td><p id="jisya" class="info"></p></td>
    </tr>
  </table>
  

  <hr/>
  <h3>Iqomah</h3>
  <div>
    <table width='100%'>
      <tr>
        <td>
          <label for="iqmhs">Subuh</label><br>
          <input id="iqmhs" placeholder="12" maxlength="2" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="iqmhd">Dzuhur</label><br>
          <input id="iqmhd" placeholder="8" maxlength="2" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="iqmha">Ashar</label><br>
          <input id="iqmha" placeholder="6" maxlength="2" size="2" onchange="setJws()"/>
        </td>
      </tr>
      <tr>
        <td>
          <label for="iqmhm">Maghrib</label><br>
          <input id="iqmhm" placeholder="5" maxlength="2" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="iqmhi">Isya</label><br>
          <input id="iqmhi" placeholder="5" maxlength="2" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="durasiadzan">Adzan</label><br>
          <input id="durasiadzan" placeholder="2" maxlength="2" size="2" onchange="setJws()"/>
        </td>
      </tr>
    </table>    
  </div>

  <hr/>
  <form>
    <h3>Sambung ke Wifi</h3>
    <div>
      <label for="wifissid">Wifi SSID</label>
      <input id="wifissid" onchange="setWifi()"/>
    </div>
    <div>
      <label for="wifipassword">Wifi Password</label>
      <input type="password" id="wifipassword" onchange="setWifi()"/>
    </div>
    <br/><br/>
    <h3>Wifi JWS</h3>
    <div>
      <label for="ssid">SSID</label>
      <input id="ssid" onchange="setWifi()"/>
    </div>
    <div>
      <label for="password">Password</label>
      <input type="password" id="password" onchange="setWifi()"/>
    </div>
    <div>
      <button onClick="resetNodeMCU()"> Terapkan dan Restart </button>
    </div>
  </form>

  <hr/>
  <h3>Waktu & Lokasi</h3>
  <div>
    <table width='100%'>
      <tr>
        <td>
          <form >
            <h4>Tanggal</h4>
            <input type='date' name='date' id="tanggal" onchange="sendTanggal()">
          </form>  
        </td>        
      </tr>
      <tr>
        <td>
          <form >  
            <h4>Jam</h4>
            <input type='time' name='time' id="jam" onchange="sendJam()">
          </form>
        </td>
      </tr>
    </table>
    <br/>
    <table width='100%'>
      <tr>
        <td>
          <label for="latitude">Latitude</label><br>
          <input id="latitude" placeholder="-6.165" size="9" onchange="setJws()"/>
        </td>
        <td>
          <label for="longitude">Longitude</label><br>
          <input id="longitude" placeholder="106.608" size="9" onchange="setJws()"/>
        </td>    
      </tr>
      <tr>
        <td>
          <label for="zonawaktu">Zona Waktu</label><br>
          <input id="zonawaktu" placeholder="7" size="2" onchange="setJws()"/>
        </td>
        <td>
          <label for="ihti">Ihtiyati</label><br>
          <input id="ihti" placeholder="2" maxlength="2" size="2" onchange="setJws()"/>
        </td>
      </tr>
    </table>
  </div>
  
  <hr/>
  <h3>Kecerahan</h3>
  <div>
    <input type="range" min="15" max="254" value="20" id="kecerahan" oninput="sendKecerahan()" />
  </div>
  <h3>Jumlah Panel</h3>
  <div>
    <select id="panel" onchange="sendKecerahan()">
      <option value="1">1 Panel</option>
      <option value="2">2 Panel</option>
    </select>
  </div>

  <hr/>
  <div>
    <a href="#" class="tombol" id="modetesled" onclick="sendTesLED()">Tes LED</a>    
  </div>

  <hr/>
  <p>JWS Murottal V2.0.0 - 2021</p>
  <p class="footer"><a href="http://www.elektronmart.com" target="_blank">ElektronMart.Com</a> | <a href="https://www.grobak.net" target="_blank">Grobak.Net</a></p>

</center>
</body>

<script>

var xmlHttp=createXmlHttpObject();

function createXmlHttpObject(){
 if(window.XMLHttpRequest){
    xmlHttp=new XMLHttpRequest();
 }else{
    xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');// code for IE6, IE5
 }
 return xmlHttp;
}

function updateData() {
  process();
  processreal();
}

function process(){
 if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
   xmlHttp.open('PUT','xml',true);
   xmlHttp.onreadystatechange=handleServerResponse;
   xmlHttp.send(null);
 }

 //setTimeout('process()',1000);

}

function processreal(){
 if(xmlHttp.readyState==0 || xmlHttp.readyState==4){
   xmlHttp.open('PUT','realxml',true);
   xmlHttp.onreadystatechange=handleRealServerResponse;
   xmlHttp.send(null);
 }

 setTimeout('processreal()',1000);

}

function handleServerResponse(){
 if(xmlHttp.readyState==4 && xmlHttp.status==200){
   xmlResponse=xmlHttp.responseXML;

   xmldoc = xmlResponse.getElementsByTagName('rNama');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('nama').value=message;
   
   xmldoc = xmlResponse.getElementsByTagName('rInfo1');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('info1').value=message;
   
   xmldoc = xmlResponse.getElementsByTagName('rInfo2');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('info2').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rIqmhs');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmhs').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rIqmhd');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmhd').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rIqmha');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmha').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rIqmhm');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmhm').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rIqmhi');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('iqmhi').value=message;

    xmldoc = xmlResponse.getElementsByTagName('rDurasiAdzan');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('durasiadzan').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rIhti');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('ihti').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rLatitude');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('latitude').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rLongitude');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('longitude').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rZonaWaktu');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('zonawaktu').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rSsid');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('ssid').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rPassword');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('password').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rWifissid');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('wifissid').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rTanbih');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('jtanbih').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rSubuh');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('jsubuh').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rDzuhur');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('jdzuhur').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rAshar');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('jashar').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rMaghrib');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('jmaghrib').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rIsya');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('jisya').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rPanel');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('panel').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rWifipassword');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('wifipassword').value=message;

 }
}


function handleRealServerResponse(){
 if(xmlHttp.readyState==4 && xmlHttp.status==200){
   xmlResponse=xmlHttp.responseXML;

   xmldoc = xmlResponse.getElementsByTagName('rYear');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('year').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rMonth');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('month').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rDay');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('day').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rHour');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('hour').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rMinute');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('minute').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rSecond');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('second').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rTemp');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('temp').innerHTML=message;

   xmldoc = xmlResponse.getElementsByTagName('rVolume');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('volume').value=message;

   xmldoc = xmlResponse.getElementsByTagName('rKecerahan');
   message = xmldoc[0].firstChild.nodeValue;
   document.getElementById('kecerahan').value=message;

 }
}


InitWebSocket()

function InitWebSocket() {
  Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
  Socket.onmessage = function(event) {
    
  }

  Socket.onclose = function(event) {
    location.reload();
  }
}

function sendVolume() {    
  var volume = document.getElementById("volume").value;
  var datadf = {volume:volume};
  Socket.send("#" + JSON.stringify(datadf));
}

function sendPlay() {
  Socket.send("dplay");
}
function sendPause() {
  Socket.send("dpause");
}
function sendStop() {
  Socket.send("dstop");
}  
function sendPrev() {
  Socket.send("dprev");
}
function sendNext() {
  Socket.send("dnext");
}
function sendRandom() {
  Socket.send("drandom");
}
function sendModeMP3() {
  Socket.send("dmodemp3");
}
function sendModeJam() {
  Socket.send("dmodejam");
}
function sendPlaylist() {
  var option = document.getElementById("playlist").value;
  Socket.send(option);
}
function sendEqualizer() {
  var option = document.getElementById("equalizer").value;
  Socket.send(option);
}

function sendTanggal() {
  Socket.send("t" + document.getElementById("tanggal").value);
}
function sendJam() {
  Socket.send("j" + document.getElementById("jam").value);
}

function sendNama() {
  var nama = document.getElementById("nama").value;
  var info1 = document.getElementById("info1").value;
  var info2 = document.getElementById("info2").value;
  var datainfo = {nama:nama, info1:info1, info2:info2};
  Socket.send("i" + JSON.stringify(datainfo));
}

function sendKecerahan() {
  var kecerahan = document.getElementById("kecerahan").value;
  var panel = document.getElementById("panel").value;
  var datadisp = {kecerahan:kecerahan, panel:panel};
  
  Socket.send("c" + JSON.stringify(datadisp));
}


function setJws() {
  
  var iqmhs = document.getElementById("iqmhs").value;
  var iqmhd = document.getElementById("iqmhd").value;
  var iqmha = document.getElementById("iqmha").value;
  var iqmhm = document.getElementById("iqmhm").value;
  var iqmhi = document.getElementById("iqmhi").value;
  var durasiadzan = document.getElementById("durasiadzan").value;
  var ihti = document.getElementById("ihti").value;
  var latitude = document.getElementById("latitude").value;
  var longitude = document.getElementById("longitude").value;
  var zonawaktu = document.getElementById("zonawaktu").value;
  var datajws = {iqmhs:iqmhs, iqmhd:iqmhd, iqmha:iqmha, iqmhm:iqmhm, iqmhi:iqmhi, durasiadzan:durasiadzan, ihti:ihti, latitude:latitude, longitude:longitude, zonawaktu:zonawaktu};

  Socket.send("s" + JSON.stringify(datajws));    
  
}

function setWifi() {

  var wifissid = document.getElementById("wifissid").value;
  var wifipassword = document.getElementById("wifipassword").value;
  var ssid = document.getElementById("ssid").value;
  var password = document.getElementById("password").value;
  var datawifi = {wifissid:wifissid, wifipassword:wifipassword, ssid:ssid, password:password};

  Socket.send("w" + JSON.stringify(datawifi));
  
}

function resetNodeMCU() {

  Socket.send("z");
  
}

function sendTesLED() {
  
  Socket.send("dtesled");
  
}



var foldermp3 = document.getElementById("foldermp3");
var trackmp3 = document.getElementById("trackmp3");

//Create array of options to be added
var array = ["Saad Alghamdi","Mishary Rasyid","As Sudais","Al Budair","Al Muaiqly","Al Hudhaifi","Lain-lain"];

//Create and append select list
var slmp3 = document.createElement("select");
slmp3.setAttribute("id", "slmp3");
foldermp3.appendChild(slmp3);

var trmp3 = document.createElement("select");
trmp3.setAttribute("id", "trmp3");
trackmp3.appendChild(trmp3);

//Create and append the options
for (var i = 0; i < array.length; i++) {
    var option = document.createElement("option");
    option.setAttribute("value", array[i]);
    option.text = array[i];
    slmp3.appendChild(option);
}

for (var i = 0; i < 115; i++) {
    var option = document.createElement("option");
    option.setAttribute("value", i);
    option.text = i;
    trmp3.appendChild(option);
}

function sendPlayFolderTrack() {
  var foldermp3 = document.getElementById("foldermp3").value;
  var trackmp3 = document.getElementById("trackmp3").value;
  Socket.send(foldermp3 + trackmp3);
}


</script>

</html>

)=====";
