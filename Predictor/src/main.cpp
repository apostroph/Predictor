/* 
 * Copyright (C): None
 * Authors: Jimmy Baraglia
 * Public License for more details
*/

#include <vector>
#include <cstdlib>
#include <iostream>

#include "Predictor.h"

int main(int argc, char * argv[]) {

    Predictor module(argc, argv); 
    srand(0);
    
    for(int training = 0; training < 5000; training++){
	  int randomNumber = rand()%30+1;
	  string src = "Data/cond1/c1_trial_" + to_string(randomNumber) + ".txt";
	  module.openFile(src, 1, 1);
	  if(training%50 == 0)
		cout<<training<<endl;
    }
    
    for(int training = 1; training <= 30; training++){
      string src = "Data/cond1/c1_trial_" + to_string(training) + ".txt";
      module.openFile(src, 1, 0);
      if(training%50 == 0)
	    cout<<training<<endl;
    }
    
    for(int training = 1; training <= 30; training++){
      string src = "Data/cond2/c2_trial_" + to_string(training) + ".txt";
      module.openFile(src, 1, 0);
      if(training%50 == 0)
	    cout<<training<<endl;
    }

    return 0;
}

