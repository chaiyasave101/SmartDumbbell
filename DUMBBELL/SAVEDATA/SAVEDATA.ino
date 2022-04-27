#define M5STACK_MPU6886
#include <M5Stack.h>
#include <SPI.h>
#include <SD.h>

File myFile;
unsigned long previousMillis_Save = 0;
unsigned long Time = 0;
int saveState = 0;
String dataLog[6][21];

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float pitch = 0.0F;
float roll  = 0.0F;
float yaw   = 0.0F;



// the setup routine runs once when M5Stack starts up
void setup() {

  // Initialize the M5Stack object
  
  M5.begin();
  Wire.begin();
  M5.Power.begin();
  M5.IMU.Init();
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(GREEN , BLACK);
  M5.Lcd.setTextSize(2);
}

// the loop routine runs over and over again forever
void loop() {
  unsigned long currentMillis = millis();
  M5.update();
  // put your main code here, to run repeatedly:
  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  M5.IMU.getAhrsData(&pitch, &roll, &yaw);
  

  M5.Lcd.setCursor(0, 20);
  M5.Lcd.printf("%6.2f  %6.2f  %6.2f      ", gyroX, gyroY, gyroZ);
  M5.Lcd.setCursor(220, 42);
  M5.Lcd.print(" o/s");
  M5.Lcd.setCursor(0, 65);
  M5.Lcd.printf(" %5.2f   %5.2f   %5.2f   ", accX, accY, accZ);
  M5.Lcd.setCursor(220, 87);
  M5.Lcd.print(" G");
  M5.Lcd.setCursor(0, 110);
  M5.Lcd.printf(" %5.2f   %5.2f   %5.2f   ", pitch, roll, yaw);
  M5.Lcd.setCursor(220, 132);
  M5.Lcd.print(" degree");

  if (M5.BtnA.wasReleased() && saveState == 0) {
    saveState = 1;
    previousMillis_Save = currentMillis;
    Time = currentMillis;
  }
  if (saveState == 1) {
    M5.Lcd.setTextColor(WHITE , BLACK);
    M5.Lcd.setCursor(20, 220);
    M5.Lcd.print(Time);
    if ((currentMillis - previousMillis_Save) >= 5000 && (currentMillis - previousMillis_Save) <= 5000 + 50) {
      dataLog[0][0] = accX;
      dataLog[1][0] = accY;
      dataLog[2][0] = accZ;
      dataLog[3][0] = gyroX;
      dataLog[4][0] = gyroY;
      dataLog[5][0] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5050 && (currentMillis - previousMillis_Save) <= 5050 + 50) {
      dataLog[0][1] = accX;
      dataLog[1][1] = accY;
      dataLog[2][1] = accZ;
      dataLog[3][1] = gyroX;
      dataLog[4][1] = gyroY;
      dataLog[5][1] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5100 && (currentMillis - previousMillis_Save) <= 5100 + 50) {
      dataLog[0][2] = accX;
      dataLog[1][2] = accY;
      dataLog[2][2] = accZ;
      dataLog[3][2] = gyroX;
      dataLog[4][2] = gyroY;
      dataLog[5][2] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5150 && (currentMillis - previousMillis_Save) <= 5150 + 50) {
      dataLog[0][3] = accX;
      dataLog[1][3] = accY;
      dataLog[2][3] = accZ;
      dataLog[3][3] = gyroX;
      dataLog[4][3] = gyroY;
      dataLog[5][3] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5200 && (currentMillis - previousMillis_Save) <= 5200 + 50) {
      dataLog[0][4] = accX;
      dataLog[1][4] = accY;
      dataLog[2][4] = accZ;
      dataLog[3][4] = gyroX;
      dataLog[4][4] = gyroY;
      dataLog[5][4] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5250 && (currentMillis - previousMillis_Save) <= 5250 + 50) {
      dataLog[0][5] = accX;
      dataLog[1][5] = accY;
      dataLog[2][5] = accZ;
      dataLog[3][5] = gyroX;
      dataLog[4][5] = gyroY;
      dataLog[5][5] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5300 && (currentMillis - previousMillis_Save) <= 5300 + 50) {
      dataLog[0][6] = accX;
      dataLog[1][6] = accY;
      dataLog[2][6] = accZ;
      dataLog[3][6] = gyroX;
      dataLog[4][6] = gyroY;
      dataLog[5][6] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5350 && (currentMillis - previousMillis_Save) <= 5350 + 50) {
      dataLog[0][7] = accX;
      dataLog[1][7] = accY;
      dataLog[2][7] = accZ;
      dataLog[3][7] = gyroX;
      dataLog[4][7] = gyroY;
      dataLog[5][7] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5400 && (currentMillis - previousMillis_Save) <= 5400 + 50) {
      dataLog[0][8] = accX;
      dataLog[1][8] = accY;
      dataLog[2][8] = accZ;
      dataLog[3][8] = gyroX;
      dataLog[4][8] = gyroY;
      dataLog[5][8] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5450 && (currentMillis - previousMillis_Save) <= 5450 + 50) {
      dataLog[0][9] = accX;
      dataLog[1][9] = accY;
      dataLog[2][9] = accZ;
      dataLog[3][9] = gyroX;
      dataLog[4][9] = gyroY;
      dataLog[5][9] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5450 && (currentMillis - previousMillis_Save) <= 5450 + 50) {
      dataLog[0][10] = accX;
      dataLog[1][10] = accY;
      dataLog[2][10] = accZ;
      dataLog[3][10] = gyroX;
      dataLog[4][10] = gyroY;
      dataLog[5][10] = gyroZ;
     } else if ((currentMillis - previousMillis_Save) >= 5050 && (currentMillis - previousMillis_Save) <= 5050 + 50) {
      dataLog[0][11] = accX;
      dataLog[1][11] = accY;
      dataLog[2][11] = accZ;
      dataLog[3][11] = gyroX;
      dataLog[4][11] = gyroY;
      dataLog[5][11] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5100 && (currentMillis - previousMillis_Save) <= 5100 + 50) {
      dataLog[0][12] = accX;
      dataLog[1][12] = accY;
      dataLog[2][12] = accZ;
      dataLog[3][12] = gyroX;
      dataLog[4][12] = gyroY;
      dataLog[5][12] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5150 && (currentMillis - previousMillis_Save) <= 5150 + 50) {
      dataLog[0][13] = accX;
      dataLog[1][13] = accY;
      dataLog[2][13] = accZ;
      dataLog[3][13] = gyroX;
      dataLog[4][13] = gyroY;
      dataLog[5][13] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5200 && (currentMillis - previousMillis_Save) <= 5200 + 50) {
      dataLog[0][14] = accX;
      dataLog[1][14] = accY;
      dataLog[2][14] = accZ;
      dataLog[3][14] = gyroX;
      dataLog[4][14] = gyroY;
      dataLog[5][14] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5250 && (currentMillis - previousMillis_Save) <= 5250 + 50) {
      dataLog[0][15] = accX;
      dataLog[1][15] = accY;
      dataLog[2][15] = accZ;
      dataLog[3][15] = gyroX;
      dataLog[4][15] = gyroY;
      dataLog[5][15] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5300 && (currentMillis - previousMillis_Save) <= 5300 + 50) {
      dataLog[0][16] = accX;
      dataLog[1][16] = accY;
      dataLog[2][16] = accZ;
      dataLog[3][16] = gyroX;
      dataLog[4][16] = gyroY;
      dataLog[5][16] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5350 && (currentMillis - previousMillis_Save) <= 5350 + 50) {
      dataLog[0][17] = accX;
      dataLog[1][17] = accY;
      dataLog[2][17] = accZ;
      dataLog[3][17] = gyroX;
      dataLog[4][17] = gyroY;
      dataLog[5][17] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5400 && (currentMillis - previousMillis_Save) <= 5400 + 50) {
      dataLog[0][18] = accX;
      dataLog[1][18] = accY;
      dataLog[2][18] = accZ;
      dataLog[3][18] = gyroX;
      dataLog[4][18] = gyroY;
      dataLog[5][18] = gyroZ;
    } else if ((currentMillis - previousMillis_Save) >= 5450 && (currentMillis - previousMillis_Save) <= 5450 + 50) {
      dataLog[0][19] = accX;
      dataLog[1][19] = accY;
      dataLog[2][19] = accZ;
      dataLog[3][19] = gyroX;
      dataLog[4][19] = gyroY;
      dataLog[5][19] = gyroZ;
   
      saveState = 2;
    }
  }
   if (saveState == 2) {
    myFile = SD.open("/data.txt", FILE_WRITE);
    if (myFile) {
      Serial.print("Writing...");
      myFile.println("Accel  X" + dataLog[0][0] + " " +  "Y" + dataLog[1][0] + " " + "Z" + dataLog[2][0] + " " + "GYRO" + " " + "X" + dataLog[3][0] + " " + "Y" + dataLog[4][0] + " " + "Z" + dataLog[5][0]);
      myFile.println("Accel  X" + dataLog[0][1] + " " +  "Y" + dataLog[1][1] + " " + "Z" + dataLog[2][1] + " " + "GYRO" + " " + "X" + dataLog[3][1] + " " + "Y" + dataLog[4][1] + " " + "Z" + dataLog[5][1]);
      myFile.println("Accel  X" + dataLog[0][2] + " " +  "Y" + dataLog[1][2] + " " + "Z" + dataLog[2][2] + " " + "GYRO" + " " + "X" + dataLog[3][2] + " " + "Y" + dataLog[4][2] + " " + "Z" + dataLog[5][2]);
      myFile.println("Accel  X" + dataLog[0][3] + " " +  "Y" + dataLog[1][3] + " " + "Z" + dataLog[2][3] + " " + "GYRO" + " " + "X" + dataLog[3][3] + " " + "Y" + dataLog[4][3] + " " + "Z" + dataLog[5][3]);
      myFile.println("Accel  X" + dataLog[0][4] + " " +  "Y" + dataLog[1][4] + " " + "Z" + dataLog[2][4] + " " + "GYRO" + " " + "X" + dataLog[3][4] + " " + "Y" + dataLog[4][4] + " " + "Z" + dataLog[5][4]);
      myFile.println("Accel  X" + dataLog[0][5] + " " +  "Y" + dataLog[1][5] + " " + "Z" + dataLog[2][5] + " " + "GYRO" + " " + "X" + dataLog[3][5] + " " + "Y" + dataLog[4][5] + " " + "Z" + dataLog[5][5]);
      myFile.println("Accel  X" + dataLog[0][6] + " " +  "Y" + dataLog[1][6] + " " + "Z" + dataLog[2][6] + " " + "GYRO" + " " + "X" + dataLog[3][6] + " " + "Y" + dataLog[4][6] + " " + "Z" + dataLog[5][6]);
      myFile.println("Accel  X" + dataLog[0][7] + " " +  "Y" + dataLog[1][7] + " " + "Z" + dataLog[2][7] + " " + "GYRO" + " " + "X" + dataLog[3][7] + " " + "Y" + dataLog[4][7] + " " + "Z" + dataLog[5][7]);
      myFile.println("Accel  X" + dataLog[0][8] + " " +  "Y" + dataLog[1][8] + " " + "Z" + dataLog[2][8] + " " + "GYRO" + " " + "X" + dataLog[3][8] + " " + "Y" + dataLog[4][8] + " " + "Z" + dataLog[5][8]);
      myFile.println("Accel  X" + dataLog[0][9] + " " +  "Y" + dataLog[1][9] + " " + "Z" + dataLog[2][9] + " " + "GYRO" + " " + "X" + dataLog[3][9] + " " + "Y" + dataLog[4][9] + " " + "Z" + dataLog[5][9]);
      myFile.println("Accel  X" + dataLog[0][10] + " " +  "Y" + dataLog[1][10] + " " + "Z" + dataLog[2][10] + " " + "GYRO" + " " + "X" + dataLog[3][10] + " " + "Y" + dataLog[4][10] + " " + "Z" + dataLog[5][10]);
      myFile.println("Accel  X" + dataLog[0][11] + " " +  "Y" + dataLog[1][11] + " " + "Z" + dataLog[2][11] + " " + "GYRO" + " " + "X" + dataLog[3][11] + " " + "Y" + dataLog[4][11] + " " + "Z" + dataLog[5][11]);
      myFile.println("Accel  X" + dataLog[0][12] + " " +  "Y" + dataLog[1][12] + " " + "Z" + dataLog[2][12] + " " + "GYRO" + " " + "X" + dataLog[3][12] + " " + "Y" + dataLog[4][12] + " " + "Z" + dataLog[5][12]);
      myFile.println("Accel  X" + dataLog[0][13] + " " +  "Y" + dataLog[1][13] + " " + "Z" + dataLog[2][13] + " " + "GYRO" + " " + "X" + dataLog[3][13] + " " + "Y" + dataLog[4][13] + " " + "Z" + dataLog[5][13]);
      myFile.println("Accel  X" + dataLog[0][14] + " " +  "Y" + dataLog[1][14] + " " + "Z" + dataLog[2][14] + " " + "GYRO" + " " + "X" + dataLog[3][14] + " " + "Y" + dataLog[4][14] + " " + "Z" + dataLog[5][14]);
      myFile.println("Accel  X" + dataLog[0][15] + " " +  "Y" + dataLog[1][15] + " " + "Z" + dataLog[2][15] + " " + "GYRO" + " " + "X" + dataLog[3][15] + " " + "Y" + dataLog[4][15] + " " + "Z" + dataLog[5][15]);
      myFile.println("Accel  X" + dataLog[0][16] + " " +  "Y" + dataLog[1][16] + " " + "Z" + dataLog[2][16] + " " + "GYRO" + " " + "X" + dataLog[3][16] + " " + "Y" + dataLog[4][16] + " " + "Z" + dataLog[5][16]);
      myFile.println("Accel  X" + dataLog[0][17] + " " +  "Y" + dataLog[1][17] + " " + "Z" + dataLog[2][17] + " " + "GYRO" + " " + "X" + dataLog[3][17] + " " + "Y" + dataLog[4][17] + " " + "Z" + dataLog[5][17]);
      myFile.println("Accel  X" + dataLog[0][18] + " " +  "Y" + dataLog[1][18] + " " + "Z" + dataLog[2][18] + " " + "GYRO" + " " + "X" + dataLog[3][18] + " " + "Y" + dataLog[4][18] + " " + "Z" + dataLog[5][18]);
      myFile.println("Accel  X" + dataLog[0][19] + " " +  "Y" + dataLog[1][19] + " " + "Z" + dataLog[2][19] + " " + "GYRO" + " " + "X" + dataLog[3][19] + " " + "Y" + dataLog[4][19] + " " + "Z" + dataLog[5][19]);

      
      Serial.println("Done.");
      M5.Lcd.setTextColor(WHITE , BLACK);
      M5.Lcd.setCursor(100, 220);
      M5.Lcd.print("Save Done");
      //saveState = 0;
    } else {
      Serial.println("error opening");
    }
  }
  delay(1);
}
