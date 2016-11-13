#ifndef DEFINE_SERVEUR_CLIENT_H
#define DEFINE_SERVEUR_CLIENT_H

#include<opus/opus.h>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<iostream>

#define VERSION_PROJET 1

#define TABLE_SIZE 2500
#define RESERVE_SAMPLE 2
#define TEMPS_SELECTEUR sf::milliseconds(20)
#define TAILLE_PACKET 1000
#define CHN_FICHIER_AUDIO "/home/ledoux/Qt_creator/projet/C++/progets/proj_mentora_terminal/projet_final_mentora/KariSigurdssonTwistofFate.wav"

#define VARIABLE_ELEMENTAIRE 2880
#define TAILLE_ABSOLU VARIABLE_ELEMENTAIRE*2/**sizeof(opus_int16)*/
#define APPLICATION OPUS_APPLICATION_AUDIO
#define FREQUENCE_SAMPLE_OPUS 48000
#define CANAUX 2

#define COMPTEUR_PACKET 6
#define COMPTEUR_PONG_MAXIMUM 3

#define LOG(commentaire,affichage) std::cout<<commentaire<<"::"<<affichage<<std::endl

#endif //DEFINE_SERVEUR_CLIENT_H
