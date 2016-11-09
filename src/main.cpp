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
        ///
        ///
        //1-si je recois des données je verifie que je ne connaisse pas deja le client
        //2-et je renvois a tout les clients le message
        ////////////////////////////////////////////////////////////////////////////////////////////////////
    }
        break;
    case 'c':
    case 'C':
    {
        sf::IpAddress adresse;
        unsigned short port;

        //        std::cout<<"adresse ip"<<std::endl;
        //        std::cin>> adresse;
        adresse.getLocalAddress();
        std::cout<<"port"<<std::endl;
        //std::cin>> port;
        //socket_client client(adresse,port);
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

#if(VERSION_PROJET ==2)


int main(void)
{


    sf::InputSoundFile file;
    if (!file.openFromFile(CHN_FICHIER_AUDIO))
    {
        std::cout<<"erreur"<<std::endl;
    }


    sf::Uint64 boucle;
    audiostream stream;

    stream.initialization(file.getChannelCount(),file.getSampleRate());

    int error;
    OpusEncoder *encoder=NULL;
    encoder=opus_encoder_create(FREQUENCE_SAMPLE_OPUS,file.getChannelCount(),OPUS_APPLICATION_AUDIO,&error);
    //int taille_absolu(VARIABLE_ELEMENTAIRE*2*sizeof(opus_int16));

    do
    {

        sf::Int16 lots_echantillions[TAILLE_ABSOLU];
        boucle = file.read(lots_echantillions, TAILLE_ABSOLU);


        std::vector<unsigned char>lots_echantillion_encoder(TAILLE_ABSOLU);
        opus_int32 sortie_audio_encoder(0);
        sortie_audio_encoder = opus_encode(encoder,lots_echantillions,VARIABLE_ELEMENTAIRE,&lots_echantillion_encoder[0],TAILLE_ABSOLU);
        lots_echantillion_encoder.resize(sortie_audio_encoder);


        stream.load(lots_echantillion_encoder);



        if(stream.getStatus()!= audiostream::Playing)
        {
            stream.play();
        }

    }        while (boucle > 0);



    while(stream.getStatus() == audiostream::Playing)
    {
        sf::sleep(sf::seconds(0.1f));
    }
}
#endif


/*
int main(void)
{


    std::queue<std::vector<int>>tableau;

    for(int i(0);i<5000;i++)
    {
        std::vector<int>m_echantillon;
        m_echantillon.push_back(i);

        tableau.push(m_echantillon);
    }

        bool debut(true);
        int size= tableau.size();
    for(int i(0);i<size;i++)
    {
        if(debut==true)
        {
        std::cout<<i<<" : "<<tableau.front()[0]<<std::endl;
        debut=false;
        }
        else
        {
            tableau.pop();
            std::cout<<i<<" : "<<tableau.front()[0]<<std::endl;

        }


    }
}
*/

/*
int main(void)
{
    std::queue<std::vector<int>>tableau;

    for(int i(0);i<5000;i++)
    {
        std::vector<int>m_echantillon;
        m_echantillon.push_back(i);

        tableau.push(m_echantillon);
    }
    int t(300);
    int size= tableau.size();
    for(int i(0);i<size;i++)
    {
        if(t<=tableau.size())
        {
            for(int i(0);i<t;i++)
            {
                tableau.pop();
            }

            std::cout<<i<<" : "<<tableau.front()[0]<<" : "<<tableau.size()<<std::endl;
        }
    }
}
*/


/*
bool status(true);

int main(void)
{
    std::queue<std::vector<int>>tableau;
    for(int i(0);i<5100;i++)
    {
        std::vector<int>m_echantillon;
        m_echantillon.reserve(5001);
        for(int i(0);i<5001;i++)
        {

            m_echantillon.push_back(i);


        }
        tableau.push(m_echantillon);
    }

    int t(5000);

    for(int i(0);i<100;i++)
    {
        if(status==true)
        {
        std::cout<<i<<" : "<<tableau.front()[t]<<" : "<<tableau.size()<<std::endl;
        status=false;
        }
        else
        {
            tableau.pop();
            std::cout<<i<<" : "<<tableau.front()[t]<<" : "<<tableau.size()<<std::endl;

        }
    }

}

*/
