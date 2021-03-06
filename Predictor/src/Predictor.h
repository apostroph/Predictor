/* 
 * Copyright (C): None
 * Authors: Jimmy Baraglia
 * Public License for more details
*/

#ifndef _Predictor_H_
#define _Predictor_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>

#include <list>
#include <math.h> //isnan

#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

class Predictor {

public:
    /** 
     * document your methods too.
     */
    Predictor(int argc, char * argv[]);
    ~Predictor();
    
    void openFile(string src, int iter, bool test_train);

    bool close();         
    
private:
  string moduleName;
  
  int maxTests;// = 10000;
  int maxSamples;// = 4;

  int inputNeurons;// = 6;
  int hiddenNeurons;// = 3;
  int outputNeurons;// = 6;
  int contextNeurons;// = 3;

  double learnRate;// = 0.2;    //Rho.
  int trainingReps;// = 2000;
  double maxError;
  bool FILE;
  
  long long iterations;
  long long testIter;
  
  VectorXd beVector;//[inputNeurons] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};

                                     //  0    1    2    3    4    5
  MatrixXd sampleInput;//[3][inputNeurons] = {{0.0, 0.0, 0.0, 1.0, 0.0, 0.0},
					//{0.0, 0.0, 0.0, 0.0, 0.0, 1.0},
					//{0.0, 0.0, 1.0, 0.0, 0.0, 0.0}};
  
  VectorXd nextInput;
  VectorXd nextTarget;

  //Input to Hidden weights (with biases).
  MatrixXd wih;//[inputNeurons + 1][hiddenNeurons];

  //Context to Hidden weights (with biases).
  MatrixXd wch;//[contextNeurons + 1][hiddenNeurons];

  //Hidden to Output weights (with biases).
  MatrixXd who;//[hiddenNeurons + 1][outputNeurons];

  //Hidden to Context weights (no biases).
  MatrixXd whc;//[hiddenNeurons + 1][contextNeurons];
  
    //Activations.
  VectorXd inputs;//[inputNeurons];
  VectorXd hidden;//[hiddenNeurons];
  VectorXd target;//[outputNeurons];
  VectorXd actual;//[outputNeurons];
  VectorXd context;//[contextNeurons];

  //Unit errors.
  VectorXd erro;//[outputNeurons];
  VectorXd errh;//[hiddenNeurons];
  
  void ElmanNetwork();
  void testNetwork();
  void feedForward();
  void backPropagate();
  void assignRandomWeights();
  void resetNodes();
  void measurePE();
  
  double string_to_double(const std::string& s);
  
  //Data generation
  ofstream *EmO, *inO, *outO;
  void mapInput(double value, int index, int setTarget = -1);
  long long fileCounter;
  double averageError;
  std::list<double> Em;
  
  //Math function
  int getRandomNumber();
  double sigmoid(double val);
  double sigmoidDerivative(double val);
  double gaussian(double in, double mean, double variance);
  
};


#endif // __Recognition_H__

//----- end-of-file --- ( next line intentionally left blank ) ------------------

