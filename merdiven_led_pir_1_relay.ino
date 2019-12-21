/* Dizi ve fonksiyon kullanımlarına örnek _ an example string and functions...
  Basit ve kolay bir merdiven aydınlatma örneği _ simple and easy stair lights...
  https://github.com/ronaer/Smart-stair-lights.git
  www.ronaer.com
  TR.ALP.18 >>> youtube
*/

const int pir_pin_up = 12; // merdivenin üstündeki pir sensor pini tanımlama
const int pir_pin_down = 13; // merdivenin altındaki pir sensor pini tanımlama
int pir_up_deger; 
int pir_down_deger;

int merdiven_led[11]  = { A0, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2,}; // 11 adet led için dizi tanımı _ string
int merdiven_led_[11] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, A0,}; // 11 adet led için dizi tanımı _ string


int y = 400;  // yanma aralığı süresi _ light on interval
int b = 5000; // yandıktan sonra geri sönmek için bekleme süresi _ light off interval after full lighting
int s = 800;  // sönme aralığı süresi _ light off interval

void setup() {
  pinMode(pir_pin_up, INPUT); // üstteki pir sensor pini giriş tanımlandı
  pinMode(pir_pin_down, INPUT); // alttaki pir sensor pini giriş tanımlandı

  for (int i = 0; i < 11; i++)
  {
    pinMode(merdiven_led[i], OUTPUT); //dizideki tüm ledler çıkış olarak ayarlandı
    pinMode(merdiven_led_[i], OUTPUT);
  }
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led[i], HIGH); //
    delay(250);
    digitalWrite(merdiven_led[i], LOW); //
  }
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led_[i], HIGH); //
    delay(250);
    digitalWrite(merdiven_led_[i], LOW); //
  }
}

void loop()
{
  pir_up_deger = digitalRead(pir_pin_up); //üst pir pin değeri pir_up_deger e atandı
  pir_down_deger = digitalRead(pir_pin_down); //alt pir pin değeri pir_down_deger e atandı

  if (pir_up_deger == HIGH) // eğer üst pir den sinyal gelirse
  {
    stairs_from_up(); // bu fonksiyonu çalıştır
  }

   
   if (pir_down_deger == HIGH) // eğer alt pir den sinyal gelirse
  {
    stairs_from_down();  // bu fonksiyonu çalıştır
  }


  else // bu şartlardan hiçbiri olmazsa
  {
    kapat();  // bu fonksiyonu çalıştır
  }


}
///////// fonksiyon tanımları \\\\\\\\\\

void stairs_from_up() // üstten merdivene ayak basıldığında çalışacak fonksiyon
  {
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led[i], HIGH);
    delay(y);
  }
  delay(b);
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led[i], LOW);
    delay(s);
  }

}

void stairs_from_down()  // alltan merdivene ayak basıldığında çalışacak fonksiyon
{
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led_[i], HIGH);
    delay(y);
  }
  delay(b);
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led_[i], LOW);
    delay(s);
  }

}

void kapat() // if komut şartlarının oluşmadığı durumda çalışacak fonksiyon
{
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led[i], LOW);
    digitalWrite(merdiven_led_[i], LOW);
    
  }
}
