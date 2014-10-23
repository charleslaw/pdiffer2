/*
RGBAImage.cpp
Copyright (C) 2006 Yangli Hector Yee

(This entire file was rewritten by Jim Tilander)

This program is free software; you can redistribute it and/or modify it under the terms of the
GNU General Public License as published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program;
if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "RGBAImage_np.h"
#include <cstdio>
#include <cstring>


RGBAImage::RGBAImage(int w, int h, void * imgdatav) {
    Width = w;
    Height = h;
    Data = (uint8_t *) imgdatav;
}


unsigned char RGBAImage::Get_Red(unsigned int i) {
    unsigned int act_i = i*3;
    return (unsigned char)(Data[i+2]);
}

unsigned char RGBAImage::Get_Green(unsigned int i) {
    unsigned int act_i = i*3;
    return (unsigned char)(Data[i+1]);
}

unsigned char RGBAImage::Get_Blue(unsigned int i) {
    unsigned int act_i = i*3;
    return (unsigned char)(Data[i]);
}

unsigned char RGBAImage::Get_Alpha(unsigned int i) {
    // Just return 0
    uint8_t no_alpha;
    no_alpha = 0;
    return no_alpha;
}

void RGBAImage::Set(unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned int i) {
    Data[i+3] = r;
    Data[i+2] = g;
    Data[i] = b;
}

int RGBAImage::Get_Width(void) const {
    return Width;
}

int RGBAImage::Get_Height(void) const {
    return Height;
}

void RGBAImage::Set(int x, int y, unsigned int d) {
    int i = x + y * Width;
    Data[i] = d;
}

unsigned int RGBAImage::Get(int x, int y) const {
    int i = x + y * Width;
    return Get(i);
}

unsigned int RGBAImage::Get(int i) const {
    int act_i = i*3;
    unsigned int res = Data[i+2] | (Data[i+1] << 8) | (Data[i] << 16);
    return res;
}
