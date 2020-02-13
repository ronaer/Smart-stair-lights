/* Dizi ve fonksiyon kullanımlarına örnek _ an example string and functions...
  Basit ve kolay bir trabzanlı 10 basamaklı merdiven aydınlatma örneği _ simple and easy stair lights with handrail...
  https://github.com/ronaer/Smart-stair-lights.git
  TR.ALP.18 >>> youtube
*/

const int mz_pin_up = 12; // merdivenin üstündeki pir sensor pini tanımlama
const int mz_pin_down = 13; // merdivenin altındaki pir sensor pini tanımlama
int mz_up_deger;
int mz_down_deger;

int merdiven_led[10]  = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2,}; // 11 adet led için dizi tanımı  string
int merdiven_led_[10] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,}; // 11 adet led için dizi tanımı _ string


int y = 400;  // yanma aralığı süresi _ light on interval
int b = 5000; // yandıktan sonra geri sönmek için bekleme süresi _ light off interval after full lighting
int s = 800;  // sönme aralığı süresi _ light off interval
int ani_time = 350; //temsili animasyon için tanımlanan delay süresi

void setup() {
  pinMode(mz_pin_up, INPUT); // üstteki mz80 sensor pini giriş tanımlandı
  pinMode(mz_pin_down, INPUT); // alttaki mz80 sensor pini giriş tanımlandı
  
  for (int i = 0; i < 10; i++)
  {
    pinMode(merdiven_led[i], OUTPUT);  //dizideki tüm ledler çıkış olarak ayarlandı
    pinMode(merdiven_led_[i], OUTPUT); //_dizisindeki tüm ledler çıkış olarak ayarlandı
    pinMode(A0, OUTPUT);//trabzan aydınlatma çıkış olarak ayarlandı
  }

  //__________TEST_________merdivendeki tüm ledler yanıyor mu?

  digitalWrite(A0, HIGH);
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(merdiven_led[i], HIGH); //
    delay(250);
    digitalWrite(merdiven_led[i], LOW); //
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(merdiven_led_[i], HIGH); //
    delay(250);
    digitalWrite(merdiven_led_[i], LOW); //
  }
  digitalWrite(A0, LOW);

  //__________TEST SONU__________

  //_________İsteğe Bağlı Animasyom Örneği_______

  digitalWrite(A0, HIGH); // trabzanı yakalım
  delay(ani_time);

  digitalWrite(11, HIGH); //ilk basamaklar yansın
  digitalWrite(2, HIGH);
  delay(ani_time);
  digitalWrite(11, LOW); //ve sönsün
  digitalWrite(2, LOW);
  delay(ani_time);

  digitalWrite(11, HIGH); //ilk basamaklarla birlikte komşu basamaklar da yansın
  digitalWrite(2, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(3, HIGH);
  delay(ani_time);
  digitalWrite(10, LOW); //ve sönsün
  digitalWrite(3, LOW);
  delay(ani_time);


  digitalWrite(10, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(4, HIGH);
  delay(ani_time);
  digitalWrite(9, LOW); //ve sönsün
  digitalWrite(4, LOW);
  delay(ani_time);


  digitalWrite(9, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(5, HIGH);
  delay(ani_time);
  digitalWrite(8, LOW); //ve sönsün
  digitalWrite(5, LOW);
  delay(ani_time);

  digitalWrite(8, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(ani_time);
  digitalWrite(7, LOW); //ve sönsün
  digitalWrite(6, LOW);
  delay(ani_time);

  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);

  delay(4 * ani_time);

  for (int i = 0; i < 10; i++)
  {
    digitalWrite(merdiven_led[i], LOW);
    delay(100);
  }
  delay(4 * ani_time);
  digitalWrite(A0, LOW);

  kapat;

}

void loop()
{
  mz_up_deger = digitalRead(mz_pin_up); //üst mz80 pin değeri mz_up_deger e atandı
  mz_down_deger = digitalRead(mz_pin_down); //alt mz80 pin değeri mz_down_deger e atandı

  if (mz_up_deger == LOW) // eğer üst mz80 den sinyal gelmez ise; normalde mz80 çıkışı HIGH/1 dir, engelden dönerse LOW/0 değer döndürür...
  {
    stairs_from_up(); // bu fonksiyonu çalıştır
  }


  if (mz_down_deger == LOW) // eğer alt mz80 den sinyal gelmez ise; normalde mz80 çıkışı HIGH/1 dir, engelden dönerse LOW/0 değer döndürür...
  {
    stairs_from_down();  // bu fonksiyonu çalıştır
  }


  else // bu şartlardan hiçbiri olmazsa
  {
    kapat();  // bu fonksiyonu çalıştır
  }


}
//_________________ fonksiyon / void tanımları_________________

// üstten merdivene ayak basıldığında çalışacak fonksiyon başlangıcı

void stairs_from_up()
{
  digitalWrite(A0, HIGH);
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(merdiven_led[i], HIGH);
    delay(y);
  }
  delay(b);
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(merdiven_led[i], LOW);
    delay(s);
  }
  digitalWrite(A0, LOW);
}
//_____________fonksiyon sonu

// alltan merdivene ayak basıldığında çalışacak fonksiyon başlangıcı
void stairs_from_down()
{
  digitalWrite(A0, HIGH);
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(merdiven_led_[i], HIGH);
    delay(y);
  }
  delay(b);
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(merdiven_led_[i], LOW);
    delay(s);
  }
  digitalWrite(A0, LOW);
}
//_____________fonksiyon sonu

// if komut şartlarının oluşmadığı durumda çalışacak fonksiyon başlangıcı
void kapat()
{
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(merdiven_led[i], LOW);
    digitalWrite(merdiven_led_[i], LOW);
    digitalWrite(A0, LOW);

  }
}
//_____________fonksiyon sonu
//youtube  >>> TR.ALP.18 <<< abone olursanız sevinirim... :)
