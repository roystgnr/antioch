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

// C++
#include <iostream>
#include <cmath>

// Antioch
#include "antioch/sutherland_viscosity.h"

int test_viscosity( const double mu, const double mu_exact, const double tol );

int main()
{
  const double mu_ref = 1.0e-3;
  const double T_ref = 300.0;

  Antioch::SutherlandViscosity<double> mu(mu_ref,T_ref);

  std::cout << mu << std::endl;

  const double T = 1521.2;

  // octave gives
  const double mu_exact = 0.0325778060534850;

  int return_flag = 0;

  const double tol = 1.0e-14;

  return_flag = test_viscosity( mu(T), mu_exact, tol );
  
  const double mu_ref2 = 3.14159e-3;
  const double T_ref2 = 420.42;

  mu.reset_coeffs(mu_ref2,T_ref2);

  // octave gives
  const double mu_exact2 = 0.0959985656417205;

  return_flag = test_viscosity( mu(T), mu_exact2, tol );

  return return_flag;
}

int test_viscosity( const double mu, const double mu_exact, const double tol )
{
  int return_flag = 0;

  const double rel_error = std::fabs( (mu - mu_exact)/mu_exact);

  if( rel_error  > tol )
    {
      std::cerr << "Error: Mismatch in viscosity" << std::endl
		<< "mu(T)    = " << mu << std::endl
		<< "mu_exact = " << mu_exact << std::endl
		<< "rel_error = " << rel_error << std::endl
		<< "tol = " << tol << std::endl;
      return_flag = 1;
    }

  return return_flag;
}