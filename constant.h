#ifndef CONSTANT_H
#define CONSTANT_H

#define touch Sensor(S1)
#define compass SensorHTCompass(S2)
#define ultras SensorUS(S3)
#define light SensorRaw(S4)

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

// used to store the position of Jarvis
struct position {
    float theta;                    // angle of jarvis
    float x;                        // x pos of jarvis
    float y;                        // y pos of jarvis
    long r_tacho_last_rotate;       // right tacho counter at the end of the last translation of jarvis
    long l_tacho_last_rotate;       // left tacho counter at the end of the last translation of jarvis
    float angle_last_rotate;        // angle of jarvis at the end of the last translation
    float angle_cumul;              // cumulative angle jarvis was asked to rotate since his last translation
    float angle_arm;                // angle of the arm
};


bool MV_OUT_OF_BOUND;   // set to true when going out of bound
bool STOP;              // set to true when one want to interrupt a movement
bool PAUSE;             // set to true if one want to pause a movement
bool ROTATING;          // set to true when jarvis is rotating
mutex movement_mutex;   // mutex for the movement functions

position current_pos;   // current position of jarvis
int compass_start;      // value of the compass at the begining of the game

#endif      // constant.h
