
#include "serveur_udp.h"

//////////////////////////////////////////////////////////////////////////////////
///                CONSTRUCTEUR/DESTRUCTEUR
//////////////////////////////////////////////////////////////////////////////////

socket_serveur::socket_serveur(void): m_quitter(false),m_analyse_audio(CHN_FICHIER_AUDIO),m_encodeur(nullptr),m_compteur_envoi(0),m_numero_client(0)
{
    /////////////////////////////////////////////////////////////////////
    ///je cree mon serveur (aquisition du port gerer par l'OS)
    ///je connect le socket de mon serveur au selecteur
    /////////////////////////////////////////////////////////////////////

#if(VERSION_PROJET ==0)
    if(m_socket.bind(sf::Socket::AnyPort) != sf::Socket::Done)
     {
         std::cerr <<"erreur dans le lancement du serveur"<<std::endl;
     }
#else
    if(m_socket.bind(5000) != sf::Socket::Done)

    {
        std::cerr <<"erreur dans le lancement du serveur"<<std::endl;
    }
#endif
    else
    {
        m_selecteur.add(m_socket);
        std::cout<<"serveur mit en ligne port:" << m_socket.getLocalPort() <<std::endl;
        std::cout<<"serveur adresse ip:local "  << sf::IpAddress::getLocalAddress()
                <<"\n          adresse public "<< sf::IpAddress::getPublicAddress()<<std::endl;

    }
    m_encodeur=new encodeur_audio(/*2,FREQUENCE_SAMPLE_OPUS,APPLICATION*/);
}


socket_serveur::~socket_serveur()
{
    for(std::list<socket_client*>::iterator it = m_clients.begin();it != m_clients.end();++it)
    {
        delete (*it);

    }
}


//////////////////////////////////////////////////////////////////////////////////
///                     FONCTION PUBLIC
//////////////////////////////////////////////////////////////////////////////////


void socket_serveur::run_serveur(void)
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///lancement de la boucle infini
    ///      (SI)->le groupe de socket du selecteur recois des données pendant le temps imparti
    ///          ->(SI)->le socket du serveur et pret a recevoir des données
    ///                ->je receptionne les données pour les traiter
    ///         (SINON)->je verifie les sockets de la base de donnée
    ///   (SINON)-> je continu à envoyer des donnée aux autres socket de la base de donnée
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
  #if(SOUS_VERSION == 0)
    while (!m_quitter)
    {
        if(m_selecteur.wait(TEMPS_SELECTEUR))
        {
            if(m_selecteur.isReady(m_socket))
            {
                std::cout<<"reception de donnee"<< std::endl;
                gestionnaire_reception_donnee();
            }

        }
        else
        {
            if(m_compteur_envoi < COMPTEUR_PACKET)
            {

                transm_raw_data();
            }
            else
            {
                if(m_numero_client<m_clients.size())
                {
                    for(std::list<socket_client*>::iterator it = m_clients.begin();it != m_clients.end();++it)
                    {

                        transm_ping(*it);
                    }
                }

                m_numero_client =0;
                m_compteur_envoi =0;
            }
        }
    }
}
#endif

#if(SOUS_VERSION == 1)

while (!m_quitter)
{
    if(m_selecteur.wait(TEMPS_SELECTEUR))
    {
        if(m_selecteur.isReady(m_socket))
        {
            std::cout<<"reception de donnee"<< std::endl;
            gestionnaire_reception_donnee();
        }
    }
    else
    {
        if(m_clients.size() != 0)
        {
            if(m_compteur_envoi < COMPTEUR_PACKET)
            {
                transm_raw_data();
            }
            else
            {
                std::list<socket_client*>::iterator it = m_clients.begin();
                int cpt(0);
                while (cpt!=m_numero_client)
                {
                    ++it;
                    ++cpt;
                }
                transm_ping(*it);

                if(m_numero_client==m_clients.size()-1)
                    m_numero_client =0;
                else
                    m_numero_client++;
                m_compteur_envoi =0;
            }
        }
    }
}
}
#endif

void  socket_serveur::gestionnaire_reception_donnee(void)
{

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// je reçois des données du socket du serveur
    /// en fonction du typage du packet j'oriente les données au CASE qui lui son propre
    ///         SI nouveau client je lui transmet les données d'initialization et je rajoute le client au selecteur
    ///         SI je recois un pong c'est la reponse d'un client pour savoir si il et toujour present
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Packet pck;
    sf::IpAddress adresse;
    unsigned short port;


    std::cout<< "RECEPTION" << std::endl;


    if(m_socket.receive(pck,adresse,port)==sf::Socket::Done)
    {
        switch (pck.type)
        {
        case Packet::pckType::NewConnection:
        {
            std::cout<< "new connection" << std::endl;
            transm_init_data_sound(adresse,port);
            ajouter_client(adresse,port);

            std::cout<<"nombre de client dans la list: "<< m_clients.size()<< std::endl;
        }
            break;
        case Packet::pckType::Pong:
        {
            std::list<socket_client*>::iterator it;
            it = find_object (m_clients.begin(), m_clients.end(), socket_client(adresse,port));
            if (it != m_clients.end())
                (*it)->reset_compteur_pong();
              else
                std::cerr << "Element no found in the list"<<std::endl;

        }
            break;

        default:
        {

        }
            break;
        }

        pck.clear();
        std::cout<<"fin"<<std::endl;
    }
}

#if(SOUS_VERSION == 0)
void  socket_serveur::envoyer_a_tous(Packet &pck)
{
    ///////////////////////////////////////////////////////////////////////////////
    /// cette fonction envoi un packet de type RawData
    /// elle envoi à chaque client du serveur le packet par une boucle for
    ///////////////////////////////////////////////////////////////////////////////

    if(m_clients.size() != 0)
    {

        for(std::list<socket_client*>::iterator it = m_clients.begin();it != m_clients.end();++it)
        {
            if((*it)->get_compteur_pong()>=COMPTEUR_PONG_MAXIMUM)
            {
                delete (*it);
                m_clients.erase(it);
                std::cout<<"suppression client"<<std::endl;
                return;
            }
            else
            {
                m_socket.send(pck,(*it)->get_adresse(),(*it)->get_port());
            }

        }
        m_compteur_envoi++;
    }
}
#endif

#if(SOUS_VERSION == 1)
void  socket_serveur::envoyer_a_tous(Packet &pck)
{
    ///////////////////////////////////////////////////////////////////////////////
    /// cette fonction envoi un packet de type RawData
    /// elle envoi à chaque client du serveur le packet par une boucle for
    ///////////////////////////////////////////////////////////////////////////////

    std::list<socket_client*>::iterator it = m_clients.begin();
    while (it!=m_clients.end())
    {
        if((*it)->get_compteur_pong()>=COMPTEUR_PONG_MAXIMUM)
        {
            delete (*it);
            m_clients.erase(it);
            std::cout<<"suppression client"<<std::endl;
            // return;
        }
        else
        {
            m_socket.send(pck,(*it)->get_adresse(),(*it)->get_port());
            COUT("transmission audio");
        }
        if(m_clients.size()!=0)
            it++;
        else
            break;
    }
    m_compteur_envoi++;

}


#endif

//////////////////////////////////////////////////////////////////////////////////
///                         PROTEGER
//////////////////////////////////////////////////////////////////////////////////


void  socket_serveur::ajouter_client(sf::IpAddress const &adresse, const unsigned short &port)
{
    ///////////////////////////////////////////////////
    /// je rajoute le client dans la list
    /// et je rajoute le client dans le selecteur
    ////////////////////////////////////////////////////
    ///
    socket_client*client = new socket_client(adresse,port);
    m_clients.push_back(client);
    m_selecteur.add(client->get_socket());

    std::cout<<"ajout client:"<< *client <<std::endl;
}


void  socket_serveur::commande_serveur(void)
{
    ///////////////////////////////////////////////////////////////////////////
    /// la fonction membre commande_serveur permet de commander le serveur
    /// ou de verifier certaine chose comme le nombre de client sur la list
    /// de rajouter des musiques etc
    /// pour le moment elle n'est pas encore implementer
    ///////////////////////////////////////////////////////////////////////////

    while(!m_quitter)
    {
        char commande;
        std::cout<<"commande serveur >>"<<std::endl;
        std::cin >> commande;

        switch (commande)
        {
        case 'S':
        {
            std::cout<<"tableau size :"<<m_clients.size()<<std::endl;
        }
            break;
        case 'Q':
        {
            std::cout<<"arret serveur"<<std::endl;
            m_quitter = true;
        }
            break;

        default:
            std::cout<<"erreur commande"<<std::endl;
            break;
        }
    }

}


void  socket_serveur::transm_ping (socket_client* client)
{
    ///////////////////////////////////////////////////////////////////////////////////////////////
    ///    cette fonction membre du serveur envoi un ping au client designée
    ////////////////////////////////////////////////////////////////////////////////////////////////

    Packet pck(Packet::pckType::Ping);
    m_socket.send(pck,client->get_adresse(),client->get_port());
    client->set_compteur_pong();
}


void socket_serveur::transm_init_data_sound (sf::IpAddress adresse_client, unsigned short port_client)
{
    /////////////////////////////////////////////////////////////////////////////////////
    ///    cette fonction membre du serveur prépare dans un packet les données audio recuperer
    ///    de l'analyse de la musique et de les envoyer au nouveau client
    ///    ou au changement de musique
    /////////////////////////////////////////////////////////////////////////////////////

    std::cout<<"procedure d'init "<<std::endl;

    Packet pck(Packet::pckType::initialization);
    pck<<m_analyse_audio.get_fichier_sound().getChannelCount()<<m_analyse_audio.get_fichier_sound().getSampleRate();
    m_socket.send(pck,adresse_client,port_client);
}


void socket_serveur::transm_raw_data(void)
{
    ///////////////////////////////////////////
    /// creation d'un tableau(taille absolu)
    /// transfere du lot de donnée audio dans le tableau
    /// creation d'un tableau pour les donnée audio encodé
    /// encodage des données audio
    /// transfere des donnée audio dans un tableau pour envoi par packet
    /////////////////////////////////////////////

    sf::Int16 lots_echantillions[TAILLE_ABSOLU];
    m_analyse_audio.get_fichier_sound().read(lots_echantillions,TAILLE_ABSOLU);

    std::vector<unsigned char>lots_echantillion_encoder(TAILLE_ABSOLU);
    opus_int32 taille_audio_encode(0);
    taille_audio_encode= m_encodeur->encodage_donnee_audio(lots_echantillions,VARIABLE_ELEMENTAIRE,&lots_echantillion_encoder[0],TAILLE_ABSOLU);
    lots_echantillion_encoder.resize(taille_audio_encode);

    Packet pck(Packet::pckType::RawData);
    pck<<lots_echantillion_encoder;
    envoyer_a_tous(pck);
}
