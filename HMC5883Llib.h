// Code by Blaise Jarrett @ OSEPP http://blaisejarrett.com
// Released to the public domain! Enjoy!

#ifndef _HMC5833LLIB_H_
#define _HMC5833LLIB_H_

#include <stdint.h>

#define HMC5833L_I2CADD 0x1E

#define HMC5833L_ERROR_NOT_INITIALIZED -2
#define HMC5833L_ERROR_WRONG_ID -3
#define HMC5833L_ERROR_I2CREAD -4
#define HMC5833L_ERROR_I2CWRITE -5
#define HMC5833L_ERROR_GAINOUTOFRANGE -6
#define HMC5833L_ERROR_GAINOVERFLOW -7

// Register Map
#define HMC5833L_REG_CFGA 0
#define HMC5833L_REG_CFGB 1
#define HMC5833L_REG_MODE 2
#define HMC5833L_REG_DATAXYZ 3
#define HMC5833L_REG_IDA 10
#define HMC5833L_REG_IDB 11
#define HMC5833L_REG_IDC 12

#define HMC5833L_REG_IDA_ID 0x48
#define HMC5833L_REG_IDB_ID 0x34
#define HMC5833L_REG_IDC_ID 0x33

// LSB / Gauss - refer to datasheet
#define HMC5833L_GAIN_1370 0
#define HMC5833L_GAIN_1090 1
#define HMC5833L_GAIN_820 2
#define HMC5833L_GAIN_660 3
#define HMC5833L_GAIN_440 4
#define HMC5833L_GAIN_390 5
#define HMC5833L_GAIN_330 6
#define HMC5833L_GAIN_230 7
// 1370     +- 0.88 Ga
// 1090     +- 1.3 Ga
// 820      +- 1.9 Ga
// 660      +- 2.5 Ga
// 440      +- 4.0 Ga
// 390      +- 4.7 Ga
// 330      +- 5.6 Ga
// 230      +- 8.1 Ga


class Magnetometer {
    public:
        Magnetometer();
        int8_t begin();
        int8_t readRaw(int16_t * x, int16_t * y, int16_t * z);
        int8_t readGauss(double * x, double * y, double * z);
        int8_t setGain(uint8_t gain);
        int8_t readHeadingDeg(double * heading);
    protected:
        int8_t i2cReadBytes(uint8_t reg, uint8_t * data, uint8_t len);
        int8_t i2cWriteByte(uint8_t reg, uint8_t data);
        uint8_t i2cAddr_;
        uint8_t gain_;
    private:
        void conv2Byte2Signed16(uint8_t LSB, uint8_t MSB, int16_t * dest);
};


#endif