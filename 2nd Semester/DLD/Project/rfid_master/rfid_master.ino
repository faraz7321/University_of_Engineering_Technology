#include <MFRC522.h>
#include <LCD_I2C.h>
#include <SPI.h>
#include <Servo.h>

//LCD
LCD_I2C lcd(0x27); // Default address of most PCF8574 modules, change according

//RFID
MFRC522 mfrc522(10, 9);
int MasterCounter = 0;

//SERVO
Servo myservo;
int dooropen = 10;
int doorlocked = 140;

String tags[4] = {"0761CFB5", "4A50F68", "", ""};
String names[4] = {"Faraz", "Ahmad", "Mahnoor", "Fatima"};

void setup()
{
  //LCD
  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
  // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
  SPI.begin();
  myservo.attach(8);
  myservo.write(doorlocked);
  mfrc522.PCD_Init();
  Serial.println("Scan Tag");
}

void print(String name)
{
  String s = "Welcome " + name;
  lcd.clear();
  lcd.print("Access Granted!");
  lcd.setCursor(0, 1);
  lcd.print(s);
  Serial.println("\n");
  Serial.println("Access granted");
  myservo.write(dooropen);
  Serial.println("Door opened");
}

void loop()
{
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  String uid = "";
  Serial.print("UID=");
  for (int i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    uid.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    uid.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  uid.toUpperCase();
  bool flag = false;
  for (int i = 0; i < 4; i++)
  {
    if (uid == tags[i])
    {
      print(names[i]);
      flag = true;
      break;
    }
  }
  if (flag == false)
  {
    Serial.println("Access denied");
    lcd.print("Access Denied!");
  }

  delay(4000);
  finalize();
  return;
}
void finalize()
{
  myservo.write(doorlocked);
  lcd.clear();
  Serial.println("Door locked");
}