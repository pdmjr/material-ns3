/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2013 Lawrence Livermore National Laboratory
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Peter D. Barnes, Jr. <pdbarnes@llnl.gov>
 */

#include <iostream>
#include <iomanip>
#include <string>

#include "ns3/core-module.h"

using namespace ns3;

int main (int argc, char *argv[])
{

  int         intArg  = 1;
  bool        boolArg = false;
  std::string strArg  = "strArg inicial";

  const int intDef = intArg;
  const bool boolDef = boolArg;
  const std::string strDef = strArg;

  CommandLine cmd (__FILE__);
  cmd.Usage ("Programa exemplo da classe CommandLine.\n"
             "\n"
             "Este pequeno programa ilustra como utilizar CommandLine.");
  cmd.AddValue ("intArg",  "um argumento inteiro", intArg);
  cmd.AddValue ("boolArg", "um argumento booleano", boolArg);
  cmd.AddValue ("strArg",  "um argumento tipo string", strArg);
  cmd.Parse (argc, argv);

  // Show initial values:
  std::cout << std::endl;
  std::cout << "Nome do programa: " <<  cmd.GetName () << std::endl;

  //Print the source version used to build this example
  // std::cout << "Versao do programa: ";
  // cmd.PrintVersion (std::cout);
  // std::cout << std::endl;

  std::cout << "Valores iniciais:" << std::endl;

  std::cout << std::left << std::setw (10) << "intArg:" << intDef << std::endl;
  std::cout << std::setw (10) << "boolArg:" << std::boolalpha << boolDef   << std::noboolalpha << std::endl;
  std::cout << std::setw (10) << "strArg:" << "\"" << strDef << "\"" << std::endl;
  std::cout << std::endl;

  // Show final values
  std::cout << "Valores finais:" << std::endl;
  std::cout << std::left << std::setw (10) << "intArg:" << intArg << std::endl;
  std::cout << std::setw (10) << "boolArg:" << std::boolalpha << boolArg   << std::noboolalpha << std::endl;
  std::cout << std::setw (10) << "strArg:" << "\"" << strArg << "\"" << std::endl;

  std::cout << std::left << "Numero de argumentos extra: " << cmd.GetNExtraNonOptions () << std::endl;

  for (std::size_t i = 0; i < cmd.GetNExtraNonOptions (); ++i)
    {
      std::cout << std::left << std::setw (10) << "Arg. extra: " << "\"" << cmd.GetExtraNonOption (i) << "\"" << std::endl;
    }


  return 0;
}
