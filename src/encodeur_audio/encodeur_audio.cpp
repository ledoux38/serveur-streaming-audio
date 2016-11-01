#include "encodeur_audio.h"

encodeur_audio::encodeur_audio(unsigned int cannaux, opus_int32 frequence_opus, int application)
    :m_error(0)
{
    m_encodeur=opus_encoder_create(frequence_opus,cannaux,application,&m_error);
}
   encodeur_audio::~encodeur_audio()
{
    opus_encoder_destroy(m_encodeur);
}

int encodeur_audio::get_encodeur_erreur()const
{
    return m_error;
}

OpusEncoder& encodeur_audio::get_encodeur()const
{
    return *m_encodeur;
}

    opus_int32 encodeur_audio::encodage_donnee_audio(const opus_int16* donnee_audio,int taille_donnee_audio,unsigned char *donnee_audio_encoder,opus_int32	taille_donnee_audio_max)
    {
       return opus_encode(m_encodeur,donnee_audio,taille_donnee_audio,donnee_audio_encoder,taille_donnee_audio_max);


    }
