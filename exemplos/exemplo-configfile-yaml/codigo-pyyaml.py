# -*- Mode:Python; -*-

import ns.core
import yaml

def main():

    with open('./scratch/exemplo-configfile-yaml/entrada.yaml') as f:
        entrada = yaml.load(f, Loader=yaml.FullLoader)

    print(entrada)

    ns.core.Simulator.Run()
    ns.core.Simulator.Destroy()

if __name__ == "__main__":
    main()