/*Basamak sayısı: 16; Sensör: MZ80 Relay: Logic 0
 *Authored by Dr.TRonik youTube @June/2020
 *Açık kaynak lisansı altında kullanılabilir, dağıtılabilir, geliştirilebilir...
 *Konu ile ilgili soru ve sorunlar için: bilgi@ronaer.com
 *Programı nano ya yükledikten sonra bağlantıları yapınız... 
*/

const int mz_pin_up = 0; // merdivenin üstündeki mz sensor pini tanımlama
const int mz_pin_down = 1; // merdivenin altındaki mz sensor pini tanımlama
int mz_up_deger; 
int mz_down_deger;

int merdiven_led_up[16] =   {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, A5, A4, A3, A2, A1, A0,}; // 16 adet led için dizi tanımı
int merdiven_led_down[16] = {A0, A1, A2, A3, A4, A5, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,}; // 16 adet led için dizi tanımı ters sırada_ reverse
/*
 * Nano için bu programda A6 ve A7 pinlerini giriş / çıkış olarak ayarlamayınız,
 * Bu pinler MCU / Mikrodenetleyicinin dahili 10 bit ADC / Analog Digital Converter kanalını oluşturduklarından,
 * Bu tür sensörler ile kullanılırken yazılımın bu haliyle istenilen sonuç alınamayacaktır!..
 * 
 * İlk dizideki pinleri 
 * 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, A5, A4, A3, A2, A1, A0 
 * sıra ile röle kartı pinlerine bağlayınız,
 * Alt ve üst MZ80 sensörleri D0 ve D1 pinlerine bağlayınız...
 * 
 */ 
int y = 400;  // yanma aralığı süresi _ light on interval_400 milisaniye aralıkla yanarlar, değiştirbilirsiniz...
int b = 5000; // yandıktan sonra geri sönmek için bekleme süresi _ light off interval after full lighting_5 saniye sonra sönme başlar, değiştirebilirsiniz...
int s = 800;  // sönme aralığı süresi _ light off interval_800 milisaniye aralıkla ledler söner, değiştirebilirsiniz...

void setup() {
  pinMode(mz_pin_up, INPUT_PULLUP); // üstteki mz sensor pini giriş tanımlandı
  pinMode(mz_pin_down, INPUT_PULLUP); // alttaki mz sensor pini giriş tanımlandı

  for (int i = 0; i < 16; i++)
  {
    pinMode(merdiven_led_up[i], OUTPUT); //dizideki tüm ledler çıkış olarak ayarlandı
    pinMode(merdiven_led_down[i], OUTPUT); //dizideki tüm ledler çıkış olarak ayarlandı
  }

}

void loop()
{
  mz_up_deger = digitalRead(mz_pin_up); //üst mz pin değeri mz_up_deger e atandı
  mz_down_deger = digitalRead(mz_pin_down); //alt mz pin değeri mz_down_deger e atandı

  if (mz_up_deger == LOW) // eğer üst mz den sinyal gelirse (MZ80 aktif olduğunda LOW değeri döndürür)...
  {
    stairs_from_up(); // bu fonksiyonu çalıştır
  }

   
   if (mz_down_deger == LOW) // eğer alt mz den sinyal gelirse (MZ80 aktif olduğunda LOW değeri döndürür)...
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
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(merdiven_led_up[i], LOW);
    delay(y);
  }
  delay(b);
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(merdiven_led_up[i], HIGH);
    delay(s);
  }

}

void stairs_from_down()  // alltan merdivene ayak basıldığında çalışacak fonksiyon
{
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(merdiven_led_down[i], LOW);
    delay(y);
  }
  delay(b);
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(merdiven_led_down[i], HIGH);
    delay(s);
  }


}

void kapat() // if komut şartlarının oluşmadığı durumda çalışacak fonksiyon
{
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(merdiven_led_up[i], HIGH);
    digitalWrite(merdiven_led_down[i], HIGH);

  }
}
/*e-posta: bilgi@ronaer.com
 *https://www.instagram.com/dr.tronik2022/   
 *YouTube: Dr.TRonik: www.youtube.com/c/DrTRonik
*/
