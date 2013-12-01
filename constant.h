#ifndef CONSTANT_H
#define CONSTANT_H

#define touch SENSOR_1
#define compass SensorHTCompass(IN_4)

#define DEBUG

#ifdef DEBUG
#define D(i,s) ClearLine(LCD_LINE##i); NumOut(1, LCD_LINE##i, s)
#define Ds(i,c,s) _print(LCD_LINE##i, c, s)
void _print(int i, string com, int s) {
    ClearLine(i);
    TextOut(0, i, com);
    NumOut(50, i, s);
}
#else
#define D(i,s)
#define Ds(i,c,s)
#endif

struct position {
    float theta;
    float x;
    float y;
};


bool MV_OUT_OF_BOUND;   // set to true when going out of bond
bool STOP;              // set to true when one want to interrupt a movement
bool PAUSE;             // set to true if one want to pause a movement
bool ROTATING;          // set to true when jarvis is rotating
mutex movement_mutex;   // mutex for the movement functions

position current_pos;   // current position of jarvis
int compass_start;

#endif      // constant.h
