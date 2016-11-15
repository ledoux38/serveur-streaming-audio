/*
 * client udp:
 * que faut-il pour être un client de serveur udp:
 *
 * -avoir un port                 > attribut
 * -avoir l'adresse ip du serveur > attribut
 * -avoir un identifiant          > attribut
 *
 * -envoyer des données           > methodes
 * -recevoir des données          > methodes
 *
*/
//-----------------------------------------------------------------------------------

#ifndef CLIENT_UDP_H
#define CLIENT_UDP_H
//#include <SFML/System.hpp>
//#include <SFML/Network.hpp>


#include <iostream>
#include <ostream>
#include <vector>
#include <array>

#include "../audiostream/audiostream.h"
#include "../utils/utils.h"
#include"../define_serveur_client.h"
#include"../decodeur_audio/decodeur_audio.h"

class socket_client
{
public:
    socket_client(sf::IpAddress adresse,unsigned short port);

    void run_client(void);

    sf::IpAddress get_adresse() const;

    void reception();

    unsigned short get_port() const;

    sf::UdpSocket& get_socket();

    bool est_egal(socket_client const& bdd_client) const;

    void commande_client(void);

    void decodage_donnee(std::vector<sf::Uint8>tableau);

    void reset_compteur_pong(void);

    void set_compteur_pong(void);

    int get_compteur_pong(void);

protected:

private:
    sf::IpAddress m_adresse;
    unsigned short m_port;
    sf::UdpSocket m_socket;
    audiostream m_soundstream;
    bool m_play;
    decodeur_audio* m_decodeur;
    int m_compteur_pong;

};

bool operator ==(socket_client const & nouveau_client, socket_client const & BDD_client);


std::ostream &operator <<(std::ostream &flux, socket_client &client);

#endif //CLIENT_UDP_H
