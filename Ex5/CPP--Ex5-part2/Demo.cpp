/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main()
{
  OrgChart organization;  
  //"The Milky Way", "Earth", "Venus", "Mars", "Israel", "Meridiani Planum"
  organization.add_root("The Milky Way")
      .add_sub("The Milky Way", "Earth")    // Now the Earth is subordinate to the The Milky Way
      .add_sub("The Milky Way", "Venus")    // Now the Venus is subordinate to the The Milky Way
      .add_sub("The Milky Way", "Mars")    // Now the Mars is subordinate to the The Milky Way
      .add_sub("Earth", "Israel")  // Now the VP Software is subordinate to the Earth
      .add_sub("Mars", "Meridiani Planum") // Now the Meridiani Planum is subordinate to the Mars
      .add_sub("Israel", "Tel Aviv") // Now the Tel Aviv is subordinate to the Israel
      .add_sub("Israel", "Ariel"); // Now the Ariel is subordinate to the Israel
  cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
    └─>The Milky Way
    ├─>Earth
    │  └─>Israel
    │     ├─>Tel Aviv
    │     └─>Ariel
    ├─>Venus
    └─>Mars
       └─>Meridiani Planum
 */
  cout << endl;
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << (*it) << ", ";
  } // prints: The Milky Way, Earth, Venus, Mars, Israel, Meridiani Planum, Tel Aviv, Ariel,
  cout << endl << endl;
  for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
    cout << (*it) << ", ";
  } // prints: Tel Aviv, Ariel, Israel, Meridiani Planum, Earth, Venus, Mars, The Milky Way,
  cout << endl << endl;
  for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
  {
    cout << (*it) << ", ";
  } // prints: The Milky Way, Earth, Israel, Tel Aviv, Ariel, Venus, Mars, Meridiani Planum,
  cout << endl << endl;
  for (auto element : organization)
  { // this should work like level order
    cout << element << ", ";
  } // prints: The Milky Way, Earth, Venus, Mars, Israel, Meridiani Planum, Tel Aviv, Ariel,
  cout << endl << endl;
  // demonstrate the arrow operator:
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << it->size() << ", ";
  } // prints: 13, 5, 5, 4, 6, 16, 8, 5,
  cout << endl << endl;
}
