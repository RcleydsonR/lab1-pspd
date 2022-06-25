<h1>
    <div align="center">
        <b style="font-family: Arial;">
            <span style="color:#FFD54F">Laboratório 1 - RPC, Socket</span>
        </b>
    </div>
</h1>

# Visão Geral

<p align="justify"> &emsp;&emsp; O presente repositório tem como objetivo viabilizar a comunicação entre cliente e servidor através do protocolo tcp/ip utilizando abstrações da camada de rede como os sockets e/ou as chamadas de procedimento remoto (RPC).

# Guia de instalação
Para o pleno funcionamento de todas as funções é necessária a instalação dos requisitos abaixo.

Essa aplicação tem alguns ambientes configurado através de conteiners [Docker](https://www.docker.com), portanto, tem como pré-requisitos a instalação do [Docker](https://www.docker.com/get-started) e [Docker-compose](https://docs.docker.com/compose/install/). Para gerenciar os comandos, é necessario ter o [Make GNU](https://www.gnu.org/software/make/).

Também é necessário ter o [Git](https://git-scm.com) instalado para clonar o repositório utilizando o comando:

```bash
git clone https://github.com/RcleydsonR/lab1-pspd
```

# Apenas um worker
## Socket
1. Acessar a pasta:

    ```bash
    cd entrega1/socket
    ```

2. Execute o servidor:

    ```bash
    ./tcpServ 127.0.0.1 <porta>
    ```

3. Execute o servidor:

    ```bash
    ./tcpCli 127.0.0.1 <porta>
    ```

4. Repetir a operação:

    ```bash
    S
    ```

## RPC

1. Acessar a pasta:

    ```bash
    cd entrega1/rpc
    ```

2. Execute o comando:

    ```bash
    make
    ```

3. Execute o servidor:

    ```bash
    ./lab1_server
    ```

4. Execute o servidor:

    ```bash
    ./lab1_client 127.0.0.1
    ```

5. Repetir a operação:

    ```bash
    S
    ```

# Múltiplos worker

1. Acessar a pasta:

    ```bash
    cd entrega2
    ```

2. Execute o comando:

    ```bash
    make
    ```

3. Execute o comando:

    ```bash
    docker-compose -p teste up --build
    ```

4. Execute o comando:

    ```bash
    docker inspect -f '{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' teste_rpcdocker_1
    ```

5. Copie o IP informado

6. Crie quantos containers achar necessário

7. Execute o servidor:

    ```bash
    ./lab1_server
    ```

8. Execute o cliente:

    ```bash
    ./lab1_client <qtd de servidore> <ip server 1> <ip server 2> ... <ip server n>
    ```

9. Repetir a operação:

    ```bash
    S
    ```

# Equipe
<table>
     <!-- Eduardo   -->
        <td align="center"><a href="https://github.com/oEduardoAfonso"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/54921791?s=400&u=12d7cd0e0fdb7e4540dd786c4cc936167d8b7666&v=4" width="100px;" alt=""/><br /><sub><b>Eduardo Afonso</b></sub></a><br /></td>
     <!-- Rafael -->
        <td align="center"><a href="https://github.com/RcleydsonR">
        <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/74625814?s=460&u=c3b77eaa289d931e139e184d494e0151956372a8&v=4"width="100px;" alt=""/>
        <br /><sub><b>Rafael Cleydson</b><br></sub></a><br /></td>
    </table>
