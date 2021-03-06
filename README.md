# FT_IRC
      
## Sommaire
- [Introduction](#Introduction)
- [Notions de bases](#Notions-de-bases)
    - [serveur IRC](#+-SERVEUR-IRC)
    - [client IRC](#CLIENT-IRC)
    - [procole TCP/IP](#PROTOCOLE-TCP/IP)
    - [sockets](#SOCKETS)
- [Plan du projet](#Plan-du-projet)
    - [Creation du serveur](#Creation-du-serveur)
    - [ Implementation des commandes](#Implementation-des-commandes)
- [Notes](#Notes)
- [Ressources](#Ressources)
       
## Introduction
      
>On va creer notre propre serveur irc (Internet Relay Chat) en suivant le [protocole irc](https://datatracker.ietf.org/doc/html/rfc2812). 
>Ce protocole sera implemente grace a un systeme utilisant le protocole TCP/IP. 
       
## Notions de bases
+ SERVEUR IRC
     - Concretement, un serveur IRC est un systeme de communication textuel via le reseau. Utilisant le modele serveur-client, ce protocole permet de l'adapter a de nombreuses plateformes comme messenger, twitter ou ~~MSN~~. 
     - Le serveur c'est le point central du systeme IRC, il fournit un point auquel les clients peuvent se connecter pour parler et permettre la connexion entre serveurs (partie qu'on ne doit pas implementer dans notre ft_irc)
     
+ CLIENT IRC
    - Un client IRC est tout simplement un element qui se connecte au serveur IRC qui n'est pas un serveur. TADAM :tada: 
    - Les clients se distinguent entre eux grace a un surnom qu'il est d'usage d'entrer des son entree dans le serveur ainsi que son username.  

+ PROTOCOLE TCP/IP
    - Le protocole TCP/IP (Transmission Control Protocol) permet de gérer les données en provenance (ou à destination) de la couche inférieure du modèle (c'est-à-dire le protocole IP). TCP est un protocole orienté connexion, c'est-à-dire qu'il permet à deux machines qui communiquent de contrôler l'état de la transmission.
    - Lors d'une communication à travers ce protocole, les deux machines doivent établir une connexion. La machine émettrice est appelée client, tandis que la machine réceptrice est appelée serveur. On dit qu'on est alors dans un environnement Client-Serveur.
    - Le protocole TCP/IP et le protocole IRC sont indissociables. Notre cher [arthur](https://github.com/arthur-trt) vous propose donc une comparaison plutot parlante : 
                → le protocole TCP est a considere comme la maniere de communiquer (ex: une lettre) tandis que le protocole IRC est la maniere de transmettre l'information (ex: dans la langue francaise). On ne peut donc pas obtenir tous les resultats attendus si on utilise pas les deux outils ensembles. 
    - Concretement, on va pas reimplementer le protocole TCP mais simplement l'utiliser. 

+ SOCKETS 
    -  Il s'agit d'un modele permettant la communication notamment a travers un réseau TCP/IP.
    -   Une fois qu'une connexion est établie, un fichier socket est utilisé pour identifier de façon unique la connexion.
    -   Une nouvelle petite analogie pour comprendre l'interet des sockets → la communication par sockets est souvent comparee aux communications humaines. On en distingue 2 types :
        * le mode connecte (ex : communication telephonique) utilisant le protocole TCP. La connexion durable etablie entre les deux processus permet de ne pas necessairement avoir besoin de l'adresse de destination a chaque envoi de donnees.
        * le mode non connecte (ex: communication par courrier) utilisant le protocole UDP. Ce dernier necessite l'adresse de destination a chaque envoi et il n'y a pas d'accuse de reception de celle ci. 

<p align="center"><img src="medias/schema.png"/></p>

+ FONCTIONS

| Fonctions                      | Description                                                            | 
| -------------------------------|------------------------------------------------------------------------|
 **socket()**                    | cree un endpoint pour la communication et return un descriptor.        | 
 **setsockopt()**                | manipulent les options pour la socket.                                 |
 **getsockname()**               |  renvoie l'adresse actuelle a laquelle la socket est lie.              |
 **getprotobyname()**            | lit l'entree suivante depuis la base de donnees du protocole.          |
 **gethostbyname()**             |  obsolete                                                              |
 **getaddrinfo()**               | retourne une ou plus de structures dans laquelle contient l'adresse internet avec laquelle on peut utiliser bind ou connect. |
 **freeaddrinfo()**              |  free the memory                                                       |
 **bind()**                      | pour donner un nom assigne a la creation d'une socket, affecte l'adresse spécifiée dans addr à la socket référencée par le descripteur de fichier sockfd. Traditionnellement cette opération est appelée « affectation d'un nom à une socket ».|
 **connect()**                   | connecte la socket referencee par le descriptor sockfd indiquee par serv_addr.  |
 **listen()**                    |  marque la socket referencee par sockfd comme une socket passive, c'est-a-dire comme une socket qui sera utilisee pour accepter les demandes de connexions entrantes en utilisant accept. |
 **accept()**                    | utilise avec les sockets utilisant un protocole en mode connecte; extrait la première connexion de la file des connexions en attente de la socket sockfd à l'écoute, crée une nouvelle socket connectée, et renvoie un nouveau descripteur de fichier qui fait référence à cette socket. La nouvelle socket n'est pas en état d'écoute. La socket originale sockfd n'est pas modifiée par l'appel système. |
 **htons()**                     |  convertit un entier court non signé hostshort depuis l'ordre des octets de l'hôte vers celui du réseau. |
 **htonl()**                     | convertit un entier non signé hostlong depuis l'ordre des octets de l'hôte vers celui du réseau.    |  
 **ntohs()**                     | convertit un entier court non signé netshort depuis l'ordre des octets du réseau vers celui de l'hôte. |
 **ntohl()**                     | convertit un entier non signé netlong depuis l'ordre des octets du réseau vers celui de l'hôte. |
 **inet_addr()**                 | convertit l'adresse Internet de l'hôte cp depuis la notation IPv4 décimale pointée vers une forme binaire (dans l'ordre d'octet du réseau), et la stocke dans la structure pointée par inp. inet_aton() renvoie une valeur non nulle si l'adresse est valide, et zéro sinon. |
 **inet_ntoa()**                 | convertit l'adresse Internet de l'hôte in donne dans l'ordre des octets du réseau en une chaîne de caractères dans la notation numérique pointée. La chaîne est renvoyée dans un tampon alloué statiquement, qui est donc écrasé à chaque appel. |       
 **send()**                      | permet de transmettre un message à destination d'une autre socket.     |
 **recv()**                      |  utilisé pour recevoir des messages depuis une socket.                |
 **signal()**                    | installe le gestionnaire handler pour le signal signum.               |
 **lseek()**                     | place la tête de lecture/écriture à la position offset dans le fichier ouvert associé au descripteur fd en suivant la directive whence. |
 **fstat()**                     | recupere les informations d'un fichier.                                 |
 **fcntl()**                     | permet de se livrer à l'une des opérations décrites plus loin sur le descripteur de fichier. |
 **poll (ou équivalent)**        |  variation de select, attend que l'un des descripteurs de fichiers parmi un ensemble soit pret pour effectuer des entrees-sorties. |
 
## Plan du projet 

### Creation d'un simple serveur TCP

#### Creation de la main socket
1. Mise en place de la master socket, celui du serveur grace a la fonction socket()
```
(master_socket = socket(AF_INET , SOCK_STREAM , 0))
```

2. Choix des options de notre socket avec dans notre cas, la possibilite d'avoir une mutiples connexions (de client, pas de multiserver ici)

```
setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)
```

3. Faire en sorte que notre reseau TCP puisse se connecter sur le port 6667.
    + un define du port en question
    ```
    #define PORT 6667
    ```
    + utilisation de la fonction htons pour recuperer l'adresse du port 
    ```
    address.sin_port = htons( PORT );
    ```
    + affectation d'un 'nom' a notre socket principale
    ```
    bind(master_socket, (struct sockaddr *)&address, sizeof(address))
    ```

4. On arrive maintenant a l'etape ou attends qu'une action ait lieu sur notre serveur 

```
listen(master_socket, 3)
```
**Notre serveur est pret a attendre la connexion d'un client TCP !**

#### Creation des possibles sockets secondaires
Pour cette seconde et derniere etape de notre premier serveur TCP plutot basique on va placer tous ca dans une boucle while(true).
1. Tant qu'on atteint pas le nombres maximum de clients autorises dans notre serveur, on va pouvoir associer a chaque client un socket pour pouvoir lire son contenu par la suite. 

```
//socket descriptor
sd = client_socket[i];
//if valid socket descriptor then add to read list
if(sd > 0)
    FD_SET( sd , &readfds);
```

2. On arrive a l'etape ou on va attendre que nos chers clients osent prendre la parole
```
activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);
```

3. Deux cas possibles dans cette situation:
    + Une action sur notre main socket (notre serveur). Il s'agira ici donc d'une connexion d'un nouveau client. 
        - Si on a pas encore atteint notre nombres maximums de clients on va pouvoir accepter notre nouveau copain
        ```
        new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)
        ```
        - Comme on est vachement polie on va envoyer un petit message a notre serveur pour le plaisir qu'il a un nouveau pote
        ```
        printf("New connection , socket fd is %d , ip is : %s , port : %d\n" , new_socket , inet_ntoa(address.sin_addr) , ntohs
				(address.sin_port));
        ```

    + Une action provenant des sockets secondaires (un de nos clients, s'ils existent). Pour comprendre de quel type d'action il s'agit, on utilisera toujours le socket
        - Si le serveur n'arrive pas a lire sur le socket de notre client = deconnexion. 
        ```
        if ((valread = read( sd , buffer, 1024)) == 0)
        ```
      → Dans ce cas, il faut : detecter de quel client il s'agit, envoyer un message de deconnexion a notre serveur, fermer le sockets de notre client et retirer notre client de notre listes de clients.
        ```
        getpeername(sd , (struct sockaddr*)&address , \
						(socklen_t*)&addrlen);
		printf("Host disconnected , ip %s , port %d \n" ,
		inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
		close( sd );
		client_socket[i] = 0;
        ```

        - Si le serveur arrive a lire dessus = nouveau message.
        → Dans ce cas la, on va simplement renvoyer a notre client qu'il a envoye pour lui attester de sa bonne reception 
        ```
        send(sd, "Recu : ", 7, 0);
		buffer[valread] = '\0';
	    send(sd , buffer , strlen(buffer) , 0 );
        ```

**TADAM :tada: On va notre beau serveur TCP**


<p align="center"><img src="medias/schema2.png"/></p>

On mets tous ca au propre dans une class TcpServer et on part pour la suite ! 

### Comprendre le protocole IRC

→ [Pour une lecture optimale du RFC du protocole IRC](https://www.rfcreader.com/#rfc2812)

Globalement, on va vite comprendre le protocole IRC est tres codifie. Ce qui rend donc son implementation minitieuse mais egalement plutot simple a faire. 
Globalement, on va retrouver a chaque commande : 
- son parsing 
- quelques details 
- les sorties d'erreurs. 


<p align="center"><img src="medias/rfc_PASS.png" title="Petite exemple"/></p>


#### Inscription

- La commande PASS est facultative. Selon le RFC, cette commande doit etre lance avant USER et NICK qui sont obligatoires.
Comme son nom l'indique, elle definit le mot de passe que l'utilisateur peut (ou doit?) entrer pour se connecter au serveur.
- on instancie ensuite le nickname grace a la commande NICK
- on termine par lancer la commande USER

#### Recuperation des commandes

C'est bien joli de donner la possibilite a notre utilisateur de pouvoir lancer des commandes mais il faut qu'on soit en mesure de les executer pour qu'on puisse considerer le tout commefonctionnel. 
Pour ca, on est passe par des etapes intermediaire : 

1. Comme on l'a vu dans notre serveur TCP de base, le buffer est renvoye au client sans qu'on puisse l'interpreter pour faire accuse de reception. On va reutiliser cette notion d'accuse de reception mais en faisant en sorte que notre code soit capable de detecter la commande que nous envoie le client. 

2. On passe alors a notre seconde etape d'implementation. On va creer un simple pointeur sur fonctions des premieres fonctions qu'on a vu jusque la (PASS, NICK & USER). 

```
 	std::string     _command[3];
```

```
    _command[0] = "PASS\n";
    _command[1] = "NICK\n";
    _command[2] = "USER\n";
```

```
void	(IrcServer::*func[3])(void) = {
            &IrcServer::pass,
            &IrcServer::nick,
            &IrcServer::user,
        };

        for (int i = 0; i < 3; i++)
        {
        //     std::cout << "cmd = " << "[" << cmd << "]"<< std::endl;
        //     std::cout << "_cmd[i] = " << "[" << _command[i] << "]" << std::endl;
            if (cmd == _command[i])
            {
                (this->*func[i])();
                return ;
            }
        }
        return ;
```

On commence a avoir un accuse de reception (qui a terme deviendra l'execution de la commande) deja plus precis. 

3. A present, on se rend compte que fais de cette maniere ce sera a terme, bien degueu et en plus de ca, pas des plus fonctionnel. On va donc remplacer ce joli pointeur sur fonctions par une jolie map qui prendra comme paire une std::string qui represente la commande + un pointeur sur la fonction concerne. 

#### Parsing des commandes 



#### Execution des commandes




## Notes



## Ressources
- [un super cool site fait par des etudiants de 42](https://ircgod.com/)
- [encore et toujours un super readme de notre Claire nationale](https://github.com/Ccommiss/ft_irc/blob/main/README.md)
- [l'ancienne RFC du protocole IRC](https://datatracker.ietf.org/doc/html/rfc1459#section-1)
- [Un RFC plus recent](https://datatracker.ietf.org/doc/html/rfc2812)
- [un memo des commandes irc](https://fr.wikipedia.org/wiki/Aide:IRC/commandes)
- [un tres bon resume pas a pas du protocole IRC](http://www.lsv.fr/~rodrigue/teach/npp/2012/tp1.pdf)
- [un tuto d'implementation d'un serveur IRC en python](https://www.youtube.com/watch?v=3QiPPX-KeSc)
- [pour comprendre comment utiliser concretement un serveur IRC](https://bioinfo-fr.net/irc-mais-cest-quoi-en-fait)
- [creation d'un serveur TCP](https://riptutorial.com/cplusplus/example/23999/hello-tcp-server)
