#ifndef _TSP_CYCLE_HPP
#define _TSP_CYCLE_HPP

#include <iostream>

#include "listofpoints.hpp"

using namespace std;

// the class stores a cycle that traverses all points in some order
// it is used to store the solution to the problem
// it is a subclass of ListOfPoints

//class stores cycle traverses all points in some order

class TSPCycle : public ListOfPoints {

  public:
    TSPCycle()     {
      
    }

    // returns the length of the ListOfPoints
    float getLength() const {

      float totalDistance = 0;

      Node* tempDist = new Node;
      tempDist = head;

      while (tempDist->next!=NULL) {
        totalDistance = totalDistance + tempDist->point->getDistance(*tempDist->next->point);
        tempDist=tempDist->next;
      }
      //connect last 2 values
      totalDistance = totalDistance + head->point->getDistance(*tail->point);


      //cout << "total distance: " << totalDistance << endl;
      return totalDistance;
    }

};

#endif