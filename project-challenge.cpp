#include <iostream> 
#include <math.h> 
#include "wav.hpp" 
 
using namespace std; 
 
// model answer for generating single tone 
int main(){ 
    
   WavSound sound1; // helper 
   int sample_rate = 41400; // samples per second  
   int duration = 5;
   // your code... 
   int n_samples = duration * sample_rate;
   
   double f; 
   int nsf = 40000;
   cout << (double) sample_rate;
   double dt = 1.0 / (double) sample_rate;
   for (int i = 0 ; i<n_samples ; i++){ 
	  if ((int)(i/nsf) % 2 == 0){ 
		  f = 900;
		  }
	  else {
		  f = 1600;
		  }
      double time = i * dt;
      double a = 6000 * sin(2 * M_PI * f * time); 
      sound1.AddSample( a ); 
   } 
   sound1.MakeWavFromVector("sound1.wav",sample_rate); //file name can be changed but keep extension .wav 
   return 0; 
} 
