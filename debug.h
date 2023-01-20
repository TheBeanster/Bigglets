#pragma once



namespace debug
{



void SetColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

void DrawRect(int x, int y, int w, int h);
void FillRect(int x, int y, int w, int h);

void DrawRectInWorld(int x, int y, int w, int h);
void FillRectInWorld(int x, int y, int w, int h);

void DrawFrameRateDisplay(int frame);



}