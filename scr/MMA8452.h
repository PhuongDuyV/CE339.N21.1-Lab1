#ifndef MMA8452_h
#define MMA8452_h

#include <Wire.h>

class MMA8452 {
public:
    void begin();// Khởi tạo cảm biến MMA8452.
    void readXYZ(int* x, int* y, int* z); // khởi tạo phương thức đọc giá trị gia tốc trên các trục x, y và z.
private:
    void writeRegister(uint8_t reg, uint8_t val); //các phương thức để ghi và đọc các giá trị từ thanh ghi (register) của MMA8452 thông qua giao thức I2C.
    void readRegister(uint8_t reg, uint8_t* val);
};

#endif
