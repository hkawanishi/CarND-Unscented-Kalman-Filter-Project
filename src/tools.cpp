#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {

  VectorXd rmse(4);
	rmse << 0,0,0,0;
	VectorXd diff;
  // check to make sure:
  // - the estimation vector size should not be zero
  // - the estimation vector size should equal to ground truth.
  if(estimations.size() != ground_truth.size() || estimations.size() == 0){
  	cout << "CalculateRMSE() Error - Check the estimation or ground truth data" << endl;
  	return rmse;
  }
  // calculate the squared residuals.
  for(unsigned int i=0; i < estimations.size(); ++i){
  	diff = estimations[i] - ground_truth[i];
  	//cout << "i is = " << i << " estimations = " << estimations[i] << "\n";
  	//cout << " ground truth = " << ground_truth[i] << "\n";
  	diff = diff.array()*diff.array();
  	rmse += diff;
  }
  // calculate the mean
  rmse = rmse/estimations.size();

  // calculate the squared root.
  rmse = rmse.array().sqrt();

  return rmse;
}