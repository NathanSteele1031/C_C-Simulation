#include "plants.h"
#include <iostream>

using namespace std;

const int MAX_ENERGY_LEVEL = 100; // Sugar and energy max is the same
const int SUGAR_TO_ENERGY_RATIO = 2;
const int SUN_TO_SUGAR_RATIO = 5;

void Plant::setEnergyLevel(int givenLevel){
    energy = givenLevel % (MAX_ENERGY_LEVEL + 1);
}

void Plant::changeEnergyLevel(int givenValue){
    energy += givenValue;
    energy = energy % (MAX_ENERGY_LEVEL + 1);
}

void Plant::setSugarLevel(int givenLevel){
    storedSugar = givenLevel % (MAX_ENERGY_LEVEL + 1);
}

void Plant::changeSugarLevel(int givenValue){
    storedSugar += givenValue;
    storedSugar = storedSugar % (MAX_ENERGY_LEVEL + 1);
}

void Plant::cellularRespiration(){
    if (storedSugar > 10){
        storedSugar -= 10;
        changeEnergyLevel(10 * SUGAR_TO_ENERGY_RATIO);
    }
}

void Plant::photosynthesis(int sunStrength){
    // The sun strength should be 0 - 10 for now.
    changeSugarLevel(sunStrength * SUN_TO_SUGAR_RATIO);

}

void Plant::showStats(){
    cout << "Energy Level: " << energy << " | Sugar Level: " << storedSugar << "\n";
}

void Plant::growNextStage(){
    if (giveSeedStage()){
        toggleSeedStage();
        toggleSproutStage();
    } else if (giveSproutStage()){
        toggleSproutStage();
        toggleAdultStage();
    }
}

void Plant::grow(){
    changeEnergyLevel(-10);
    changeSize(1);
}

void Plant::showDNA(){
    for (int i = 0; i<4; i++){
        cout << i << " : " << DNA[i] << " ";
    }
    cout << "\n";
}

void Plant::setDNA(char* givenDNA, int length){
    for (int i = 0; i<length; i++){
        DNA[i] = givenDNA[i];
    }
}

Plant::Plant(){
    setEnergyLevel(50);
    setSugarLevel(50);
    toggleSeedStage();
    setSize(5);
    // char createdDNA[4];
    // createdDNA[0] = 0;
    // createdDNA[1] = 1;
    // createdDNA[2] = 1;
    // createdDNA[3] = 0;
    // setDNA(createdDNA, 4);
}