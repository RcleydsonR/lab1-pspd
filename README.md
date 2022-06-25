<h1>
    <div align="center">
        <b style="font-family: Arial;">
            <span style="color:#FFD54F">Laboratório 1 - RPC, Socket</span>
        </b>
    </div>
</h1>
    
## Principais Funcionalidades

    
## Visão Geral

<p align="justify"> &emsp;&emsp; O presente repositório tem como objetivo viabilizar a comunicação entre cliente e servidor através do protocolo tcp/ip utilizando abstrações da camada de rede como os sockets e/ou as chamadas de procedimento remoto (RPC).

## Guia de instalação
Para o pleno funcionamento de todas as funções é necessária a instalação dos requisitos abaixo.

Essa aplicação tem alguns ambientes configurado através de conteiners [Docker](https://www.docker.com), portanto, tem como pré-requisitos a instalação do [Docker](https://www.docker.com/get-started) e [Docker-compose](https://docs.docker.com/compose/install/). Para gerenciar os comandos, é necessario ter o [Make GNU](https://www.gnu.org/software/make/).

Também é necessário ter o [Git](https://git-scm.com) instalado para clonar o repositório.

### Back-end

Clonar o repositório:

* `git clone https://github.com/fga-eps-mds/2020.2-Anunbis.git`

Execução do conteiner:

* `docker-compose up`

Acesso  a aplicação:

* `localhost:5000`

Outros comandos:

* `make install` Instala as dependências da aplicação.
* `make up` Executa a aplicação.
* `make seed` Alimenta o banco de dados.
* `make down` Reseta a aplicação.
* `make test` Executa todos os testes.
* `make lint` Formata os arquivos Python para atender a [PEP8](https://www.python.org/dev/peps/pep-0008/).

## Equipe
<table>
    <tr>
     <!-- Eduardo   -->
        <td align="center"><a href="https://github.com/oEduardoAfonso"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/54921791?s=400&u=12d7cd0e0fdb7e4540dd786c4cc936167d8b7666&v=4" width="100px;" alt=""/><br /><sub><b>Eduardo Afonso</b></sub></a><br /></td>
     <!-- Rafael -->
        <td align="center"><a href="https://github.com/RcleydsonR">
        <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/74625814?s=460&u=c3b77eaa289d931e139e184d494e0151956372a8&v=4"width="100px;" alt=""/>
        <br /><sub><b>Rafael Cleydson</b><br></sub></a><br /></td>
    </table>
