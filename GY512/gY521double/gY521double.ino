    // MPU-6050 Short Example Sketch
    // By Arduino User JohnChi
    // August 17, 2014
    // Public Domain
    #include<Wire.h>
    const int MPU_addr=0x68;  // I2C address of the MPU-6050
    const int MPU_addr_unit2=0x69;  // I2C address of the MPU-6050

    int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

    void setup(){
      Wire.begin();
      Wire.beginTransmission(MPU_addr);
      Wire.write(0x6B);  // PWR_MGMT_1 register
      Wire.write(0);     // set to zero (wakes up the MPU-6050)
      Wire.endTransmission(true);
      
//      Wire.beginTransmission(MPU_addr_unit2);
//      Wire.write(0x6B);  // PWR_MGMT_1 register
//      Wire.write(0);     // set to zero (wakes up the MPU-6050)
//      Wire.endTransmission(true);

      Serial.begin(9600);
    }
    int16_t printValues(int sensoradress)
    {
        //Serial.print("Sensor = "); Serial.println(sensoradress);
        Wire.beginTransmission(sensoradress);
        Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
        Wire.endTransmission(false);
        Wire.requestFrom(sensoradress,14,true);  // request a total of 14 registers
        AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
        AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
        AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
        Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
        GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
        GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
        GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
//        Serial.print("AcX = "); Serial.print(AcX);
//        Serial.print(" | AcY = "); Serial.print(AcY);
//        Serial.print(" | AcZ = "); Serial.print(AcZ);
//        Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
//        Serial.print(" | GyX = "); Serial.print(GyX);
//        Serial.print(" | GyY = "); Serial.print(GyY);
//        Serial.print(" | GyZ = "); Serial.println(GyZ);
        
        return AcZ;
    
    }
    
    void getdat(int16_t (& myarray) [3],int sensoradress)
    {
        Wire.beginTransmission(sensoradress);
        Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
        Wire.endTransmission(false);
        Wire.requestFrom(sensoradress,14,true);  // request a total of 14 registers
        AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
        AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
        AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
        Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
        GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
        GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
        GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
//        Serial.print("AcX = "); Serial.print(AcX);
//        Serial.print(" | AcY = "); Serial.print(AcY);
//        Serial.print(" | AcZ = "); Serial.print(AcZ);
//        Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
//        Serial.print(" | GyX = "); Serial.print(GyX);
//        Serial.print(" | GyY = "); Serial.print(GyY);
//        Serial.print(" | GyZ = "); Serial.println(GyZ);
        myarray[0] = AcX;
        myarray[1] = AcY;
        myarray[2] = AcZ;

    }
    void loop(){
        int16_t data1[3];
        getdat(data1,MPU_addr);
        int16_t data2[3];
        getdat(data2,MPU_addr_unit2);      

      //b = printValues(MPU_addr_unit2);
           // double kata = ((double)(a-b))/(16384.0)*90.0;
    
     double kata = asin((double)data1[1]/16384.0)*180.0/3.14;
     double katb = asin((double)data2[1]/16384.0)*180.0/3.14;
          Serial.print("Z nadgarstka = "); Serial.println(data1[2]);

    if((abs(data1[2])>2000)||(abs(data2[2])>2000)){
          Serial.print("popraw reke");Serial.println();
          Serial.print("Z nadgarstka = "); Serial.println(data1[2]);
          Serial.print("Z ramienia = "); Serial.println(data2[2]);
    }
    else{
          Serial.print("kat = "); Serial.println(abs(katb-kata));

    }
      delay(3300);
    }

