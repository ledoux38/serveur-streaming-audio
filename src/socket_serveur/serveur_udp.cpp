
#include "serveur_udp.h"

//////////////////////////////////////////////////////////////////////////////////
///                CONSTRUCTEUR/DESTRUCTEUR
//////////////////////////////////////////////////////////////////////////////////

socket_serveur::socket_serveur(void)
    : m_quitter(false)
    ,m_analyse_audio(CHN_FICHIER_AUDIO)
    ,m_encodeur(0)
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
        delete *it;

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
    while (!m_quitter)
    {
        if(m_selecteur.wait(TEMPS_SELECTEUR))
        {
            if(m_selecteur.isReady(m_socket))
            {
                std::cout<<"reception de donnee"<< std::endl;
                gestionnaire_reception_donnee();
            }
            else
            {
                std::cout<<"verif client selecteur"<< std::endl;
                verif_recep_socket();
            }

        }
        else
        {
            //std::cout<<"envoyer a tous"<< std::endl;
            transm_raw_data();
        }

    }


}



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

            std::cout<<"pong"<<std::endl;

        }
            break;

        default:
        {
            std::cout<<"erreur typage inconnu"<<std::endl;
        }
            break;

        }

        pck.clear();
        std::cout<<"fin"<<std::endl;
    }
}



void  socket_serveur::envoyer_a_tous(Packet &pck)
{
    ///////////////////////////////////////////////////////////////////////////////
    /// cette fonction envoi un packet de type RawData
    /// elle envoi à chaque client du serveur le packet par une boucle for
    ///////////////////////////////////////////////////////////////////////////////

    for(std::list<socket_client*>::iterator it = m_clients.begin();it != m_clients.end();++it)
    {
        socket_client&client = **it;
        m_socket.send(pck,client.get_adresse(),client.get_port());
    }
}



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



bool  socket_serveur::list_client(socket_client* client)
{
    ///////////////////////////////////////////////////////////////////////////////////////
    ///je verifie sur tous les socket de la list si le client et pas deja repertorié
    ///    (SI)-> le client et deja repertorié
    ///        -> je renvoie true
    /// (SINON)-> je renvoie false
    ///////////////////////////////////////////////////////////////////////////////////////

    socket_client* list_client (0);
    for(std::list<socket_client*>::iterator it = m_clients.begin();it != m_clients.end();++it)
    {
        list_client = *it;
        if(*client == *list_client)
        {
            std::cout<<"client deja connu"<<std::endl;
            return true;
        }

        else
        {
            std::cout<<"client inconnu du serveur"<<std::endl;
            return false;
        }

    }
    ///////////////////////////////////////////////////////////////////////
    /// si m_client different de zero je verifie dans la list
    /// si le client et deja connu je renvoi true
    /// si au bout de la liste je ne l'ai pas trouvé je renvoi false
    ///////////////////////////////////////////////////////////////////////
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



void  socket_serveur::verif_recep_socket(void)
{
    /////////////////////////////////////////////////////////////////////////////
    /// je verifie si chaque socket de la list et pret à recevoir des données
    ///  et je traite les packet reçu
    ////////////////////////////////////////////////////////////////////////////



    sf::Packet pck;
    sf::IpAddress ip;
    unsigned short prt;

    socket_client* list_client (0);
    for(std::list<socket_client*>::iterator it = m_clients.begin();it != m_clients.end();++it)
    {
        list_client = *it;
        if(m_selecteur.isReady(list_client->get_socket()))
        {
            list_client->get_socket().receive(pck,ip,prt);
        }
    }

}

