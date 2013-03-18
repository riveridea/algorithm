//----------------------------------------------------------------------
//
// FILE NAME:   rstream.h
//
// AUTHORS:     Violet Syrotiuk, Stefano Basagni
//
// CREATED:     February 1999
//
// DESCRIPTION: This file contains the class definition for a random
//              stream.
//
//----------------------------------------------------------------------

#ifndef RSTREAM_H
#define RSTREAM_H

class Rstream{
 public:


	   Rstream( unsigned long int );
	   unsigned long int get_xi() const { return xi; };
	   double uniform01();
	   double uniform( double, double );
	   double poisson( float );
	   unsigned long int uniform_discrete( unsigned long int,
					       unsigned long int );
 private:

   // Value of the last number generated according to the linear
   // congruential generator theory
   unsigned long int xi; 
   float lngamma ( float ) const;

};

#endif


