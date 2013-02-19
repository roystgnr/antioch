//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
// 
// Antioch - A Gas Dynamics Thermochemistry Library
//
// Copyright (C) 2013 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-
//
// $Id$
//
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

// valarray has to be declared before Antioch or gcc can't find the
// right versions of exp() and pow() to use??
#include <valarray>

#include "antioch/arrhenius_rate.h"

#include <cmath>
#include <limits>

template <typename Scalar, typename PairScalars>
int vectester(const PairScalars& example)
{
  const Scalar Cf = 1.4;
  const Scalar eta = 1.2;
  const Scalar Ea = 5.0;

  Antioch::ArrheniusRate<Scalar> arrhenius_rate(Cf,eta,Ea);

  // Construct from example to avoid resizing issues
  PairScalars T = example;
  T[0] = 1500.1;
  T[1] = 1600.1;
  
  const Scalar rate_exact0 = Cf*std::pow(1500.1,eta)*std::exp(-Ea/1500.1);
  const Scalar rate_exact1 = Cf*std::pow(1600.1,eta)*std::exp(-Ea/1600.1);

  int return_flag = 0;

  const PairScalars rate = arrhenius_rate(T);

  const Scalar tol = std::numeric_limits<Scalar>::epsilon()*10;

  if( std::fabs( (rate[0] - rate_exact0)/rate_exact0 ) > tol )
    {
      std::cout << "Error: Mismatch in rate values." << std::endl
		<< "rate(T0)   = " << rate[0] << std::endl
		<< "rate_exact = " << rate_exact0 << std::endl
		<< "difference = " << rate[0] - rate_exact0 << std::endl;

      return_flag = 1;
    }

  if( std::fabs( (rate[1] - rate_exact1)/rate_exact1 ) > tol )
    {
      std::cout << "Error: Mismatch in rate values." << std::endl
		<< "rate(T1)   = " << rate[1] << std::endl
		<< "rate_exact = " << rate_exact1 << std::endl
		<< "difference = " << rate[1] - rate_exact1 << std::endl;

      return_flag = 1;
    }

  std::cout << "Arrhenius rate: " << arrhenius_rate << std::endl;

  return return_flag;
}


int main()
{
  return (vectester<double, std::valarray<double> >
	    (std::valarray<double>(2)) ||
          vectester<long double, std::valarray<long double> >
	    (std::valarray<long double>(2)) ||
          vectester<float, std::valarray<float> >
	    (std::valarray<float>(2)));
}