#pragma once

void PrintOut(const int& Instances, const int& Height, const int& Width, bool  BodyArea[5][16][16], bool  MapArea[16][16]);

void SomeRandomFunnyGeneration(const int& Instances, bool  BodyArea[10][16][16], const int& Width, const int& Height);

void Display(const int& Width, const int& Height, int PlayerX, int PlayerY, bool  BodyArea[10][16][16], int PlayerXPad, int t);

void ClearMap(const int& Height, const int& Width, bool  MapArea[16][16]);
