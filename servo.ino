#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> // مكتبة الـ servo driver
#include <U8g2lib.h>                 // مكتبة الشاشة 128x64

// تهيئة الشاشة SPI - تأكد من تعديل البنات حسب التوصيلات
U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, /* CS=*/ 10, /* DC=*/ 9, /* RESET=*/ 8);

// تهيئة servo driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int touchButtonPin = 7;
const int vibrationSensorPin = 8;
const int buzzerPin = 6;

// إعداد زوايا السرفو
#define SERVOMIN 150  // الحد الأدنى
#define SERVOMAX 600  // الحد الأقصى

void setup() {
  // إعداد الشاشة
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);

  // عرض رسالة على الشاشة للتأكد من عملها
  u8g2.drawStr(0, 10, "Initializing...");
  u8g2.sendBuffer();

  // إعداد servo driver
  pwm.begin();
  pwm.setPWMFreq(60); // ضبط تردد PWM

  // إعداد البنات
  pinMode(touchButtonPin, INPUT);
  pinMode(vibrationSensorPin, INPUT);

  // عرض رسالة التأكيد على الشاشة
  u8g2.clearBuffer();
  u8g2.drawStr(0, 10, "Setup Complete!");
  u8g2.sendBuffer();
  delay(2000); // تأخير لملاحظة الرسالة
}

void loop() {
  // تجربة تحريك المحرك الأول لتحديد إذا كان يعمل
  int angle = 90; // زاوية الحركة
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(0, 0, pulse); // تحريك السرفو المتصل بالقناة 0 إلى الزاوية المحددة

  // عرض رسالة على الشاشة لعرض حالة المحرك
  u8g2.clearBuffer();
  u8g2.drawStr(0, 10, "Servo Moving...");
  u8g2.sendBuffer();

  delay(1000); // تأخير لملاحظة الحركة

  // إيقاف المحرك للحظة
  pwm.setPWM(0, 0, 0);
  u8g2.clearBuffer();
  u8g2.drawStr(0, 10, "Servo Stopped");
  u8g2.sendBuffer();

  delay(1000); // تأخير قبل التكرار
}
