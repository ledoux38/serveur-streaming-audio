#ifndef SERVEUR_UDP_H
#define SERVEUR_UDP_H

/////////////////////////////////////////////////////////////////
//HEADERS
/////////////////////////////////////////////////////////////////
//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>


#include <iostream>
#include <list>
#include <array>

#include "../socket_client/client_udp.h"
#include "../audiostream/audiostream.h"
#include "../utils/utils.h"
#include "../analyse_audio/analyse_audio.h"
#include "../define_serveur_client.h"
#include "../encodeur_audio/encodeur_audio.h"
/////////////////////////////////////////////////////////////////


class socket_serveur
{
public:
    /////////////////////////////////////////////////////////////////
    /// \brief socket_serveur
    /// constructeur de la classe par defaut
    /////////////////////////////////////////////////////////////////
    socket_serveur(void);

    /////////////////////////////////////////////////////////////////
    ///\brief run_serveur
    /// destructeur de la classe
    /// elle permet de detruire les pointeurs de la list de client
    /////////////////////////////////////////////////////////////////
    ~socket_serveur();

    /////////////////////////////////////////////////////////////////
    /// \brief run_serveur
    /// cette fonction membre à pour but de lancer le serveur ainsi
    /// que le selecteur et la transmission de donnée brute par packet
    /// de facon generale le fonctionnement et simple.
    /// j'attent pandant une durée de 20 ms si pendant ce temps le selecteur
    /// ou le serveur en lui meme non rien recu je transmet par packet
    /// les donnée audio via la fonction envoyer à tous
    /////////////////////////////////////////////////////////////////
    void run_serveur(void);

    /////////////////////////////////////////////////////////////////
    /// \brief gestionnaire_reception_donnee
    /// cette fonction membre à pour fonction de receptionner les packets
    /// en fonction du typage des packets de les orienter dans leur partie
    /// respectif.
    /////////////////////////////////////////////////////////////////
    void gestionnaire_reception_donnee(void);

    /////////////////////////////////////////////////////////////////
    /// \brief envoyer_a_tous
    /// cette fonction membre à pour fonction d'envoyer des packets
    /// a tous les clients enregistrée au niveau du serveur
    /////////////////////////////////////////////////////////////////
    void envoyer_a_tous(Packet &pck);

    /////////////////////////////////////////////////////////////////
    /// \brief commande_serveur
    /// fonction qui permer de parametrer le serveur
    /////////////////////////////////////////////////////////////////
    void commande_serveur(void);



protected:

    void new_connect_client(void);

    void transm_init_data_sound (sf::IpAddress adresse_client,unsigned short port_client);

    void transm_ping (socket_client *client);

    void transm_raw_data(void);

    void verif_recep_socket(void);

    void ajouter_client(const sf::IpAddress &adresse, const unsigned short &port);

    bool list_client(socket_client* client);

private:
    std :: list <socket_client *> m_clients;
    sf::SocketSelector m_selecteur;
    sf::UdpSocket m_socket;
    bool m_quitter;
    analyse_audio m_analyse_audio;
    encodeur_audio*m_encodeur;
};

#endif //SERVEUR_UDP_H


