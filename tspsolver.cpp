#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) {
    m_list=list;

    m_solution = TSPCycle();
}

void TSPSolver::solve() {
  //start with the first element
  //connect second element to the first element, cycle = l[0] -> l[1]
  //compare distance between l[0] and l[1], 
  //if l[0] -> l[2] < l[0] -> l[1] ---> 
  //cycle = l[0] -> l[2] -> l[1]

  //store the correct order cycle in a vector
  //put in a linked list, 
  vector<string> vect;

  Node* temp = new Node;
  temp = m_list.getHead();

  //start with first element
  vect.push_back(temp->point->getName());

  //connect second element
  vect.push_back(temp->next->point->getName());



  //iterate through the list
  //iterator tempY starts at 3rd element
  Node* tempY = new Node;
  tempY = m_list.getHead()->next->next;

  //inner iterator tempX to compare with tempY
  Node* tempX = new Node;
  tempX = m_list.getHead();

  //temp 2 = C
  while (tempY!=m_list.getTail()->next) {
    //iterate from head to tempY, current index

    Node* smallestValue = new Node;
    //temp 3 = head
    smallestValue = tempX;

    //while temp 3->next != tempY
    while (tempX->next !=tempY) {
      
      //check if current distance between tempY and tempX is greater than the next element's
      //cout << tempY->point->getDistance(*tempX->point) << " greater than? " << tempY->point->getDistance(*tempX->next->point) << endl;
      if (tempY->point->getDistance(*tempX->point) > tempY->point->getDistance(*tempX->next->point)) {
        //if the next distance is smaller, smallest value is now the next value
        smallestValue = tempX->next;
        //cout << "smallest distance is now " << smallestValue->point->getName()<<endl;
      }
      else {
      }
      //check next value
      tempX = tempX->next;
    }
    //
    //smallest value is now the smallest value comparing current tempY and tempX.
    //tempX->next = temp 2
    //cout << "smallest distance is currently " << smallestValue->point->getName()<<endl;
  //find position inside vect of the name

  
  //cout << endl;
  auto it = find(vect.begin(), vect.end(), smallestValue->point->getName());

  int index = 0;

  //find vector index of tempY
  if (it != vect.end()) {
    index = it - vect.begin();
  }
  //cout << "index is: " << index << endl;


  vect.insert(vect.begin() + index + 1, tempY->point->getName());
    
  tempY=tempY->next;

  }



  Node* outerLoop = new Node;


  outerLoop = m_list.getHead();



  
  //convert vector list into the m_solution list
  for (string i: vect) {

    while (outerLoop != NULL) {
      if (outerLoop->point->getName()==i) {
        m_solution.addPoint(*outerLoop->point);
      }
      outerLoop = outerLoop->next;
    }
    outerLoop = m_list.getHead();

  }


/*
  for (string i: vect) {
    Node* tmp = new Node;
    tmp = m_list.getHead();
    while (tmp!=m_list.getTail()->next) {
      if 
    }
    m_solution.addPoint()
}
*/

}





TSPCycle& TSPSolver::getSolution() {
  // implement me

  // currently returns an empty cycle
  return m_solution;
}

