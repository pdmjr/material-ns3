# NS-3 sobre o Ubuntu Focal

Este contêiner implanta o ambiente de desenvolvimento do NS-3 versão 3.32 sobre o Ubuntu 20.04.

O projeto original foi retirado do repositório [ns3-focal](https://github.com/Luxxii/ns3-focal).

## Instalação

Assumindo que o ambiente Docker e o Git estão instalados, utilizar os seguintes comandos para configuração (atenção, esse procedimento pode levar um tempo considerável para finaliar):
> `git clone https://github.com/pdmjr/material-ns3.git`
> `cd material-ns3; chmod +x install-ns3-focal.sh`
> `docker build .`

Após instalação, verificar o ID da imagem criada a partir do comando:
> `docker image ls`

Para "taguear" a imagem com um nome mais representativo (ex: ns3-focal):
> `docker image tag "IMAGE_ID" ns3-focal`

## Uso

Pode ser utilizado da seguinte maneira:
> `docker run "NS3_IMAGE" "./waf --run hello-simulator"`

Debugging também é possível:
> `docker run -it "NS3_IMAGE" "./waf --run=hello-simulator --command-template=\"gdb %s --args <args> \""`

Pode-se disponibilizar o seu próprio código fonte (ex: my_source_code.cc) das simulações através de um volume local com `-v`:
> `docker run --rm -v /home/user/project/mycode/:/ns3/ns-allinone-3.31/ns-3.31/scratch "NS3_IMAGE" "./waf --run scratch/my_source_code"`

## Dicas

Para navegar nos arquivos da imagem:
> `docker run -it "NS3_IMAGE" /bin/bash`

Lembre-se que o script que queremos executar deve estar na pasta `scratch`.

`NS3_IMAGE` se refere que você deve substituir pelo nome da imagem em si.
