#include "dissipation.h"
#include <iostream>

using namespace std;

void showDissipationMap(int* ground, int width){
    for (int y = 0; y < width; y++){
        for (int x = 0; x < width; x++){
            cout << ground[x + (y * width)] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void setLevel(int* ground, int width, int selectedIndex, int level){
    if (selectedIndex < 0 || selectedIndex > width*width){
        return;
    }
    ground[selectedIndex] = level;
}

void dissipate(int* ground, int width, int sourceIndex){
    if (ground[sourceIndex] == 1){
        return;
    }
    if (sourceIndex - width >= 0 && !(ground[sourceIndex - width] >= ground[sourceIndex])){ // Up
        setLevel(ground, width, sourceIndex - width, ground[sourceIndex] - 1);
        dissipate(ground, width, sourceIndex - width);
        // cout << "Up";
    }if ((sourceIndex % width) + 1 < width && !(ground[sourceIndex + 1] >= ground[sourceIndex])){ // Right
        setLevel(ground, width, sourceIndex + 1, ground[sourceIndex] - 1);
        dissipate(ground, width, sourceIndex + 1);
        // cout << "Right";
    }if ((sourceIndex % width) - 1 >= 0 && !(ground[sourceIndex - 1] >= ground[sourceIndex])){ // Left
        setLevel(ground, width, sourceIndex - 1, ground[sourceIndex] - 1);
        dissipate(ground, width, sourceIndex - 1);
        // cout << "Left";
    }if (sourceIndex + width < width*width && !(ground[sourceIndex + width] >= ground[sourceIndex])){ // Down
        setLevel(ground, width, sourceIndex + width, ground[sourceIndex] - 1);
        dissipate(ground, width, sourceIndex + width);
        // cout << "Down";
    }
    return;
}

void placeSource(int* ground, int width, int sourceIndex){
    setLevel(ground, width, sourceIndex, 5);
    dissipate(ground, width, sourceIndex);
}