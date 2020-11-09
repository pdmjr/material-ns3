/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ns3/core-module.h"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("ExemploCommanLine");

int 
main (int argc, char *argv[])
{
  CommandLine cmd (__FILE__);
  cmd.Parse (argc, argv);

  for (std::size_t i = 0; i < cmd.GetNExtraNonOptions (); ++i)
  {
    std::cout << cmd.GetExtraNonOption (i) << std::endl;
  }
  
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
