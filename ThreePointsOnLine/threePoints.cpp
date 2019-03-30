#include "threePoints.hpp"


bool isOnLine(int pkt[NR_POINTS]){

  if(haveTheSameCoordinates(pkt)){
    return true;
  }

   

  int slope, b_coefficient;
  if( (pkt[X_2] - pkt[X_1]) == 0){
    return false;
  }else{
    slope = (pkt[Y_2] - pkt[Y_1])/(pkt[X_2] - pkt[X_1]);
    b_coefficient = pkt[Y_1] - pkt[X_1] * slope;
  }

  if(pkt[Y_3] == slope * pkt[X_3] + b_coefficient){
    return true;
  }else{
    return false;
  }
}


bool haveTheSameCoordinates(int* pkt){

   if( (pkt[X_3] == pkt[X_2]) && (pkt[X_3] == pkt[X_1]) && (pkt[X_2] == pkt[X_1]) ){
    return true;
  }

  
  if( (pkt[X_3] == pkt[X_2]) && (pkt[X_3] == pkt[X_1]) && (pkt[X_2] == pkt[X_1]) ){
    return true;
  }
  
	
	return false;
}
