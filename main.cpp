#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(3,4,"Q");
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;


}

// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();


  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

void test1() {
  Point p[4] = {Point(0,0,"A"),
                Point(20,20,"B"),
                Point(20,0,"C"),
                Point(0,20,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}



void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<5;i++) {
    p = Point(i,0,to_string(i));
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  

  inputTSP.draw();

  testSolver(inputTSP);
}


void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<100;i++) {
    p = Point(rand() % 1000, rand() % 1000,to_string(i));
    inputTSP.addPoint(p);
  }
  
  testSolver(inputTSP);
  
}



int main() {

  cout << "**** Test point **" << endl;
  testPoint();
  cout << "**** End of test point **" << endl << endl;

  cout << "**** test1 **:" << endl;
  test1();
  cout << "**** end of test1 **:" << endl << endl;

 //uncomment for more testing
  cout << "**** test2 **:" << endl;
  test2();
  cout << "**** end of test2 **:" << endl << endl;

 
  cout << "**** test3 **:" << endl;
  test3();
  cout << "**** end of test3 **:" << endl << endl;


  return 0;
}

/*
int main() {

  Point A( 9, 4, "A");
  Point B( 4, 5, "B");
  Point C( 10, 15, "C");
  Point D(2, 15, "D");


  ListOfPoints list;
  
  list.addPoint(A);
  list.addPoint(B);
  list.addPoint(C);
  list.addPoint(D);

  list.printList();

  TSPSolver solver(list);
  solver.solve();
  TSPCycle cycle = solver.getSolution();
  cycle.getLength();

  cycle.printList();



  return 0;
}
*/