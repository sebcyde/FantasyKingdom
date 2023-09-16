#ifndef KINGDOM_H
#define KINGDOM_H

#include <vector>
#include <string>

// Forward declaration of other classes (if needed)
class FoodResource;
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

  // Kingdom management functions
  void buildBuilding(Building *building);
  void buildFactory(Factory *factory);
  void gatherResource(Resource *resource);
  void upgradeBuilding(Building *building);

  // Other member functions as needed
  void subtractGold(int amount)
  {
    gold -= amount;
  }

private:
  std::vector<Building *> buildings;
  std::string name;
  int foodresource;
  int population;
  int gold;

  // Private helper functions (if needed)
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