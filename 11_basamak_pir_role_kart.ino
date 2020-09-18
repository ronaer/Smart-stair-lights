/* Dizi ve fonksiyon kullanımlarına örnek _ an example string and functions...
  Basit ve kolay bir merdiven aydınlatma örneği _ simple and easy stair lights...
 11 basamaklı, pir sensörlü, logic 0 röle kartı için...
  www.ronaer.com
  TR.ALP.18 >>> youtube
*/

//Sensörlerimiz Arduino D12 ve A0 pinlerine bağlı
const int pir_pin_up = 12; // merdivenin üstündeki pir sensor pini tanımlama
const int pir_pin_down = A0; // merdivenin altındaki pir sensor pini tanımlama

int pir_up_deger; 
int pir_down_deger;

int merdiven_led_up[11] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, A5,}; // 11 adet led için dizi tanımı _ string
int merdiven_led_down[11] = {A5, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,}; // 11 adet led için dizi tanımı ters sırada_ reverse string
// Dizi olarak tanımladığımız arduino çıkışlarını, sıra ile röle kart girişine bağlayalım...

int y = 400;  // yanma aralığı süresi _ light on interval
int b = 5000; // yandıktan sonra geri sönmek için bekleme süresi _ light off interval after full lighting
int s = 800;  // sönme aralığı süresi _ light off interval

void setup() {
  pinMode(pir_pin_up, INPUT); // üstteki pir sensor pini giriş tanımlandı
  pinMode(pir_pin_down, INPUT); // alttaki pir sensor pini giriş tanımlandı

  for (int i = 0; i < 11; i++)
  {
    pinMode(merdiven_led_up[i], OUTPUT); //dizideki tüm ledler çıkış olarak ayarlandı
    pinMode(merdiven_led_down[i], OUTPUT); //dizideki tüm ledler çıkış olarak ayarlandı
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
///////// fonksiyon tanımları 

void stairs_from_up() // üstten merdivene ayak basıldığında çalışacak fonksiyon
  {
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led_up[i], LOW);
    delay(y);
  }
  delay(b);
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led_up[i], HIGH);
    delay(s);
  }

}

void stairs_from_down()  // alltan merdivene ayak basıldığında çalışacak fonksiyon
{
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led_down[i], LOW);
    delay(y);
  }
  delay(b);
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led_down[i], HIGH);
    delay(s);
  }


}

void kapat() // if komut şartlarının oluşmadığı durumda çalışacak fonksiyon
{
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(merdiven_led_up[i], HIGH);
    digitalWrite(merdiven_led_down[i], HIGH);

  }
}
// TR.ALP.18 >>> youtube  bilgi@ronaer.com
