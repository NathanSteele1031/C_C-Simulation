#ifndef DISSIPATION_H
#define DISSIPATION_H

void setLevel(int* ground, int width, int selectedIndex, int level);
void dissipate(int* ground, int width, int sourceIndex);
void placeSource(int* ground, int width, int sourceIndex);
void showDissipationMap(int* ground, int width);

#endif