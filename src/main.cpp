#include <Arduino.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup()
{
  Serial.begin(115200);

  // Use GPIO23 for SDA and GPIO22 for SCL
  Wire.begin(23, 22);

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  if (mpu.testConnection())
  {
    Serial.println("MPU6050 connection successful!");
  }
  else
  {
    Serial.println("MPU6050 connection failed!");
    while (1)
      ; // Stop if no connection
  }
}

void loop()
{
  int16_t ax, ay, az, gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Serial.print("Accel: ");
  Serial.print("X=");
  Serial.print(ax);
  Serial.print(" Y=");
  Serial.print(ay);
  Serial.print(" Z=");
  Serial.print(az);

  Serial.print(" | Gyro: ");
  Serial.print("X=");
  Serial.print(gx);
  Serial.print(" Y=");
  Serial.print(gy);
  Serial.print(" Z=");
  Serial.println(gz);

  delay(500);
}