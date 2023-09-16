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
  // Constructor =
  inline Factory::Factory(int type) : type(type), level(1), active(true){};

  // Destructor
  inline Factory::~Factory(){};

  // Accessors
  int getType();
  int getLevel();
  bool isActive();

  // Factory management functions
  void generateResources(Kingdom &kingdom);
  void maintainFactory(Kingdom &kingdom);
  void upgradeFactory(Kingdom &kingdom);
  void changeActiveStatus(bool newStatus);

private:
  // Factory Status
  bool isActive;
  int level;
  int type;

  // Factory Status checkers
  inline int Factory::getType()
  {
    return Factory::type;
  };

  inline int Factory::getLevel()
  {
    return Factory::level;
  };

  inline bool Factory::isActive()
  {
    return Factory::isActive;
  }

  // Factory Status Changers
  void Factory::changeActiveStatus(bool newStatus)
  {
    Factory::isActive = newStatus;
  }

  // Factory Resource Generation
  int Factory::getResourceGenerationRate() const
  {
    // Define base generation rates for each factory type
    int baseTextileGenerationRate = 5;
    int baseFoodGenerationRate = 7;

    // Determine the base generation rate based on factory type
    int baseGenerationRate = (getType() == 1) ? baseTextileGenerationRate : baseFoodGenerationRate;

    // Define a multiplier for each factory type (1.0 for textiles, 1.2 for food)
    double multiplier = (getType() == 1) ? 1.0 : 1.2;

    // Calculate the resource generation rate based on the formula
    int generationRate = static_cast<int>(baseGenerationRate * multiplier * getLevel());

    return generationRate;
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
    }
  }

  // Factory Upgrades
  int calculateUpgradeCost() const
  {
    // Define base upgrade cost for each factory type
    int baseUpgradeCost = 100;

    // Define a multiplier for each factory type (1.0 for textiles, 1.2 for food)
    double multiplier = (getType() == 1) ? 1.0 : 1.2;

    // Calculate the upgrade cost based on the formula
    int upgradeCost = static_cast<int>(baseUpgradeCost * multiplier * getLevel());

    return upgradeCost;
  }

  void Factory::upgradeFactory(Kingdom &kingdom)
  {
    if (isActive())
    {
      int upgradeCost = calculateUpgradeCost();

      // Check if kingdom has enough gold for the upgrade
      if (kingdom.getGold() >= upgradeCost)
      {
        // Deduct the upgrade cost from the kingdom's gold
        kingdom.subtractGold(upgradeCost);

        // Increase the factory level
        upgradeFactory();
      }
      else
      {
        std::cout << "Not enough gold to upgrade";
      }
    }
  }

  // Factory Maintenace
  int Factory::calculateMaintenanceCost() const
  {
    // Define base maintenance costs for each factory type
    int baseTextileMaintenanceCost = 50;
    int baseFoodMaintenanceCost = 60; // Adjust this value as needed

    // Determine the base maintenance cost based on factory type
    int baseMaintenanceCost = (getType() == 1) ? baseTextileMaintenanceCost : baseFoodMaintenanceCost;

    // Define a multiplier for each factory type (1.0 for textiles, 1.2 for food)
    double multiplier = (getType() == 1) ? 1.0 : 1.2;

    // Calculate the maintenance cost based on the formula
    int maintenanceCost = static_cast<int>(baseMaintenanceCost * multiplier * getLevel());

    return maintenanceCost;
  }

  void Factory::maintainFactory(Kingdom &kingdom)
  {
    if (isActive())
    {
      int maintenanceCost = calculateMaintenanceCost();

      // Check if kingdom has enough gold for maintenance
      if (kingdom.getGold() >= maintenanceCost)
      {
        // Deduct the maintenance cost from the kingdom's gold
        kingdom.subtractGold(maintenanceCost);
      }
      else
      {
        std::cout << "Not enough gold to maintain the factory!";
        Factory::
      }
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
// 1 - textiles;
// 2 - food;