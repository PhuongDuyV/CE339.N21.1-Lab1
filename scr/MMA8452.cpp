#include "MMA8452.h"

#define MMA8452_ADDRESS 0x1C // Địa chỉ mặc định của thiết bị trên giao thức I2C, sẽ là 0x1D nếu chân SA0 có điện mức cao

void MMA8452::begin() {
	Wire.begin();
	writeRegister(0x2A, 0x01); /
}

void MMA8452::readXYZ(int* x, int* y, int* z) //Đọc giá trị gia tốc trên các trục x, y và z. Sử dụng phương thức readRegister() để đọc dữ liệu từ thanh ghi OUT_X_MSB và OUT_X_LSB cho trục x
                                              //OUT_Y_MSB và OUT_Y_LSB cho trục y và OUT_Z_MSB và OUT_Z_LSB cho trục z. 
	                                         //Sau đó, giá trị đọc được được chuyển đổi từ định dạng 12 bit sang giá trị số nguyên.
{ 
	uint8_t data[6];
	readRegister(0x01, data);
	*x = ((data[0] << 8) | data[1]) >> 4;
	*y = ((data[2] << 8) | data[3]) >> 4;
	*z = ((data[4] << 8) | data[5]) >> 4;
}

void MMA8452::writeRegister(uint8_t reg, uint8_t val) // ghi giá trị vào thanh ghi (register) của MMA8452 thông qua giao thức I2C
{
	Wire.beginTransmission(MMA8452_ADDRESS);
	Wire.write(reg);
	Wire.write(val);
	Wire.endTransmission();
}

void MMA8452::readRegister(uint8_t reg, uint8_t* val) // đọc giá trị từ thanh ghi của MMA8452 thông qua giao thức I2C.
{
	Wire.beginTransmission(MMA8452_ADDRESS);
	Wire.write(reg);
	Wire.endTransmission(false);
	Wire.requestFrom(MMA8452_ADDRESS, (uint8_t)1);
	*val = Wire.read();
}