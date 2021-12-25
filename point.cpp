#include "point.hpp"



float Point::getDistance(const Point &other) { 

    //horizontal case
    if (m_y == other.m_y) { 
      return(abs(m_x - other.m_x));
    }
    //vertical case
    else if (m_x==other.m_x) {
      return(abs(m_y - other.m_y));
    }
    //diag case
    else {
      return(sqrt( pow(abs(m_x - other.m_x), 2) + pow(abs(m_y - other.m_y), 2) ));
    }
  
  return 0;
}

string Point::toString() const{
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const{
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
