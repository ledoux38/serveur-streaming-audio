#include <iostream>
#include "audiostream/audiostream.h"
#include "socket_serveur/serveur_udp.h"
#include "socket_client/client_udp.h"
#include "define_serveur_client.h"
#include <ostream>
#include <array>
#include <queue>

#if(VERSION_PROJET ==0)
int main(void)
{
    char reponse;
    std::cout << "voulez vous utiliser lancer le serveur (s) ou le client (c) ?" << std::endl;
    std::cin >> reponse;

    switch (reponse)
    {
    case 's':
    case 'S':
    {
        ///////////////////////////////////////////////////////////////////////////////////////////////
        /// 1-je crée mon serveur avec un port gerer par l'OS
        /// 2-  si -->mon serveur c'est bien lancé j'affiche un message avec le port du serveur, adresse ip...
        ///  sinon -->erreur
        ///1-si je recois des données je verifie que je ne connaisse pas deja le client
        ///2-et je renvois a tout les clients le message
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        socket_serveur serveur;
        serveur.run_serveur();
    }
        break;
    case 'c':
    case 'C':
    {
        sf::IpAddress adresse;
        unsigned short port;
        std::cout<<"adresse ip"<<std::endl;
        std::cin>> adresse;
        std::cout<<"port"<<std::endl;
        std::cin>> port;
        socket_client client(adresse,port);

        sf::Thread thread(&socket_client::commande_client,&client);
        thread.launch();
        client.run_client();
    }
        break;

    default:
        std::cerr<<"error switch invalid"<<std::endl;
        break;
    }

    return EXIT_SUCCESS;
}
#endif

#if(VERSION_PROJET ==1)

int main(void)
{
    char reponse;
    std::cout << "voulez vous utiliser lancer le serveur (s) ou le client (c) ?" << std::endl;
    std::cin >> reponse;

    switch (reponse)
    {
    case 's':
    case 'S':
    {
        socket_serveur serveur;
        serveur.run_serveur();
        ///////////////////////////////////////////////////////////////////////////////////////////////
        /// 1-je crée mon serveur avec un port gerer par l'OS
        /// 2-  si -->mon serveur c'est bien lancé j'affiche un message avec le port du serveur, adresse ip...
        ///  sinon -->erreur
        ////////////////////////////////////////////////////////////////////////////////////////////////////
    }
        break;
    case 'c':
    case 'C':
    {
        sf::IpAddress adresse;
        adresse.getLocalAddress();
        socket_client client(adresse,5000);
        sf::Thread thread(&socket_client::commande_client,&client);
        thread.launch();

        client.run_client();
    }
        break;

    default:
        std::cerr<<"error switch invalid"<<std::endl;
        break;
    }

    return EXIT_SUCCESS;
}


#endif

