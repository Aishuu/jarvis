#ifndef CONSTANT_H
#define CONSTANT_H

#define touch Sensor(S1)
#define compass SensorHTCompass(IN_2)
#define ultras SensorUS(S3)
#define light SensorRaw(IN_4)

#define DEBUG

#ifdef DEBUG
#define D(_i,_s) ClearLine(LCD_LINE##_i); NumOut(1, LCD_LINE##_i, _s)
#define Ds(_i,_c,_s) _print(LCD_LINE##_i, _c, _s)
#define DGraph(_i,_m,_n) _graph(_i, _m, _n)
void _print(int _i, string _com, int _s) {
    ClearLine(_i);
    TextOut(0, _i, _com);
    NumOut(50, _i, _s);
}
int _debug_x = 0;
int _debug_points[100];
void _graph(int _i, int _max, int _min) {
    _debug_points[_debug_x] = 64-((_i-_min)*64)/(_max-_min);
    ClearScreen();
    for(int _c=0;_c<100;_c++) {
        if(_debug_points[_c]<0 || _debug_points[_c]>64)
            break;
        PointOut(_c, _debug_points[_c]);
    }
    _debug_x++;
    _debug_x=_debug_x%100;
}
#else
#define D(_i,_s)
#define Ds(_i,_c,_s)
#define DGraph(_i,_m,_n)
#endif

struct position {
    float theta;
    float x;
    float y;
    long r_tacho_last_rotate;
    long l_tacho_last_rotate;
    float angle_last_rotate;
    float angle_cumul;
    float angle_arm;
};


bool MV_OUT_OF_BOUND;   // set to true when going out of bound
bool STOP;              // set to true when one want to interrupt a movement
bool PAUSE;             // set to true if one want to pause a movement
bool ROTATING;          // set to true when jarvis is rotating
mutex movement_mutex;   // mutex for the movement functions

position current_pos;   // current position of jarvis
int compass_start;

#endif      // constant.h
