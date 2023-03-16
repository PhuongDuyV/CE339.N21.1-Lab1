#include <MMA8452.h>
#include <math.h>
MMA8452 angle = MMA8452();


int sensorPin = A0; // Đầu vào Analog cho cảm biến
int sensorValue = 0; // Giá trị Analog đọc được từ cảm biến

void setup() {
  Serial.begin(9600); // Khởi tạo Serial Monitor
  angle.begin();
}

void loop() {
  //------IR-Sensor--------//
  sensorValue = digitalRead(sensorPin); 
  Serial.print("Sensor Value: "); 
  Serial.println(sensorValue); 
  
//------MMA8452-Sensor--------//

  int x, y, z;
  angle.readXYZ(&x, &y, &z);
  float xAngle = atan2(y, sqrt(x*x + z*z)) * 180.0 / PI;  //Sử dụng hàm atan để đổi đơn vị sang độ và tính góc nghiêng của từng trục
  float yAngle = atan2(x, sqrt(y*y + z*z)) * 180.0 / PI;
  float zAngle = atan2(sqrt(x*x + y*y), z) * 180.0 / PI;

  Serial.print(xAngle);
  Serial.print("\t");
  Serial.print(yAngle);
  Serial.print("\t");
  Serial.println(zAngle);
  Serial.println();

  delay(1000); 
}

  