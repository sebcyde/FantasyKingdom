#ifndef FACTORY_H
#define FACTORY_H

#include "Kingdom.h"
#include <string>
#include <vector>

// Forward declaration of other classes (if needed)
class Resource;
class Kingdom;

class Factory
{
public:
  // Constructor
  Factory(const std::string &name, int type);

  // Destructor
  ~Factory();

  // Accessors
  const std::string &getName() const;
  int getType() const;
  int getLevel() const;
  bool isActive() const;

  // Factory management functions
  void generateResources(Kingdom &kingdom);
  void upgradeFactory();

private:
  std::string name;
  bool active;
  int level;
  int type;

  // Define resource generation rates for each factory type (you can use constants)
  static const int TEXTILES_GENERATION_RATE = 5;
  static const int FOOD_GENERATION_RATE = 10;

  // Resource generation functions for different factory types
  void generateTextilesResources(Kingdom &kingdom);
  void generateFoodResources(Kingdom &kingdom);

  int Factory::getResourceGenerationRate() const
  {
    // Define resource generation rates for different factory types
    switch (getType())
    {
    case 1: // Textiles factory
      return TEXTILES_GENERATION_RATE;
    case 2: // Food factory
      return FOOD_GENERATION_RATE;
    // Add cases for other factory types as needed
    default:
      return 0; // Default case (no resource generation)
    }
  }

  void Factory::generateResources(Kingdom &kingdom)
  {
    if (isActive())
    {
      int generationRate = getResourceGenerationRate();
      int generatedResources = generationRate * getLevel();

      // Update the kingdom's resources based on the factory's type
      if (getType() == 1)
      { // For example, 1 represents textiles factory
        kingdom.addTextilesResources(generatedResources);
      }
      else if (getType() == 2)
      { // 2 represents food factory
        kingdom.addFoodResources(generatedResources);
      }

      // You can also apply other effects to the kingdom here, like increasing happiness or health.
    }
  }

  static const int TEXTILES_UPGRADE_ONE_COST = 50;
  static const int TEXTILES_UPGRADE_TWO_COST = 150;
  static const int TEXTILES_UPGRADE_THREE_COST = 450;

  static const int FOOD_UPGRADE_ONE_COST = 100;
  static const int FOOD_UPGRADE_TWO_COST = 200;
  static const int FOOD_UPGRADE_THREE_COST = 500;

  void Factory::upgradeFactory(Kingdom &kingdom)
  {
    if (isActive())
    {
      int upgradeCost = 0; // Initialize the upgrade cost variable

      // Calculate the upgrade cost based on factory type and level
      if (getType() == 1)
      {
        // Textiles factory upgrade cost calculation
        if (getLevel() == 1)
          upgradeCost = TEXTILES_UPGRADE_ONE_COST;
        else if (getLevel() == 2)
          upgradeCost = TEXTILES_UPGRADE_TWO_COST;
        else if (getLevel() == 3)
          upgradeCost = TEXTILES_UPGRADE_THREE_COST;
      }
      else if (getType() == 2)
      {
        // Food factory upgrade cost calculation
        if (getLevel() == 1)
          upgradeCost = FOOD_UPGRADE_ONE_COST;
        else if (getLevel() == 2)
          upgradeCost = FOOD_UPGRADE_TWO_COST;
        else if (getLevel() == 3)
          upgradeCost = FOOD_UPGRADE_THREE_COST;
      }

      // Check if kingdom has enough gold for the upgrade
      if (kingdom.getGold() >= upgradeCost)
      {
        // Deduct the upgrade cost from the kingdom's gold
        kingdom.subtractGold(upgradeCost);

        // Increase the factory level
        upgradeFactory();
      }
    }
  }

#endif // FACTORY_H

  // Factory

  //   - has a type, will determine what kind of resources it generates
  //   - can be inactive (due to surprise events like strikes/revolts from low Kingdom happiness)
  //   - can be upgraded to produce more resources per turn
  //
  // Factory Types:
  // 1 - textiles
  // 2 - food
  // 3 - ...