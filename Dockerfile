FROM ubuntu:focal
COPY install-ns3-focal.sh $HOME/ns3/install-ns3-focal.sh

WORKDIR $HOME/ns3

RUN apt-get update && \
    apt-get install -y sudo && \
    ./install-ns3-focal.sh && \
    rm -rf /var/lib/apt/lists/*

WORKDIR $HOME/ns3/ns-allinone-3.35/ns-3.35

ENTRYPOINT ["/bin/bash", "-c"]
