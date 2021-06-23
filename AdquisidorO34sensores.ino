/*
 * 
 * Autor: Gaston Valdez
 * Lugar de realización: Instituto Argentino de radioastronomía
 * Fecha 23/6/2021
 * Version 0.1 
 * Software adquisidor de datos 
 * de los sensores SEN0321 de DFRobot
 * Los sensores captan O3 y lo envian por puerto
 * Serie para su posterior procesamiento
 * 
*/


#include "DFRobot_OzoneSensor-master\DFRobot_OzoneSensor.cpp" 
#define SET_ADQUISITION_TIME 10000 // tiempo en ms -- 10000 -- corresponde a 10 segundos
#define COLLECT_NUMBER 15 
// OBJETO SERIALES 

#define OZONE_SENSOR_ADDRESS_I2C_1 0x70  
#define OZONE_SENSOR_ADDRESS_I2C_2 0x71 
#define OZONE_SENSOR_ADDRESS_I2C_3 0x72
#define OZONE_SENSOR_ADDRESS_I2C_4 0x73 

DFRobot_OzoneSensor Ozone_1; 
DFRobot_OzoneSensor Ozone_2; 
DFRobot_OzoneSensor Ozone_3; 
DFRobot_OzoneSensor Ozone_4; 







void setup() {
  Serial.begin(9600); 
  while(!Ozone_1.begin(OZONE_SENSOR_ADDRESS_I2C_1)) {
    Serial.println("I2c device number error !");
    delay(100);
  }
  Serial.println("I2C_1 connect ok"); 
  Ozone_1.SetModes(MEASURE_MODE_PASSIVE);
/*** Segundo Sensor de ozono ***/  
  while(!Ozone_2.begin(OZONE_SENSOR_ADDRESS_I2C_2)) {
    Serial.println("I2c device number error !");
    delay(100);
  }
  Serial.println("I2C_2 connect ok"); 
  Ozone_2.SetModes(MEASURE_MODE_PASSIVE);
 /* Tercer sensor de ozono */
  while(!Ozone_3.begin(OZONE_SENSOR_ADDRESS_I2C_3)) {
    Serial.println("I2c device number error !");
    delay(100);
  }
  Serial.println("I2C_3 connect ok"); 
  Ozone_3.SetModes(MEASURE_MODE_PASSIVE);  
 /* Cuarto sensor de ozono */
  while(!Ozone_4.begin(OZONE_SENSOR_ADDRESS_I2C_4)) {
    Serial.println("I2c device number error !");
    delay(100);
  }
  Serial.println("I2C_4 connect ok");  
  Ozone_4.SetModes(MEASURE_MODE_PASSIVE);
 

  
}

void loop() {

  float ppm_oz1 = (Ozone_1.ReadOzoneData(COLLECT_NUMBER))/1000.0; 
  float ppm_oz2 = (Ozone_2.ReadOzoneData(COLLECT_NUMBER))/1000.0;; 
  float ppm_oz3 = (Ozone_3.ReadOzoneData(COLLECT_NUMBER))/1000.0;; 
  float ppm_oz4 = (Ozone_4.ReadOzoneData(COLLECT_NUMBER))/1000.0;; 
  char ppm_oz1_buff[5] ; 
  char ppm_oz2_buff[5] ;
  char ppm_oz3_buff[5] ;
  char ppm_oz4_buff[5] ; 
  char data_ozone_sensor_print[32] ; 
  dtostrf(ppm_oz1,1,2,ppm_oz1_buff);
  dtostrf(ppm_oz2,1,2,ppm_oz2_buff);
  dtostrf(ppm_oz3,1,2,ppm_oz3_buff);
  dtostrf(ppm_oz4,1,2,ppm_oz4_buff);
  sprintf(data_ozone_sensor_print,"%s,%s,%s,%s\n",ppm_oz1_buff,ppm_oz2_buff,ppm_oz3_buff,ppm_oz4_buff) ; 
  Serial.print(data_ozone_sensor_print);
  delay(SET_ADQUISITION_TIME) ;  
}
