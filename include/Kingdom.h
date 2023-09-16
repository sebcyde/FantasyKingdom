#ifndef KINGDOM_H
#define KINGDOM_H

#include <vector>
#include <string>

// Importing other classes
class Building;
class Factory;

class Kingdom
{
public:
  // Constructor
  Kingdom(const std::string &name);

  // Destructor
  ~Kingdom();

  // Accessors
  const std::string &getName() const;
  int getHappiness() const;
  int getGold() const;

  // Resource management functions
  void minusTextilesResources(int amount);
  void addTextilesResources(int amount);
  void minusFoodResources(int amount);
  void addFoodResources(int amount);

  // Upgrade related functions
  void buildBuilding(int type);
  void buildFactory(int type);

  // Other member functions
  void subtractGold(int amount);
  void addGold(int amount);

private:
  // Kingdom Status
  std::vector<Building *> buildings;
  std::vector<Factory *> factories;

  std::string name;
  int foodResource;
  int textileResource;
  int population;
  int happiness;
  int gold;

  // Private helper functions (if needed)

  // Kingdom Status checkers
  std::string Kingdom::getName() const
  {
    return Kingdom::&name;
  };

  int Kingdom::getGold() const
  {
    return Kingdom::gold;
  };

  int Kingdom::getHappiness() const
  {
    return Kingdom::happiness;
  };

  int Kingdom::getPopulation() const
  {
    return Kingdom::population;
  }

  int Kingdom::getFoodResource() const
  {
    return Kingdom::foodResource;
  }

  int Kingdom::getTextileResource() const
  {
    return Kingdom::textileResource;
  }

  // Kingdom Status Changers
  void Kingdom::subtractGold(int amount)
  {
    Kingdom::gold -= amount;
  }

  void Kingdom::addGold(int amount)
  {
    Kingdom::gold += amount;
  }

  void Kingdom::addFoodResources(int amount)
  {
    Kingdom::foodResource += amount;
  }

  void Kingdom::addTextilesResources(int amount)
  {
    Kingdom::textileResource += amount;
  }

  void Kingdom::minusFoodResources(int amount)
  {
    Kingdom::foodResource -= amount;
  }

  void Kingdom::minusTextilesResources(int amount)
  {
    Kingdom::textileResource -= amount;
  }

  // Kingdom Upgrades
  void Kingdom::buildFactory(int type)
  {
    Factory newFactory(type);
    Kingdom::factories.push_back(newFactory);
  }

  void Kingdom::buildBuilding(int type)
  {
    Building newBuilding(type);
    Kingdom::buildings.push_back(newBuilding);
  };
};

#endif // KINGDOM_H

// addTextilesResources
// addFoodResources

// Kingdom {
//   - has happiness levels of population that can lead to revolt if low,
//   - has gold that can lead to surprise events if high (robberies) or low (crime)
//   - buildings, increase happiness
//   - factories, increase potential resources
// }