#include "client_udp.h"

socket_client::socket_client(sf::IpAddress adresse,unsigned short port)
    : m_adresse(adresse), m_port(port),m_play(false),m_decodeur(0)
{
    m_decodeur=new decodeur_audio();

    Packet pck_emission(Packet::pckType::NewConnection);
    m_socket.send(pck_emission,m_adresse,m_port);


}

void socket_client::reception()
{

    Packet pck;
    sf::IpAddress adressIp;
    unsigned short port;


    if(m_socket.receive(pck,adressIp,port)==sf::Socket::Done)
    {

        switch (pck.type)
        {
        case Packet::pckType::Ping:
        {
            std::cout<<"Ping"<<std::endl;
            Packet pckPing(Packet::pckType::Pong);
            m_socket.send(pckPing,adressIp,port);

        }
            break;
        case Packet::pckType::RawData:
        {

            std::vector<sf::Uint8>tableau;
            pck>>tableau;
            decodage_donnee(tableau);

        }
            break;
        case Packet::pckType::initialization:
        {
            std::cout<<"initialization"<<std::endl;
            sf::Uint32 canaux,taux_echantillonnage;

            if(pck>>canaux>>taux_echantillonnage)
            {
                std::cout<<" "<< canaux <<" "<< taux_echantillonnage <<std::endl;
                m_soundstream.initialization(canaux,taux_echantillonnage);
            }


        }
            break;

        default:
        {
            std::cout<<"erreur typage inconnu"<<std::endl;
        }
            break;
        }

    }


}
void socket_client::decodage_donnee(std::array< sf::Uint8,TAILLE_PACKET>tableau,opus_int32 taille_tableau_donnee)
{
    std::vector<sf::Uint8>tableau_encode(taille_tableau_donnee);
    for(int i(0);i<taille_tableau_donnee;++i)
    {
        tableau_encode[i]=tableau[i];
    }
            int taille_decode(0);
            std::vector<sf::Int16>echantillions(TAILLE_ABSOLU);
            taille_decode=m_decodeur->decodage_donnee_audio(&tableau_encode[0],tableau_encode.size(),&echantillions[0],0);
            echantillions.resize(taille_decode);
}

void socket_client::decodage_donnee(std::vector<sf::Uint8>tableau)
{
    int taille_decode(0);
    std::vector<sf::Int16>echantillions(TAILLE_ABSOLU);
    taille_decode=m_decodeur->decodage_donnee_audio(&tableau[0],tableau.size(),&echantillions[0],0);
    echantillions.resize(taille_decode*CANAUX);
    m_soundstream.load(echantillions);
}

    sf::IpAddress socket_client::get_adresse() const
    {
        return m_adresse;
    }

    unsigned short socket_client::get_port() const
    {
        return m_port;
    }

    sf::UdpSocket& socket_client::get_socket()
    {
        return m_socket;
    }

    bool socket_client::est_egal(socket_client const& bdd_client) const
    {
        return(m_adresse == bdd_client.m_adresse && m_port == bdd_client.m_port);
    }

    void socket_client::emission()
    {

    }

    void socket_client::run_client(void)
    {
        while (true)
        {
            reception();
        }


    }

    bool operator ==(socket_client const & nouveau_client, socket_client const & BDD_client)
    {
        return nouveau_client.est_egal(BDD_client);
    }

    void socket_client::commande_client(void)
    {
        ///////////////////////////////////////////////////////////////////////////
        /// la fonction membre commande_serveur permet de commander le serveur
        /// ou de verifier certaine chose comme le nombre de client sur la list
        /// de rajouter des musiques etc
        /// pour le moment elle n'est pas encore implementer
        ///////////////////////////////////////////////////////////////////////////

        while(true)
        {
            char commande;
            std::cout<<"commande client >>"<<std::endl;
            std::cout<<"L -> play"<<std::endl;
            std::cout<<"P -> pause"<<std::endl;
            std::cout<<"Q -> quit"<<std::endl;
            std::cin >> commande;

            switch (commande)
            {
            case 'l':
            case 'L':
            {
                if(m_soundstream.getStatus()!= audiostream::Playing)
                {
                    m_soundstream.play();
                }
            }
                break;

            case 'p':
            case 'P':
            {
                if(m_soundstream.getStatus()== audiostream::Playing)
                {
                    m_soundstream.pause();
                }
            }
                break;
            case 'q':
            case 'Q':
            {

            }
                break;

            default:
                std::cout<<"erreur commande"<<std::endl;
                break;
            }
        }

    }

    void socket_client::set_compteur_pong(void)
    {
        m_compteur_pong++;
    }


    void socket_client::reset_compteur_pong(void)
    {
        m_compteur_pong = 0;
    }

    int socket_client::get_compteur_pong(void)
    {
        return m_compteur_pong;
    }

    std::ostream &operator <<(std::ostream &flux, socket_client &client)
    {
        flux<<"adresse ip: " << client.get_adresse().toString()<< "  port:" << client.get_port() << std::endl;
        return flux;
    }

