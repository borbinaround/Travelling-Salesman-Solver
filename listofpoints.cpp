#include "listofpoints.hpp"


ListOfPoints::ListOfPoints() {
  head=NULL;
  tail=NULL;

}

void ListOfPoints::addPoint(Point &newPt)  {
    Point *copiedPt = new Point(newPt.getX(), newPt.getY(), newPt.getName());
    //*copiedPt.printPoint();
    Node* tmp = new Node;
    tmp->point = copiedPt;
    tmp->next=NULL;

    if (head==NULL) {
        head=tmp;
        tail=tmp;
    }
    else {
        tail->next=tmp;
        tail = tail->next;
    }

}

void ListOfPoints::printList() const {
  Node* n = new Node;
  n=head;
  while (n != NULL) {
      cout << n->point->getName() << " :" << n->point->getX() <<", " << n->point->getY() << endl;
      n = n->next;
  }
}

void ListOfPoints::draw() const {
  // implement me
  cout << "drawing the points..." << endl;
  vector<vector<string>> vect(21, vector<string>(21, "-"));

  Node* tmp = new Node;
  tmp = head;
  while (tmp!=NULL) {
      vect[20-tmp->point->getY()][tmp->point->getX()]=tmp->point->getName();
      tmp=tmp->next;
  }


  for (long unsigned int i = 0; i < vect.size(); i++)
  {
      for (long unsigned int j = 0; j < vect[i].size(); j++)
      {
          cout << vect[i][j] << " ";
      }   
      cout << endl;
  }
}

Node* ListOfPoints::getHead() {
  return(head);
}

Node* ListOfPoints::getTail() {
  return(tail);
}
 