# -*-  Mode: Python; -*-

import ns.core
import sys

cmd = ns.core.CommandLine()
cmd.Parse(sys.argv)

for i in range(cmd.GetNExtraNonOptions()):
    print(cmd.GetExtraNonOption(i))

ns.core.Simulator.Run()
ns.core.Simulator.Destroy()