#ifndef PLANTS_H
#define PLANTS_H

class Plant{
    private:
    int energy;
    int storedSugar;
    void setEnergyLevel(int givenLevel);
    void changeEnergyLevel(int givenValue);
    void changeSugarLevel(int givenValue);
    void setSugarLevel(int givenLevel);

    /*DNA LAYOUT
    0 - Grow when dark
    1 - Grow when Light
    2 - Photosynthesis when light
    3 - Photosynthesis when dark
    */
    int DNA[4];
    void setDNA(char* givenDNA, int length);
    int size;
    void setSize(int givenValue){size = givenValue;};
    void changeSize(int givenValue){size += givenValue;};
    void grow();

    int seedStage;
    int sproutStage;
    int adultStage;
    void toggleSeedStage(){seedStage = !seedStage;};
    void toggleSproutStage(){sproutStage = !sproutStage;};
    void toggleAdultStage(){adultStage = !adultStage;};
    void growNextStage();

    public:
    Plant();
    void cellularRespiration(); // Converts sugar to energy.
    void photosynthesis(int sunStrength);
    void showStats();
    int giveSeedStage(){return seedStage;};
    int giveSproutStage(){return sproutStage;};
    int giveAdultStage(){return adultStage;};

    void showDNA();
};

#endif