/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini)
{
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
   k_p = Kpi;
   k_i = Kii;
   k_d = Kdi;
   out_max = output_lim_maxi;
   out_min = output_lim_mini;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
   derror = cte - error; 
   ierror += cte;
   error = cte;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = k_p * error + k_i * ierror + k_d * derror;
    control = control < out_min ? out_min : control;
    control = control > out_max ? out_max : control;

    return control;  
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   dt = new_delta_time;
}