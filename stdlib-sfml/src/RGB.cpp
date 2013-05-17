#include "RGB.h"
#include "TuringCommon/Libdefs.h"
#include "TuringCommon/RuntimeError.h"

#define FAST_RGB_SET

char TuringPalette[256][3] = {
    {255, 255, 255},	// 0  = white
    {  0,   0, 128},	// 1  = blue
    {  0, 128,   0},	// 2  = green
    {  0, 128, 128},	// 3  = cyan
    {128,   0,   0},	// 4  = red
    {128,   0, 128},	// 5  = magenta (purple)
    {128, 128,   0},	// 6  = brown
    {  0,   0,   0},	// 7  = black
    {192, 192, 192},	// 8  = gray
    {  0,   0, 255},	// 9  = bright blue
    {  0, 255,   0},	// 10 = bright green
    {  0, 255, 255},	// 11 = bright cyan
    {255,   0,   0},	// 12 = bright red
    {255,   0, 255},	// 13 = bright magenta (purple)
    {255, 255,   0},	// 14 = yellow
    {128, 128, 128},	// 15 = dark gray
    {  0,   0,   0},	// 16
    { 20,  20,  20},	// 17
    { 32,  32,  32},	// 18
    { 44,  44,  44},	// 19
    { 56,  56,  56},	// 20
    { 69,  69,  69},	// 21
    { 81,  81,  81},	// 22
    { 97,  97,  97},	// 23
    {113, 113, 113},	// 24
    {130, 130, 130},	// 25
    {146, 146, 146},	// 26
    {162, 162, 162},	// 27
    {182, 182, 182},	// 28
    {203, 203, 203},	// 29
    {227, 227, 227},	// 30
    {255, 255, 255},	// 31
    {  0,   0, 255},	// 32
    { 65,   0, 255},	// 33
    {125,   0, 255},	// 34
    {190,   0, 255},	// 35
    {255,   0, 255},	// 36
    {255,   0, 190},	// 37
    {255,   0, 125},	// 38
    {255,   0,  65},	// 39
    {255,   0,   0},	// 40
    {255,  65,   0},	// 41
    {255, 125,   0},	// 42
    {255, 190,   0},	// 43
    {255, 255,   0},	// 44
    {190, 255,   0},	// 45
    {125, 255,   0},	// 46
    { 65, 255,   0},	// 47
    {  0, 255,   0},	// 48
    {  0, 255,  65},	// 49
    {  0, 255, 125},	// 50
    {  0, 255, 190},	// 51
    {  0, 255, 255},	// 52
    {  0, 190, 255},	// 53
    {  0, 125, 255},	// 54
    {  0,  65, 255},	// 55
    {125, 125, 255},	// 56
    {158, 125, 255},	// 57
    {190, 125, 255},	// 58
    {223, 125, 255},	// 59
    {255, 125, 255},	// 60
    {255, 125, 223},	// 61
    {255, 125, 190},	// 62
    {255, 125, 158},	// 63
    {255, 125, 125},	// 64
    {255, 158, 125},	// 65
    {255, 190, 125},	// 66
    {255, 223, 125},	// 67
    {255, 255, 125},	// 68
    {223, 255, 125},	// 69
    {190, 255, 125},	// 70
    {158, 255, 125},	// 71
    {125, 255, 125},	// 72
    {125, 255, 158},	// 73
    {125, 255, 190},	// 74
    {125, 255, 223},	// 75
    {125, 255, 255},	// 76
    {125, 223, 255},	// 77
    {125, 190, 255},	// 78
    {125, 158, 255},	// 79
    {182, 182, 255},	// 80
    {199, 182, 255},	// 81
    {219, 182, 255},	// 82
    {235, 182, 255},	// 83
    {255, 182, 255},	// 84
    {255, 182, 235},	// 85
    {255, 182, 219},	// 86
    {255, 182, 199},	// 87
    {255, 182, 182},	// 88
    {255, 199, 182},	// 89
    {255, 219, 182},	// 90
    {255, 235, 182},	// 91
    {255, 255, 182},	// 92
    {235, 255, 182},	// 93
    {219, 255, 182},	// 94
    {199, 255, 182},	// 95
    {182, 255, 182},	// 96
    {182, 255, 199},	// 97
    {182, 255, 219},	// 98
    {182, 255, 235},	// 99
    {182, 255, 255},	// 100
    {182, 235, 255},	// 101
    {182, 219, 255},	// 102
    {182, 199, 255},	// 103
    {  0,   0, 113},	// 104
    { 28,   0, 113},	// 105
    { 56,   0, 113},	// 106
    { 85,   0, 113},	// 107
    {113,   0, 113},	// 108
    {113,   0,  85},	// 109
    {113,   0,  56},	// 110
    {113,   0,  28},	// 111
    {113,   0,   0},	// 112
    {113,  28,   0},	// 113
    {113,  56,   0},	// 114
    {113,  85,   0},	// 115
    {113, 113,   0},	// 116
    { 85, 113,   0},	// 117
    { 56, 113,   0},	// 118
    { 28, 113,   0},	// 119
    {  0, 113,   0},	// 120
    {  0, 113,  28},	// 121
    {  0, 113,  56},	// 122
    {  0, 113,  85},	// 123
    {  0, 113, 113},	// 124
    {  0,  85, 113},	// 125
    {  0,  56, 113},	// 126
    {  0,  28, 113},	// 127
    { 56,  56, 113},	// 128
    { 69,  56, 113},	// 129
    { 85,  56, 113},	// 130
    { 97,  56, 113},	// 131
    {113,  56, 113},	// 132
    {113,  56,  97},	// 133
    {113,  56,  85},	// 134
    {113,  56,  69},	// 135
    {113,  56,  56},	// 136
    {113,  69,  56},	// 137
    {113,  85,  56},	// 138
    {113,  97,  56},	// 139
    {113, 113,  56},	// 140
    { 97, 113,  56},	// 141
    { 85, 113,  56},	// 142
    { 69, 113,  56},	// 143
    { 56, 113,  56},	// 144
    { 56, 113,  69},	// 145
    { 56, 113,  85},	// 146
    { 56, 113,  97},	// 147
    { 56, 113, 113},	// 148
    { 56,  97, 113},	// 149
    { 56,  85, 113},	// 150
    { 56,  69, 113},	// 151
    { 81,  81, 113},	// 152
    { 89,  81, 113},	// 153
    { 97,  81, 113},	// 154
    {105,  81, 113},	// 155
    {113,  81, 113},	// 156
    {113,  81, 105},	// 157
    {113,  81,  97},	// 158
    {113,  81,  89},	// 159
    {113,  81,  81},	// 160
    {113,  89,  81},	// 161
    {113,  97,  81},	// 162
    {113, 105,  81},	// 163
    {113, 113,  81},	// 164
    {105, 113,  81},	// 165
    { 97, 113,  81},	// 166
    { 89, 113,  81},	// 167
    { 81, 113,  81},	// 168
    { 81, 113,  89},	// 169
    { 81, 113,  97},	// 170
    { 81, 113, 105},	// 171
    { 81, 113, 113},	// 172
    { 81, 105, 113},	// 173
    { 81,  97, 113},	// 174
    { 81,  89, 113},	// 175
    {  0,   0,  65},	// 176
    { 16,   0,  65},	// 177
    { 32,   0,  65},	// 178
    { 48,   0,  65},	// 179
    { 65,   0,  65},	// 180
    { 65,   0,  48},	// 181
    { 65,   0,  32},	// 182
    { 65,   0,  16},	// 183
    { 65,   0,   0},	// 184
    { 65,  16,   0},	// 185
    { 65,  32,   0},	// 186
    { 65,  48,   0},	// 187
    { 65,  65,   0},	// 188
    { 48,  65,   0},	// 189
    { 32,  65,   0},	// 190
    { 16,  65,   0},	// 191
    {  0,  65,   0},	// 192
    {  0,  65,  16},	// 193
    {  0,  65,  32},	// 194
    {  0,  65,  48},	// 195
    {  0,  65,  65},	// 196
    {  0,  48,  65},	// 197
    {  0,  32,  65},	// 198
    {  0,  16,  65},	// 199
    { 32,  32,  65},	// 200
    { 40,  32,  65},	// 201
    { 48,  32,  65},	// 202
    { 56,  32,  65},	// 203
    { 65,  32,  65},	// 204
    { 65,  32,  56},	// 205
    { 65,  32,  48},	// 206
    { 65,  32,  40},	// 207
    { 65,  32,  32},	// 208
    { 65,  40,  32},	// 209
    { 65,  48,  32},	// 210
    { 65,  56,  32},	// 211
    { 65,  65,  32},	// 212
    { 56,  65,  32},	// 213
    { 48,  65,  32},	// 214
    { 40,  65,  32},	// 215
    { 32,  65,  32},	// 216
    { 32,  65,  40},	// 217
    { 32,  65,  48},	// 218
    { 32,  65,  56},	// 219
    { 32,  65,  65},	// 220
    { 32,  56,  65},	// 221
    { 32,  48,  65},	// 222
    { 32,  40,  65},	// 223
    { 44,  44,  65},	// 224
    { 48,  44,  65},	// 225
    { 52,  44,  65},	// 226
    { 60,  44,  65},	// 227
    { 65,  44,  65},	// 228
    { 65,  44,  60},	// 229
    { 65,  44,  52},	// 230
    { 65,  44,  48},	// 231
    { 65,  44,  44},	// 232
    { 65,  48,  44},	// 233
    { 65,  52,  44},	// 234
    { 65,  60,  44},	// 235
    { 65,  65,  44},	// 236
    { 60,  65,  44},	// 237
    { 52,  65,  44},	// 238
    { 48,  65,  44},	// 239
    { 44,  65,  44},	// 240
    { 44,  65,  48},	// 241
    { 44,  65,  52},	// 242
    { 44,  65,  60},	// 243
    { 44,  65,  65},	// 244
    { 44,  60,  65},	// 245
    { 44,  52,  65},	// 246
    { 44,  48,  65},	// 247
    {  0,   0,   0},	// 248
    {  0,   0,   0},	// 249
    {  0,   0,   0},	// 250
    {  0,   0,   0},	// 251
    {  0,   0,   0},	// 252
    {  0,   0,   0},	// 253
    {  0,   0,   0},	// 254
    {  0,   0,   0}	// 255
};

void setRGBCoulourForNum(TInt num, char r, char g, char b) {
    TuringPalette[num][0] = r;
    TuringPalette[num][1] = g;
    TuringPalette[num][2] = b;
}

char *getRGBColourFromNum(TInt num) {
    if (num < 0 || num > 255) {
        TuringCommon::runtimeError("Colour number out of range.");
    }
    return TuringPalette[num];
}

extern "C" {
    void Turing_StdlibSFML_RGB_SetColor(TInt num, TReal r, TReal g, TReal b) {
#ifndef FAST_RGB_SET
        if (r > 1.0 || g > 1.0 || b > 1.0 || r < 0.0 || g < 0.0 || b < 0.0) {
            TuringCommon::runtimeError("Color component out of range in RGB.SetColor");
        }
        if (num < 0 || num > 255) {
            TuringCommon::runtimeError("Color number out of range in RGB.SetColor");
        }
#endif
        setRGBCoulourForNum(num, r*255, g*255, b*255);
    }
}