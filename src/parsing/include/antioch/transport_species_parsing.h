//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// Antioch - A Gas Dynamics Thermochemistry Library
//
// Copyright (C) 2014 Paul T. Bauman, Benjamin S. Kirk, Sylvain Plessis,
//                    Roy H. Stonger
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

#ifndef ANTIOCH_TRANSPORT_SPECIES_PARSING_H
#define ANTIOCH_TRANSPORT_SPECIES_PARSING_H

// Antioch
#include "antioch/ascii_parser.h"
#include "antioch/chemkin_parser.h"
#include "antioch/xml_parser.h"

//C++
#include <iostream>
#include <string>
#include <fstream>


namespace Antioch
{
  //Forward declaration
  template <typename NumericType>
  class ParserBase;

  template <typename NumericType>
  class TransportMixture;

  template <typename NumericType>
  void read_transport_species_data(ParserBase<NumericType> * parser,
                                   TransportMixture<NumericType> & transport);

} //end namespace Antioch

#endif // ANTIOCH_TRANSPORT_SPECIES_PARSING_H
