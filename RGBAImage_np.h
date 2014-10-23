/*
RGBAImage.h
Copyright (C) 2006 Yangli Hector Yee

This program is free software; you can redistribute it and/or modify it under the terms of the
GNU General Public License as published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program;
if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef _RGAIMAGE_H
#define _RGBAIMAGE_H

#include <stdint.h>

/** Class encapsulating an image containing R,G,B,A channels.
 *
 * Internal representation assumes data is in the ABGR format, with the RGB
 * color channels premultiplied by the alpha value.  Premultiplied alpha is
 * often also called "associated alpha" - see the tiff 6 specification for some
 * discussion - http://partners.adobe.com/asn/developer/PDFS/TN/TIFF6.pdf
 *
 */
class RGBAImage
{
	RGBAImage(const RGBAImage&);
	RGBAImage& operator=(const RGBAImage&);
public:
	RGBAImage(int w, int h, void * imgdatav);
	unsigned char Get_Red(unsigned int i);
	unsigned char Get_Green(unsigned int i);
	unsigned char Get_Blue(unsigned int i);
	unsigned char Get_Alpha(unsigned int i);
	void Set(unsigned char r, unsigned char g, unsigned char b, unsigned char a, unsigned int i);
	int Get_Width(void) const;
	int Get_Height(void) const;
	void Set(int x, int y, unsigned int d);
	unsigned int Get(int x, int y) const;
	unsigned int Get(int i) const;
	//const std::string &Get_Name(void) const { return Name; }
    //RGBAImage* DownSample() const;
	
	//bool WriteToFile(const char* filename);
	//static RGBAImage* ReadFromFile(const char* filename);
	
protected:
	int Width;
	int Height;
	uint8_t *Data;
};

#endif
