#ifndef CONSTANT_H
#define CONSTANT_H

#define touch Sensor(S1)
#define compass SensorHTCompass(IN_2)
#define ultras SensorUS(S3)
#define light SensorRaw(IN_4)

#define DEBUG

#ifdef DEBUG
#define D(i,s) ClearLine(LCD_LINE##i); NumOut(1, LCD_LINE##i, s)
#define Ds(i,c,s) _print(LCD_LINE##i, c, s)
#define DGraph(i,m,n) _graph(i, m, n)
void _print(int i, string com, int s) {
    ClearLine(i);
    TextOut(0, i, com);
    NumOut(50, i, s);
}
int _debug_x = 0;
int _debug_points[100];
void _graph(int i, int max, int min) {
    _debug_points[_debug_x] = 64-((i-min)*64)/(max-min);
    ClearScreen();
    for(int c=0;c<100;c++) {
        if(_debug_points[c]<0 || _debug_points[c]>64)
            break;
        PointOut(c, _debug_points[c]);
    }
    _debug_x++;
    _debug_x=_debug_x%100;
}
#else
#define D(i,s)
#define Ds(i,c,s)
#define DGraph(i,m,n)
#endif

struct position {
    float theta;
    float x;
    float y;
    long r_tacho_last_rotate;
    long l_tacho_last_rotate;
    float angle_last_rotate;
    float angle_cumul;
};


bool STOP;              // set to true when one want to interrupt a movement
bool PAUSE;             // set to true if one want to pause a movement
bool ROTATING;          // set to true when jarvis is rotating
mutex movement_mutex;   // mutex for the movement functions

position current_pos;   // current position of jarvis
int compass_start;

#endif      // constant.h
