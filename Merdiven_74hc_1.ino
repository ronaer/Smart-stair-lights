/********************************************************************
   https://www.youtube.com/watch?v=-cNZDVtvr1Y&t=21s
   KASIM 2021 Dr.TRonik YouTube
   Nano + 2 74HC595 ile 16 basamak merdiven akıllı aydınlatma
   2 adet PIR veya IR sensör (Değişiklik yapılarak)
   16*Mosfet
   Zaman ve bekleme ayarlı
   ********************************************************************/

int dataPin = 8;    //DS -> 14.pin
int latchPin = 9;   //ST_CP -> 12.Pin
int clockPin = 10;  // SH_CP -> 11.Pin
boolean registers[16];

int wt_okunan ; //Tüm basamaklar yandıktan sonra geri sönme süresi potansiyometreden okunan waitingtime
int st_okunan ; // Basamakların yanma sönme süresi potansiyometreden okunan stairstime
int wt_;
int st_;

#define sens_up 3
#define sens_down 4

boolean sens_up_deger = LOW;
boolean sens_down_deger = LOW;

void setup() {
  //Serial.begin (9600);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  pinMode(sens_up, INPUT);
  pinMode(sens_down, INPUT);

  writereg();
}

void writereg()
{
  digitalWrite(latchPin, LOW);
  for (int i = 0; i < 17; i++) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, registers[i]);
    digitalWrite(clockPin, HIGH);
  }

  digitalWrite(latchPin, HIGH);
}

void loop() {
  //Tüm basamaklar yandıktan sonra geri sönme gecikme süresini 1 saniye ile 5 saniye arasında ayralamak için
  wt_okunan = analogRead(A0);
  if (wt_okunan > 0 && wt_okunan < 204) {
    wt_ = 1000;
  }
  if (wt_okunan > 203 && wt_okunan < 408) {
    wt_ = 2000;
  }
  if (wt_okunan > 407 && wt_okunan < 612) {
    wt_ = 3000;
  }
  if (wt_okunan > 611 && wt_okunan < 816) {
    wt_ = 4000;
  }
  if (wt_okunan > 815 && wt_okunan < 1024) {
    wt_ = 5000;
  }
  
//  Serial.print("wt:");
//  Serial.print(wt_);
 
  //Her bir basamak yanma sönme sürelerini ~0,2 saniye ile ~1 saniye arasında ayralamak için
  st_okunan = analogRead(A1);
  if (st_okunan < 200) {
    st_ = 200;
  }
  else {
    (st_ = st_okunan);
  }
  
//  Serial.print("st:");
//  Serial.println(st_);
//  delay(450);
  
  sens_up_deger = digitalRead(sens_up);
  sens_down_deger = digitalRead(sens_down);

  if (sens_up_deger == HIGH) {
    for (int i = 0; i < 17; i++) {
      registers[i] = HIGH;
      delay(st_);
      writereg();
    }

    delay(wt_);

    for (int i = 0; i < 17; i++) {
      registers[i] = LOW;
      delay(st_);
      writereg();
    }
  }

  if (sens_down_deger == HIGH) {
    for (int i = 16; i > 0; i--) {
      registers[i] = HIGH;
      delay(st_);
      writereg();
    }

    delay(wt_);

    for (int i = 16; i > 0; i--) {
      registers[i] = LOW;
      delay(st_);
      writereg();
    }
  }
}
//NOVEMBER 2021 Dr.TRonik >>> YouTube
