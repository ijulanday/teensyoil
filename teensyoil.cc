#include "teensyoil.hh"

uint16_t parseMsbFirst(uint8_t b0, uint8_t b1) {
    return b0 << 8 | b1;
}

uint16_t parseOilSensorMessage(CAN_message_t msg, float* oilLevel, float* pcbTemp, float* oilTemp) {
    uint16_t rawlevel = parseMsbFirst(msg.buf[0], msg.buf[1]);
    uint16_t rawpcbt = parseMsbFirst(msg.buf[2], msg.buf[3]);
    uint16_t rawoilt = parseMsbFirst(msg.buf[4], msg.buf[5]);

    if (rawpcbt == 0x8001 || rawpcbt == 0x8002 || rawpcbt == 0xFFFF)   
        return rawpcbt;
    if (rawoilt == 0x8001 || rawoilt == 0x8002 || rawoilt == 0xFFFF)   
        return rawoilt;
    
    *oilLevel = (float)rawlevel * 0.1;
    *pcbTemp = (float)rawpcbt * 0.1;
    *oilTemp = (float)rawoilt * 0.1;

    return 0;
}